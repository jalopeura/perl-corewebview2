#include "InterfaceWrapper.h"

//#include <functional>

#ifdef DEBUG
#define DEBUG_TAG "InterfaceWrapper"
#endif // DEBUG

IUNKNOWN_DEFS(Unknown, IUnknown, InterfaceWrapper)

// IUnknown has no other functions

static IUnknownVtbl UnknownVtbl = {
	IUNKNOWN_INIT(Unknown)
	// IUnknown has no other functions
};

// IUnknown

HRESULT InterfaceWrapper::QueryInterface(REFIID riid, void** ppvObject) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("QueryInterface (refcount %d, mortal %d) in %s (%p)", m_refcount, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	*ppvObject = GetInterface(riid);

	if (*ppvObject == NULL) {
		return E_NOINTERFACE;
	}

	AddRef();
	return S_OK;
}

ULONG InterfaceWrapper::AddRef() {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("AddRef (%d => %d, mortal %d) in %s (%p)", m_refcount, m_refcount+1, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	m_refcount++;

	// apply any mortalizations (pending releases)
	if (m_mortalcount > 0) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Applying mortalization (%d => %d) in %s (%p)", m_refcount, m_refcount-m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
		m_refcount -= m_mortalcount;
		m_mortalcount = 0;
	}

	return m_refcount;
}

ULONG InterfaceWrapper::Release() {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Release (%d => %d, mortal %d) in %s (%p)", m_refcount, m_refcount-1, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	m_refcount--;

	// apply any mortalizations (pending releases)
	if (m_mortalcount > 0) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Applying mortalization (%d => %d) in %s (%p)", m_refcount, m_refcount-m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
		m_refcount -= m_mortalcount;
		m_mortalcount = 0;
	}

	if (m_refcount == 0) {
		#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Deleting %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
		delete this;
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Back from deleting");
}
#endif // DEBUG
	}
	return m_refcount;
}

/*
 * special function - create a delayed Release() that will take effect on the next AddRef() or actual Release()
 */

ULONG InterfaceWrapper::Mortalize() {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Mortalize (%d => %d, %d actual) in %s (%p)", m_mortalcount, m_mortalcount+1, m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	m_mortalcount++;
	return m_mortalcount;
}

/*
 * constructor and destructor (the vtables must be defined before defining the constructor
 */

InterfaceWrapper::InterfaceWrapper(const char* type_name) : m_refcount{1}, m_typename{type_name} {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("New object (refcount %d, mortal %d) %s (%p)", m_refcount, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
/*
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("New object (refcount %d) %s (%p)", m_refcount, typeid(this).name(), this);
}
#endif // DEBUG
	InterfaceWrapper::Unknown* object = new InterfaceWrapper::Unknown(this, &UnknownVtbl);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Created child wrapper (%p)", object);
}
#endif // DEBUG
	IUnknown* iface = (IUnknown*)object;
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Cast pointer to interface (%p)", iface);
}
#endif // DEBUG
	AddInterface(IID_IUnknown, iface);
*/

	AddInterface(IID_IUnknown, (IUnknown*)(new InterfaceWrapper::Unknown(this, &UnknownVtbl)));
}

InterfaceWrapper::~InterfaceWrapper() {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Deleting object %s (%p)", this->TypeName(), this);
}
#endif // DEBUG
}

/*
 * helper methods
 */

HRESULT InterfaceWrapper::AddInterface(REFIID riid, void* pvObject) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("AddInterface %p (refcount %d, mortal %d) in %s (%p)", pvObject, m_refcount, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	LPOLESTR idstr = NULL;
	HRESULT result = StringFromIID(riid, &idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	std::string name = iidname(SHORTEN(idstr));
	WARN("Converted iid to string %s => %s", SHORTEN(idstr), name.c_str());
}
#endif // DEBUG
	
	if (result == S_OK) {
		std::wstring key(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Assigning %p to %s", pvObject, SHORTEN(key.c_str()));
}
#endif // DEBUG
		m_interfaces[key] = pvObject;
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("About to free key");
}
#endif // DEBUG
		CoTaskMemFree(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Done freeing key");
}
#endif // DEBUG
	}

	return result;
}

void* InterfaceWrapper::GetInterface(REFIID riid) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("GetInterface (refcount %d, mortal %d) in %s (%p)", m_refcount, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	void* out = NULL;
	LPOLESTR idstr = NULL;
	HRESULT result = StringFromIID(riid, &idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	std::string name = iidname(SHORTEN(idstr));
	WARN("Converted iid to string %s => %s", SHORTEN(idstr), name.c_str());
}
#endif // DEBUG

	if (result == S_OK) {
		std::wstring key(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Fetching value for %s", SHORTEN(key.c_str()));
}
#endif // DEBUG
		out = m_interfaces[key];
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("About to free key");
}
#endif // DEBUG
		CoTaskMemFree(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Done freeing key");
}
#endif // DEBUG
	}

#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("About to return interface (%p)", out);
}
#endif // DEBUG
	return out;
}

/*
HRESULT InterfaceWrapper::RemoveInterface(REFIID riid) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("RemoveInterface (refcount %d, mortal %d) in %s (%p)", m_refcount, m_mortalcount, this->TypeName(), this);
}
#endif // DEBUG
	LPOLESTR idstr = NULL;
	HRESULT result = StringFromIID(riid, &idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	std::string name = iidname(SHORTEN(idstr));
	WARN("Converted iid to string %s => %s", SHORTEN(idstr), name.c_str());
}
#endif // DEBUG
	
	if (result == S_OK) {
		std::wstring key(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Erasing %s", SHORTEN(key.c_str()));
}
#endif // DEBUG
		m_interfaces.erase(key);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("About to free key");
}
#endif // DEBUG
		CoTaskMemFree(idstr);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Done freeing key");
}
#endif // DEBUG
	}

	return result;
}
*/

const char* InterfaceWrapper::TypeName() { return m_typename; }
