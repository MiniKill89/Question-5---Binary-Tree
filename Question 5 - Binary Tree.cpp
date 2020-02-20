#include <iostream>
#include <Windows.h>
#include "BinSST.h";
using namespace std;

BinSST* Tree;

int main()
{
	int treeIns [5] = {0, 1, 3, 4, 9};
	Tree = new BinSST();
	for(int i = 0; i < 5; i++)
	{
		Tree->insert(treeIns[i]);
	}
	Tree->CheckTree();
	cout << "End of Tree" << endl;
}