#include"BSTNode.h"
#include<string>
#include<vector>
class BST
{
public:
	BSTNode* root;
	BST();
	~BST();
	void insert(data, BSTNode*);
	int height(BSTNode*);
	BSTNode* search(int, BSTNode*);
	void show(BSTNode*, std::string);
	BSTNode* FindMin(BSTNode*);
	BSTNode* deleteNodes(BSTNode*, data);
	bool contains(std::vector<int>, int );
	int randomNumber(std::vector<int>, int);
};

