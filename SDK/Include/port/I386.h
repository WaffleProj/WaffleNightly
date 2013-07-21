#ifndef __SDK_WAFFLE_PORT_I386_H_
#define __SDK_WAFFLE_PORT_I386_H_

#define WAFFLE_PORT_PRIVILEGED_INSTRUCTION                  0xF4 //hlt
#define WAFFLE_PORT_PRIVILEGED_INSTRUCTION_DATA             char
#define WAFFLE_PORT_WRITE_PRIVILEGED_INSTRUCTION(lpAddress) *(WAFFLE_PORT_PRIVILEGED_INSTRUCTION_DATA *)(lpAddress) = WAFFLE_PORT_PRIVILEGED_INSTRUCTION

#define	WAFFLE_PORT_PEB_ADDRESS                             (PPEB)__readfsdword(0x30)
#define	WAFFLE_PORT_INSTRUCTION_POINTER(ExceptionInfo)      ExceptionInfo->ContextRecord->Eip

#define WAFFLE_PORT_MACHINE             WAFFLE_PORT_MACHINE_I386
#define WAFFLE_PORT_MACHINE_STRING      TEXT("I386")

#endif /* __SDK_WAFFLE_PORT_I386_H_ */