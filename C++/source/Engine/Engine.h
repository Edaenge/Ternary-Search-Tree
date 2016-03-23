#include "TST.h"
#include "KeyLoader.h"
#include "DotCoder.h"

using namespace Ternary;

class Engine
{
public:
	Engine(const string binPath);
	~Engine();

    bool Put(const string &key, unsigned int value);
    bool Delete(const string &key);
    bool Contains(const string &key);
    vector<string> KeysWithPrefix(string prefix);
    vector<string> KeysThatMatch(const string &pattern);
    string LongestPrefixOf(const string &query);
    vector<string> GetAllKeys();
    void ClearTree();
    bool IsEmpty() const;
    unsigned int Size() const;
    bool LoadKeysFromFile(const string &path);
	bool GenerateDotCode();
	bool GenerateDotCode(const string &key, const unsigned int option);

private:
	string mBinPath;
    Ternary::TernarySearchTree *mTST;
    KeyLoader *mKeyLoader;
	DotCoder *mDotCoder;
};
