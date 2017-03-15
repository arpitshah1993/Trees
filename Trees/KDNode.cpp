
#include "KDNode.h"
#include <cstdlib>

KDNode::KDNode()
{
}

KDNode::KDNode(KDData info)
{
	data = info;
	left = right = NULL;
}

KDNode::~KDNode()
{
}

KDData::KDData()
{
}

KDData::KDData(int a, int b, int c)
{
	x = keyValue(a);
	y = 500-keyValue(b);
	d = c;
}

KDData::~KDData()
{
}



bool KDData::Equals(KDData info)
{
	if (x == info.x && y == info.y && d == info.d)
		return true;
	else
		return false;
}
int KDData::keyValue(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 500;
	}
	else
	{
		int i = keyValue(n - 1);
		int j = keyValue(n - 2);
		return (i + j) / 2;
	}
}
