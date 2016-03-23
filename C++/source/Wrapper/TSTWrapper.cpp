#include "TSTWrapper.h"
#include "Engine.h"

using namespace std;

TSTWrapper::TSTWrapper(const char *binPath)
{
    mEngine = new Engine(binPath);
}

TSTWrapper::~TSTWrapper()
{
    SAFE_DELETE(mEngine);
}

bool TSTWrapper::Put(const char *key, unsigned int value)
{
    return mEngine->Put(key, value);
}

bool TSTWrapper::Delete(const char *key)
{
    return mEngine->Delete(key);
}

bool TSTWrapper::Contains(const char *key)
{
    return mEngine->Contains(key);
}

std::vector<std::string> TSTWrapper::KeysWithPrefix(char *prefix)
{
    return mEngine->KeysWithPrefix(prefix);
}

std::vector<std::string> TSTWrapper::KeysThatMatch(const char *pattern)
{
    return mEngine->KeysThatMatch(pattern);
}

std::string TSTWrapper::LongestPrefixOf(const char *query)
{
    return mEngine->LongestPrefixOf(query);
}

std::vector<std::string> TSTWrapper::GetAllKeys()
{
    return mEngine->GetAllKeys();
}

void TSTWrapper::ClearTree()
{
    mEngine->ClearTree();
}

bool TSTWrapper::IsEmpty() const
{
    return mEngine->IsEmpty();
}

unsigned int TSTWrapper::Size() const
{
    return mEngine->Size();
}

bool TSTWrapper::LoadKeysFromFile(const char *path)
{
    return mEngine->LoadKeysFromFile(path);
}

bool TSTWrapper::GenerateDotCode()
{
	return mEngine->GenerateDotCode();
}

bool TSTWrapper::GenerateDotCode(const char *key, const unsigned int option)
{
	return mEngine->GenerateDotCode(key, option);
}

