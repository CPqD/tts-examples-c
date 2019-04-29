#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "loader.hh"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <sstream>


#if defined(WIN32) || defined(WIN64)
#include <fcntl.h>
#include <io.h>
char DIRECTORY_SEPARATOR = '\\';
#else
char DIRECTORY_SEPARATOR = '/';
#endif

using namespace std;

static FILE *outputFile = NULL;


static void main_usage()
{
	std::cerr << "Usage: exemplo_tts <product path>" << std::endl << std::endl;
	exit(EXIT_FAILURE);
}


/**
 * @brief Open the input file and read it content.
 */
static std::string main_loadInputFile(
	const std::string &fileName )
{
	string text;
	ifstream input(fileName.c_str());
	if (!input.good())
	{
		std::cerr << "Error opening input file '" << fileName << "'. Using default text." << std::endl;
		text = "meu teste";
	}
	else
	{
		string line;
		while (getline(input, line))
		{
			text += line;
			text += "\n";
		}
		input.close();
	}

	return text;
}


static void main_printError(
	const char *function )
{
	const TTS_ERROR_INFO *info = NULL;
	const char *message = "(null)";
	int code = 0;
	int subCode = 0;

	TTS_RETURN result = TTS_GetLastError(&info);
	if (result == TTS_OK && info->Message != NULL)
	{
		message = info->Message;
		code    = info->Code;
		subCode = info->SubCode;
	}

	std::cerr << "Error at " << function << ": " << message << " (0x"
		<< std::hex << std::setw(4) << std::setfill('0')
		<< code << ":0x"
		<< std::hex << std::setw(4) << std::setfill('0')
		<< subCode << ')' << std::endl;

	if (info != NULL) TTS_Free(info);

	exit(1);
}


static uint8_t main_audioCallback(
	TTS_HANDLE handle,
	const TTS_STREAM_EVENT *event,
	void *data)
{
	(void) handle;
	(void) data;

	if (event->Audio != NULL)
	{
		fwrite(event->Audio->Content, 1, event->Audio->Length, outputFile);
	}

	return 1;
}


int main( int argc, char **argv )
{
	TTS_HANDLE handle;
	TTS_RETURN result;
	std::list<string> lines;

	if (argc != 2)
	{
		main_usage();
	}

	// very simple way to generate the CPqD Texto Fala library file name
	string productPath(argv[1]);
	#if defined(WIN32) || defined(WIN64)
		string libraryFile = productPath + DIRECTORY_SEPARATOR + "libcpqdtts.dll";
	#else
		string libraryFile = productPath + DIRECTORY_SEPARATOR + "libcpqdtts.so";
	#endif

	result = tts_loadLibrary(libraryFile.c_str());
	if (result != TTS_OK)
	{
		std::cerr << "Can not load library '" << libraryFile << "'" << std::endl;
		return 1;
	}

	// initialize the TTS
	result = TTS_Initialize(productPath.c_str(), productPath.c_str());
	if (result != TTS_OK)
	{
		main_printError("TTS_Initialize");
		exit(EXIT_FAILURE);
	}

	// create a synthesis session using the default voice (from the configuration file)
	result = TTS_CreateSession(NULL, &handle);
	if (result != TTS_OK)
	{
		main_printError("TTS_CreateSession");
		exit(EXIT_FAILURE);
	}

	//read input file
	string inputFile = productPath + DIRECTORY_SEPARATOR + "example.txt";
	string text = main_loadInputFile(inputFile);

	//output streaming file
	string outputFileName = productPath + DIRECTORY_SEPARATOR + "example.wav";
	outputFile = fopen(outputFileName.c_str(), "wb");

	// perform the text to speech streaming convertion
	result = TTS_TextToSpeechStream(handle, text.c_str(), main_audioCallback, NULL);
	if (result != TTS_OK)
	{
		main_printError("TTS_TextToSpeechStream");
		exit(EXIT_FAILURE);
	}

	fclose(outputFile);

	result = TTS_ReleaseSession(handle);
	if (result != TTS_OK)
	{
		main_printError("TTS_ReleaseSession");
		exit(EXIT_FAILURE);
	}

	result = TTS_Terminate();
	if (result != TTS_OK)
	{
		main_printError("TTS_ReleaseSession");
		exit(EXIT_FAILURE);
	}

	tts_unloadLibrary();

	return 0;
}
