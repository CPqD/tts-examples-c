#ifndef CPQD_TTS_LOADER_H
#define CPQD_TTS_LOADER_H

#define TTS_LOADABLE_LIBRARY 1

#include "tts.h"
#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#else
#include <dlfcn.h>
#endif


#if defined(WIN32) || defined(WIN64)
#define dynlib_load(path)                LoadLibrary(path)
#define dynlib_unload(ptr)               { if ((ptr) != 0) FreeLibrary(ptr); }
#define dynlib_get(handle, name)         GetProcAddress(handle, name)
#else
#define dynlib_load(path)                dlopen(path, RTLD_LAZY)
#define dynlib_unload(ptr)               { if ((ptr) != 0) dlclose(ptr); }
#define dynlib_get(handle, name)         dlsym(handle, name)
#endif

#define dynlib_symbol(handle, name, ptr, type)  \
    { ptr = (type)dynlib_get(handle, name); \
    if (ptr == 0) { funcName = (name); result = 1; \
    goto ESCAPE; } }



#if defined(WIN32) || defined(WIN64)
typedef HMODULE LIB_HANDLE;
#else
typedef  void *LIB_HANDLE;
#endif

extern TTS_INITIALIZE          TTS_Initialize;
extern TTS_TERMINATE           TTS_Terminate;
extern TTS_FREE                TTS_Free;
extern TTS_LOADVOICE           TTS_LoadVoice;
extern TTS_UNLOADVOICE         TTS_UnloadVoice;
extern TTS_CREATESESSION       TTS_CreateSession;
extern TTS_RELEASESESSION      TTS_ReleaseSession;
extern TTS_TEXTTOSPEECH        TTS_TextToSpeech;
extern TTS_TEXTTOSPEECHSTREAM  TTS_TextToSpeechStream;
extern TTS_GETAUDIOLENGTH      TTS_GetAudioLength;
extern TTS_GETAUDIOINFO        TTS_GetAudioInfo;
extern TTS_COPYAUDIO           TTS_CopyAudio;
extern TTS_SAVEAUDIO           TTS_SaveAudio;
extern TTS_GETLASTERROR        TTS_GetLastError;
extern TTS_GETENGINEINFO       TTS_GetEngineInfo;
extern TTS_GETSESSIONINFO      TTS_GetSessionInfo;
extern TTS_SETFLOATPARAMETER   TTS_SetFloatParameter;
extern TTS_GETFLOATPARAMETER   TTS_GetFloatParameter;
extern TTS_SETSTRINGPARAMETER  TTS_SetStringParameter;
extern TTS_GETSTRINGPARAMETER  TTS_GetStringParameter;
extern TTS_LOADPLUGIN          TTS_LoadPlugin;
extern TTS_UNLOADPLUGIN        TTS_UnloadPlugin;
extern TTS_ENUMERATEVOICE      TTS_EnumerateVoices;
extern TTS_ENUMERATEENCODER    TTS_EnumerateEncoders;


#ifdef __cplusplus
extern "C" {
#endif

TTS_RETURN tts_loadLibrary( const char *path );

TTS_RETURN tts_unloadLibrary( void );

#ifdef __cplusplus
}
#endif

#endif // CPQD_TTS_PROT_API_H
