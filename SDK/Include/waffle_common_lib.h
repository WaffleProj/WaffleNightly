#ifndef __SDK_WAFFLE_COMMON_LIB_H_
#define __SDK_WAFFLE_COMMON_LIB_H_

typedef BOOL (WINAPI *LPWOW64DISABLEWOW64FSREDIRECTION)(
  _Out_  PVOID *OldValue
);
typedef BOOL (WINAPI *LPWOW64REVERTWOW64FSREDIRECTION)(
  _In_  PVOID OldValue
);

#ifdef __cplusplus
extern "C" {
#endif

BOOL WINAPI WaffleCreateProcess(
  _In_  HINSTANCE hinstDLL,
  _In_  DWORD fdwReason,
  _In_  LPVOID lpvReserved
);

typedef BOOL (WINAPI *LPWAFFLECREATEPROCESS)(
  _In_  HINSTANCE hinstDLL,
  _In_  DWORD fdwReason,
  _In_  LPVOID lpvReserved
);

int WINAPI WaffleArgc();
SIZE_T WINAPI WaffleArgv(
  _In_  int intPosition,
  _In_  LPTSTR lpString,
  _In_  int intSize
);
LPCTSTR WINAPI WaffleArgp(
  _In_  int intPosition
);

typedef int (WINAPI *LPWAFFLEARGC)();
typedef SIZE_T (WINAPI *LPWAFFLEARGV)(
  _In_  int intPosition,
  _In_  LPTSTR lpString,
  _In_  int intSize
);
typedef LPCTSTR (WINAPI *LPWAFFLEARGP)(
  _In_  int intPosition
);

WORD WINAPI WaffleGetMachineType(
  _In_  LPCTSTR lpszFile
);

typedef WORD (WINAPI *LPWAFFLEGETMACHINETYPE)(
  _In_  LPCTSTR lpszFile
);

PROCESS_INFORMATION WINAPI WaffleInjectDll(
  _In_  LPCTSTR lpszTarget,
  _In_  LPTSTR lpszArgument,
  _In_  LPCTSTR lpszDirectory,
  _In_  LPCTSTR lpszDllFull
);

typedef PROCESS_INFORMATION (WINAPI *LPWAFFLEINJECTDLL)(
  _In_  LPCTSTR lpszTarget,
  _In_  LPTSTR lpszArgument,
  _In_  LPCTSTR lpszDirectory,
  _In_  LPCTSTR lpszDllFull
);

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMMON_LIB_H_ */