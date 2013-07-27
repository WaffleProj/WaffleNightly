#ifndef __SDK_WAFFLE_COMMON_LIB_H_
#define __SDK_WAFFLE_COMMON_LIB_H_

#define szNameProcessSetting        TEXT("WaffleProcessSetting")
#define szFmtValueProcessSetting    TEXT("WaffleProcessSetting/TID%08X/TickCount%08X")
#define WAFFLE_PROCESS_SETTING_SIZE sizeof(WAFFLE_PROCESS_SETTING)
typedef struct
{
    SIZE_T  wVersionMajor;  // = WAFFLE_SDK_VERSION_MAJOR
    SIZE_T  wVersionMinor;  // = WAFFLE_SDK_VERSION_MINOR
    SIZE_T  cbSize;         // = sizeof(WAFFLE_PROCESS_SETTING)
    SIZE_T  dwProcessId;
    SIZE_T  dwThreadId;
    TCHAR   szPlugin[MAX_PATH];
} WAFFLE_PROCESS_SETTING, *LPWAFFLE_PROCESS_SETTING;

typedef BOOL(WINAPI *LPWOW64DISABLEWOW64FSREDIRECTION)(
    _Out_   PVOID *OldValue
    );
typedef BOOL(WINAPI *LPWOW64REVERTWOW64FSREDIRECTION)(
    _In_    PVOID OldValue
    );

#ifdef __cplusplus
extern "C" {
#endif

    BOOL WINAPI WaffleCreateProcess(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPSECURITY_ATTRIBUTES lpProcessAttributes,
        _In_opt_    LPSECURITY_ATTRIBUTES lpThreadAttributes,
        _In_        BOOL bInheritHandles,
        _In_        DWORD dwCreationFlags,
        _In_opt_    LPVOID lpEnvironment,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _In_opt_    LPSTARTUPINFO lpStartupInfo,
        _Out_opt_   LPPROCESS_INFORMATION lpProcessInformation
        );

    typedef BOOL(WINAPI *LPWAFFLECREATEPROCESS)(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPSECURITY_ATTRIBUTES lpProcessAttributes,
        _In_opt_    LPSECURITY_ATTRIBUTES lpThreadAttributes,
        _In_        BOOL bInheritHandles,
        _In_        DWORD dwCreationFlags,
        _In_opt_    LPVOID lpEnvironment,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _In_opt_    LPSTARTUPINFO lpStartupInfo,
        _Out_opt_   LPPROCESS_INFORMATION lpProcessInformation
        );

    void WINAPI WaffleInjectDll(
        _In_    HANDLE hProcess,
        _In_    LPCTSTR lpszDllFull
        );

    typedef void(WINAPI *LPWAFFLEINJECTDLL)(
        _In_    HANDLE hProcess,
        _In_    LPCTSTR lpszDllFull
        );
    
    void WINAPI WaffleExecute(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _Out_opt_   LPWAFFLE_PROCESS_SETTING lpstProcessSetting
        );

    typedef void(WINAPI *LPWAFFLEEXECUTE)(
        _In_opt_    LPCTSTR lpApplicationName,
        _Inout_opt_ LPTSTR lpCommandLine,
        _In_opt_    LPCTSTR lpCurrentDirectory,
        _Out_opt_   LPWAFFLE_PROCESS_SETTING lpstProcessSetting
        );

    int WINAPI WaffleArgc(void);
    SIZE_T WINAPI WaffleArgv(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );
    LPCTSTR WINAPI WaffleArgp(
        _In_    int intPosition
        );

    typedef int (WINAPI *LPWAFFLEARGC)(void);
    typedef SIZE_T(WINAPI *LPWAFFLEARGV)(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );
    typedef LPCTSTR(WINAPI *LPWAFFLEARGP)(
        _In_    int intPosition
        );

    WORD WINAPI WaffleGetMachineType(
        _In_    LPCTSTR lpszFile
        );

    typedef WORD(WINAPI *LPWAFFLEGETMACHINETYPE)(
        _In_    LPCTSTR lpszFile
        );

    void WINAPI WaffleGetModuleDirectory(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );

    typedef void (WINAPI *LPWAFFLEGETMODULEDIRECTORY)(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );

    LPWAFFLE_PROCESS_SETTING WINAPI WaffleOpenProcessSetting(void);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLEOPENPROCESSSETTING)(void);

    LPWAFFLE_PROCESS_SETTING WINAPI WaffleCreateProcessSetting(void);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLECREATEPROCESSSETTING)(void);

    void WINAPI WaffleResumeMainThread(void);

    typedef void (WINAPI *LPWAFFLERESUMEMAINTHREAD)(void) ;

    SIZE_T WINAPI WaffleInit(
        _In_    LPVOID lpReserved
        );

    typedef SIZE_T(WINAPI *LPWAFFLEINIT)(
        _In_    LPVOID lpReserved
        );

    void WINAPI WaffleGetFileHash(
        _In_    LPTSTR lpszFile,
        _In_    LPTSTR lpszResult
        );

    typedef void (WINAPI *LPWAFFLEGETFILEHASH)(
        _In_    LPTSTR lpszFile,
        _In_    LPTSTR lpszResult
        );

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMMON_LIB_H_ */