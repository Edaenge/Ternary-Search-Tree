//File C++CLIWrapper.h


#pragma once
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "TSTWrapper.h"
#include <cliext/vector>
using namespace System;
using namespace System::Windows::Interop;
using namespace System::Windows;
using namespace System::Runtime::InteropServices;

namespace System { namespace Windows { namespace Interop
{
    public ref class CppCLI
    {
    protected:
        TSTWrapper* TST_Wrapper;

    public:
        CppCLI(String^ binPath);
        ~CppCLI();

        bool PutWord(String^ word, unsigned int value);
        bool DeleteWord(String^ word);
        bool ContainsWord(String^ word);
        bool IsEmpty();
		bool GenerateDotCode();
		bool GenerateDotCode(String ^key, const unsigned int option);
        array<String^>^ WordsWithPrefix(String^ word);
        array<String^>^ WordsThatMatch(String^ pattern);
        array<String^>^ GetAllWords();
        bool LoadKeysFromFile(String^ path);
        String^ LongestPrefixOf(String^ word);
        void ClearTree();
        unsigned int Size();

    private:
        char* NewChar(String^ txt);
        void FreeChar(char *&lpText);
        array<String^>^ CopyFromVector(const std::vector<std::string> &vec);

    };
}}}
