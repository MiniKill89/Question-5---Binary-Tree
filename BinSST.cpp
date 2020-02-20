#include "BinSST.h"
#include <cstddef>
#include <iostream>

using namespace std;

BinSST::BinSST()
{
	root = NULL;
}

BinSST::~BinSST()
{
	destroy();
}

void BinSST::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node* BinSST::search(int key)
{
	return search(key, root);
}

void BinSST::destroy()
{
	destroy(root);
}

void BinSST::CheckTree()
{
	system("CLS");
	CheckTree(root);
}

void BinSST::destroy(node* leaf)
{
	if (leaf != NULL)
	{
		destroy(leaf->left);
		destroy(leaf->right);
		delete leaf;
	}
}

void BinSST::insert(int key, node* leaf)
{
	if (key < leaf->value)
	{
		if (leaf->left != NULL)
		{
			insert(key, leaf->left);
		}
		else
		{
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->value)
	{
		if (leaf->right != NULL)
		{
			insert(key, leaf->right);
		}
		else
		{
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node* BinSST::search(int key, node* leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
		{
			cout << "Found" << endl;
			return leaf;
		}
		if (key < leaf->value)
		{
			cout << "Searching Next Left" << endl;
			return search(key, leaf->left);
		}
		else
		{
			cout << "Searching Next Right" << endl;
			return search(key, leaf->right);
		}
	}
	else
	{
		cout << "Not Found" << endl;
		return NULL;
	}
}

void BinSST::CheckTree(node* leaf)
{
	writeConsole(leaf);
	if ((leaf->right != NULL) && (leaf->left != NULL))
	{
		cout << endl;
		cout << "Left Side" << endl;
		CheckTree(leaf->left);
		cout << endl;
		cout << "Right Side" << endl;
		CheckTree(leaf->right);
		cout << endl;
	}
	else if ((leaf->right == NULL) && (leaf->left == NULL))
	{
		cout << "No more nodes" << endl;
	}
	else if (leaf->right == NULL)
	{
		CheckTree(leaf->left);
	}
	else if (leaf->right != NULL)
	{
		CheckTree(leaf->right);
	}
}

void BinSST::writeConsole(node* leaf)
{
	if (leaf->left != NULL && leaf->right != NULL)
	{
		cout << "NODE: Key: " << leaf->value;
		cout << " Left Side: " << leaf->left->value;
		cout << " Right Side: " << leaf->right->value << endl;;
		//cout << Keyout << " " << Leftout << " " << Rightout << endl;
	}
	else if (leaf->right != NULL)
	{
		cout << "NODE: Key: " << leaf->value;
		cout << " Left Side: NULL ";
		cout << " Right Side: " << leaf->right->value << endl;
		//cout << Keyout << " " << Leftout << " " << Rightout << endl;
	}
	else if (leaf->left != NULL)
	{
		cout << "NODE: Key: " << leaf->value;
		cout << " Left Side: " << leaf->left->value;
		cout << " Right Side: NULL" << endl;
		//cout << Keyout << " " << Leftout << " " << Rightout << endl;
	}
	else
	{
		cout << "NODE: Key: " << leaf->value;
		cout << " Left Side: NULL " ;
		cout << " Right Side: NULL" << endl;
	}
}