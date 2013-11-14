#ifndef __SDK_WAFFLE_PORT_ARMNT_H_
#define __SDK_WAFFLE_PORT_ARMNT_H_

//http://mamaich-eng.blogspot.ru/2013/02/no-arm-code-on-windows-on-arm.html
//you can't see ARM code in it. Everything is THUMB2.
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION                   0xBE00      //bkpt 00h   Thumb-16
                                                            //0xE1200070  bkpt 0000h ARM
#define WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA              WORD
#define WAFFLE_PORT_EXCEPTION_CODE                          EXCEPTION_BREAKPOINT
#define WAFFLE_PORT_WRITE_EXCEPTION_INSTRUCTION(lpAddress)  *(WAFFLE_PORT_EXCEPTION_INSTRUCTION_DATA *)(lpAddress) = WAFFLE_PORT_EXCEPTION_INSTRUCTION

//http://www.phrack.com/issues.html?issue=63&id=6
//By convention, r13 is used as a stack pointer(sp) in ARM assembly language.
//In User mode and System mode, r14 is used as a link register(lr) to store the return address when a subroutine call is made.
//The program counter is accessed as r15(pc).
#define	WAFFLE_PORT_STACK_POINTER                           Sp
#define	WAFFLE_PORT_FRAME_POINTER                           R7
//http://msdn.microsoft.com/en-us/library/ms253599%28v=vs.80%29.aspx
//R11 in ARM mode
#define	WAFFLE_PORT_PROGRAM_POINTER                         Pc
#define	WAFFLE_PORT_FASTCALL_ARGUMENT                       R0

#if     defined(__GNUC__)
#define	WAFFLE_PORT_RETURN_ADDRESS	__builtin_return_address(0)
#elif   defined(_MSC_VER)
#define	WAFFLE_PORT_RETURN_ADDRESS	_ReturnAddress()
#endif

#define WAFFLE_PORT_MACHINE             WAFFLE_PORT_MACHINE_ARMNT
#define WAFFLE_PORT_MACHINE_STRING      WAFFLE_PORT_MACHINE_STRING_ARMNT

#endif /* __SDK_WAFFLE_PORT_ARMNT_H_ */