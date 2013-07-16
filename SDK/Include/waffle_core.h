#ifndef __SDK_WAFFLE_CORE_H_
#define __SDK_WAFFLE_CORE_H_

#ifdef  LIBRARY_EXPORTS
#define LIBRARY_API     __declspec(dllexport)
#else
#define LIBRARY_API     __declspec(dllimport)
#endif

#define MACHINE_AMD64   0x8664  //IMAGE_FILE_MACHINE_AMD64
#define MACHINE_I386    0x14C   //IMAGE_FILE_MACHINE_I386

#define WAFFLE_VERSION_MAJOR        0
#define WAFFLE_VERSION_MINOR        10
#define WAFFLE_SDK_VERSION_MAJOR    0
#define WAFFLE_SDK_VERSION_MINOR    10

#define	TM_FIRSTMESSAGE         TM_GETTID
#define	TM_GETTID               WM_USER + 1
#define	TM_LASTMESSAGE          TM_GETTID

#define szNameProcessSetting        TEXT("WaffleProcessSetting")
#define szFmtValueProcessSetting    TEXT("WaffleProcessSetting/TID%08X/TickCount%08X")
#define WAFFLE_PROCESS_SETTING_SIZE 512
typedef struct
{
    SIZE_T  wVersionMajor;  // = WAFFLE_SDK_VERSION_MAJOR
    SIZE_T  wVersionMinor;   // = WAFFLE_SDK_VERSION_MINOR
    SIZE_T  cbSize;         // = sizeof(WAFFLE_PROCESS_SETTING)
    SIZE_T  dwThreadId;
    SIZE_T  offsetPluginName;
} WAFFLE_PROCESS_SETTING, *LPWAFFLE_PROCESS_SETTING;

#endif /* __SDK_WAFFLE_CORE_H_ */