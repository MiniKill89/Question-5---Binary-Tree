#pragma once

struct node
{
	int value;
	node* left;
	node* right;
};

class BinSST
{
public:
	BinSST();
	~BinSST();

	void insert(int key);
	node* search(int key);
	void destroy();
	void CheckTree();

private:
	void destroy(node* leaf);
	void insert(int key, node* leaf);
	node* search(int key, node* leaf);
	void CheckTree(node* leaf);
	void writeConsole(node* leaf);

	node* root;
};