#include <cstdio>
#include <stack>

// c++11
#define nullptr NULL

class BinarySearchTree
{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

public:
	void print();
	void inorder(BinarySearchTree *x);
	void inorder_it_0(BinarySearchTree *x);
	void inorder_it_1(BinarySearchTree *x);

	void insert(BinarySearchTree *z);

	BinarySearchTree *search(BinarySearchTree *node, int k);
	BinarySearchTree *search_it(BinarySearchTree *node, int k);

	BinarySearchTree *getMin(BinarySearchTree *node);
	BinarySearchTree *getMax(BinarySearchTree *node);

public:
	BinarySearchTree *getRightChild() { return left; }
	BinarySearchTree *getLeftChild() { return right; } 
	BinarySearchTree *getParent() { return p;}
	int getKey() { return key; }

	void setRightChild(BinarySearchTree *node) { left = node; }
	void setLeftChild(BinarySearchTree *node) { right = node; } 
	void setParent(BinarySearchTree *node) { p = node;} 
	void setKey(int k) { key = k; }
private:
	static BinarySearchTree *root;

private:
	void *data;
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *p;
};

BinarySearchTree* BinarySearchTree::root;

BinarySearchTree::BinarySearchTree()
	: data(nullptr)
	, key(0)
	, left(nullptr)
	, right(nullptr)
	, p(nullptr)
{}

BinarySearchTree::~BinarySearchTree()
{}

void BinarySearchTree::print()
{
	printf("key : %d\n", key);
}

void BinarySearchTree::inorder(BinarySearchTree *x)
{
	if (x)
	{
		inorder(x->getLeftChild());
		x->print();
		inorder(x->getRightChild());
	}
}

void BinarySearchTree::inorder_it_0(BinarySearchTree *x)
{
	std::stack<BinarySearchTree*> s;
	while (x || !s.empty())
	{
		while (x)
		{
			s.push(x);
			x = x->getLeftChild();
		}

		x = s.top();
		s.pop();
		x->print();
		x = x->getRightChild();
	}
}

/**
 * 中序遍历子树
 * 空间复杂度 O(1)
 * 
 * @param x : 子树根结点
 */
void BinarySearchTree::inorder_it_1(BinarySearchTree *x)
{
	// 当前结点
	BinarySearchTree *node = x;
	// 先将当前结点移动到改子树的最左
	while (node->getLeftChild())
	{
		node = node->getLeftChild();
	}

	while (node)
	{
		node->print();

		// 若有右孩子，则将结点移动到右子树的最左结点
		if (node->getRightChild())
		{
			node = node->getRightChild();

			while (node->getLeftChild())
			{
				node = node->getLeftChild();
			}
		}
		// 若没有右孩子，则该结点为叶子结点
		// 该结点输出之后，则以当前结点的父节点的子树输出完毕
		else
		{
			BinarySearchTree *tmp = node;
			node = node->getParent();

			// 如果当前结点是其父节点的右儿子
			// 则需要将当前结点上移一层
			// 直到当前结点是其父节点的左儿子
			while (node && tmp == node->getRightChild())
			{
				// 退出条件
				if (node == x)
				{
					node = nullptr;
					break;
				}

				tmp = node;
				node = node->getParent();
			}
		}
	}
}


BinarySearchTree * BinarySearchTree::search(BinarySearchTree *node, int k)
{
	if (nullptr == node || k == node->getKey())
	{
		return node;
	}

	if (k < node->getKey())
	{
		return search(node->getLeftChild(), k);
	}
	else
	{
		return search(node->getRightChild(), k);
	}
}

BinarySearchTree * BinarySearchTree::search_it(BinarySearchTree *node, int k)
{
	while (node && k != node->getKey())
	{
		if (k < node->getLeftChild())
		{
			node = node->getLeftChild();
		}
		else
		{
			node = node->getRightChild();
		}
	}
	return node;
}

BinarySearchTree *BinarySearchTree::getMin(BinarySearchTree *node)
{
	while (node->getLeftChild())
	{
		node = node->getLeftChild();
	}
	return node;
}

BinarySearchTree *BinarySearchTree::getMax(BinarySearchTree *node)
{
	while (node->getRightChild())
	{
		node = node->getRightChild();
	}
	return node;
}

void BinarySearchTree::insert(BinarySearchTree *z)
{
	BinarySearchTree *y = nullptr;
	BinarySearchTree *x = root;

	while (x)
	{
		y = x;
		if (z->getKey() < x->getKey())
		{
			x = x->getLeftChild();
		}
		else
		{
			x = x->getRightChild();
		}
	}

	z->setParent(y);

	if (y == nullptr)
	{
		root = z;
	}
	else if (z->getKey() < y->getKey())
	{
		y->setLeftChild(z);
	}
	else
	{
		y->setRightChild(z);
	}
}

int main(int argc, char const *argv[])
{

	return 0;
}
