第 12 章 二叉查找树
===================

在二叉查找树(binary search tree)上执行时间和树的高度成正比。

## 12\.1 二叉查找树

二叉查找树数据域：

* key
* 卫星数据？
* left
* right
* p（父节点）

二叉查找树性质：

假设x为二叉查找树中的一个点

1. 如果y是x的左子树中的一个点，则key[y] <= key[x]
2. 如果y是x的右子树中的一个点，则key[y] >= key[x]


中序遍历二叉树：

* 递归算法

```cpp
void BinarySearchTree::inorder(BinarySearchTree *x)
{
    if (x)
    {
        inorder(x->getLeftChild());
        x->print();
        inorder(x->getRightChild());
    }
}
```

* 迭代，辅助栈

```cpp
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
```

* 迭代，无辅助栈

```cpp
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
```

## 12\.2 查询二叉查找树

> 查找

* 递归版

```cpp
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
```

* 迭代

```cpp
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
```

> 最大元素和最小元素

* 最小

```cpp
BinarySearchTree *BinarySearchTree::getMin(BinarySearchTree *node)
{
    while (node->getLeftChild())
    {
        node = node->getLeftChild();
    }
    return node;
}
```

* 最大

```cpp
BinarySearchTree *BinarySearchTree::getMax(BinarySearchTree *node)
{
    while (node->getRightChild())
    {
        node = node->getRightChild();
    }
    return node;
}
```

* 前驱和后继

```cpp
//wait for a moment
```


## 12\.3 插入和删除

* 插入

```cpp
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
```

