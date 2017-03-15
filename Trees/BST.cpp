
#include "BST.h"
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<queue>
#include<fstream>


BST::BST()
{
	root = NULL;
}

BST::~BST()
{
}

//insert the node
void BST::insert(data info, BSTNode* currentNode)
{
	if (root == NULL)
	{
		root = new BSTNode(info);
		return;
	}
	if (currentNode->node.key < info.key)
	{
		if (currentNode->right == NULL)
		{
			currentNode->right = new BSTNode(info);
			return;
		}
		else
		{
			insert(info, currentNode->right);
		}
	}
	if (currentNode->node.key >= info.key)
	{
		if (currentNode->left == NULL)
		{
			currentNode->left = new BSTNode(info);
			return;
		}
		else
		{
			insert(info, currentNode->left);
		}
	}
}

//measure the height
int BST::height(BSTNode* root)
{
	if (root == NULL)
		return -1;
	else
		return 1 + std::max(height(root->left), height(root->right));
}

//search the given node
BSTNode* BST::search(int ikey, BSTNode* currentNode)
{
	if (currentNode == NULL)
		return NULL;
	if (currentNode->node.key == ikey)
	{
		return currentNode;
	}
	else if (currentNode->node.key < ikey)
	{
		search(ikey, currentNode->right);
	}
	else if (currentNode->node.key > ikey)
	{
		search(ikey, currentNode->left);
	}
}

//Find the minimum value
BSTNode* BST::FindMin(BSTNode* root) {
	while (root->left != NULL && ((root->node.key!=root->left->node.key)|| (root->node.key == root->left->node.key && root->left->left != NULL))) root = root->left;
	return root;
}

//delete the given node
BSTNode* BST::deleteNodes(BSTNode* currentNode, data data)
{
	if (currentNode == NULL) return currentNode;
	else if (data.key < currentNode->node.key || (data.key == currentNode->node.key && data.value!= currentNode->node.value)) currentNode->left = deleteNodes(currentNode->left, data);
	else if (data.key > currentNode->node.key) currentNode->right = deleteNodes(currentNode->right, data);
	else {
		// No Child
		if (currentNode->left == NULL && currentNode->right == NULL) {
			delete currentNode;
			currentNode = NULL;
			
		}
		// for one child
		else if (currentNode->left == NULL) {
			BSTNode* temp = currentNode;
			currentNode = currentNode->right;
			delete temp;
		}
		else if (currentNode->right == NULL) {
			BSTNode* temp = currentNode;
			currentNode = currentNode->left;
			delete temp;
		}
		else {
			BSTNode* temp = FindMin(currentNode->right);
			currentNode->node = temp->node;
			currentNode->right = deleteNodes(currentNode->right, temp->node);
		}
	}
	return currentNode;
}

//return true if generatedNumber contains number
bool BST::contains(std::vector<int> generatedNumber, int num)
{
	for (int i = 0; i < generatedNumber.size(); i++)
	{
		if (generatedNumber[i] == num)
			return true;
	}
	return false;
}

//to generate distinct random number
int BST::randomNumber(std::vector<int> generatedNumber, int limit)
{
	int num = rand() % limit;

	while (contains(generatedNumber, num)) 
	{
		num = rand() % limit;
	}
	return num;
}

//create dot file
void BST::show(BSTNode* root, std::string fileName)
{
	std::ofstream outputFile;
	outputFile.open(fileName.c_str());
	outputFile << " digraph G {" << std::endl;
	if (root == NULL)
		return;
	std::queue<BSTNode*> Q;
	Q.push(root);
	//while at least one discovered node found
	while (!Q.empty())
	{
		BSTNode* current = Q.front();
		Q.pop(); 
				 
		if (current->left != NULL)
		{
			outputFile << "\"[" << current->node.key << "  " << current->node.value << "]\"" << " -> " << "\"[" << current->left->node.key << "  " << current->left->node.value << "]\"" << "[tailport=sw];" << std::endl;
			Q.push(current->left);
		}
		if (current->right != NULL)
		{
			outputFile << "\"[" << current->node.key << "  " << current->node.value << "]\"" << " -> " << "\"[" << current->right->node.key << "  " << current->right->node.value << "]\"" << "[tailport=se];" << std::endl;
			Q.push(current->right);
		}
	}
	outputFile << "}" << std::endl;
	outputFile.close();
}





