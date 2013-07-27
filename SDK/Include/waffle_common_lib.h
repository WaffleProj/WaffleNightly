#ifndef __SDK_WAFFLE_COMMON_LIB_H_
#define __SDK_WAFFLE_COMMON_LIB_H_

#define szNameProcessSetting        TEXT("WaffleProcessSetting")
#define szFmtValueProcessSetting    TEXT("WaffleProcessSetting/TID%08X/TickCount%08X")
#define WAFFLE_PROCESS_SETTING_SIZE 512
typedef struct
{
    SIZE_T  wVersionMajor;  // = WAFFLE_SDK_VERSION_MAJOR
    SIZE_T  wVersionMinor;  // = WAFFLE_SDK_VERSION_MINOR
    SIZE_T  cbSize;         // = sizeof(WAFFLE_PROCESS_SETTING)
    SIZE_T  dwProcessId;
    SIZE_T  dwThreadId;
    SIZE_T  offsetszPlugin;
    LPTSTR  lpszPlugin;
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
        _In_    HINSTANCE hinstDLL,
        _In_    DWORD fdwReason,
        _In_    LPVOID lpvReserved
        );

    typedef BOOL(WINAPI *LPWAFFLECREATEPROCESS)(
        _In_    HINSTANCE hinstDLL,
        _In_    DWORD fdwReason,
        _In_    LPVOID lpvReserved
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

    PROCESS_INFORMATION WINAPI WaffleInjectDll(
        _In_    LPCTSTR lpszTarget,
        _In_    LPTSTR lpszArgument,
        _In_    LPCTSTR lpszDirectory,
        _In_    LPCTSTR lpszDllFull,
        _In_    LPWAFFLE_PROCESS_SETTING lpstProcessSetting
        );

    typedef PROCESS_INFORMATION(WINAPI *LPWAFFLEINJECTDLL)(
        _In_    LPCTSTR lpszTarget,
        _In_    LPTSTR lpszArgument,
        _In_    LPCTSTR lpszDirectory,
        _In_    LPCTSTR lpszDllFull,
        _In_    LPWAFFLE_PROCESS_SETTING lpstProcessSetting
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

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLEOPENPROCESSSETTING)();

    LPWAFFLE_PROCESS_SETTING WINAPI WaffleCreateProcessSetting(
        _In_    LPWAFFLE_PROCESS_SETTING lpstNewSetting
        );

    typedef LPWAFFLE_PROCESS_SETTING(WINAPI *LPWAFFLECREATEPROCESSSETTING)(
        _In_    LPWAFFLE_PROCESS_SETTING lpstNewSetting
        );

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