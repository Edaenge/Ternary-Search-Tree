#pragma once

#include "stdafx.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

namespace Ternary
{
    class Value
    {
	friend class TernarySearchTree;

    public:
        Value(const unsigned int value) { mValue = value; }
		inline const unsigned int GetValue() const {return mValue;}

    private:
        unsigned int mValue;
    };

    class Node
    {
	friend class TernarySearchTree;

	public:
		Node(const char character, Node *p)
		{
			parent   = p;
			left     = nullptr;
			mid      = nullptr;
			right    = nullptr;
			value    = nullptr;
			charData = character;
		}

		Node(const char character, Node *p, Value *val)
		{
			parent   = p;
			left     = nullptr;
			mid      = nullptr;
			right    = nullptr;
			value    = val;
			charData = character;
		}

		virtual ~Node()
		{
			SAFE_DELETE(value);
		}

		inline bool IsEndKey() const {return value ? true : false;}

		inline bool HasChildren() const
		{
			if (left || right || mid)
				return true;
			else
				return false;
		}

		inline const Node* GetParent() const {return parent;}
		inline const Node* GetLeft() const {return left;}
		inline const Node* GetMid() const {return mid;}
		inline const Node* GetRight() const {return right;}
		inline const Value* GetValue() const {return value;}
		inline const char GetCharData() const {return charData;}

	private:
		Node *parent;
		Node *left;
		Node *mid;
		Node *right;
		Value *value;
		char charData;
    };

    class TernarySearchTree
    {
    public:

        /// <summary>
        /// Initializes a new instance of the <see cref="TernarySearchTree"/> class.
        /// </summary>
        TernarySearchTree();

        /// <summary>
        /// Finalizes an instance of the <see cref="TernarySearchTree"/> class.
        /// </summary>
        virtual ~TernarySearchTree();

        /// <summary>
        /// Puts the specified key into the tree.
        /// </summary>
        /// <param name="key">The key.</param>
        /// <param name="val">The value.</param>
        /// <returns>True on success.</returns>
        bool Put(const string &key, unsigned int val);

        /// <summary>
        /// Put multiple keys into the tree.
        /// Key values will be auto-generated.
        /// </summary>
        /// <param name="cont">The container with keys.</param>
        void Put(const vector<string> &cont);

        /// <summary>
        /// Deletes the specified key.
        /// </summary>
        /// <param name="key">The key.</param>
        /// <returns>True on success.</returns>
        bool Delete(const string key);

        /// <summary>
        /// Gets the value of the specified key.
        /// </summary>
        /// <param name="key">The key.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns>Value of the specified key.</returns>
        const Value* Get(const string key, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Returns the longest key that is a prefix of the specified string.
        /// </summary>
        /// <param name="query">The query.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns></returns>
        string LongestPrefixOf(const string query, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Returns all keys from the tree that has the specified prefix string.
        /// </summary>
        /// <param name="prefix">The prefix.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns></returns>
        vector<string> KeysWithPrefix(string prefix, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Returns all keys from the tree that match the specified string pattern.
        /// Pattern can be specified with a wildcard '.', which will match any character in the tree.
        /// </summary>
        /// <param name="pat">The pattern.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns></returns>
        vector<string> KeysThatMatch(const string pat, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Determines whether the tree contains the specified key.
        /// </summary>
        /// <param name="key">The key.</param>
        /// <returns></returns>
        bool Contains(const string key);

        /// <summary>
        /// Gets all keys from the tree.
        /// </summary>
        /// <returns></returns>
        vector<string> GetAllKeys();

        /// <summary>
        /// Clears the whole tree.
        /// </summary>
        /// <param name="node">The main node root of the tree or a part root of the tree.</param>
        void ClearTree(Node** node = nullptr);

        /// <summary>
        /// Gets the main root of the tree.
        /// </summary>
        /// <returns>The main root.</returns>
        inline const Node *GetRoot() { return mRoot; }

        /// <summary>
        /// Determines whether this instance is empty.
        /// </summary>
        /// <returns>True if empty.</returns>
        inline bool IsEmpty() const { return mSize ? false : true; }

        /// <summary>
        /// Size as in total words existing in the tree.
        /// </summary>
        /// <returns>Total words in the tree.</returns>
        inline unsigned int Size() const { return mSize; }

    private:
        /// <summary>
        /// Called by public function 'Get'. 
        /// This function recursively goes through the tree to find the end node of the key specified.
        /// </summary>
        /// <param name="n">The current node.</param>
        /// <param name="key">The specified key.</param>
        /// <param name="d">The current char index in key.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns>The end node of the specified key. Returns null if not found.</returns>
        Node* GetRec(Node *n, const string &key, unsigned int d, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Called by public function 'Put'.
        /// This function recursively goes through the tree and creates new nodes for the key specified.
        /// </summary>
        /// <param name="prev">The previous node.</param>
        /// <param name="n">The current node.</param>
        /// <param name="key">The key.</param>
        /// <param name="val">The value.</param>
        /// <param name="d">The current char index in key.</param>
        /// <returns></returns>
        Node* PutRec(Node *prev, Node *n, const string &key, Value *val, unsigned int d);

        /// <summary>
        /// Called by public function 'Delete'.
        /// This function recursively goes through the tree and deletes nodes specified by key.
        /// A node can only be deleted if it is not dependent on other nodes.
        /// </summary>
        /// <param name="n">The current node.</param>
        /// <param name="key">The key.</param>
        /// <param name="d">The current char index in key.</param>
        /// <returns></returns>
        bool DeleteRec(Node *n, const string &key, unsigned int d);

        /// <summary>
        /// Finds the successor of a tree node.
        /// </summary>
        /// <param name="n">The node's successor to be found.</param>
        /// <returns>The successor node</returns>
        Node* FindSuccessor(Node* n);

        /// <summary>
        /// Searches the specified key.
        /// Returns the length of the key if found, or the length of the longest prefix.
        /// Returns 0 if not found.
        /// </summary>
        /// <param name="n">The current node.</param>
        /// <param name="key">The key.</param>
        /// <param name="d">The current char index in key.</param>
        /// <param name="len">The current length.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        /// <returns></returns>
        unsigned int Search(Node *n, const string &key, unsigned int d, unsigned int len, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Transplants the specified nodes.
        /// Used on deletion of a node.
        /// </summary>
        /// <param name="u">The node to be deleted.</param>
        /// <param name="v">The successor node (null allowed).</param>
        void Transplant(Node *u, Node *v);

        /// <summary>
        /// Collects and stores node chars from the tree.
        /// </summary>
        /// <param name="n">The current node.</param>
        /// <param name="prefix">The prefix.</param>
        /// <param name="cont">The container.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        void Collect(Node *n, string &prefix, vector<string> &cont, set<const Node*> *visitedNodes = nullptr);

        /// <summary>
        /// Collects and stores node chars from the tree.
        /// </summary>
        /// <param name="n">The n.</param>
        /// <param name="prefix">The prefix.</param>
        /// <param name="pat">The pattern.</param>
        /// <param name="cont">The container.</param>
        /// <param name="d">The current char index of the pattern.</param>
		/// <param name="visitedNodes">Collects visited nodes (used for rendering graphs).</param>
        void Collect(Node *n, string &prefix, const string &pat, vector<string> &cont, unsigned int d, set<const Node*> *visitedNodes = nullptr);
    private:
        unsigned int mSize;
        Node *mRoot;
    };
}
