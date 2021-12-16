/*
 * CPqD Texto Fala 4.8.0
 *
 * Online documentation: https://speechweb.cpqd.com.br/tts/docs/4.8/
 */

#ifndef CPQD_TTS_PUBLIC_TTS_H
#define CPQD_TTS_PUBLIC_TTS_H


#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


#define TTS_MAJOR_VERSION     4
#define TTS_MINOR_VERSION     8
#define TTS_PATCH_VERSION     0
#define TTS_PRODUCT_NAME      "CPqD Texto Fala 4.8.0"


/**
 * @brief Type for session handle.
 */
typedef uint32_t TTS_HANDLE;


#define TTS_MAX_HANDLE  ( (TTS_HANDLE) 0x0000FFFFU )


/**
 * @brief Type for API function return.
 *
 * Valid values are @ref TTS_OK (for success) or an error code.
 */
typedef uint32_t TTS_RETURN;


/**
 * @brief Return value for succeed operations.
 */
#define TTS_OK                          (0x00)



/**
 * @brief Name of the audio encoder in use by session.
 *
 * This parameter expects an @b string value.
 */
#define TTS_PARAM_ENCODER            (0x01)

/**
 * @brief Volume of the shynthesized speech.
 *
 * This parameter should be an @b integer value from @c 0.3 @c to 3. The default value is @c 1.0.
 */
#define TTS_PARAM_VOLUME             (0x04)

/**
 * @brief Rate of the shynthesized speech.
 *
 * This parameter should be an @b integer value from 1 to 100 (linear scale). The default value is 50.
 */
#define TTS_PARAM_RATE               (0x05)

/**
 * @brief Amount of silence at the begin of synthesized speech.
 *
 * This parameter should be a positive @b integer value in milliseconds.
 */
#define TTS_PARAM_BEGIN_SILENCE      (0x07)

/**
 * @brief Amount of silence at the end of synthesized speech.
 *
 * This parameter should be a positive @b integer value in milliseconds.
 */
#define TTS_PARAM_END_SILENCE        (0x08)

/**
 * @brief Name of the default voice.
 *
 * This parameter expects an @b string value. Valid values depends on the loaded voices.
 */
#define TTS_PARAM_VOICE              (0x0B)

/**
 * @brief Pitch of the synthesized speech.
 *
 * This parameter should be an @b integer value from 1 to 100 (linear scale). The default value is 50.
 */
#define TTS_PARAM_PITCH              (0x0C)

/**
 * @brief Define the text is in SSML format.
 *
 * This parameter should be an @b interger value '1' (is true) or '0' (is false). The default value is 0.
 */
#define TTS_PARAM_TEXT_SSML          (0x0D)


/**
 * @brief Define to force break line processing.
 *
 * This parameter should be an @b interger value '1' (is true) or '0' (is false). The default value is 0.
 */
#define TTS_PARAM_TEXT_BREAKLINE     (0x0E)


/**
 * @brief Define the writing of the text sent in the synthesis.
 *
 * This parameter should be an @b interger value '1' (is true) or '0' (is false). The default value is 0.
 */
#define TTS_PARAM_LOG_TEXT           (0x0F)

/**
 * @brief License identifier.
 *
 * This parameter expects an @b string value.
 */
#define TTS_PARAM_LICENSE_ID         (0x10)

/**
 * @brief Instance identifier.
 *
 * This parameter expects an @b string value.
 */
#define TTS_PARAM_LICENSE_TAG        (0x11)


/**
 * @brief Match with any gender. This value can be used while searching for
 * a voice.
 */
#define TTS_VOICE_GENDER_ANY         (0x00)

/**
 * @brief Female voice.
 */
#define TTS_VOICE_GENDER_FEMALE      (0x01)

/**
 * @brief Male voice.
 */
#define TTS_VOICE_GENDER_MALE        (0x02)

/**
 * @brief Neutral voice that is neither male or female (e.g. artificial voice).
 */
#define TTS_VOICE_GENDER_NEUTRAL     (0x03)



/**
 * @brief Match with any age. This value can be used while searching for
 * a voice.
 */
#define TTS_VOICE_AGE_ANY            (0x00)

/**
 * @brief Age roughly up to 12 years.
 */
#define TTS_VOICE_AGE_CHILD          (0x01)

/**
 * @brief Age roughly 13 to 19 years.
 */
#define TTS_VOICE_AGE_TEENAGER       (0x02)

/**
 * @brief Age roughly 20 to 40 years.
 */
#define TTS_VOICE_AGE_YOUNG_ADULT    (0x03)

/**
 * @brief Age roughly 40 to 60 years.
 */
#define TTS_VOICE_AGE_MIDDLE_ADULT   (0x04)

/**
 * @brief Age roughly 60 years and up.
 */
#define TTS_VOICE_AGE_OLDER_ADULT    (0x05)

/**
 * @brief Neutral voice which the age is indeterminate (e.g artificial voice).
 */
