第 4 章 语句
============

## 4\.1 赋值

```lua
a, b = 10, 2 * x --> 多重赋值
```
`lua`总是会将等号右边值的个数调整到与左边变量个数一致。

* 若值的个数**少于**变量的个数，那么多余的变量被赋值为`nil`
* 若值的个数**多于**变量的个数，那么多余的变量会被舍去。 

```lua
a[i], a[j] = a[j], a[i]  --> 交换两个变量的值
```

## 4\.2 局部变量

局部变量的作用域仅限于声明他们的那个块

一个`块（block）`是一个控制结构的执行体，或是一个函数的执行体，再或者是一个`程序块（chunk）`

> 可以显式的定义一个`程序块` （do - end）

```lua
do
    local a2 = a
end
```

> 可以创建一个局部变量并用全局变量初始化

```lua
local foo = foo
```

>优点如下：

* 防止foo被修改
* 加速当前作用域的访问

## 4\.3 控制结构

```lua
-- case 1
if .. then
    ...
else 
    ...
end

-- case 2
if .. then
    ...
else if .. then
    ...
else
    ...
end

-- while
while .. do
    ...
end

-- repeat
repeat ... until ...
```

`lua`中，一个声明在循环中的局部变量的作用域包括了条件测试。

------

* for 数字型

```lua
for var = exp1, exp2, exp3 do
    ...
end
```

`var`从`exp1`到`exp2`，每次步长为`exp3`，若`exp3`不指定，默认为1


```lua
for i = 1, math.huge do
    ...
end
```

for循环的3个表达式是在循环开始时一次性求值。控制变量var被自动声明为for语句的局部变量。仅在循环体内可见。循环结束后就不存在了。

> 不要再循环过程中改变控制变量的值！

* 泛型for

```lua
for i, v in pairs(a) do
    print(v)
end
```

> 迭代器
> 
> * io.lines
> * table(pairs)
> * 数组(ipairs)
> * 字符串中的单词(string.gmatch)


> 泛型for与数字型for相同点
> 
> * 循环变量是局部变量
> * 不应该对循环变量赋值