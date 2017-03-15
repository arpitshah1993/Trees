#pragma once
class KDData
{
public:
	int x;
	int y;
	int d;
	KDData();
	KDData(int, int, int);
	~KDData();
	int keyValue(int);
	bool Equals(KDData);
};
class KDNode
{
public:
	KDData data;
	KDNode* left;
	KDNode* right;
	KDNode();
	KDNode(KDData);
	~KDNode();
};