#define TTS_VOICE_AGE_NEUTRAL        (0x06)



/**
 * @brief Voice for HMM-based synthesis engine.
 */
#define TTS_VOICE_FLAG_HMM           (0x10)

/**
 * @brief Voice for concatenative synthesis engine through unit selection.
 */
#define TTS_VOICE_FLAG_USL           (0x02)

/**
 * @brief Indicate the presence of voice customizations.
 */
#define TTS_VOICE_FLAG_CUSTOM        (0x04)

/**
 * @brief Indicate whether the voice is completely loaded.
 *
 * If this flag is not present, the
 * voice was loaded with TTS_VOICE_LOAD_LAZY flag and was not used yet.
 */
#define TTS_VOICE_FLAG_LOADED        (0x08)


/**
* @brief Flag que define o arquivo criptografado.
*/
#define TTS_VOICE_FLAG_ENCRYPTED     (0x01)


/**
 * @brief Structure to hold voice meta-information.
 */
typedef struct TTS_VOICE_INFO
{

    /**
     * Unique voice name.
     */
    char Name[64];

    /**
     * Path to the voice file.
     */
    char FileName[256];

    /**
     * Age of the voice. Valid values are defined by @c TTS_VOICE_AGE_ prefixed macros in @ref GRP_VOICE_INFO.
     */
    uint8_t Age;

    /**
     * Gender of the voice. Valid values are defined by @c TTS_VOICE_GENDER_ prefixed macros in @ref GRP_VOICE_INFO.
     */
    uint8_t Gender;

    /**
     * Specifies flags that indicate voice characteristics. Valid flags are defined by
     * @c TTS_VOICE_FLAG_ prefixed macros in @ref GRP_VOICE_INFO.
     */
    uint8_t Flags;
    
    /**
     * Language of the voice.
     */
    char Language[8];

} TTS_VOICE_INFO;


/**
 * @brief Contains information about an audio encoder.
 */
typedef struct TTS_ENCODER_INFO
{

	char Name[64];

    char Codec[16];

	char Description[256];

	uint16_t SampleRate;

    uint8_t BitsPerSample;

    uint8_t Channels;

    uint8_t Flags;

} TTS_ENCODER_INFO;


/**
 * @brief Indicates the audio format implemented by the encoder include a header.
 */
#define TTS_ENCODER_FLAG_HEADER      (0x01)

/**
 * @brief Indicates the audio format implemented by the encoder supports streaming.
 */
#define TTS_ENCODER_FLAG_STREAM      (0x02)


/**
 * @brief Indicates the audio format implemented by the encoder doesnt support the change of bits for sample.
 */
#define TTS_ENCODER_FLAG_NOT_CHANGE_BITS_FOR_SAMPLE   (0x04)


typedef struct TTS_SESSION_INFO
{

    /**
    * @brief Name of the voice in use.
    */
    char *VoiceName;

    /**
    * @brief Amount of speech synthesis performed with the session.
    */
    uint32_t SynthesisCount;

    /**
    * @brief Amount of seconds of speech synthesized with the session.
    */
    uint32_t SynthesisTime;

} TTS_SESSION_INFO;



/**
 * @brief Enable the viseme boundary table.
 */
#define TTS_BIF_VISEME_BOUNDARY         (0x01)

/**
 * @brief Enable the phoneme boundary table.
 */
#define TTS_BIF_PHONEME_BOUNDARY        (0x02)

/**
 * @brief Enable the word boundary table.
 */
#define TTS_BIF_WORD_BOUNDARY           (0x04)

/**
 * @brief Enable the sentence boundary table.
 */
#define TTS_BIF_SENTENCE_BOUNDARY       (0x08)

/**
 * @brief Enable the token boundary table.
 */
#define TTS_BIF_TOKEN_BOUNDARY          (0x10)


/**
 * @ingroup GRP_AUDIO_INFO
 */
typedef struct TTS_BOUNDARY_INFO
{

    /**
     * @brief String representation of the element.
     */
    const char *Text;

    /**
     * @brief Index of the first sample of the element in the audio stream.
     *
     * The initial index in the audio stream is zero.
     */
    uint32_t FirstSample;

    /**
     * @brief Index of the last sample of the element in the audio stream.
     *
     * The initial index in the audio stream is zero.
     */
    uint32_t LastSample;

} TTS_BOUNDARY_INFO;


/**
 * @brief Table mapping elements in the audio stream.
 * @ingroup GRP_AUDIO_INFO
 */
typedef struct TTS_BOUNDARY_TABLE
{

    /**
     * @brief Amount of entries in the table.
     */
    uint16_t Count;

    /**
     * @brief Entries of the table.
     */
    const TTS_BOUNDARY_INFO *Entries;

} TTS_BOUNDARY_TABLE;


/**
 * @ingroup GRP_AUDIO_INFO
 */
