#ifndef __SDK_WAFFLE_CORE_H_
#define __SDK_WAFFLE_CORE_H_

#define LIBRARY_EXPORT      __declspec(dllexport)
#define LIBRARY_IMPORT      __declspec(dllimport)
#if     defined(__GNUC__)
#define GCC_NOINLINE        __attribute__(noinline)
#define MSVC_NOINLINE
#endif
#if     defined(_MSC_VER)
#define GCC_NOINLINE
#define MSVC_NOINLINE       __declspec(noinline)
#endif

typedef struct
{
    DWORD   dwBehind;
    LPCTSTR lpszFunction;
    LPVOID  lpSource;
    LPVOID  lpBackup;
    LPVOID  lpDetour;
} WAFFLE_FUNCTION_ARRAY, *LPWAFFLE_FUNCTION_ARRAY;

typedef struct
{
    DWORD                   dwBehind;
    LPCTSTR                 lpszLibrary;
    HMODULE                 hSource;
    LPVOID                  hSourceEnd;
    HMODULE                 hBackup;
    LPVOID                  hBackupEnd;
    LPWAFFLE_FUNCTION_ARRAY lpstFunction;
} WAFFLE_LIBRARY_ARRAY, *LPWAFFLE_LIBRARY_ARRAY;

typedef struct
{
    DWORD                   dwBehind;
    LPCTSTR                 lpszComponent;
    HMODULE                 hSource;
    LPVOID                  hSourceEnd;
} WAFFLE_COMPONENT_ARRAY, *LPWAFFLE_COMPONENT_ARRAY;

#define WAFFLE_VERSION_MAJOR        0
#define WAFFLE_VERSION_MINOR        10
#define WAFFLE_SDK_VERSION_MAJOR    1
#define WAFFLE_SDK_VERSION_MINOR    0

#define WAFFLE_HASH_LENGTH          20

#define szNameProcessSetting        TEXT("WaffleProcessSetting")
#define szFmtValueProcessSetting    TEXT("WaffleProcessSetting/TID%08X/TickCount%08X")
#define WAFFLE_PROCESS_SETTING_SIZE sizeof(WAFFLE_PROCESS_SETTING)

typedef struct
{
    DWORD   cbSize;         // = sizeof(WAFFLE_PROCESS_SETTING)
    DWORD   dwVersionMajor; // = WAFFLE_SDK_VERSION_MAJOR
    DWORD   dwVersionMinor; // = WAFFLE_SDK_VERSION_MINOR
    DWORD   dwProcessId;
    DWORD   dwThreadId;
    LPWAFFLE_COMPONENT_ARRAY    lpstComponent
    LPWAFFLE_LIBRARY_ARRAY      lpstLibrary;
    TCHAR   szComponent[MAX_PATH];
    TCHAR   szComponentDirectory[MAX_PATH];
    TCHAR   szHash[WAFFLE_HASH_LENGTH * 2 + 1];
} WAFFLE_PROCESS_SETTING, *LPWAFFLE_PROCESS_SETTING;

typedef struct
{
    CRITICAL_SECTION    csRead;
    CRITICAL_SECTION    csWrite;
    HANDLE              hReader;
    DWORD               dwReader;
} WAFFLE_RWLOCK, *LPWAFFLE_RWLOCK;

typedef struct
{
    LPWAFFLE_PROCESS_SETTING lpstProcessSetting;
    HANDLE   hThread;
    PCONTEXT lpstContext;
} WAFFLE_THREAD_CONTEXT, *LPWAFFLE_THREAD_CONTEXT;

#endif /* __SDK_WAFFLE_CORE_H_ */