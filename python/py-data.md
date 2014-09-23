python数据
==========

## 列表

```py
# This is my shopping list
shoplist = ['apple', 'mango', 'carrot', 'banana']

print 'I have', len(shoplist),'items to purchase.'

print 'These items are:', # 注意末尾的逗号
for item in shoplist:
	print item,
print '\nI also have to buy rice.'
shoplist.append('rice')
print 'My shopping list is now', shoplist

print 'I will sort my list now' 
shoplist.sort()
print 'Sorted shopping list is', shoplist

print 'The first item I will buy is', shoplist[0] 
olditem = shoplist[0]
del shoplist[0]
print 'I bought the', olditem
print 'My shopping list is now', shoplist
```

## 元组

**元组不可变**

```py
zoo=("wolf", "elephant", "penguin")
print "number of animals in the zoo is", len(zoo)

new_zoo=("monkey", "dolphin", zoo)
print "number of animals in the new zoo is", len(new_zoo)
print "all animals in new zoo are", new_zoo
print "animals brought from old zoo are", new_zoo[2]
print "last animal brought from old zoo is", new_zoo[2][2]
```

常用于打印

```py
age = 22
name = 'Swaroop'
print '%s is %d years old' % (name, age)
print 'Why is %s playing with that python?' % name
```

## 字典

**字典键必须唯一**

```py
ab = {
	'Swaroop' : 'swaroopch@byteofpython.info', 'Larry' : 'larry@wall.org',
	'Matsumoto' : 'matz@ruby-lang.org',
	'Spammer' : 'spammer@hotmail.com' 
}
print "Swaroop's address is %s" % ab['Swaroop']

# 添加
ab['Guido'] = 'guido@python.org'

# 删除
del ab['Spammer']

print '\nThere are %d contacts in the address-book\n' % len(ab) for name, address in ab.items():

print 'Contact %s at %s' % (name, address)

if 'Guido' in ab: # 或者是 ab.has_key('Guido')
	print "\nGuido's address is %s" % ab['Guido']
```

## 序列

序列：

* 索引操作 ：获取序列中一个项目
* 切片操作 ：获取序列中一段项目

列表，元组，字典都是序列。

```py
shoplist = ['apple', 'mango', 'carrot', 'banana']

# Indexing or 'Subscription' operation 
print 'Item 0 is', shoplist[0]
print 'Item 1 is', shoplist[1]
print 'Item 2 is', shoplist[2]
print 'Item 3 is', shoplist[3] 
print 'Item -1 is', shoplist[-1] 
print 'Item -2 is', shoplist[-2]

# Slicing on a list
print 'Item 1 to 3 is', shoplist[1:3] 
print 'Item 2 to end is', shoplist[2:] 
print 'Item 1 to -1 is', shoplist[1:-1] 
print 'Item start to end is', shoplist[:]

# Slicing on a string
name = 'swaroop'
print 'characters 1 to 3 is', name[1:3] 
print 'characters 2 to end is', name[2:] 
print 'characters 1 to -1 is', name[1:-1] 
print 'characters start to end is', name[:]
```

> 索引负数-n表示倒数第n个

> 切片操作 list[n:m] ---- 从n开始到m结束
> list[:] 返回整个序列的**拷贝**

## 引用

```py
print 'Simple Assignment'
shoplist = ['apple', 'mango', 'carrot', 'banana']
mylist = shoplist # 引用
del shoplist[0] # 删除shoplist的一个项目

print 'shoplist is', shoplist
print 'mylist is', mylist

# 注意两者之间的不同之处

print 'Copy by making a full slice'
mylist = shoplist[:] # 获得shoplist的全拷贝
del mylist[0] # 删除mylist第一个项目
print 'shoplist is', shoplist
print 'mylist is', mylist
```