typedef struct TTS_AUDIO_INFO
{

    /**
    * @brief Amount of milliseconds of speech synthesized.
    *
    * The audio duration is given by the following equation:
    *
    * Duration = Length / (BitsPerSample / 8 * Channels * (SampleRate / 1000));
    *
    */
    uint32_t Duration;

    /**
     * @brief Amount of bytes occupied by the synthesized speech.
     *
     * This is the same value returned by TTS_GetAudioLength() function.
     *
     * @see TTS_GetAudioLength()
     */
    uint32_t Length;

    uint8_t BitsPerSample;

    uint8_t Channels;

    uint16_t SampleRate;

    /**
     * @brief Table mapping tokens in the audio stream.
     * @see TTS_BIF_TOKEN_BOUNDARY
     */
    const TTS_BOUNDARY_TABLE *TokenBoundary;

    /**
     * @brief Table mapping normalized words in the audio stream.
     * @see TTS_BIF_WORD_BOUNDARY
     */
    const TTS_BOUNDARY_TABLE *WordBoundary;

    /**
     * @brief Table mapping phonemes in the audio stream.
     * @see TTS_BIF_PHONEME_BOUNDARY
     */
    const TTS_BOUNDARY_TABLE *PhonemeBoundary;

} TTS_AUDIO_INFO;


typedef struct TTS_VERSION_INFO
{

    uint8_t Major;

    uint8_t Minor;

    uint8_t Patch;

} TTS_VERSION_INFO;


/**
 * @brief Can provide the token boundary table.
 */
#define TTS_CAP_TOKEN_BOUNDARY          (0x0001)

/**
 * @brief Can provide the word boundary table.
 */
#define TTS_CAP_WORD_BOUNDARY           (0x0002)

/**
 * @brief Can provide the phoneme boundary table.
 */
#define TTS_CAP_PHONEME_BOUNDARY        (0x0004)

/**
 * @brief The function TTS_TextToSpeech() is available.
 */
#define TTS_CAP_SUPPORT_API_TEXTTOSPEECH        (0x0008)

/**
 * @brief The function TTS_TextToSpeechStream() is available.
 */
#define TTS_CAP_SUPPORT_API_TEXTTOSPEECHSTREAM  (0x0010)

/**
 * @brief The function TTS_LoadVoice() is available.
 */
#define TTS_CAP_SUPPORT_API_LOADVOICE           (0x0020)

/**
 * @brief The function TTS_UnloadVoice() is available.
 */
#define TTS_CAP_SUPPORT_API_UNLOADVOICE         (0x0040)

/**
 * @brief The function TTS_GetAudioInfo() is available.
 */
#define TTS_CAP_SUPPORT_API_GETAUDIOINFO        (0x0080)

/**
 * @brief The function TTS_CopyAudio() is available.
 */
#define TTS_CAP_SUPPORT_API_COPYAUDIO           (0x0100)

/**
 * @brief The function TTS_SaveAudio() is available.
 */
#define TTS_CAP_SUPPORT_API_SAVEAUDIO           (0x0200)

/**
 * @brief The function TTS_LoadPlugin() is available.
 */
#define TTS_CAP_SUPPORT_API_LOADPLUGIN          (0x0400)

/**
 * @brief The function TTS_UnloadPlugin() is available.
 */
#define TTS_CAP_SUPPORT_API_UNLOADPLUGIN        (0x0800)

/**
 * @brief The function TTS_RegisterTemplate() is available.
 */
#define TTS_CAP_SUPPORT_API_REGISTERTEMPLATE    (0x1000)

/**
 * @brief The function TTS_LoadTemplate() is available.
 */
#define TTS_CAP_SUPPORT_API_LOADTEMPLATE        (0x2000)

/**
 * @brief The function TTS_UnloadTemplate() is available.
 */
#define TTS_CAP_SUPPORT_API_UNLOADTEMPLATE        (0x4000)

/**
 * @brief The function TTS_RegisterInterpretation() is available.
 */
#define TTS_CAP_SUPPORT_API_REGISTERINTERPRETATION (0x8000)

/**
 * @brief The function TTS_ProcessMessage() is available.
 */
#define TTS_CAP_SUPPORT_API_PROCESSMESSAGE      (0x1010)

/**
 * @brief The function TTS_ValidateSSML() is available.
 */
#define TTS_CAP_SUPPORT_API_VALIDATESSML        (0x1020)



#define TTS_STATE_ONLINE                (0x01)

#define TTS_STATE_OFFLINE               (0x02)

#define TTS_STATE_BLOCKED               (0x03)

#define TTS_STATE_UNKNOWN               (0xFF)



//template message

/**
 * @brief Check if there are all templates of the message.
 */
#define TEMPLATE_MESSAGE_CHECK_ALL   (0x01)

/**
 * @brief Doesn't check for message templates.
 */
#define TEMPLATE_MESSAGE_DONT_CHECK  (0x02)

/**
 * @brief Check if there is only one template in the message.
 */
#define TEMPLATE_MESSAGE_FOUND_ONE   (0x03)


/**
 * @ingroup GRP_ENGINE_INFO
 */
