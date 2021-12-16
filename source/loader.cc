#include <stdio.h>
#include <iostream>

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#endif

#include "loader.hh"

static LIB_HANDLE library = 0;


TTS_INITIALIZE          TTS_Initialize;
TTS_TERMINATE           TTS_Terminate;
TTS_FREE                TTS_Free;
TTS_LOADVOICE           TTS_LoadVoice;
TTS_UNLOADVOICE         TTS_UnloadVoice;
TTS_CREATESESSION       TTS_CreateSession;
TTS_RELEASESESSION      TTS_ReleaseSession;
TTS_TEXTTOSPEECH        TTS_TextToSpeech;
TTS_TEXTTOSPEECHSTREAM  TTS_TextToSpeechStream;
TTS_GETAUDIOLENGTH      TTS_GetAudioLength;
TTS_GETAUDIOINFO        TTS_GetAudioInfo;
TTS_COPYAUDIO           TTS_CopyAudio;
TTS_SAVEAUDIO           TTS_SaveAudio;
TTS_GETLASTERROR        TTS_GetLastError;
TTS_GETENGINEINFO       TTS_GetEngineInfo;
TTS_GETSESSIONINFO      TTS_GetSessionInfo;
TTS_SETBOOLEANPARAMETER TTS_SetBooleanParameter;
TTS_GETBOOLEANPARAMETER TTS_GetBooleanParameter;
TTS_SETFLOATPARAMETER   TTS_SetFloatParameter;
TTS_GETFLOATPARAMETER   TTS_GetFloatParameter;
TTS_SETSTRINGPARAMETER  TTS_SetStringParameter;
TTS_GETSTRINGPARAMETER  TTS_GetStringParameter;
TTS_LOADPLUGIN          TTS_LoadPlugin;
TTS_UNLOADPLUGIN        TTS_UnloadPlugin;
TTS_ENUMERATEVOICE      TTS_EnumerateVoices;
TTS_ENUMERATEENCODER    TTS_EnumerateEncoders;
TTS_VALIDATESSML        TTS_ValidateSSML;
TTS_PROCESSMESSAGE      TTS_ProcessMessage;
TTS_REGISTERINTERPRETATION TTS_RegisterInterpretation;
TTS_UNLOADTEMPLATE      TTS_UnloadTemplate;
TTS_LOADTEMPLATE        TTS_LoadTemplate;
TTS_LOADTEMPLATEFROMSTRING TTS_LoadTemplateFromString;


TTS_RETURN tts_loadLibrary(
	const char *path )
{
    const char* funcName = "";
    TTS_RETURN result = 0;

    if (path == NULL) return 1;

    // carrega o plugin
    library = dynlib_load(path);
    if (library == NULL) return 1;

    dynlib_symbol(library, "TTS_Initialize", TTS_Initialize, TTS_INITIALIZE);
    dynlib_symbol(library, "TTS_Terminate", TTS_Terminate, TTS_TERMINATE);
    dynlib_symbol(library, "TTS_Free", TTS_Free, TTS_FREE);
    dynlib_symbol(library, "TTS_LoadVoice", TTS_LoadVoice, TTS_LOADVOICE);
    dynlib_symbol(library, "TTS_UnloadVoice", TTS_UnloadVoice, TTS_UNLOADVOICE);
    dynlib_symbol(library, "TTS_CreateSession", TTS_CreateSession, TTS_CREATESESSION);
    dynlib_symbol(library, "TTS_ReleaseSession", TTS_ReleaseSession, TTS_RELEASESESSION);
    dynlib_symbol(library, "TTS_TextToSpeech", TTS_TextToSpeech, TTS_TEXTTOSPEECH);
    dynlib_symbol(library, "TTS_TextToSpeechStream", TTS_TextToSpeechStream, TTS_TEXTTOSPEECHSTREAM);
    dynlib_symbol(library, "TTS_GetAudioLength", TTS_GetAudioLength, TTS_GETAUDIOLENGTH);
    dynlib_symbol(library, "TTS_GetAudioInfo", TTS_GetAudioInfo, TTS_GETAUDIOINFO);
    dynlib_symbol(library, "TTS_CopyAudio", TTS_CopyAudio, TTS_COPYAUDIO);
    dynlib_symbol(library, "TTS_SaveAudio", TTS_SaveAudio, TTS_SAVEAUDIO);
    dynlib_symbol(library, "TTS_GetLastError", TTS_GetLastError, TTS_GETLASTERROR);
    dynlib_symbol(library, "TTS_GetEngineInfo", TTS_GetEngineInfo, TTS_GETENGINEINFO);
    dynlib_symbol(library, "TTS_GetSessionInfo", TTS_GetSessionInfo, TTS_GETSESSIONINFO);
	dynlib_symbol(library, "TTS_SetBooleanParameter", TTS_SetBooleanParameter, TTS_SETBOOLEANPARAMETER);
    dynlib_symbol(library, "TTS_GetBooleanParameter", TTS_GetBooleanParameter, TTS_GETBOOLEANPARAMETER);
    dynlib_symbol(library, "TTS_SetFloatParameter", TTS_SetFloatParameter, TTS_SETFLOATPARAMETER);
    dynlib_symbol(library, "TTS_GetFloatParameter", TTS_GetFloatParameter, TTS_GETFLOATPARAMETER);
    dynlib_symbol(library, "TTS_SetStringParameter", TTS_SetStringParameter, TTS_SETSTRINGPARAMETER);
    dynlib_symbol(library, "TTS_GetStringParameter", TTS_GetStringParameter, TTS_GETSTRINGPARAMETER);
    dynlib_symbol(library, "TTS_LoadPlugin", TTS_LoadPlugin, TTS_LOADPLUGIN);
    dynlib_symbol(library, "TTS_UnloadPlugin", TTS_UnloadPlugin, TTS_UNLOADPLUGIN);
    dynlib_symbol(library, "TTS_EnumerateVoices", TTS_EnumerateVoices, TTS_ENUMERATEVOICE);
    dynlib_symbol(library, "TTS_ValidateSSML", TTS_ValidateSSML, TTS_VALIDATESSML);
    dynlib_symbol(library, "TTS_ProcessMessage", TTS_ProcessMessage, TTS_PROCESSMESSAGE);
    dynlib_symbol(library, "TTS_RegisterInterpretation", TTS_RegisterInterpretation, TTS_REGISTERINTERPRETATION);
    dynlib_symbol(library, "TTS_UnloadTemplate", TTS_UnloadTemplate, TTS_UNLOADTEMPLATE);
    dynlib_symbol(library, "TTS_LoadTemplate", TTS_LoadTemplate, TTS_LOADTEMPLATE);
    dynlib_symbol(library, "TTS_LoadTemplateFromString", TTS_LoadTemplateFromString, TTS_LOADTEMPLATEFROMSTRING);

ESCAPE:
    if (result != 0)
    {
		std::cerr << "Missing symbol '" << funcName << "'" << std::endl;
        return 1;
	}

    return TTS_OK;
}


TTS_RETURN tts_unloadLibrary( void )
{
    dynlib_unload(library);
    return TTS_OK;
}
