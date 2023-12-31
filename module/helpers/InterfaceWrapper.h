#pragma once

#include "utils.h"
#include <map>

// forward declaration so WRAP_INTERFACE will see it
//class InterfaceWrapper;

// create the child class (use in the .h, once per wrapped interface)
// name is the name for the inner wrapper class to be created
// iface is the name of the interface
// wrapper is the name of the outer wrapper class (the one that inherits from InterfaceWrapper)
#define WRAP_INTERFACE(name, iface, wrapper) class name : public iface { \
public: \
	name(wrapper* wrapper, iface##Vtbl* vtbl) : m_wrapper{wrapper}, iface{vtbl} { \
	} \
	virtual ~name() { \
	} \
	wrapper* Wrapper() { return m_wrapper; } \
private: \
	wrapper* m_wrapper = NULL; \
}; \
private: \
name* m_##name = NULL; \
public:

// was not able to make these macro-within-a-macro calls work
//		DEBUG(WARN("New object %s (%p)", typeid(this).name(), this);) \
//		DEBUG(WARN("Deleting object %s (%p)", typeid(this).name(), this);) \

// create the IUknown functions that will go in the vtable (use in the .cpp, once per wrapped interface)
// name, iface, and wrapper are the same as in WRAP_INTERFACE
#ifdef DEBUG
#define IUNKNOWN_DEFS(name, iface, wrapper) static HRESULT STDMETHODCALLTYPE name##_QueryInterface(iface* This, REFIID riid, void** ppvObject) { \
if (debugme(DEBUG_TAG)) { \
	WARN("QueryInterface: iface %p / object %p", This, static_cast<wrapper::name*>(This)); \
} \
	return static_cast<wrapper::name*>(This)->Wrapper()->QueryInterface(riid, ppvObject); \
} \
static ULONG STDMETHODCALLTYPE name##_AddRef(iface* This) { \
if (debugme(DEBUG_TAG)) { \
	WARN("AddRef: iface %p / object %p", This, static_cast<wrapper::name*>(This)); \
} \
	return static_cast<wrapper::name*>(This)->Wrapper()->AddRef(); \
} \
static ULONG STDMETHODCALLTYPE name##_Release(iface* This) { \
if (debugme(DEBUG_TAG)) { \
	WARN("Release: iface %p / object %p", This, static_cast<wrapper::name*>(This)); \
} \
	return static_cast<wrapper::name*>(This)->Wrapper()->Release(); \
}
#else
#define IUNKNOWN_DEFS(name, iface, wrapper) static HRESULT STDMETHODCALLTYPE name##_QueryInterface(iface* This, REFIID riid, void** ppvObject) { \
	return static_cast<wrapper::name*>(This)->Wrapper()->QueryInterface(riid, ppvObject); \
} \
static ULONG STDMETHODCALLTYPE name##_AddRef(iface* This) { \
	return static_cast<wrapper::name*>(This)->Wrapper()->AddRef(); \
} \
static ULONG STDMETHODCALLTYPE name##_Release(iface* This) { \
	return static_cast<wrapper::name*>(This)->Wrapper()->Release(); \
}
#endif // DEBUG

// init the first three slots in the vtable (use in the .cpp, once per wrapped interface)
// name is the same as in WRAP_INTERFACE
#define IUNKNOWN_INIT(name) name##_QueryInterface, name##_AddRef, name##_Release,

//#define xADD_INTERFACE(name, iface, vtbl) \
//iface* name##iface = (iface*)new name(this, vtbl); \
//m_##name = static_cast<iface*>(name##iface); \
//AddInterface(IID_##iface, name##iface);
//
//#define yADD_INTERFACE(name, iface, vtbl) \
//m_##name = new name(this, vtbl); \
//AddInterface(IID_##iface, static_cast<iface*>(m_##name));
//
//#define ADD_INTERFACE(name, iface, vtbl) \
//AddInterface(IID_##iface, (iface*)new name(this, vtbl));
//
//#define REMOVE_INTERFACE(name, iface) \
//RemoveInterface(IID_##iface); \

//delete m_##name; \
//m_##name = NULL;

class InterfaceWrapper {
public:
	InterfaceWrapper(const char* type_name = NULL);
	virtual ~InterfaceWrapper();

	const char* TypeName();

	HRESULT AddInterface(REFIID riid, void* pvObject);
	void* GetInterface(REFIID riid);
//	HRESULT RemoveInterface(REFIID riid);

	// IUnknown
	HRESULT QueryInterface(REFIID riid, void** ppvObject);
	ULONG AddRef();
	ULONG Release();

	ULONG Mortalize();

	WRAP_INTERFACE(Unknown, IUnknown, InterfaceWrapper)

protected:
	ULONG m_refcount;
	const char* m_typename = NULL;

private:
	ULONG m_mortalcount = 0;
	std::map<std::wstring, void*> m_interfaces;
};
