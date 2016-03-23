#include "TST.h"

using namespace Ternary;

Ternary::TernarySearchTree::TernarySearchTree()
{
    mRoot = nullptr;
    mSize = 0;
}

Ternary::TernarySearchTree::~TernarySearchTree()
{
    ClearTree(&mRoot);
}

bool Ternary::TernarySearchTree::Put(const string &key, unsigned int val)
{
    if (key.empty())
        return false;

	// Value used for identifying end positions of a key
    Value *value = new Value(val);

	// Recursively go through the tree and add new nodes if needed
    mRoot = PutRec(nullptr, mRoot, key, value, 0);
    return true;
}

void Ternary::TernarySearchTree::Put(const vector<string> &cont)
{
    if (cont.empty())
        return;

    int val = 1;
    auto it_end = cont.end();

	// Add multiple keys
    for (auto it = cont.begin(); it != it_end; it++)
    {
        Put((*it), val++);
    }
}

Node* Ternary::TernarySearchTree::PutRec(Node *prev, Node *n, const string &key, Value *val, unsigned int d)
{
    char c = key[d];

	// Create a new node if current node is nil
    if (n == nullptr)
        n = new Node(c, prev);

	// Go to left, if less
    if (c < n->charData)
    {
        n->left = PutRec(n, n->left, key, val, d);
    }
	// Go to right, if greater
    else if (c > n->charData)
    {
        n->right = PutRec(n, n->right, key, val, d);
    }
	// Go to mid, if equal
    else if (d < key.size() - 1)
    {
        n->mid = PutRec(n, n->mid, key, val, d+1);
    }
	// Final destination reached
    else
    {
        // If there is a key here, the same word was added again.
        if (!n->IsEndKey())
            mSize++;

		// Mark as an end node
        n->value = val;
    }

    return n;
}

bool Ternary::TernarySearchTree::Delete(const string key)
{
    if (key.empty())
        return false;

	// Recursively go all the way down to the end key (if it exists) and delete the nodes (if possible)
    bool ret = DeleteRec(mRoot, key, 0);

    if (ret)
        mSize--;

    return ret;
}

bool Ternary::TernarySearchTree::DeleteRec(Node *n, const string &key, unsigned int d)
{
	// End of the line (key does not exist)
    if (n == nullptr)
        return false;

    char c = key[d];
    bool ret = true;

	// Go left, if less
    if (c < n->charData)
    {
        ret = DeleteRec(n->left, key, d);
    }
	// Go right, if greater
    else if (c > n->charData)
    {
        ret = DeleteRec(n->right, key, d);
    }
    else
    {
        // If node is an end node and if we are on our last character, remove the end value and proceed to deletion below
		// Return false if there is no end key as it does not exist within the tree.
        if (d == key.size() - 1)
        {
            if (n->IsEndKey())
                SAFE_DELETE(n->value);
            else
                return false;
        }
		// Go mid, if equal (if we don't exceed the key)
        else if (d < key.size() + 1)
        {
            ret = DeleteRec(n->mid, key, d+1);
        }
    }

    // Only remove if n's mid is nil and if n is not an end key
    // If ret is false, means the value was never found. Thus the key does not exist within this tree
    if (ret && n->mid == nullptr && !n->IsEndKey())
    {
        // #Case 1: No children, safe to delete
        if (!n->HasChildren())
        {
            Transplant(n, nullptr);
            SAFE_DELETE(n);
        }
        // #Case 2: Right is null, transplant it to left
        else if (n->right == nullptr)
        {
            Transplant(n, n->left);
            SAFE_DELETE(n);
        }
        // #Case 2: Left is null, transplant it to right
        else if (n->left == nullptr)
        {
            Transplant(n, n->right);
            SAFE_DELETE(n);
        }
        // #Case 3: Both left and right children exists, find successor and transplant
        else
        {
            Node *y = FindSuccessor(n->right);
            if (y->parent != n)
            {
                Transplant(y, y->right);
                y->right = n->right;
                y->right->parent = y;
            }
            Transplant(n, y);
            y->left = n->left;
            y->left->parent = y;

            SAFE_DELETE(n);
        }
    }

    return ret;
}

const Value* Ternary::TernarySearchTree::Get(const string key, set<const Node*> *visitedNodes)
{
	// Recursively go through the nodes and return the end key node.
    Node *node = GetRec(mRoot, key, 0, visitedNodes);

    if (node)
        return node->value;

    return nullptr;
}

Node* Ternary::TernarySearchTree::GetRec(Node *n, const string &key, unsigned int d, set<const Node*> *visitedNodes)
{
	// End of the line (prefix does not exist)
    if (n == nullptr)
        return n;

	// Fetch character at position 'd'
	char c = key[d];

	// Used for graph presentation for this application (not part of Ternary)
	if (visitedNodes != nullptr && n->charData == c)
		visitedNodes->insert(n);

	// Go left, if less
    if (c < n->charData)
        return GetRec(n->left, key, d, visitedNodes);
	// Go right, if greater
    else if (c > n->charData)
        return GetRec(n->right, key, d, visitedNodes);
	// Go mid if, equal (if we don't exceed the prefix)
    else if(d < key.size() - 1)
        return GetRec(n->mid, key, d+1, visitedNodes);

    return n;
}

