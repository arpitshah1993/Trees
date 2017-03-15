
#include "KDT.h"
#include<fstream>
#include<queue>
#include<time.h>
#include <cstddef>
#include <cstdlib>

KDT::KDT()
{
}


KDT::~KDT()
{
}

//insert the node
void KDT::insert(KDNode* currentNode, KDData data, int depth)
{
	if (root == NULL)
	{
		root = new KDNode(data);
		return;
	}

	int currentNodekey, datakey;
	switch (depth % 2)
	{
	case 0:
		currentNodekey = currentNode->data.x;
		datakey = data.x;
		break;
	case 1:
		currentNodekey = currentNode->data.y;
		datakey = data.y;
		break;
	default:
		break;
	}
	if (currentNodekey < datakey)
	{
		if (currentNode->right == NULL)
		{
			currentNode->right = new KDNode(data);
			return;
		}
		insert(currentNode->right, data, depth + 1);
	}
	else
	{
		if (currentNode->left == NULL)
		{
			currentNode->left = new KDNode(data);
			return;
		}
		insert(currentNode->left, data, depth + 1);
	}
}

//search the given node
KDNode* KDT::search(KDNode *currentNode, KDData data, int depth)
{
	if (currentNode == NULL)
		return NULL;

	int currentNodekey, datakey;
	switch (depth % 2)
	{
	case 0:
		currentNodekey = currentNode->data.x;
		datakey = data.x;
		break;
	case 1:
		currentNodekey = currentNode->data.y;
		datakey = data.y;
		break;
	default:
		break;
	}
	if (currentNode->data.x== data.x && currentNode->data.y ==data.y)
	{
		return currentNode;
	}
	else if (currentNodekey < datakey)
	{
		return search(currentNode->right, data, depth + 1);
	}
	else
	{
		return search(currentNode->left, data, depth + 1);
	}
}

//create the dot file
void KDT::show(KDNode* root, std::string fileName)
{
	std::ofstream outputFile;
	outputFile.open(fileName.c_str());
	outputFile << " digraph G {" << std::endl;
	if (root == NULL)
		return;
	std::queue<KDNode*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty())
	{
		KDNode* current = Q.front();
		// removing the Node at front
		Q.pop(); 

		if (current->left != NULL)
		{
			outputFile << "\"[" << current->data.x << "  " << current->data.y << "  " << current->data.d << "]\"" << " -> " << "\"[" << current->left->data.x << "  " << current->left->data.y << "  " << current->left->data.d << "]\"" << "[tailport=sw];" << std::endl;
			Q.push(current->left);
		}
		if (current->right != NULL)
		{
			outputFile << "\"[" << current->data.x << "  " << current->data.y << "  " << current->data.d << "]\"" << " -> " << "\"[" << current->right->data.x << "  " << current->right->data.y << "  " << current->right->data.d << "]\"" << "[tailport = se];" << std::endl;
			Q.push(current->right);
		}
	}
	outputFile << "}" << std::endl;
	outputFile.close();
}

//find minimum from given number
KDNode* KDT::findMin(KDNode* root, int d, unsigned depth)
{
	if (root == NULL)
		return NULL;

	unsigned cd = depth % 2;

	//if it is same then it should be in right subtree
	if (cd == d)
	{
		if (root->left == NULL)
			return root;
		return findMin(root->left, d, depth + 1);
	}
	//It can be anywhere
	KDNode* left = findMin(root->left, d, depth + 1);
	KDNode* right = findMin(root->right, d, depth + 1);
	KDNode* min;
	if (left == NULL && right == NULL)
	{
		min = root;
	}
	else if (left == NULL)
	{
		min = right;
	}
	else if (right == NULL)
	{
		min = left;
	}
	else
	{
		min = findMinInTwo(left, right, d);
	}
	return findMinInTwo(root, min, d);
}

//find minimum from given two number
KDNode* KDT::findMinInTwo(KDNode* a, KDNode* b, int depth)
{
	int akey, bkey;
	switch (depth % 2)
	{
	case 0:
		akey = a->data.x;
		bkey = b->data.x;
		break;
	case 1:
		akey = a->data.y;
		bkey = b->data.y;
		break;
	default:
		break;
	}
	if (akey <= bkey)
		return a;
	else
		return b;
}


///returns true if contains num
bool KDT::contains(std::vector<int> generatedNumber, int num)
{
	for (int i = 0; i < generatedNumber.size(); i++)
	{
		if (generatedNumber[i] == num)
			return true;
	}
	return false;
}

//used to create random number
int KDT::randomNumber(std::vector<int> generatedNumber, int limit)
{
	int num = rand() % limit;

	while (contains(generatedNumber, num)) //You'll need a function to check whether the num is in this vector
	{
		num = rand() % limit;
	}
	return num;
}

//returns true if generatedNumber contains num
bool KDT::contains2D(std::vector<std::pair<int, int> > generatedNumber, std::pair<int, int> num)
{
	for (int i = 0; i < generatedNumber.size(); i++)
	{
		if (generatedNumber[i] == num)
			return true;
	}
	return false;
}

//to genrate pair if distinct random number
std::pair<int, int> KDT::randomNumber2D(std::vector<std::pair<int, int> > generatedNumber, int limit)
{
	int num1 = rand() % limit;
	int num2;
	do {
		num2 = rand() % limit;
	} while (num1 == num2);

	std::pair<int, int> num;
	num.first = num1;
	num.second = num2;
	while (contains2D(generatedNumber, num)) //You'll need a function to check whether the num is in this vector
	{
		num1 = rand() % limit;
		num2 = rand() % limit;
		num.first = num1;
		num.second = num2;
	}

	return num;
}

//delete the given node
KDNode* KDT::deleteNode(KDNode* currentNode, KDData info, int depth)
{
	if (currentNode == NULL)
		return NULL;

	// Find dimension of current node
	int cd = depth % 2;

	// If the node to be deleted is present at currentNode
	if (currentNode->data.Equals(info))
	{
		if (currentNode->right != NULL)
		{
			KDNode* min = findMin(currentNode->right, cd, depth + 1);

			currentNode->data = min->data;

			currentNode->right = deleteNode(currentNode->right, min->data, depth + 1);
		}
		else if (currentNode->left != NULL) // same as above
		{
			KDNode* min = findMin(currentNode->left, cd, depth + 1);
			currentNode->data = min->data;
			currentNode->right = deleteNode(currentNode->left, min->data, depth + 1);
			currentNode->left = NULL;
		}
		else // If node to be deleted is leaf node
		{
			delete currentNode;
			return NULL;
		}
		return currentNode;
	}


	//If current node doesn't contain the data, search downwards for actual node
	int currentNodekey, datakey;
	switch (depth % 2)
	{
	case 0:
		currentNodekey = currentNode->data.x;
		datakey = info.x;
		break;
	case 1:
		currentNodekey = currentNode->data.y;
		datakey = info.y;
		break;
	default:
		break;
	}

	if (datakey < currentNodekey)
		currentNode->left = deleteNode(currentNode->left, info, depth + 1);
	else
		currentNode->right = deleteNode(currentNode->right, info, depth + 1);
	return currentNode;
}

//measure the height
int KDT::height(KDNode* root)
{
	if (root == NULL)
		return -1;
	else
		return 1 + std::max(height(root->left), height(root->right));
}
