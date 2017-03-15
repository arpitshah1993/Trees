// main.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include <cstdlib>
#include "BST.h"
#include "BSTNode.h"
#include "KDT.h"
#include<time.h>
#include <iomanip>
#include<math.h>
#include<vector>
#include <math.h>
#include <stdint.h>
#include<sstream>

namespace std {
    template<typename T>
    std::string to_string(const T &n) {
        std::ostringstream s;
        s << n;
        return s.str();
    }
}

int main()
{
	std::vector<int> genratedNumber;
	srand(time(NULL));

	//Case:1
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:1"<<std::endl;
	BST T1;
	std::vector<data> Lis1Temp;
	for (int i = 0; i <= 15; i++)
	{
		data info(i, i);
		T1.insert(info, T1.root);
		Lis1Temp.push_back(info);
	}
	std::cout << "Created t1.dot file for this case" << std::endl;
	T1.show(T1.root,"t1.dot");

	//Case: 2
	std::cout << "Demonstrating Case:2"<<std::endl;
	KDT T2;
	std::vector<KDData> Lis2Temp;
	for (int i = 0; i <= 15; i++)
	{
		KDData info(i, i,i);
		T2.insert(T2.root,info,0);
		Lis2Temp.push_back(info);
	}
	std::cout << "Created t2.dot file for this case" << std::endl;
	T2.show(T2.root, "t2.dot");


	//Case:3
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:3" << std::endl;
	BST T3;
	
	std::cout << std::setw(40) << "n = No. of Nodes in the tree" << std::setw(20) << "Height of BST T3" << std::setw(10) << "lgn" << std::setw(8)<<"sqroot(n)"<<std::endl;
	std::cout << std::string(80, '=') << std::endl;
	for (int i = 0; i < 201; i++)
	{
		if (i % 20 == 0)
		{
			std::cout << std::setw(40) << i << std::setw(20) << T3.height(T3.root) << std::setw(10) << log(i) << std::setw(8) << sqrt(i) << std::endl;
		}
		data info;
		info.key = T3.randomNumber(genratedNumber,INT32_MAX);
			genratedNumber.push_back(info.key);
		info.value = i;
		T3.insert(info, T3.root);
	}
	genratedNumber.clear();

	//Case:4
	std::vector<std::pair<int,int> > genratedNumber2d;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:4" << std::endl;
	KDT T4;
	srand(time(NULL));
	std::cout << std::setw(40) << "n = No. of Nodes in the tree" << std::setw(20) << "Height of BST T4" << std::setw(10) << "lgn" << std::setw(12)<<"sqroot(n)"<<std::endl;
	std::cout << std::string(80, '=') << std::endl;
	for (int i = 0; i < 201; i++)
	{
		if (i % 20 == 0)
		{
			std::cout << std::setw(40) << i << std::setw(20) << T4.height(T4.root) << std::setw(10) << log(i) << std::setw(12) << sqrt(i) << std::endl;
		}
		KDData info;
		std::pair<int, int> num = T4.randomNumber2D(genratedNumber2d, 51);
		info.x = num.first;
		info.y = num.second;
		genratedNumber2d.push_back(num);
		info.d = i;
		T4.insert(T4.root,info,0);
	}
	genratedNumber.clear();
	genratedNumber2d.clear();

	//Case:5
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:5" << std::endl;
	BST T5;
	for (int i = 0; i < 10 ; i++)
	{
		int randomnumber = T5.randomNumber(genratedNumber, 16);
			genratedNumber.push_back(randomnumber);
			data info = Lis1Temp[randomnumber];
			T5.insert(info, T5.root);
	}
	std::cout << "Created t5-a.dot file for this case" << std::endl;
	T5.show(T5.root,"t5-a.dot");
	std::cout << "Deleting the root node of List5" << std::endl;
	T5.root= T5.deleteNodes(T5.root, T5.root->node);
	std::cout << "Created t5-b.dot file for this case" << std::endl;
	T5.show(T5.root, "t5-b.dot");
	genratedNumber.clear();

	//Case:6
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:6" << std::endl;
	KDT T6;
	for (int i = 0; i < 10 ; i++)
	{
		int randomnumber = T6.randomNumber(genratedNumber, 16);
		genratedNumber.push_back(randomnumber);
		KDData info=Lis2Temp[randomnumber];
		T6.insert(T6.root,info,0);
	}
	std::cout << "Created t6-a.dot file for this case" << std::endl;
	T6.show(T6.root, "t6-a.dot");
	std::cout << "Deleting the root node of List6" << std::endl;
	T6.deleteNode(T6.root, T6.root->data, 0);
	std::cout << "Created t6-b.dot file for this case" << std::endl;
	T6.show(T6.root, "t6-b.dot");
	genratedNumber.clear();



	//Case:7
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:7" << std::endl;
	BST T7;
	int i = 1;
	for (int j = 1; j <= 20; j++)
	{
		if (i == 11)
		{
			i = 1;
		}
		data info(i, j);
		T7.insert(info, T7.root);
		i++;
	}
	std::cout << std::setw(5) << "Stage" << std::setw(30) << "data item at root" << std::setw(30) << "the root (after deletion)" << std::setw(30) << "search for data with key" << std::endl;
	std::cout << std::string(100, '=') << std::endl;
	for (int b = 0; b < 20; b++)
	{
		data infoToSearch = T7.root->node;
		T7.root = T7.deleteNodes(T7.root, infoToSearch);
		
		BSTNode* duplicateNode = T7.search(infoToSearch.key, T7.root);
		//to search  more than one node since this case has probability of having 
		//duplicate nodes while searching
		std::string bstData="";
		if (duplicateNode == NULL)
		{
			bstData = "nil";
		}
		else
		{
			while (duplicateNode != NULL)
			{
				bstData += "[" + std::to_string(duplicateNode->node.key) + "  " + std::to_string(duplicateNode->node.value) + "]; ";
				duplicateNode = T7.search(infoToSearch.key, duplicateNode->left);
			}

		}
		
		std::string rootAfterDeletion= T7.root == NULL ? "nil" : "[" + std::to_string(T7.root->node.key) + "  " + std::to_string(T7.root->node.value) + "]";
		std::cout << std::setw(5) << b << std::setw(30) << "[" << infoToSearch.key << "  " << infoToSearch.value << "]" << std::setw(30) << rootAfterDeletion << std::setw(30) << bstData << std::endl;
		if (b == 10)
		{
			T7.show(T7.root, "t7.dot");
			std::cout << "**Creating dot file t7.dot for Stage 10**"<<std::endl;
		}
	}


	//Case:8
	std::cout << std::string(100, '*') << std::endl;
	std::cout << std::string(100, '*') << std::endl;
	std::cout << "Demonstrating Case:8" << std::endl;
	KDT T8;
	std::vector<KDData> Lis8Temp;
	i = 1;
	int j = 1;
	for (int s = 1; s <= 18; s++,i++,j++)
	{
		if (s == 7)
		{
			i = 1;
		}
		if (s == 13)
		{
			j = 1;
		}
		KDData info(i, j, s);
		T8.insert(T8.root, info, 0);
		Lis8Temp.push_back(info);
	}
	i = 0;
	j = 18;
	std::cout << "OutPut Search Node:" << std::endl;
	while (T8.root != NULL)
	{
		T8.root = T8.deleteNode(T8.root, T8.root->data,0);
		j--;
		if (j == 12)
		{
			T8.show(T8.root, "t8 - a.dot");
			std::cout << "**Creating dot file t8 - a.dot **" << std::endl;
		}
		if (j == 6)
		{
			T8.show(T8.root, "t8 - b.dot");
			std::cout << "**Creating dot file t8 - b.dot **" << std::endl;
		}
		std::cout << "After delete Operation:" << i + 1 << std::endl;
		std::cout << "Searching" << i << "th node of the list" << std::endl;
		int depth = 0;
		KDNode* searchedNode= T8.search(T8.root, Lis8Temp[i], depth%2);
		
		//to search  more than one node since this case has probability of having 
		//duplicate nodes while searching
		if (searchedNode != NULL)
			while (searchedNode != NULL)
			{
				depth++;
				std::cout <<"[" <<searchedNode->data.x << "  " << searchedNode->data.y << "  " << searchedNode->data.d <<"]"<< std::endl;
				searchedNode = T8.search(searchedNode->left, Lis8Temp[i], depth % 2);
			}
		else
			std::cout << "Null"<<std::endl;
		i ++;
	}	
return 0;
}

