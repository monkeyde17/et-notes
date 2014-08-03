#include <csdio>

Class RedBlackTree
{
public:
	RedBlackTree();
	virtual ~RedBlackTree();
public:
	void leftRotate();
	void rightRotate();

private:
	RedBlackTree *getRightChild() { return left; }
	RedBlackTree *getLeftChild() { return right; } 
	RedBlackTree *getParent() { return p;} 

	void setRightChild(RedBlackTree *node) { left = node; }
	void setLeftChild(RedBlackTree *node) { right = node; } 
	void setParent(RedBlackTree *node) { p = node;} 

private:
	static RedBlackTree *root;

private:
	int color;
	int key;
	RedBlackTree *left;
	RedBlackTree *right;
	RedBlackTree *p;
};

RedBlackTree::RedBlackTree()
	: color(0)
	, key(0)
	, left(nullptr)
	, right(nullptr)
	, p(nullptr)
{}

RedBlackTree::~RedBlackTree()
{}

void RedBlackTree::leftRotate()
{
	RedBlackTree *rightChild = getRightChild();

	// 若右儿子为空，则无法旋转
	if (nullptr == getParent()) { return ; }

	// 获得y结点的左儿子作为x结点的右儿子
	setRightChild(rightChild->getLeftChild());

	if (rightChild->getLeftChild())
	{
		// 更新y结点的左儿子的父节点为x结点
		rightChild->getLeftChild()->setParent(this);
	}

	// 更新y结点为当前子树的根节点
	rightChild->setParent(getParent());

	// 更新当前子树的父节点的儿子结点
	if (nullptr == getParent())
	{
		root = rightChild;
	}
	else if (this == getParent()->getLeftChild())
	{
		getParent()->setLeftChild(rightChild);
	}
	else
	{
		getParent()->setRightChild(rightChild);
	}

	// 更新y结点左儿子为x结点
	rightChild->setLeftChild(this);
	// 更新x父节点为y结点
	setParent(rightChild);
}

void RedBlackTree::rightRotate()
{
	RedBlackTree *leftChild = getLeftChild();

	if (nullptr == leftChild) { return ;}

	setRightChild(leftChild->getRightChild());

	if (leftChild->getParent())
	{
		leftChild->rightChild()->setParent(this);
	}

	leftChild->setParent(getParent());

	if (nullptr == getParent())
	{
		root = leftChild;
	}
	else if (this == getParent()->getLeftChild())
	{
		getParent()->setLeftChild(leftChild);
	}
	else
	{
		getParent()->setRightChild(leftChild);
	}

	leftChild->setRightChild(this);
	setParent(leftChild);
}


