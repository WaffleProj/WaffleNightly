#ifndef __SDK_WAFFLE_PORT_AMD64_H_
#define __SDK_WAFFLE_PORT_AMD64_H_

#define WAFFLE_PORT_WRITE_PRIVILEGED_INSTRUCTION(lpAddress) *(char *)(lpAddress) = 0xF4 //hlt

#define	WAFFLE_PORT_PEB_ADDRESS                             (PPEB)__readgsqword(0x60)
#define	WAFFLE_PORT_INSTRUCTION_POINTER(ExceptionInfo)      ExceptionInfo->ContextRecord->Rip

#endif /* __SDK_WAFFLE_PORT_AMD64_H_ */