#ifndef __SDK_WAFFLE_PORT_I386_H_
#define __SDK_WAFFLE_PORT_I386_H_

#define WAFFLE_PORT_EXCEPTION_INSTRUCTION                   0xF4 //hlt
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA              BYTE
#define WAFFLE_PORT_EXCEPTION_CODE                          EXCEPTION_PRIV_INSTRUCTION
#define WAFFLE_PORT_WRITE_EXCEPTION_INSTRUCTION(lpAddress)  *(WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA *)(lpAddress) = WAFFLE_PORT_EXCEPTION_INSTRUCTION

#define	WAFFLE_PORT_PROGRAM_POINTER                         Eip
#define	WAFFLE_PORT_STACK_POINTER                           Esp
#define	WAFFLE_PORT_FRAME_POINTER                           Ebp
#define	WAFFLE_PORT_FASTCALL_ARGUMENT                       Ecx

#define	WAFFLE_PORT_ENTRY_POINT                             Eax
#define WAFFLE_PORT_ENTRY_POINT_LOOP_STRING                 "\xEB\xFE"

#define WAFFLE_PORT_MACHINE             WAFFLE_PORT_MACHINE_I386
#define WAFFLE_PORT_MACHINE_STRING      WAFFLE_PORT_MACHINE_STRING_I386

#if     defined(__GNUC__)
#define	WAFFLE_PORT_RETURN_ADDRESS	__builtin_return_address(0)
#elif   defined(_MSC_VER)
#define	WAFFLE_PORT_RETURN_ADDRESS	_ReturnAddress()
#endif

#endif /* __SDK_WAFFLE_PORT_I386_H_ */