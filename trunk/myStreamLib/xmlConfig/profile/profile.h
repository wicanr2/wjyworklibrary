#ifndef PROFILE_H
#define PROFILE_H
#ifdef __cplusplus
extern "C" {
#endif
void VideoXMLProfile_Init();
int AudioProfile_Init();
int X264Profile_Init();
int RecvProfile_Init();
int AudioBindleProfile_Init();
void __XMLProfileInit();
int PAProfile_Init();
#ifdef __cplusplus
}
#endif
#endif
