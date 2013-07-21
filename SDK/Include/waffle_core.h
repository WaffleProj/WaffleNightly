#ifndef __SDK_WAFFLE_CORE_H_
#define __SDK_WAFFLE_CORE_H_

#define LIBRARY_EXPORT    __declspec(dllexport)
#define LIBRARY_IMPORT    __declspec(dllimport)

#define WAFFLE_VERSION_MAJOR        0
#define WAFFLE_VERSION_MINOR        10
#define WAFFLE_SDK_VERSION_MAJOR    1
#define WAFFLE_SDK_VERSION_MINOR    0

#define	TM_FIRSTMESSAGE         TM_GETTID
#define	TM_GETTID               WM_USER + 1
#define	TM_LASTMESSAGE          TM_GETTID

#endif /* __SDK_WAFFLE_CORE_H_ */