typedef struct TTS_ENGINE_INFO
{

    /**
     * @brief Version number.
     */
    TTS_VERSION_INFO Version;

    /**
     * @brief Maximum number of synthesis sessions that could exists simultaneously.
     */
    uint8_t MaxSessionsOld;

    /**
     * @brief Name of the customer for which the TTS engine was built.
     */
    char *CustomerName;

    /**
     * @brief Flags that indicates the capabilities of the TTS engine.
     *
     * Valid flags are defined by @c TTS_CAP_ prefixed macros. Check the page @ref GRP_ENGINE_INFO
     * for detailed information.
     */
    uint32_t Capabilities;

	/**
     * @brief Maximum number of synthesis sessions that could exists simultaneously.
     */
    uint32_t MaxSessions;

	/**
     * @brief Maximum number of synthesis sessions that currently exists.
     */
    uint32_t CurrentSessions;

    /**
     * @brief State in which the TTS engine is operating.
     */
    uint32_t OperationState;

    /**
     * @brief Remaining time until the product is blocked.
     *
     * Time in milliseconds if in ONLINE or OFFLINE state; zero if in BLOCKED state.
     * In ONLINE state the time never decrease.
     */
    uint32_t RemainingTime;

    /**
     * @brief Number of communication errors.
     */
    uint32_t CommunicationErrors;

    /**
    * @brief Amount of speech synthesis performed.
    */
    uint64_t SynthesisCount;

    /**
    * @brief Amount of milliseconds of speech synthesized.
    */
    uint64_t SynthesisTime;

    /**
     * @brief URI to the current license server.
     */
    char *LicenseServerURI;

} TTS_ENGINE_INFO;


/**
 * @ingroup GRP_ERROR
 */
typedef struct TTS_ERROR_INFO
{

    /**
     * @brief Error code as returned by the failed function.
     */
    TTS_RETURN Code;

    /**
     * @brief Secondary error code that provides additional information.
     */
    TTS_RETURN SubCode;

    /**
     * @brief Custom error message.
     */
    char *Message;

    /**
     * @brief Name of the source file which the error occurred.
     */
    char *FileName;

    /**
     * @brief Number of the line in the source file which the error occurred.
     */
    uint32_t Line;

} TTS_ERROR_INFO;


/**
 * @brief Structure used to store a linear PCM audio stream.
 * @ingroup PLUGIN_TYPES
 */
typedef struct TTS_AUDIO_BUFFER
{

    int8_t* Content;

    /**
     * @brief Amount of bytes used in the audio buffer.
     */
    uint32_t Length;

    /**
     * @brief Amount of bytes allocated for the audio buffer.
     */
    uint32_t Allocated;

    uint8_t BitsPerSample;

    uint8_t Channels;

    uint16_t SampleRate;

} TTS_AUDIO_BUFFER;


/**
 * @brief Indicates the first audio block from a stream.
 */
#define TTS_ORDER_FIRST          (0x01)

/**
 * @brief Indicates an intermediate audio block from a stream.
 */
#define TTS_ORDER_INTERMEDIATE   (0x02)

/**
 * @brief Indicates the last audio block from a stream.
 */
#define TTS_ORDER_LAST           (0x03)


/**
 * @brief Structure containing information about the generated audio using asynchronous text-to-speech.
 *
 * @ingroup PLUGIN_TYPES
 * @see TTSP_SYNTH_CALLBACK
 */
typedef struct TTS_STREAM_EVENT
{

    /**
     * @brief Current result of the text-to-speech conversion.
     *
     * @ref TTS_OK if the text-to-speech conversion is complete or an @ref GRP_ERRORS "error code"
     * otherwise.
     */
    TTS_RETURN Result;

    /**
     * @brief Order of the current event.
     *
     * This value should be @ref TTS_ORDER_FIRST, @ref TTS_ORDER_INTERMEDIATE or
     * @ref TTS_ORDER_LAST.
     */
    uint32_t Order;

    /**
     * @brief Pointer to the generated audio stream.
     *
     * In case of error, this pointer will be NULL.
     */
    TTS_AUDIO_BUFFER *Audio;

} TTS_STREAM_EVENT;



/**
 * @brief Prototype for the application callback function called during the text-to-speech convertion.
 *
 * This callback is called every time the TTS has audio to delivery to the application.
 *
 * @param [in] handle Synthesis session handle.
 * @param [out] event Pointer to the structure containing the event information.
 * @param [in,out] data Pointer to an application-specific data.
 * @return Non-zero value to indicate that the session should convert the next remaining sentence to
 *     speech or zero otherwise.
 * @remarks The callback is not called again if the 'Result' field in the event structure of current
 *     call is an error code. In case of success, if the callback returns a non-zero value and there is
 *     no remaining audio to delivery, the callback will be called again with the @ref TTSERR_NO_AUDIO error
 *     code in 'Result' field of the event structure.
 * @ingroup GRP_API
 */
