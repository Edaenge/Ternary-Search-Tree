#include "Engine.h"

Engine::Engine(const string binPath)
{
	mBinPath = binPath;
    mTST = new TernarySearchTree();
    mKeyLoader = new KeyLoader();
	mDotCoder = new DotCoder(mBinPath+"\\data\\dot.txt");
	
}

Engine::~Engine()
{
    SAFE_DELETE(mTST);
    SAFE_DELETE(mKeyLoader);
	SAFE_DELETE(mDotCoder);
}

bool Engine::Put(const string &key, unsigned int value)
{
    return mTST->Put(key, value);
}

bool Engine::Delete(const string &key)
{
    return mTST->Delete(key);
}

bool Engine::Contains(const string &key)
{
    return mTST->Contains(key);
}

vector<string> Engine::KeysWithPrefix(string prefix)
{
    return mTST->KeysWithPrefix(prefix);
}

vector<string> Engine::KeysThatMatch(const string &pattern)
{
    return mTST->KeysThatMatch(pattern);
}

string Engine::LongestPrefixOf(const string &query)
{
    return mTST->LongestPrefixOf(query);
}

vector<string> Engine::GetAllKeys()
{
    return mTST->GetAllKeys();
}

void Engine::ClearTree()
{
    mTST->ClearTree();
}

bool Engine::IsEmpty() const
{
    return mTST->IsEmpty();
}

unsigned int Engine::Size() const
{
    return mTST->Size();
}

bool Engine::LoadKeysFromFile(const string &path)
{
    if (!mKeyLoader->Load(path))
        return false;

    mTST->Put(mKeyLoader->GetData());

    return true;
}

bool Engine::GenerateDotCode()
{
	return mDotCoder->CreateDotFile(mTST);
}

bool Engine::GenerateDotCode(const string &key, const unsigned int option)
{
	set<const Node*> *visitedNodes = new set<const Node*>();
	bool ret = false;

	if (option == 0)
	{
		mTST->KeysWithPrefix(key, visitedNodes);
		ret =  mDotCoder->CreateDotFile(mTST, visitedNodes);
	}
	if (option == 1)
	{
		mTST->KeysThatMatch(key, visitedNodes);
		ret = mDotCoder->CreateDotFile(mTST, visitedNodes);
	}
	if (option == 2)
	{
		mTST->LongestPrefixOf(key, visitedNodes);
		ret = mDotCoder->CreateDotFile(mTST, visitedNodes);
	}

	SAFE_DELETE(visitedNodes);
	return ret;
}
