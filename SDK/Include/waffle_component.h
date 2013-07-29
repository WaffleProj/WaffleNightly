#ifndef __SDK_WAFFLE_COMPONENT_H_
#define __SDK_WAFFLE_COMPONENT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WAFFLE_COMPONENT_BUILD
#define WAFFLE_COMPONENT_FUNCTION LIBRARY_EXPORT
#else
#define WAFFLE_COMPONENT_FUNCTION
#endif

    WAFFLE_COMPONENT_FUNCTION SIZE_T WINAPI ComponentInit(
        _In_    LPWAFFLE_PROCESS_SETTING lpstProcessSetting
        );

    typedef SIZE_T(WINAPI *LPCOMPONENTINIT)(
        _In_    LPWAFFLE_PROCESS_SETTING lpstProcessSetting
        );
    
    WAFFLE_COMPONENT_FUNCTION SIZE_T WINAPI ThreadInit(
        _In_    LPTHREAD_CONTEXT lpstThread
        );
    
    typedef SIZE_T(WINAPI *LPTHREADINIT)(
        _In_    LPTHREAD_CONTEXT lpstThread
        );

#ifdef __cplusplus
};
#endif

#endif /* __SDK_WAFFLE_COMPONENT_H_ */