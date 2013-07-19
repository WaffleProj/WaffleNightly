#ifndef __SDK_WAFFLE_COMPONENT_H_
#define __SDK_WAFFLE_COMPONENT_H_

#ifdef __cplusplus
extern "C" {
#endif

SIZE_T WINAPI ComponentInit(
  _In_  LPWAFFLE_PROCESS_SETTING lpstProcessSetting
);
typedef SIZE_T (WINAPI *LPCOMPONENTINIT)(
  _In_  LPWAFFLE_PROCESS_SETTING lpstProcessSetting
);

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMPONENT_H_ */