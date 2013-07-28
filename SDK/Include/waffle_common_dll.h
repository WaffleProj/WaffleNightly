#ifndef __SDK_WAFFLE_COMMON_DLL_H_
#define __SDK_WAFFLE_COMMON_DLL_H_

#define szNameProcessSetting        TEXT("WaffleProcessSetting")
#define szFmtValueProcessSetting    TEXT("WaffleProcessSetting/TID%08X/TickCount%08X")
#define WAFFLE_PROCESS_SETTING_SIZE sizeof(WAFFLE_PROCESS_SETTING)
typedef struct
{
    SIZE_T  wVersionMajor;  // = WAFFLE_SDK_VERSION_MAJOR
    SIZE_T  wVersionMinor;  // = WAFFLE_SDK_VERSION_MINOR
    SIZE_T  cbSize;         // = sizeof(WAFFLE_PROCESS_SETTING)
    DWORD   dwProcessId;
    DWORD   dwThreadId;
    TCHAR   szPlugin[MAX_PATH];
} WAFFLE_PROCESS_SETTING, *LPWAFFLE_PROCESS_SETTING;

typedef BOOL(WINAPI *LPWOW64DISABLEWOW64FSREDIRECTION)(
    _Out_   PVOID *OldValue
    );
typedef BOOL(WINAPI *LPWOW64REVERTWOW64FSREDIRECTION)(
    _In_    PVOID OldValue
    );

typedef struct
{
    LPCSTR lpszFunction;
    LPVOID lpDetourFunction;
    LPVOID lpNewFunction;
    LPVOID lpOriginalFunction;
} HOOK_TABLE_OBJECT, *LPHOOK_TABLE_OBJECT;

typedef struct
{
    LPCWSTR             lpszLibrary;
    LPHOOK_TABLE_OBJECT lpHookTable;
    HMODULE             lpLibrary;
    HMODULE             hModule;
    LPVOID              lpEndOfModule;
} LIBRARY_TABLE_OBJECT, *LPLIBRARY_TABLE_OBJECT;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef  _BUILD_WAFFLE_COMMON_DLL_
#define WAFFLE_COMMON_DLL_FUNCTION LIBRARY_EXPORT
#else
#define WAFFLE_COMMON_DLL_FUNCTION
#endif

    /*
    cmdarg.c
    */
    WAFFLE_COMMON_DLL_FUNCTION int WINAPI WaffleArgc(void);

    typedef int (WINAPI *LPWAFFLEARGC)(void) ;

    WAFFLE_COMMON_DLL_FUNCTION SIZE_T WINAPI WaffleArgv(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );

    typedef SIZE_T(WINAPI *LPWAFFLEARGV)(
        _In_    int intPosition,
        _In_    LPTSTR lpString,
        _In_    int intSize
        );

    WAFFLE_COMMON_DLL_FUNCTION LPCTSTR WINAPI WaffleArgp(
        _In_    int intPosition
        );

    typedef LPCTSTR(WINAPI *LPWAFFLEARGP)(
        _In_    int intPosition
        );
    /*
    exception.h
    */
    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleSetLibraryTable(
        _In_    LPLIBRARY_TABLE_OBJECT lpstLibraryTable
        );

    WAFFLE_COMMON_DLL_FUNCTION HMODULE WINAPI WaffleGetModuleAddressW(
        _In_    LPCWSTR lpszModule
        );

    WAFFLE_COMMON_DLL_FUNCTION HMODULE WINAPI WaffleCopyLibrary(
        _In_    HMODULE hModule
        );

    WAFFLE_COMMON_DLL_FUNCTION HMODULE WINAPI WaffleCopyLibraryEx(
        _In_    LPLIBRARY_TABLE_OBJECT stLibrary
        );

    WAFFLE_COMMON_DLL_FUNCTION LPVOID WINAPI WaffleGetFunctionAddressA(
        _In_    HMODULE hDll,
        _In_    LPCSTR lpszFuncName
        );

    WAFFLE_COMMON_DLL_FUNCTION LONG CALLBACK WaffleBreakpointHandler(
        _In_    PEXCEPTION_POINTERS ExceptionInfo
        );
    /*
    filesystem.c
    */
    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleGetModuleDirectory(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );

    typedef void (WINAPI *LPWAFFLEGETMODULEDIRECTORY)(
        _In_opt_    HMODULE hModule,
        _Out_       LPTSTR lpFilename,
        _In_        DWORD nSize
        );
    /*
    hash.c
    */
    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleGetFileHash(
        _In_    LPTSTR lpszFile,
        _In_    LPTSTR lpszResult
        );

    typedef void (WINAPI *LPWAFFLEGETFILEHASH)(
        _In_    LPTSTR lpszFile,
        _In_    LPTSTR lpszResult
        );
    /*
    init.c
    */
    WAFFLE_COMMON_DLL_FUNCTION SIZE_T WINAPI WaffleInit(
        _In_    LPVOID lpReserved
        );

    typedef SIZE_T(WINAPI *LPWAFFLEINIT)(
        _In_    LPVOID lpReserved
        );
    /*
    inject.c
    */
    WAFFLE_COMMON_DLL_FUNCTION BOOL WINAPI WaffleCreateProcess(
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

    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleInjectDll(
        _In_    HANDLE hProcess,
        _In_    LPCTSTR lpszDllFull
        );

    typedef void(WINAPI *LPWAFFLEINJECTDLL)(
        _In_    HANDLE hProcess,
        _In_    LPCTSTR lpszDllFull
        );

    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleExecute(
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
    /*
    pemachine.c
    */
    WAFFLE_COMMON_DLL_FUNCTION WORD WINAPI WaffleGetMachineType(
        _In_    LPCTSTR lpszFile
        );

    typedef WORD(WINAPI *LPWAFFLEGETMACHINETYPE)(
        _In_    LPCTSTR lpszFile
        );
    /*
    setting.c
    */
    WAFFLE_COMMON_DLL_FUNCTION LPWAFFLE_PROCESS_SETTING WINAPI WaffleOpenProcessSetting(void);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLEOPENPROCESSSETTING)(void) ;

    WAFFLE_COMMON_DLL_FUNCTION LPWAFFLE_PROCESS_SETTING WINAPI WaffleCreateProcessSetting(void);

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLECREATEPROCESSSETTING)(void) ;

    WAFFLE_COMMON_DLL_FUNCTION void WINAPI WaffleResumeMainThread(void);

    typedef void (WINAPI *LPWAFFLERESUMEMAINTHREAD)(void) ;

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMMON_DLL_H_ */