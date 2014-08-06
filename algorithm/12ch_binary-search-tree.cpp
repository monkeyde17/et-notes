#include <cstdio>

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
	void *data;
	int key;
	BinarySearchTree *left;
	BinarySearchTree *right;
	BinarySearchTree *p;
};

BinarySearchTree::BinarySearchTree()
{}

BinarySearchTree::~BinarySearchTree()
{}

void BinarySearchTree::print()
{
	printf("key : %d", key);
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
	BinarySearchTree *r = x;

	while (x)
	{
		BinarySearchTree *q = x->getLeftChild();

		if (q)
		{
			while (q != r && q->getRightChild())
			{
				q = q->getRightChild();
			}

			if (q != r)
			{
				q->setRightChild(p);
				p = p->getLeftChild();
				continue ;
			}
			else
			{
				q->setRightChild(nullptr);
			}
		}

		p->print();

		r = p;
		p = p->getRightChild();
	}
}

void BinarySearchTree::inorder_it_1(BinarySearchTree *x)
{
	BinarySearchTree *t = x;
	BinarySearchTree *pLastLeft = nullptr;
	BinarySearchTree *pLastRight = nullptr;
	BinarySearchTree *pLastMid = nullptr;

	while (t != x)
	{
		while (t->getLeftChild() != pLastLeft)
		{
			t = t->getLeftChild();
		}
		t->print();
		pLastLeft = t;

		if (t->getRightChild())
		{
			if (t->getLeftChild()->getLeftChild() == nullptr)
			{
				t->get
			}
		}


	}
}