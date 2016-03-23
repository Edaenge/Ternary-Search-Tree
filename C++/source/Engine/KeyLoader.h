#pragma once

#include "TST.h"

class KeyLoader
{

public:
	KeyLoader();
	virtual ~KeyLoader();

    bool Load(const string filePath);
    void ToLowerCase(string &str);
    inline vector<string> GetData() { return mData; }

private:
    vector<string> mData;
};
