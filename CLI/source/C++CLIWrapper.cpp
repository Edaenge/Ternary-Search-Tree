//File: C++CLIWrapper.cpp

#include "C++CLIWrapper.h"

namespace System { namespace Windows { namespace Interop
{
    CppCLI::CppCLI(String^ binPath)
    {
		char * lpText = NewChar(binPath);
        TST_Wrapper = new TSTWrapper(lpText);
		FreeChar(lpText);
    }

    CppCLI::~CppCLI()
    {
        delete TST_Wrapper;
    }

    bool CppCLI::PutWord(String^ word, unsigned int value)
    {
        bool ret;
        char * lpText = NewChar(word);
        
        ret = TST_Wrapper->Put(lpText, value);

        FreeChar(lpText);
        return ret;
    }

    bool CppCLI::DeleteWord(String^ word)
    {
        bool ret;
        char * lpText = NewChar(word);

        ret = TST_Wrapper->Delete(lpText);

        FreeChar(lpText);
        return ret;
    }

    bool CppCLI::ContainsWord(String^ word)
    {
        bool ret;
        char * lpText = NewChar(word);

        ret = TST_Wrapper->Contains(lpText);

        FreeChar(lpText);
        return ret;
    }

    bool CppCLI::IsEmpty()
    {
        return TST_Wrapper->IsEmpty();
    }

    array<String^>^ CppCLI::WordsWithPrefix(String^ word)
    {
        char *lpText = NewChar(word);

        std::vector<std::string> ret = TST_Wrapper->KeysWithPrefix(lpText);

        FreeChar(lpText);
        return CopyFromVector(ret);
    }

    array<String^>^ CppCLI::WordsThatMatch(String^ pattern)
    {
        char *lpText = NewChar(pattern);

        std::vector<std::string> ret = TST_Wrapper->KeysThatMatch(lpText);

        FreeChar(lpText);
        return CopyFromVector(ret);
    }

    array<String^>^ CppCLI::GetAllWords()
    {
        std::vector<std::string> ret = TST_Wrapper->GetAllKeys();
        return CopyFromVector(ret);
    }

    bool CppCLI::LoadKeysFromFile(String^ path)
    {
        char *lpText = NewChar(path);

        bool ret = TST_Wrapper->LoadKeysFromFile(lpText);

        FreeChar(lpText);
        return ret;
    }

	bool CppCLI::GenerateDotCode()
	{
		return TST_Wrapper->GenerateDotCode();
	}

	bool CppCLI::GenerateDotCode(String ^key, const unsigned int option)
	{
		char *lpText = NewChar(key);
		bool ret = TST_Wrapper->GenerateDotCode(lpText, option);
		FreeChar(lpText);
		return ret;
	}

    String^ CppCLI::LongestPrefixOf(String^ word)
    {
        char *lpText = NewChar(word);
        
        std::string ret = TST_Wrapper->LongestPrefixOf(lpText);

        return gcnew String(ret.c_str());
    }

    void CppCLI::ClearTree()
    {
        TST_Wrapper->ClearTree();
    }

    unsigned int CppCLI::Size()
    {
        return TST_Wrapper->Size();
    }

    char* CppCLI::NewChar(String^ txt)
    {
        char *lpText = (char*)Marshal::StringToHGlobalAnsi(txt).ToPointer();
        return lpText;
    }

    void CppCLI::FreeChar(char *&lpText)
    {
        if (lpText != nullptr)
            Marshal::FreeHGlobal((IntPtr) const_cast<char*>(lpText)); // Free memory

        lpText = nullptr;
    }

    array<String^>^ CppCLI::CopyFromVector(const std::vector<std::string> &vec)
    {
        if (vec.empty())
            return nullptr;

        array<String^>^ ret = gcnew array<String^>((int)vec.size());

        for (unsigned int i = 0; i < vec.size(); i++)
        {
            ret[i] = gcnew String(vec[i].c_str());
        }

        return ret;
    }

}}}
