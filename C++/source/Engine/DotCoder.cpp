#include "DotCoder.h"
#include <list>
#include <sstream>
#include <locale>

#define LEFT			0
#define MID				1
#define	RIGHT			2
#define MAX_CHILDREN	3

DotCoder::DotCoder(const string path)
{
	mPath = path;
	mIDGen = 0;
}

DotCoder::~DotCoder()
{

}

bool DotCoder::CreateDotFile(TernarySearchTree *T, set<const Node*> *visitedNodes)
{
	if (!T)
		return false;

	if (T->IsEmpty())
		return false;

	ofstream write;
	write.open(mPath);

	if (!write.is_open())
		return false;

	mColoredNodes = visitedNodes;

	//Initialize Start Values
	mIDGen = 0;
	WriteLine(write, "digraph hierarchy {\n");
	WriteLine(write, "nodesep=0.35", 4);
	WriteLine(write, "ordering=out", 4);
	WriteLine(write, "node [color=Red, fontname=Courier, shape=circle]", 4);
	WriteLine(write, "edge [color=Black, arrowhead=\"vee\"]", 4);
	WriteLine(write, "");

	// Go through Tree and make graph nodes
	WriteTreeNodes(write, T);

	// End of code
	WriteLine(write, "}");

	write.close();
	mColoredNodes = nullptr;

	return true;
}

void DotCoder::WriteTreeNodes(ofstream &write, TernarySearchTree *T)
{
	if (!T && T->IsEmpty())
		return;

	std::list<GraphNode> levelQueue;
	unsigned int nodesInLevel = 0;
	levelQueue.push_back(GraphNode(T->GetRoot(), MakeNodeID(T->GetRoot())));

	// Queue and Write Root Node code
	const GraphNode root = levelQueue.front();
	WriteLine(write, "//Init Root Node", 4);

	// Check if we have extras (coloring) for the root
	string extras = "";
	if (mColoredNodes)
	{
		auto it = mColoredNodes->find(root.GetNode());
		if (it != mColoredNodes->end())
			extras = " style=\"filled\" fillcolor=\"green\"";
	}

	WriteLine(write, root.GetID() + " [" + GetLabelCode(root.GetNode()) + extras + "]", 4);

	// Level traverse
	while (!levelQueue.empty())
	{
		nodesInLevel = (unsigned int)levelQueue.size();

		while (nodesInLevel > 0)
		{
			GraphNode graphNode = levelQueue.front();
			levelQueue.pop_front();
			nodesInLevel--;

			// Create Graph Nodes
			// Left 0, Mid 1, Right 3
			GraphNode child[3];
			child[LEFT] = GraphNode(graphNode.GetNode()->GetLeft(), MakeNodeID(graphNode.GetNode()->GetLeft()));
			child[MID] = GraphNode(graphNode.GetNode()->GetMid(), MakeNodeID(graphNode.GetNode()->GetMid()));
			child[RIGHT] = GraphNode(graphNode.GetNode()->GetRight(), MakeNodeID(graphNode.GetNode()->GetRight()));

			// No Children, Continue Loop
			if (!child[LEFT].GetNode() && !child[MID].GetNode() && !child[RIGHT].GetNode())
				continue;

			// Create Nodes in the code
			WriteNodes(write, child);
			// Point the nodes in the code
			WriteNodePoints(write, graphNode, child);
			// Extra Line
			WriteLine(write, "");

			// Add Nodes To Queue
			for (int i = 0; i < MAX_CHILDREN; i++)
			{
				if (child[i].GetNode())
					levelQueue.push_back(child[i]);
			}
		}
	}
}

void DotCoder::WriteNodes(ofstream &write, const GraphNode children[])
{
	string invisibleNodes = "{ node[shape=point style=invis] ";
	for (int i=0; i<MAX_CHILDREN; i++)
	{
		if (!children[i].GetNode())
			invisibleNodes += children[i].GetID() + " ";
	}

	invisibleNodes += "}";
	WriteLine(write, invisibleNodes, 4);

	for (int i=0; i<MAX_CHILDREN; i++)
	{
		string extras = "";
		const Node *n = children[i].GetNode();

		if (mColoredNodes)
		{
			auto it = mColoredNodes->find(n);
			if (it != mColoredNodes->end())
				extras = " style=\"filled\" fillcolor=\"green\"";
		}

		const GraphNode g = children[i];
		WriteLine(write, children[i].GetID() + " [" + GetLabelCode(g.GetNode()) + extras + "]", 4);
	}
}

void DotCoder::WriteNodePoints(ofstream &write, const GraphNode &parent, const GraphNode children[]) const
{
	const string parentID = parent.GetID();
	for (int i=0; i<MAX_CHILDREN; i++)
	{
		string extras = "";
		const string ID = children[i].GetID();
		const Node *n = children[i].GetNode();

		if (!n && i != MID)
		{
			extras = " [style=invis]";
		}
		else if (i == MID)
		{
			extras = " [weight=100";

			if (!n)
				extras += " style=invis]";
			else
				extras += "]";
		}

		WriteLine(write, parentID + " -> " + ID + extras, 4);
	}
}

void DotCoder::WriteLine(ofstream &write, const string str) const
{
	if (write.is_open())
		write << str << endl;
}

void DotCoder::WriteLine(ofstream &write, const string str, const unsigned int tab) const
{
	string tabStr = "";

	for (unsigned int i = 0; i < tab; i++)
		tabStr += "\t";

	WriteLine(write, tabStr + str);
}

std::string DotCoder::MakeNodeID(const Node *n)
{
	string ID;
	stringstream ss;

	if (n)
		ID = n->GetCharData();
	else
		ID = "nil";

	ss << mIDGen;
	ID += ss.str();
	mIDGen++;

	return ID;
}

std::string DotCoder::GetLabelCode(const Node* node)
{
	string label = " label=";
	string c = "";

	if (node)
		c += node->GetCharData();
	else
		c + "nil";

	if (node && node->IsEndKey())
		label += "<<U><B>" + c + "</B></U>>";
	else
		label += "<<B>" + c + "</B>>";

	return label;
}
