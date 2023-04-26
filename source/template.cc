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


static void main_printError(
	const char *function )
{
	const TTS_ERROR_INFO *info = NULL;
	const char *message = "(null)";
	TTS_RETURN code = 0;
	int subCode = 0;

	TTS_RETURN result = TTS_GetLastError(&info);
	if (result == TTS_OK && info->Message != NULL)
	{
		message = info->Message;
		code = info->Code;
		subCode = info->SubCode;
	}

	std::cerr << "Error at " << function << ": " << message << " (0x"
		<< std::hex << std::setw(4) << std::setfill('0')
		<< code << ":0x"
		<< std::hex << std::setw(4) << std::setfill('0')
		<< subCode << ')' << std::endl;

	if (info != NULL) TTS_Free(info);
}


static void main_usage()
{
    std::cerr << "Usage: tool_template <TTS path> <template> <message>" << std::endl;
    std::cerr << std::endl;
    std::cerr << "   <TTS path>      Path to the TTS installation directory."  << std::endl;
    std::cerr << "   <template>      Path to a file containing template text." << std::endl;
    std::cerr << "   <message>       Path to a file containing message text."  << std::endl;
    exit(EXIT_FAILURE);
}



string main_loadInputFile(
	const std::string &fileName)
{
	string text;
	ifstream input(fileName.c_str());
	if (!input.good())
	{
		std::cout << "No '" << fileName << "' present." << std::endl;
		return "";
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


static void userCallback( void* context, const char *input, TTS_INTERPRET_OUTPUT_CALLBACK *output, void *data )
{
	(void) data;
	string out = input;
	out += " esse texto";
    output(context, out.c_str());
}


int main( int argc, char **argv )
{
    TTS_RETURN result;
	char *output = NULL;

	if (argc < 4)
		main_usage();

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
		std::cerr << "Unable to load library '" << libraryFile << "'" << std::endl;
        return 1;
    }

    // initialize the TTS
    result = TTS_Initialize(productPath.c_str(), productPath.c_str());
	if (result != TTS_OK)
	{
		main_printError("TTS_Initialize");
		exit(EXIT_FAILURE);
	}

	//register user callback
	result = TTS_RegisterInterpretation("teste", userCallback, NULL, true);
	if (result != TTS_OK)
	{
		main_printError("TTS_RegisterInterpretation");
		exit(EXIT_FAILURE);
	}

	//load template
	result = TTS_LoadTemplate(argv[2]);
	if (result != TTS_OK)
	{
		main_printError("TTS_LoadTemplate");
		exit(EXIT_FAILURE);
	}

	//load message
	string message = main_loadInputFile(argv[3]);
	result = TTS_ProcessMessage(message.c_str(), TEMPLATE_MESSAGE_DONT_CHECK, &output);
	if (result != TTS_OK)
	{
		main_printError("TTS_ProcessMessage");
		exit(EXIT_FAILURE);
	}

	stringstream fileName;
	fileName << "output.txt";
	std::ofstream outputFile(fileName.str().c_str());
	if (outputFile.is_open())
	{
		outputFile << output;
		outputFile.close();
	}
	else
	{
		main_printError("Error save output file");
		exit(EXIT_FAILURE);
	}

	result = TTS_ValidateSSML(output);
	if (result != TTS_OK)
	{
		main_printError("TTS_ValidateSSML");
		exit(EXIT_FAILURE);
	}

	result = TTS_UnloadTemplate(argv[2]);
	if (result != TTS_OK)
	{
		main_printError("TTS_UnloadTemplate");
		exit(EXIT_FAILURE);
	}

	result = TTS_Free(output);
	if (result != TTS_OK)
	{
		main_printError("TTS_Free");
		exit(EXIT_FAILURE);
	}

	result = TTS_Terminate();
	if (result != TTS_OK)
	{
		main_printError("TTS_Terminate");
		exit(EXIT_FAILURE);
	}

	tts_unloadLibrary();

	return 0;
}
