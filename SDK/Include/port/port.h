#ifndef __SDK_WAFFLE_PORT_PORT_H_
#define __SDK_WAFFLE_PORT_PORT_H_

#define WAFFLE_PORT_MACHINE_I386    0x14C   //IMAGE_FILE_MACHINE_I386
#define WAFFLE_PORT_MACHINE_AMD64   0x8664  //IMAGE_FILE_MACHINE_AMD64

#define WAFFLE_PORT_MACHINE_IA64    0x200   //IMAGE_FILE_MACHINE_IA64

#define WAFFLE_PORT_MACHINE_ARM     0x1C0   //IMAGE_FILE_MACHINE_ARM
#define WAFFLE_PORT_MACHINE_ARMNT   0x1C4   //IMAGE_FILE_MACHINE_ARMNT
#define WAFFLE_PORT_MACHINE_ARM64   0xAA64  //IMAGE_FILE_MACHINE_ARM64
#define WAFFLE_PORT_MACHINE_THUMB   0x1C2   //IMAGE_FILE_MACHINE_THUMB

#define WAFFLE_PORT_MACHINE_STRING_I386     TEXT("I386")
#define WAFFLE_PORT_MACHINE_STRING_AMD64    TEXT("AMD64")

#define WAFFLE_PORT_MACHINE_STRING_IA64     TEXT("IA64")

#define WAFFLE_PORT_MACHINE_STRING_ARM      TEXT("ARM")
#define WAFFLE_PORT_MACHINE_STRING_ARMNT    TEXT("ARMNT")
#define WAFFLE_PORT_MACHINE_STRING_ARM64    TEXT("ARM64")
#define WAFFLE_PORT_MACHINE_STRING_THUMB    TEXT("THUMB")

#if	    defined(_M_IX86)
    #include "I386.h"
#elif   defined(_M_AMD64)
    #include "AMD64.h"
#elif   defined(_M_IA64)
    #error   IA64 is unsupported right now.
#elif   defined(_M_ARM)
    #error   ARM is unsupported right now.
#else
    #error   Unknown platform.
#endif

#endif /* __SDK_WAFFLE_PORT_PORT_H_ */