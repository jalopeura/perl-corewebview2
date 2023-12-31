#pragma once

#include "utils.h"

//#include "WebView2.h"
//
////#define PERL_NO_GET_CONTEXT
//#include "EXTERN.h"
//#include "perl.h"
//#include "XSUB.h"

VARIANT scalar_to_variant(SV* scalar);
SV* variant_to_scalar(VARIANT variant);
