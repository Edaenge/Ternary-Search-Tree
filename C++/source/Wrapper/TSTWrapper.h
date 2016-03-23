#pragma once

#include "stdafx.h"
#include <string>
#include <vector>

class Engine;

class DLL_USAGE TSTWrapper
{
public:
	TSTWrapper(const char *binPath);
	~TSTWrapper();

    bool Put(const char *key, unsigned int value);
    bool Delete(const char *key);
    bool Contains(const char *key);
    std::vector<std::string> KeysWithPrefix(char *prefix);
    std::vector<std::string> KeysThatMatch(const char *pattern);
    std::string LongestPrefixOf(const char *query);
    std::vector<std::string> GetAllKeys();
    void ClearTree();
    bool IsEmpty() const;
    unsigned int Size() const;
    bool LoadKeysFromFile(const char *path);
	bool GenerateDotCode();
	bool GenerateDotCode(const char *key, const unsigned int option);
	
private:
    Engine *mEngine;
};
