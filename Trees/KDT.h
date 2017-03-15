#include"KDNode.h"
#include<string>
#include<vector>
class KDT
{
public:
	KDNode* root = NULL;
	KDT();
	~KDT();
	void insert(KDNode*, KDData,int);
	KDNode* search(KDNode*,KDData, int);
	void show(KDNode*, std::string);
	int height(KDNode*);
	std::pair<int, int> randomNumber2D(std::vector<std::pair<int, int> > generatedNumber, int limit);
	KDNode* deleteNode(KDNode*, KDData, int);
	KDNode* findMin(KDNode*, int, unsigned);
	KDNode* findMinInTwo(KDNode*, KDNode*, int);
	bool contains(std::vector<int> generatedNumber, int num);
	int randomNumber(std::vector<int> i, int);
	bool contains2D(std::vector<std::pair<int, int> > generatedNumber, std::pair<int, int> num);
};