typedef uint8_t TTS_STREAM_CALLBACK( TTS_HANDLE handle, const TTS_STREAM_EVENT *event, void* data );


typedef struct TTS_PLUGIN_INFO
{

    /**
     * @brief Logical name of the plugin.
     *
     * This name is defined by the user when loading the plugin.
     */
    const char *Name;

    /**
     * @brief Path to the shared library which implements the plugin.
     */
    const char *FileName;

    /**
     * @brief Description of the plugin functionality.
     */
    const char *Description;

    /**
     * @brief Name of the plugin developer/publisher.
     */
    const char *Vendor;

    /**
     * @brief Plugin type.
     *
     * Valid values are @c TTS_PLUGIN_ prefixed macros.
     */
    uint8_t Type;

    /**
     * @brief Version number.
     */
    TTS_VERSION_INFO Version;

} TTS_PLUGIN_INFO;


typedef bool TTS_INTERPRET_OUTPUT_CALLBACK(
	void* context,
	const char *text );


typedef void TTS_INTERPRET_CALLBACK(
		void* context,
		const char *input,
		TTS_INTERPRET_OUTPUT_CALLBACK *callback,
		void *data );


#ifdef TTS_LOADABLE_LIBRARY

typedef TTS_RETURN (* TTS_INITIALIZE)( const char *productPath, const char *logPath );
typedef TTS_RETURN (* TTS_TERMINATE)();
typedef TTS_RETURN (* TTS_FREE)(const void *ptr);
typedef TTS_RETURN (* TTS_LOADVOICE)(const char *fileName, uint32_t flags);
typedef TTS_RETURN (* TTS_UNLOADVOICE)(const char *voiceName);
typedef TTS_RETURN (* TTS_CREATESESSION)(const char *voiceName, TTS_HANDLE *handle);
typedef TTS_RETURN (* TTS_RELEASESESSION)(TTS_HANDLE handle);
typedef TTS_RETURN (* TTS_TEXTTOSPEECH)(TTS_HANDLE handle, const char *text);
typedef TTS_RETURN (* TTS_TEXTTOSPEECHSTREAM)(TTS_HANDLE handle, const char *text, TTS_STREAM_CALLBACK *callback, void *data);
typedef TTS_RETURN (* TTS_GETAUDIOLENGTH)(TTS_HANDLE handle, uint32_t *length);
typedef TTS_RETURN (* TTS_GETAUDIOINFO)(TTS_HANDLE handle, uint32_t flags, const TTS_AUDIO_INFO **info);
typedef TTS_RETURN (* TTS_COPYAUDIO)(TTS_HANDLE handle, uint32_t offset, uint32_t length, uint8_t *buffer, uint32_t *copied);
typedef TTS_RETURN (* TTS_SAVEAUDIO)(TTS_HANDLE handle, const char *fileName);
typedef TTS_RETURN (* TTS_GETLASTERROR)(const struct TTS_ERROR_INFO **info);
typedef TTS_RETURN (* TTS_GETENGINEINFO)(const struct TTS_ENGINE_INFO **info);
typedef TTS_RETURN (* TTS_GETSESSIONINFO)(TTS_HANDLE handle, const struct TTS_SESSION_INFO **info);
typedef TTS_RETURN (* TTS_SETBOOLEANPARAMETER)(TTS_HANDLE handle, uint8_t pid, bool value);
typedef TTS_RETURN (* TTS_GETBOOLEANPARAMETER)(TTS_HANDLE handle, uint8_t pid, bool *value);
typedef TTS_RETURN (* TTS_SETFLOATPARAMETER)(TTS_HANDLE handle, uint8_t pid, float value);
typedef TTS_RETURN (* TTS_GETFLOATPARAMETER)(TTS_HANDLE handle, uint8_t pid, float *value);
typedef TTS_RETURN (* TTS_SETSTRINGPARAMETER)(TTS_HANDLE handle, uint8_t pid, const char* value);
typedef TTS_RETURN (* TTS_GETSTRINGPARAMETER)(TTS_HANDLE handle, uint8_t pid, char *value, uint32_t length);
typedef TTS_RETURN (*TTS_GETSTRINGPARAMETERLENGTH)(TTS_HANDLE handle, uint8_t pid, uint32_t *length);
typedef TTS_RETURN (* TTS_LOADPLUGIN)(const char *pluginName);
typedef TTS_RETURN (* TTS_UNLOADPLUGIN)(const char *pluginName);
typedef TTS_RETURN (* TTS_ENUMERATEVOICE)(const struct TTS_VOICE_INFO **voices, size_t *count);
typedef TTS_RETURN (* TTS_ENUMERATEENCODER)(const struct TTS_ENCODER_INFO **encoders, size_t *count);
typedef TTS_RETURN(*TTS_LOADTEMPLATEFROMSTRING) (const char* name, const char* content);
typedef TTS_RETURN(*TTS_LOADTEMPLATE) (const char* fileName);
typedef TTS_RETURN(*TTS_UNLOADTEMPLATE) (const char* fileName);
typedef TTS_RETURN(*TTS_REGISTERINTERPRETATION)(const char* name, TTS_INTERPRET_CALLBACK* callback, void* data, bool isNormalized);
typedef TTS_RETURN(*TTS_PROCESSMESSAGE) (const char* message, int8_t flags, char** output);
typedef TTS_RETURN(*TTS_VALIDATESSML) (const char* ssml);

