#ifndef __SDK_WAFFLE_H_
#define __SDK_WAFFLE_H_

#include "waffle_native.h"

#include "waffle_core.h"
#include "waffle_common_lib.h"
#include "waffle_component.h"

#if	defined(_M_IX86)
    #include "port\I386.h"
#elif	defined(_M_AMD64)
    #include "port\AMD64.h"
#elif	defined(_M_IA64)
    #error  IA64 is unsupported right now.
#elif	defined(_M_ARM)
    #error  ARM is unsupported right now.
#else
    #error  Unknown platform.
#endif

#endif /* __SDK_WAFFLE_H_ */