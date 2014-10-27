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

	BinarySearchTree* successor(BinarySearchTree *x);
	BinarySearchTree* pre_successor(BinarySearchTree *x);

	BinarySearchTree* delete(BinarySearchTree *z);
public:
	BinarySearchTree *getMin(BinarySearchTree *node);
	BinarySearchTree *getMax(BinarySearchTree *node);

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

/**
 * 中序后继
 */
BinarySearchTree* BinarySearchTree::successor(BinarySearchTree *x)
{
	// 若当前结点右子树非空，则x的后继就是右子树的最左结点
	if (x->getRightChild())
	{
		return getMin(x->getRightChild());
	}

	BinarySearchTree *y = x->getParent();

	while (y && x == y->getRightChild())
	{
		x = y;
		y = y->getParent();
	}

	return y;
}

/**
 * 中序前驱
 */
BinarySearchTree* BinarySearchTree::pre_successor(BinarySearchTree *x)
{
	if (x->getRightChild())
	{
		return getMax(x->getLeftChild());
	}

	BinarySearchTree *y = x->getParent();

	while (y && x == y->getLeftChild())
	{
		x = y;
		y = y->getParent();
	}
	return y;
}

BinarySearchTree* BinarySearchTree::delete(BinarySearchTree *z)
{
	BinarySearchTree *y = nullptr;
	BinarySearchTree *x = nullptr;

	// 若z结点只有一个子女
	if (z->getLeftChild() == nullptr || z->getRightChild() == nullptr)
	{
		y = z;
	}
	else
	{
		y = successor(z);
	}

	// 获取左儿子，只在z结点只有一个子女的情况下
	if (y->getLeftChild())
	{
		x = y->getLeftChild();
	}
	// 在两个子女的情况下，永远是这种情况
	else
	{
		x = x->getRightChild();
	}

	// 更新后继的子女
	if (x)
	{
		x->setParent(y->getParent());
	}

	// 根节点的情况
	if (y->getParent() == nullptr)
	{
		root = x;
	}
	else if (y == y->getParent()->getLeftChild())
	{
		y->getParent()->setLeftChild(x);
	}
	else
	{
		y->getParent()->setRightChild(x);
	}

	// 复制数据，更新key
	// 就无须重新制定父子关系
	if (y != z)
	{
		z->setKey(y->getKey());
		// 复制y结点的存储数据到z结点
	}

	return y;
}

int main(int argc, char const *argv[])
{

	return 0;
}
