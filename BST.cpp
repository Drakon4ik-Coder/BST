#include <string>
#include "BST.h"
using namespace std;

string to_string_helper(Node* root); // Prototype of a helper function,
// You can add additional helper functions
// to this code file
int count_num(Node* root);
void destroy_tree(Node* root);
void copy_nodes(Node* dst, Node* src);

// Default constructor, initializes an empty BST
BST::BST()
{
	this->root = nullptr;
}

// Helper function to recursively deep copy tree
void copy_nodes(Node* dst, Node* src)
{
	dst->name = src->name;
	dst->value = src->value;

	if (src->right != nullptr)
	{
		dst->right = new Node();
		copy_nodes(dst->right, src->right);
	}
	if (src->left != nullptr)
	{
		dst->left = new Node();
		copy_nodes(dst->left, src->left);
	}
	return;
}

// Copy constructor, deep copies the given BST
BST::BST(const BST& other)
{
	this->root = new Node();
	copy_nodes(this->root, (&other)->root);
}

//Helper function to recursively delete tree
void destroy_tree(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left != nullptr)
	{
		destroy_tree(root->left);
	}
	if (root->left != nullptr)
	{
		destroy_tree(root->right);
	}

	delete root;

	return;
}

// Destructor, cleans up memory allocated for the BST
BST::~BST()
{
	destroy_tree(this->root);
}

//A helper function to allow recursive calls
//You can add helper functions like this for the other methods,
//to recursively move through the tree
string to_string_helper(Node* root)
{
	if (root == nullptr)
	{
		return "";
	}
	else
	{
		return to_string_helper(root->left) +
			root->name + "=" + root->value + " " +
			to_string_helper(root->right);
	}
}

// Returns a string representation of the BST
string BST::to_string() const
{
	string ret = to_string_helper(this->root);
	if (ret.length() > 1)
	{
		ret.pop_back(); //remove final space
	}

	return ret;
}


// Inserts a constant with given name and value into the BST
void BST::insert_constant(string name, string value)
{
	Node* currNode = this->root;

	if (currNode == nullptr)
	{
		root = new Node{ nullptr, nullptr, name, value };
		return;
	}

	// look for empty space for new node
	while (true)
	{
		if (name.compare(currNode->name) >= 0)
		{
			// replace nullptr with new node
			if (currNode->right == nullptr)
			{
				currNode->right = new Node{ nullptr, nullptr, name, value };
				return;
			}
			currNode = currNode->right;
		}
		else
		{
			// replace nullptr with new node
			if (currNode->left == nullptr)
			{
				currNode->left = new Node{ nullptr, nullptr, name, value };
				return;
			}
			currNode = currNode->left;
		}
	}
}

// Returns the value of the constant with the given name
string BST::get_value(string name) const
{
	Node* currNode = this->root;

	if (currNode == nullptr)
	{
		return "";
	}

	// Traverses the tree to find the constant with the given name
	while (true)
	{
		if (name.compare(currNode->name) == 0)
		{
			return currNode->value;
		}
		else if (name.compare(currNode->name) > 0)
		{
			if (currNode->right == nullptr)
			{
				return "";
			}
			currNode = currNode->right;
		}
		else
		{
			if (currNode->left == nullptr)
			{
				return "";
			}
			currNode = currNode->left;
		}
	}
}


// Helper function to count number of 
// nodes recursively
int count_num(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	// count number of nodes on the left, 
	// add to the number of nodes on the left
	// plus current node
	return 1 + count_num(root->left) + count_num(root->right);
}

// Returns the number of constants in the BST
int BST::num_constants() const
{
	return count_num(this->root);
}

// Overloaded assignment operator, deep copies the given BST
BST& BST::operator=(const BST& rhs)
{
	destroy_tree(this->root);
	this->root = new Node();
	copy_nodes(this->root, (&rhs)->root);

	return *this;
}
