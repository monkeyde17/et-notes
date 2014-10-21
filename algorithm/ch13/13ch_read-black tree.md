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

1. 每个结点不是红的就是黑的
2. 根结点是黑的
3. 每个叶结点(NIL)是黑的
4. 如果一个结点是红的，那么它的两个字结点是黑的
5. 对于每个结点，从该结点到子孙结点的所有路径上包含相同数目的黑结点。

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

## 13\.3 插入

假设`key`事先被赋值
可能被破坏的红黑树性质：

* 根节点为黑色的性质2
* 红色结点不能有红子女结点的性质4

> 至多只有一个性质被破坏。只有是根节点的时候才会破坏性质2，否则只会破坏性质4

* 若z结点`父节点`为`根节点`，那么该`父节点`为黑色。由此可知，当z结点`父节点`为`红色`且不为`根节点`时，z结点其祖父结点必定有效。

---------------------

插入分3中情况：

* 1\. z的叔叔y是红色

> * z的父亲和y着色为黑色
> * z的祖父着色为红色
> * 将z上移两层，进行下次迭代

* 2\. z的叔叔y是黑色的，而且z是右孩子

> * 以z的父节点左旋一次，使z成为左孩子，进入第三种情况

* 3\. z的叔叔y是黑色的，而且z是左孩子

> * z的父亲着色为黑色
> * z的祖父作色为红色
> * 以z的祖父结点右旋一次，保持红黑树深度，结束循环！

* 最后，将根节点着色为黑色！

```cpp
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
```

## 13\.4 删除

如果被删除的y结点是红色的，则当y结点删除后，红黑性质仍然得以保持。理由如下

* 树中各节点的黑高度都没变化。
* 不存在两个相邻的红色结点
* 如果y结点是红色的，就不可能是根节点。

如果被删除的结点是黑色的，则会产生3个问题：

1. 如果y原来的是根节点，而y的一个红儿子成为了新的根，这就违反了性质2
2. 如果x和y的父节点(也是x的父节点)都是红的，就违反了性质4
3. 删除y将导致先前包含y的任何路径上黑结点个数少1。因此性质5就被y的一个祖先给破坏了。为解决这个问题，就是把结点x视为还有额外的一重黑色。即将任意包含结点x的路径上黑色结点数加1，则性质5成立。将黑色结点y删除时，将黑色下推至其字节点。问题就变成结点x可能既不是红，也不是黑，从而违反了性质1。



```cpp
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


```