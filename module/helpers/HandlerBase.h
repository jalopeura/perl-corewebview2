#pragma once
#include "InterfaceWrapper.h"

class HandlerBase : public InterfaceWrapper {
public:
	HandlerBase(SV* perl_object, const char* type_name);
	virtual ~HandlerBase();

	bool RegisterToken(EventRegistrationToken token) {
		if (m_token.value != 0)
			return false;
		m_token = token;
		return true;
	};
	EventRegistrationToken Token() { return m_token; };

protected:
	void SetPerlObject(SV* perl_object);
	SV* m_perl_object = NULL;

private:
	EventRegistrationToken m_token = { 0 };
};
