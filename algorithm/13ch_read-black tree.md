第 13 章 红黑树
===============

## 13\.1 红黑树性质

红黑树是一种查找二叉树，**红黑树确保没有一条路径会比其他路径长出两倍，因而是接近平衡的。**

红黑树节点域

* color
* key
* left
* right
* p(父节点)

红黑树性质：

* 每个结点不是红的就是黑的
* 根结点是黑的
* 每个叶结点(NIL)是黑的
* 如果一个结点是红的，那么它的两个字结点是黑的
* 对于每个结点，从该结点到子孙结点的所有路径上包含相同数目的黑结点。

从某个结点`x`出发（不包括该结点）到达一个子叶结点的任意一条路上，黑色结点的个数称为该结点的`黑高度`，用`bh(x)`表示。

## 13\.2 旋转

指针结构的修改是通过`旋转`来完成，这是一种能保持二叉查找树性质的`查找树局部操作`。

当在某个**结点x**上做**左旋**时， 它的**右孩子y**不是**nil**，即x可以为树内任意右孩子不为nil的结点。

* **左旋**以x到y之间的链为支轴进行。
* 使y成为该子树新的`根`
* x成为y的`左孩子`
* y的左孩子成为x的`右孩子`

代码如下：

```cpp
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
```

右旋代码：
```cpp
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
```