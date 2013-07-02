#ifndef __SDK_WAFFLE_H_
#define __SDK_WAFFLE_H_

#include "waffle_native.h"

#include "waffle_core.h"
#include "waffle_common_lib.h"

#if defined(_WIN64)
#include "port\AMD64.h"
#else
#include "port\I386.h"
#endif  // defined(_WIN64)

#endif /* __SDK_WAFFLE_H_ */