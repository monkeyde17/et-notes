第 5 章 函数
============

一个函数若只有一个参数，并且此参数是一个**字面字符串**或**table构造式**，则圆括号可有可无。


`冒号操作符`
```lua
o.foo(o, x) -- line one
o:foo(x)    -- same as line one 
```


调用函数是提供的实际参数可以与形参数量不同。

* 若实参**多于**形参，则舍弃多余实参
* 若实参**少于**形参，则初始化为`nil`

## 5\.1 多重赋值

lua会调整一个函数的返回值数量以适应不同的调用情况。

* 若将函数作为表达式的一部分来调用时，lua只保留第一个返回值。
* 只当有一个函数调用是一系列表达式的最后一个元素(或仅有一个元素)时，才获得函数的所有返回值。

```lua
-- 多重赋值
x, y = foo2()
x, y, z = 10, foo2()
x, y = foo2(), 10       --> foo2() 只返回第一个值

-- 作为另一个函数的实参
print(foo2())
print(foo2(), 1)        --> foo2() 只返回第一个值

-- table 构造式
a = {foo2()}
a = {foo2(), "a"}       --> foo2() 只返回第一个值

-- return 语句
return foo2()
return (foo2())         --> foo2() 只返回第一个值
```

`unpack函数`，接受一个数组为参数，并从下标1开始返回所有参数

```lua
function unpack(t, i)
    i = i or 1
    if t[i] then
        return t[i], unpack(t, i + 1)
    end
end
```

## 5\.2 变长参数

```lua
function add (...)
    local s = 0
    for i, v in ipairs{...} do
        s = s + v
    end
    return s
end
```

>  若变长参数中含有nil 需用select来访问

```lua
for i = i, select('#', ...) do
    local arg = select(i, ...)  --> 得到第i个参数
    ...
end
```
select('#', ...) 会返回素有变长参数总数，包括nil

## 5\.3 具名参数

lua中参数传递机制具有`位置性`

我们可以通过地调用实参只有一个table表达式的函数来实现具名实参的功能

```lua
function rename(arg)
    return os.rename(arg.old, arg.new)
end

rename {old = "temp.lua", new = "temp1.lua"}
```

