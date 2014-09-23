python基础
==========

## 数据类型

### 数

* 整数
* 长整数
* 浮点数
* 复数 (-5+4j)

### 字符串

* 单引号

```py
'this is a string'
```

* 双引号

```py
"You're preaty good"
```

* 三引号

```py
'''
"What's this"
this is a pan
'''
```

* 转义符

```py
# 转义
'what\'s your name?'

# 链接两行
'Hello \
world'
```

* 自然字符串

```py
r'This is a new line \n'
```

* unicode字符串

```py
u'This is unicode string'
```

> 字符串不可变

> 字面意义级联字符串


### 变量

弱类型=。=


## 运算符表达式

* \*\* 幂
* //   取整除
* not
* and
* or

-------------------------------------------------------------------------------

## 控制语句

### 条件语句

```py
if True:
	print 'Yes, it is true'

if a == 1:
	print 'a = 1'
elif a == 2:
	print 'a = 2'
else:
	print 'a = other value'
```

> python 中没有switch语句

### while循环

```py
running = True

while running:
	print 'do some thing'
	running = False
else:
	print 'while is end'
```

### for循环

```py

for i in range(1, 5):
	print i
else:
	print 'loop is end'
```

> break, continue 如同c，c++一样

-------------------------------------------------------------------------------

## 函数

### 参数

```py
def printMax(a, b):
	if a > b:
		print a, 'is max'
	else:
		print b, 'is max'

print(3, 4)

x = 5
y = 7
print(x, y)
```

### 局部变量

```py
def func(x):
	print 'x is', x
	x = 2
	print 'changed local x', x

x = 50
func(x)
print 'x is still', x
```

### global变量

global语句被用来声明x是全局的。

```py
def func():
	global x
	print 'x is', x
	x = 2
	print 'changed local x to', x

x = 50
func()
print 'value of x is', x	# x --> 2
```

### 默认参数

默认参数只能在列表尾

```py
def say(message, times = 1):
	print message * times

say('hello')
say('ling', 2)
```

### 关键参数

def func(a, b = 5, c = 10):
	print 'a is', a, 'and b is', b, 'and c is', c

func(3, 7)
func(25, c = 24)
func(c = 50, a = 100)
```

### 返回 return

```py
def getSomeone():
	return 'zling'

print getSomeone()
```

### 文档字符串 -- DocString

```py
def printMax(x, y):
	'''Prints the maximum of two numbers.

	The two values must be integers.'''
	x = int(x) # convert to integers, if possible y = int(y)
	if x > y:
	print x, 'is maximum'
	else:
	print y, 'is maximum'

printMax(3, 5)
print printMax.__doc__
```

*惯例:*

* 第一行大写字母开始,句号结尾
* 第二行是空行 
* 第三行开始是详细的描述

