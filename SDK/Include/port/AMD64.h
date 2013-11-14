#ifndef __SDK_WAFFLE_PORT_AMD64_H_
#define __SDK_WAFFLE_PORT_AMD64_H_

#define WAFFLE_PORT_EXCEPTION_INSTRUCTION                   0xF4 //hlt
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA              BYTE
#define WAFFLE_PORT_EXCEPTION_CODE                          EXCEPTION_PRIV_INSTRUCTION
#define WAFFLE_PORT_WRITE_EXCEPTION_INSTRUCTION(lpAddress)  *(WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA *)(lpAddress) = WAFFLE_PORT_EXCEPTION_INSTRUCTION

#define	WAFFLE_PORT_PROGRAM_POINTER                         Rip
#define	WAFFLE_PORT_STACK_POINTER                           Rsp
#define	WAFFLE_PORT_FRAME_POINTER                           Rbp
#define	WAFFLE_PORT_FASTCALL_ARGUMENT                       Rcx

#define	WAFFLE_PORT_ENTRY_POINT                             Rcx
#define WAFFLE_PORT_ENTRY_POINT_LOOP_STRING                 "\xEB\xFE"

#define WAFFLE_PORT_MACHINE             WAFFLE_PORT_MACHINE_AMD64
#define WAFFLE_PORT_MACHINE_STRING      WAFFLE_PORT_MACHINE_STRING_AMD64

#if     defined(__GNUC__)
#define	WAFFLE_PORT_RETURN_ADDRESS	__builtin_return_address(0)
#elif   defined(_MSC_VER)
#define	WAFFLE_PORT_RETURN_ADDRESS	_ReturnAddress()
#endif

#endif /* __SDK_WAFFLE_PORT_AMD64_H_ */