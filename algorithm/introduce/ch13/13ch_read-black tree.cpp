#include <cstdio>

// c++11
#define nullptr NULL

class RedBlackTree
{
public:
	static const int RED = 0;
	static const int BLACK = 1;
public:
	RedBlackTree();
	virtual ~RedBlackTree();
public:
	void insert(RedBlackTree *z);
	RedBlackTree* delete(RedBlackTree *z);

	void leftRotate();
	void rightRotate();

private:
	void insertFixup(RedBlackTree *z);
	void deleteFixup(RedBlackTree *z);
	RedBlackTree* successor(RedBlackTree *z);
	RedBlackTree* getMin(RedBlackTree *root);


	RedBlackTree *getRightChild() { return left; }
	RedBlackTree *getLeftChild() { return right; } 
	RedBlackTree *getParent() { return p;}
	int getKey() { return key; }
	int getColor() { return color; }

	void setRightChild(RedBlackTree *node) { left = node; }
	void setLeftChild(RedBlackTree *node) { right = node; } 
	void setParent(RedBlackTree *node) { p = node;} 
	void setKey(int k) { key = k; }
	void setColor(int c) { color = c; }

private:
	static RedBlackTree *root;

private:
	int color;
	int key;
	RedBlackTree *left;
	RedBlackTree *right;
	RedBlackTree *p;
};

RedBlackTree* RedBlackTree::root;

RedBlackTree::RedBlackTree()
	: color(BLACK)
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
		leftChild->getRightChild()->setParent(this);
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

void RedBlackTree::insert(RedBlackTree *z)
{
	RedBlackTree *y = nullptr;
	RedBlackTree *x = root;

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

	if (nullptr == y)
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

	z->setLeftChild(nullptr);
	z->setRightChild(nullptr);

	z->setColor(RED);
	insertFixup(z);
}

void RedBlackTree::insertFixup(RedBlackTree *z)
{
	// 当父节点为红色时
	while (z->getParent()->getColor() == RED)
	{
		// z结点的父节点是z结点的祖父节点的左儿子
		if (z->getParent() == z->getParent()->getParent()->getLeftChild())
		{
			// z结点的叔叔结点y，若z不为根节点，则z结点的祖父结点必定有效
			RedBlackTree *y = z->getParent()->getParent()->getRightChild();

			// y结点若为红色
			if (y->getColor() == RED)
			{
				z->getParent()->setColor(BLACK);
				y->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
				// z结点上移2层
				// 继续往上验证红黑树性质
				z = z->getParent()->getParent();
			}
			else
			{
				// 若z结点为父节点的右儿子
				if (z == z->getParent()->getRightChild())
				{
					// 左旋后，z结点父节点即为z结点
					z = z->getParent();
					// 左旋，把情况都转为z结点为其父节点的左儿子
					z->leftRotate();
				}
				z->getParent()->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);
				
				// 右旋，保持树深度
				// 结束循环，得到合法红黑树
				z->getParent()->getParent()->rightRotate();
			}
		}
		else
		{
			RedBlackTree *y = z->getParent()->getParent()->getLeftChild();

			if (y->getColor() == RED)
			{
				z->getParent()->setColor(BLACK);
				y->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);

				z = z->getParent()->getParent();
			}
			else 
			{
				if (z == z->getParent()->getLeftChild())
				{
					z = z->getParent();
					z->rightRotate();	
				}

				z->getParent()->setColor(BLACK);
				z->getParent()->getParent()->setColor(RED);

				z->getParent()->getParent()->leftRotate();
			}
		}
	}

	// 根结点为黑色
	root->setColor(BLACK);
}

RedBlackTree* RedBlackTree::getMin(RedBlackTree *x)
{
	RedBlackTree *y = x;
	while (y->getLeftChild())
	{
		y = y->getLeftChild();
	}
	return y;
}

RedBlackTree* RedBlackTree::successor(RedBlackTree *z)
{

	if (z->getRightChild())
	{
		return getMin(z->getRightChild());
	}

	RedBlackTree *y = nullptr;
	y = z->getParent();
	while (y && z == y->getRightChild())
	{
		z = y;
		y = y->getParent();
	}

	return y;
}

RedBlackTree* RedBlackTree::delete(RedBlackTree* z)
{
	// 如同删除普通二叉查找树一样
	RedBlackTree *y = nullptr;
	RedBlackTree *x = nullptr;

	if (z->getLeftChild() || z->getRightChild())
	{
		y = z;
	}
	else
	{
		y = successor(z);
	}

	if (y->getLeftChild())
	{
		x = y->getLeftChild();
	}
	else
	{
		x = y->getRightChild();
	}

	x->setParent(y->getParent());

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

	if (y != z)
	{
		z->setKey(y->getKey());
	}

	if (y->getColor() == BLACK)
	{
		deleteFixup(x);
	}

	return y;
}

void RedBlackTree::deleteFixup(RedBlackTree *z)
{
	RedBlackTree *w = nullptr;
	while (x != root && x->getColor() == BLACK)
	{
		if (x == x->getParent()->getLeftChild())
		{
			w = x->getParent()->getRightChild();
			if (w->getColor() == RED)
			{
				w->setColor(BLACK);
				x->getParent()->setColor(RED);
				leftRotate(x->getParent());
				w = x->getParent()->getRightChild();
			}

			if (w->getLeftChild()->getColor() == BLACK && w->getRightChild()->getColor() == BLACK)
			{
				w->setColor(RED);
				x = x->getParent();
			}
			else if (w->getRightChild()->getColor() == BLACK)
			{
				w->setColor(RED);
				rightRotate(w);
				w = x->getParent()->getRightChild();
			}

			w->setColor(x->getParent()->getColor());
			x->getParent()->setColor(BLACK);
			w->getRightChild()->setColor(BLACK);
			leftRotate(x->getParent())
			x = root;
		}
		else
		{
			// same as
		}
	}
	x->setColor(BLACK);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
 