#else

#if BUILDING_LIBCPQDTTS && defined(_MSC_VER)
#define LIBCPQDTTS_EXPORTED __declspec(dllexport)
#elif BUILDING_LIBCPQDTTS
#define LIBCPQDTTS_EXPORTED __attribute__((__visibility__("default")))
#elif defined(_MSC_VER)
#define LIBCPQDTTS_EXPORTED __declspec(dllimport)
#else
#define LIBCPQDTTS_EXPORTED
#endif


#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief Initializes the TTS framework.
 *
 * All voices and plugins specified in the configuration file will be loaded automaticaly.
 *
 * @param [in] productPath Path to the instalation directory. The configuration file @c tts.conf
 *    must be in this place.
 * @param [in] logPath Path to the directory where the log files will be written. If NULL,
 *    the product path will be used.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_Initialize(
    const char *productPath,
    const char *logPath );


/**
 * @brief Terminates the TTS framework and release the allocated resources.
 *
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_Terminate();


/**
 * @brief Deallocates a memory block previously allocated by the framework.
 *
 * @param [in] ptr Pointer to the memory block.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_Free(
    const void *ptr );


/**
 * @brief Loads a voice from file.
 *
 * The name of the loaded voice will be the file name without extension.
 *
 * @param [in] fileName Path to the voice file.
 * @param [in] flags Specifies flags that controls the voice loading. Valid flags are
 *     defined by @c TTS_VOICE_LOAD_ prefixed macros.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_LoadVoice(
    const char *fileName,
    uint32_t flags );


/**
 * @brief Unloads a voice.
 *
 * @param [in] name Name of the voice.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_UnloadVoice(
    const char *name );


/**
 * @brief Creates a TTS session.
 *
 * A session allows the program to perform text-to-speech conversions.
 * When creating a session, you must specify an default voice to be used
 * if no voice is specified in the SSML.
 *
 * Usually, each session is used by only one thread at time.
 *
 * @param [in] voiceName Name of the voice. If NULL, the default voice wil be used. The default
 *     voice is specified in the configuration file.
 * @param [out] handle Pointer to the variable that will store the handle for the new session.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_CreateSession(
    const char *voiceName,
    TTS_HANDLE *handle );


/**
 * @brief Releases a TTS session and its associated resources.
 *
 * @param [in] handle Session handle.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_ReleaseSession(
    TTS_HANDLE handle );


/**
 * @brief Converts the given text into speech.
 *
 * @param [in] handle Session handle.
 * @param [in] text Text to be synthesized. The text can be given as plain text or SSML 1.1 (if enabled).
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_TextToSpeech(
    TTS_HANDLE handle,
    const char *text );


/**
 * @brief Converts the given text into speech and delivery the generated audio via a callback.
 *
 * @param [in] handle Session handle.
 * @param [in] text Text to be synthesized. The text can be given as plain text or SSML 1.1 (if enabled).
 * @param [in] callback Pointer to the application callback function to be called during the
 *     convertion. The callback function must follow the prototype specified by
 *     @ref TTS_STREAM_CALLBACK .
 * @param [in] data Pointer to an application-specific data to be passed to the callback.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_TextToSpeechStream(
    TTS_HANDLE handle,
    const char *text,
    TTS_STREAM_CALLBACK *callback,
    void *data );


/**
 * @brief Returns the number of bytes which a buffer must have to copy the entire
 * synthesized speech in a call for @c TTS_CopyAudio.
 *
 * @param [in] handle Session handle.
 * @param [out] length Pointer to the integer variable which the number of bytes will be stored.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @see TTS_GetAudioInfo()
 * @see TTS_CopyAudio()
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetAudioLength(
    TTS_HANDLE handle,
    uint32_t *length );


/**
 * @brief Returns detailed information about the synthesized speech.
 *
 * This function allocates memory for the audio information that must
 * be deallocated calling TTS_Free().
 *
 * For additional details about this function, check the @ref GRP_AUDIO_INFO page.
 *
 * @param [in] handle Session handle.
 * @param [in] flags Specifies flags that controls the amount of information returned. Valid flags are
 *     defined by @c TTS_BIF_ prefixed macros.
 * @param [out] info Pointer to a TTS_AUDIO_INFO* variable. This variable will contain the
 *     reference for the TTS_AUDIO_INFO object created by this function.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @see TTS_CopyAudio()
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetAudioInfo(
    TTS_HANDLE handle,
    uint32_t flags,
    const TTS_AUDIO_INFO **info );


/**
 * @brief Copies the synthesized speech from the internal session buffer to the given application
 * buffer.
 *
 * @param [in] handle Session handle.
 * @param [in] offset Number of bytes to be offset from the beginning of the internal
 *     session buffer. The copy will start from this point.
 * @param [in] length Number of bytes to copy from the internal session buffer. The application
 *     buffer should have at least this number of bytes available.
 * @param [out] buffer Pointer to application buffer.
 * @param [out] Pointer to a integer variable to store the number of bytes copied.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @remarks The amount of copied bytes could be lesser than the value specified in @c length if
 *     the internal buffer has no more data to copy.
 * @see TTS_GetAudioLength()
 * @see TTS_GetAudioInfo()
 * @see TTS_SaveAudio()
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_CopyAudio(
    TTS_HANDLE handle,
    uint32_t offset,
    uint32_t length,
    uint8_t *buffer,
    uint32_t *copied );

/**
 * @brief Saves the synthesized speech to a file.
 *
 * @param [in] handle Session handle.
 * @param [in] fileName Path to the output file.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @see TTS_CopyAudio()
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_SaveAudio(
    TTS_HANDLE handle,
    const char *fileName );


/**
 * @brief Returns a TTS_ERROR_INFO object with details about the last error occurred
 * by calling a TTS function on the current thread.
 *
 * This function allocates memory for the error information that must
 * be deallocated calling @ref TTS_Free().
 *
 * @param [out] info Pointer to a TTS_ERROR_INFO* object. This object will store the
 *     reference for the TTS_ERROR_INFO object created by this function.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetLastError(
    const struct TTS_ERROR_INFO **info);


/**
 * @brief Returns a TTS_ENGINE_INFO object containing details about the TTS engine.
 *
 * This function allocate memory for the TTS engine information that must
 * be deallocated calling TTS_Free().
 *
 * @param [out] info Pointer to a TTS_ENGINE_INFO* variable. This variable will hold the
 *     reference for the TTS_ENGINE_INFO object created by this function.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetEngineInfo(
    const struct TTS_ENGINE_INFO **info );


/**
 * Unused function.
 *
 * This declaration is here for compatibility with 4.0.x applications.
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetVoiceInfo(
    const char *voiceName,
    const struct TTS_VOICE_INFO **info );


/**
 * Unused function.
 *
 * This declaration is here for compatibility with 4.0.x applications.
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetPluginInfo(
   const char *name,
   const TTS_PLUGIN_INFO **info );


/**
 * @brief Returns detailed information about a TTS session.
 *
 * This function allocate memory for the session information that must
 * be deallocated calling TTS_Free().
 *
 * @param [in] handle Session handle.
 * @param [out] info Pointer to a TTS_SESSION_INFO* variable. This variable will hold the
 *     reference for the TTS_SESSION_INFO object created by this function.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetSessionInfo(
    TTS_HANDLE handle,
    const struct TTS_SESSION_INFO **info );


/**
 * @fn TTS_RETURN TTS_SetBooleanParameter( TTS_HANDLE handle, uint8_t pid, bool value )
 * @brief Set the value for a boolean parameter of a TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the table in TTS Parameters for a
 *     list of valid parameter identifiers.
 * @param [in] value New value for the parameter.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_SetBooleanParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    bool value);


/**
 * @brief Get the value of an integer parameter of the TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the page @ref GRP_TTS_PARAMS for a
 *     list of valid parameter identifiers.
 * @param [out] value Pointer that receives the current value of the parameter.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetBooleanParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    bool *value);


/**
 * @fn TTS_RETURN TTS_SetFloatParameter( TTS_HANDLE handle, uint8_t pid, float value )
 * @brief Set the value for a float parameter of a TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the table in TTS Parameters for a
 *     list of valid parameter identifiers.
 * @param [in] value New value for the parameter.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_SetFloatParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    float value);


/**
 * @brief Get the value of an integer parameter of the TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the page @ref GRP_TTS_PARAMS for a
 *     list of valid parameter identifiers.
 * @param [out] value Pointer that receives the current value of the parameter.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetFloatParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    float *value);


/**
 * @brief Set the value for an string parameter of a TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the table in TTS Parameters for a
 *     list of valid parameter identifiers.
 * @param [in] value New value for the parameter.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_SetStringParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    const char* value );


/**
 * @brief Get the value of an string parameter of the TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the table in TTS Parameters for a
 *     list of valid parameter identifiers.
 * @param [out] value Pointer that receives the current value of the parameter.
 * @param [in] length Length of the memory region of 'value'.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @see TTS_GetStringParameterLength
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetStringParameter(
    TTS_HANDLE handle,
    uint8_t pid,
    char *value,
    uint32_t length );


/**
 * @brief Get the length of a string parameter of the TTS session.
 *
 * @param [in] handle Session handle.
 * @param [in] pid Unique identifier of the parameter. Check the table in TTS Parameters for a
 *     list of valid parameter identifiers.
 * @param [out] length Pointer to an integral variable which will receive the length of
 *     the parameter value.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_GetStringParameterLength(
    TTS_HANDLE handle,
    uint8_t pid,
    uint32_t *length );


/**
 * @brief Dynamically loads the plugin in the given shared library.
 *
 * @param [in] pluginName Name to be assigned to the plugin.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_LoadPlugin(
    const char *pluginName );


/**
 * @brief Unload a previously loaded plugin.
 *
 * Built-in plugins can not be unloaded.
 *
 * @param [in] pluginName Name of the plugin.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 * @ingroup GRP_API
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_UnloadPlugin(
    const char *pluginName );


/**
 * @ingroup GRP_API
 * @brief Returns a list of TTS_VOICE_INFO objects with details about each loaded voice.
 *
 * This function allocate memory for the voices information that should
 * be deallocated calling TTS_Free().
 *
 * @param [out] info Pointer to a @ref TTS_VOICE_INFO array.
 * @param [out] count Pointer to an @c uint16_t that receives the amount of matching voices.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_EnumerateVoices(
    struct TTS_VOICE_INFO **voices,
    size_t *count );


/**
 * @ingroup GRP_API
 * @brief Returns a list of TTS_ENCODER_INFO objects with details about each supported encoder.
 *
 * This function allocate memory for the voices information that should
 * be deallocated calling TTS_Free().
 *
 * @param [out] info Pointer to a @ref TTS_ENCODER_INFO array.
 * @param [out] count Pointer to an @c uint16_t that receives the amount of matching voices.
 * @return @ref TTS_OK or an @ref GRP_ERRORS "error code" otherwise.
 */
