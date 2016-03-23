#include "KeyLoader.h"
#include <fstream>
#include <locale>

KeyLoader::KeyLoader()
{

}

KeyLoader::~KeyLoader()
{

}

bool KeyLoader::Load(const string filePath)
{
    mData.clear();
    ifstream reader;
    reader.open(filePath);
    string str;

    if (!reader.is_open())
        return false;
    
    while (!reader.eof())
    {
        getline(reader, str);

        if(str.empty())
            continue;

        ToLowerCase(str);
        mData.push_back(str);
    }

    reader.close();

    return true;
}

void KeyLoader::ToLowerCase(string &str)
{

    if (str.empty())
        return;

    std::locale loc;
    loc.global(std::locale("Swedish"));

    for (std::string::size_type i = 0; i < str.length(); i++)
        str[i] = tolower(str[i],loc);
}

