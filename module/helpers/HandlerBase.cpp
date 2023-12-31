#include "HandlerBase.h"

#ifdef DEBUG
#define DEBUG_TAG "HandlerBase"
#endif // DEBUG

HandlerBase::HandlerBase(SV* perl_object, const char* type_name = NULL) : InterfaceWrapper(type_name) {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Creating object (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	SetPerlObject(perl_object);
}

HandlerBase::~HandlerBase() {
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("Destroying object (refcount %d) in %s (%p)", m_refcount, this->TypeName(), this);
}
#endif // DEBUG
	SetPerlObject(NULL);
}

void HandlerBase::SetPerlObject(SV* perl_object) {
	// drop old object if any
	if (m_perl_object) {
		SvREFCNT_dec(m_perl_object);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG
	}

	// set new object if any
	m_perl_object = perl_object;
	if (m_perl_object) {
		SvREFCNT_inc(m_perl_object);
#ifdef DEBUG
if (debugme(DEBUG_TAG) || debugme(m_typename)) {
	WARN("SV* refcount %d (%p)", SvREFCNT(m_perl_object), m_perl_object);
}
#endif // DEBUG
	}
}