LIBCPQDTTS_EXPORTED TTS_RETURN TTS_EnumerateEncoders(
    struct TTS_ENCODER_INFO **encoders,
    size_t *encoderCount );


LIBCPQDTTS_EXPORTED TTS_RETURN TTS_LoadTemplateFromString(
    const char *name,
    const char *content );


LIBCPQDTTS_EXPORTED TTS_RETURN TTS_LoadTemplate(
    const char *fileName );

LIBCPQDTTS_EXPORTED TTS_RETURN TTS_UnloadTemplate(
    const char *fileName );


LIBCPQDTTS_EXPORTED TTS_RETURN TTS_RegisterInterpretation(
    const char *name,    // valor do 'interpret-as'
    TTS_INTERPRET_CALLBACK *callback,
    void *data,
    bool isNormalized  );


LIBCPQDTTS_EXPORTED TTS_RETURN TTS_ProcessMessage(
    const char *message,
    int8_t flags,
    char **output );


LIBCPQDTTS_EXPORTED TTS_RETURN TTS_ValidateSSML(
    const char *ssml );



#ifdef __cplusplus
}
#endif


#undef LIBCPQDTTS_EXPORTED

#endif // TTS_LOADABLE_LIBRARY


#define TTSERR_NONE                     (0x0000)
#define TTSERR_OUT_OF_MEMORY            (0x0001)
#define TTSERR_INVALID_ARGUMENT         (0x0002)
#define TTSERR_NOT_FOUND                (0x0003)
#define TTSERR_IO_OPEN                  (0x0004)
#define TTSERR_IO_WRITE                 (0x0005)
#define TTSERR_IO_READ                  (0x0006)
#define TTSERR_INVALID_DATA             (0x0007)
#define TTSERR_OUT_OF_BOUNDS            (0x0008)
#define TTSERR_LOCK_ERROR               (0x0009)
#define TTSERR_INVALID_SYNTAX           (0x000A)
#define TTSERR_NOT_SUPPORTED            (0x000B)
#define TTSERR_SOCKET                   (0x000C)
#define TTSERR_SYSTEM_ERROR             (0x000D)
#define TTSERR_ACCESS_DENIED            (0x000E)
#define TTSERR_UNHANDLED_EXCEPTION      (0x000F)
#define TTSERR_JAVA                     (0x0010)
#define TTSERR_THREAD                   (0x0011)
#define TTSERR_NOT_INITIALIZED          (0x0012)

#define TTSERR_INVALID_HANDLE           (0x0100)
#define TTSERR_INVALID_PLUGIN           (0x0101)
#define TTSERR_INVALID_VOICE            (0x0103)
#define TTSERR_NO_AUDIO                 (0x0106)
#define TTSERR_MALFORMED_SSML           (0x0108)
#define TTSERR_EMPTY_PREPROC            (0x0109)
#define TTSERR_ALREADY_RUNNING          (0x010A)
#define TTSERR_HARDKEY_EXCEPTION        (0x010B)
#define TTSERR_SYNTHESIS                (0x010C)
#define TTSERR_ALREADY_INITIALIZED      (0x010D)
#define TTSERR_MALFORMED_TEMPLATE_SSML  (0x010E)
#define TTSERR_MALFORMED_MESSAGE        (0x010F)


#define TTSERR_FATAL_ERROR              (0x01F1) // TODO: remove this


#endif // CPQD_TTS_PUBLIC_TTS_H
