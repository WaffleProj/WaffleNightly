#ifndef __SDK_WAFFLE_CORE_H_
#define __SDK_WAFFLE_CORE_H_

#ifdef  LIBRARY_EXPORTS
#define LIBRARY_API     __declspec(dllexport)
#else
#define LIBRARY_API     __declspec(dllimport)
#endif

#define MACHINE_AMD64   0x8664  //IMAGE_FILE_MACHINE_AMD64
#define MACHINE_I386    0x14C   //IMAGE_FILE_MACHINE_I386

#define	TM_FIRSTMESSAGE		TM_GETTID
#define	TM_GETTID     	        WM_USER + 1
#define	TM_LASTMESSAGE		TM_GETTID

#endif /* __SDK_WAFFLE_CORE_H_ */