#ifndef __SDK_WAFFLE_PORT_I386_H_
#define __SDK_WAFFLE_PORT_I386_H_

#define WAFFLE_PORT_WRITE_PRIVILEGED_INSTRUCTION(lpAddress) *(char *)(lpAddress) = 0xF4 //hlt

#define	WAFFLE_PORT_PEB_ADDRESS                             (PPEB)__readfsdword(0x30)
#define	WAFFLE_PORT_INSTRUCTION_POINTER(ExceptionInfo)      ExceptionInfo->ContextRecord->Eip

#endif /* __SDK_WAFFLE_PORT_I386_H_ */