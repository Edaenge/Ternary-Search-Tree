#pragma once;

#include "TST.h"
#include <fstream>

using namespace Ternary;

class GraphNode
{
public:
	GraphNode()
	{
		this->node = nullptr;
		this->ID = "none";
	}

	GraphNode(const Node *node, const string ID)
	{
		this->node = node;
		this->ID = ID;
	}

	inline const Node* GetNode() const {return node;}
	inline const string GetID() const {return ID;}

private:
	const Node *node;
	string ID;
};

class DotCoder
{
public:
	DotCoder(const string path);
	~DotCoder();

	bool CreateDotFile(TernarySearchTree *T, set<const Node*> *visitedNodes = nullptr);

private:
	void WriteNodes(ofstream &write, const GraphNode children[]);
	void WriteNodePoints(ofstream &write, const GraphNode &parent, const GraphNode children[]) const;
	void WriteTreeNodes(ofstream &write, TernarySearchTree *T);
	void WriteLine(ofstream &write, const string str) const;
	void WriteLine(ofstream &write, const string str, const unsigned int tab) const;
	string MakeNodeID(const Node *n);
	string GetLabelCode(const Node* node);

private:
	string mPath;
	unsigned int mIDGen;
	set<const Node*> *mColoredNodes;
};