unsigned int Ternary::TernarySearchTree::Search(Node *n, const string &key, unsigned int d, unsigned int len, set<const Node*> *visitedNodes)
{
	// End of the line (key does not exist)
    if (n == nullptr)
        return len;

	char c = key[d];

	// used for graph presentation for this application (not part of Ternary)
	if (visitedNodes != nullptr && n->charData == c)
		visitedNodes->insert(n);

	// Go left, if less
    if (c < n->charData)
        return Search(n->left, key, d, len, visitedNodes);
	// Go right, if greater
    else if (c > n->charData)
        return Search(n->right, key, d, len, visitedNodes);
    else
    {
		// If end key, add to the length
        if (n->IsEndKey())
            len = d+1;

		// Go mid, if equal
        return Search(n->mid, key, d+1, len, visitedNodes);
    }
}

std::string Ternary::TernarySearchTree::LongestPrefixOf(const string query, set<const Node*> *visitedNodes)
{
    if (query.empty())
        return "";

    unsigned int len = Search(mRoot, query, 0, 0, visitedNodes);

	// Used for graph presentation for this application (not part of Ternery)
	if (visitedNodes != nullptr && len == 0)
		visitedNodes->clear();

    return query.substr(0, len);
}

vector<string> Ternary::TernarySearchTree::KeysThatMatch(const string pat, set<const Node*> *visitedNodes)
{
    vector<string> container;
    string prefix = "";
    Collect(mRoot, prefix, pat, container, 0, visitedNodes);

	// Used for graph presentation for this application (not part of Ternary)
	if (visitedNodes != nullptr && container.empty())
		visitedNodes->clear();

    return container;
}

vector<string> Ternary::TernarySearchTree::KeysWithPrefix(string prefix, set<const Node*> *visitedNodes)
{
    vector<string> container;

    if (prefix.empty())
        return container;

    // Get the end node from prefix
    Node *node = GetRec(mRoot, prefix, 0, visitedNodes);

	// Prefix is not part of tree
    if (!node)
	{
		// Used for graph presentation for this application (not part of Ternary)
		if (visitedNodes != nullptr)
			visitedNodes->clear();

        return container;
	}

    // Include if prefix is a hit
    if (node->IsEndKey())
        container.push_back(prefix);

    // Collect the rest
    Collect(node->mid, prefix, container, visitedNodes);

    return container;
}

vector<string> Ternary::TernarySearchTree::GetAllKeys()
{
    vector<string> cont;
    string prefix = "";
    Collect(mRoot, prefix, cont);
    return cont;
}

bool Ternary::TernarySearchTree::Contains(const string key)
{
    if (key.empty())
        return false;

    unsigned int len = Search(mRoot, key, 0, 0);
    string substr = key.substr(0, len);

    if (substr == key)
        return true;

    return false;
}

void Ternary::TernarySearchTree::Collect(Node *n, string &prefix, vector<string> &cont, set<const Node*> *visitedNodes)
{
	// End of the line (prefix does not exist)
    if (n == nullptr)
        return;

	// Used for graph presentation for this application (not part of Ternary)
	if (visitedNodes != nullptr)
		visitedNodes->insert(n);

	// Collect all to the left, with end keys
    Collect(n->left, prefix, cont, visitedNodes);

    prefix += n->charData;

    if (n->IsEndKey())
        cont.push_back(prefix);

	// Collect all to the mid, with end keys
    Collect(n->mid, prefix, cont, visitedNodes);

    prefix = prefix.substr(0, prefix.length() - 1);

	// Collect all to the right, with end keys
    Collect(n->right, prefix, cont, visitedNodes);
}

void Ternary::TernarySearchTree::Collect(Node *n, string &prefix, const string &pat, vector<string> &cont, unsigned int d, set<const Node*> *visitedNodes)
{
	// End of the line (pattern does not exist)
    if (n == nullptr)
        return;

	char c = pat[d];

	// Used for graph presentation for this application (not part of Ternary)
	if (visitedNodes != nullptr && (c == '.' || c == n->charData))
		visitedNodes->insert(n);

	// Go left, if less or equal to the wild card
    if (c == '.' || c < n->charData)
        Collect(n->left, prefix, pat, cont, d, visitedNodes);

	// Go mid, if equal or equal to the wild card
    if (c == '.' || c == n->charData)
    {
		// If we hit an end key, add it to our container
        if (d == pat.length() - 1 && n->IsEndKey())
        {
            cont.push_back(prefix + n->charData);
        }

		// Go mid, if equal (if we don't exceed the pattern)
		// Also add to prefix
        if (d < pat.length() - 1)
        {
            prefix += n->charData;
            Collect(n->mid, prefix, pat, cont, d+1, visitedNodes);
            prefix = prefix.substr(0, prefix.length() - 1);
        }
    }

	// Go right, if greater or equal to the wild card
    if (c == '.' || c > n->charData)
        Collect(n->right, prefix, pat, cont, d, visitedNodes);
}

Node* Ternary::TernarySearchTree::FindSuccessor(Node* n)
{
    if (n->left == nullptr)
        return n;
    else
        return FindSuccessor(n->left);
}

void Ternary::TernarySearchTree::Transplant(Node *u, Node *v)
{
	// Typical BST transplant used for deletion
    if (u->parent == nullptr)
        mRoot = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else if (u == u->parent->right)
        u->parent->right = v;
    else
        u->parent->mid = v;

    if (v != nullptr)
        v->parent = u->parent;
}

void Ternary::TernarySearchTree::ClearTree(Node** node /*= nullptr*/)
{
	// In order traverse
    if (node == nullptr)
    {
        ClearTree(&mRoot);
        return;
    }
    else if (*node == nullptr)
        return;

    ClearTree(&(*node)->left);
    ClearTree(&(*node)->mid);
    ClearTree(&(*node)->right);

    SAFE_DELETE((*node));
    mSize = 0;
}
