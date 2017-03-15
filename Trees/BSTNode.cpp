
#include "BSTNode.h"

#include <cstddef>

BSTNode::BSTNode()
{
}

BSTNode::BSTNode(data info)
{
	node = info;
	left = NULL;
	right = NULL;
}

BSTNode::~BSTNode()
{
}

data::data()
{
}
data::~data()
{
}

data::data(int k, int v)
{
	key = keyValue(k);
	value = v;
}

int data::keyValue(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1000;
	}
	else
	{
		int i = keyValue(n - 1);
		int j = keyValue(n - 2);
		return (i + j) / 2;
	}
}


