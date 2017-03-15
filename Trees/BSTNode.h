#pragma once
class data
{
public:
	int key;
	int value;
	data();
	~data();
	data(int, int);
	int keyValue(int);
};

class BSTNode
{
public:
	data node;
	BSTNode* left;
	BSTNode* right;
	BSTNode();
	BSTNode(data);
	~BSTNode();
};

