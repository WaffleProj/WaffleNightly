#ifndef __SDK_WAFFLE_COMMON_LIB_H_
#define __SDK_WAFFLE_COMMON_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

BOOL WINAPI WaffleCreateProcess(
  _In_  HINSTANCE hinstDLL,
  _In_  DWORD fdwReason,
  _In_  LPVOID lpvReserved
);

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMMON_LIB_H_ */