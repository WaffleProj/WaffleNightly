#ifndef __SDK_WAFFLE_NATIVE_H_
#define __SDK_WAFFLE_NATIVE_H_

#define _In_
#define _In_opt_
#define _Out_
#define _Out_opt_
#define _Reserved_

#include <windows.h>
#include <intrin.h>
#include <winternl.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef  RtlMoveMemory
__declspec(dllimport) VOID WINAPI RtlMoveMemory(
  _In_  VOID UNALIGNED *Destination,
  _In_  const VOID UNALIGNED *Source,
  _In_  SIZE_T Length
);

#undef  RtlFillMemory
__declspec(dllimport) VOID WINAPI RtlFillMemory(
  _Out_  VOID UNALIGNED *Destination,
  _In_   SIZE_T Length,
  _In_   UCHAR Fill
);

#undef  RtlZeroMemory
__declspec(dllimport) VOID WINAPI RtlZeroMemory(
  _In_  VOID UNALIGNED *Destination,
  _In_  SIZE_T Length
);

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_NATIVE_H_ */