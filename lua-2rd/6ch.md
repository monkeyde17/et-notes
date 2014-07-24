第 6 章 深入函数
================

在lua中函数是一种第一类值，他们具有特定词法域。

`词法域(Lexical Scoping)`指一个函数可以嵌套在另一个函数中，内部函数可以访问外部函数中的变量(lambda)

```lua
function foo(x)
    return 2 * x
end

-- 上可简写如下
foo = function(x)
    return 2 * x
end
```

`高阶函数`，接受另一个函数作为实参的函数

## 6\.1 closure 闭合函数

```lua
function sortbygrade(names, grades)
    table.sort(names, function(n1, n2)
            return grades[n1] > grades[n2]
        end
    )
end
````

其中grades既不是全局变量也不是局部变量，这叫做`非局部变量(non-local variable)`，也称upvalue

一个closure就是一个函数加上该函数所需访问的所有`非局部变量`

从技术上讲，lua中只有closure，而不存在函数。因为函数本书就是一种特殊的closure

```lua
-- 可以创建一个安全的运行环境，即沙盒
do
    local oldsin = math.sin
    local r = math.pi / 180
    math.sin = function(x)
        return oldsin(x * r)
    end
end
```

## 6\.2 非全局的函数

将一个函数存储到一个局部变量中，即得到了一个局部函数。

## 6\.2 正确的尾调用

lua支持尾调用消除

尾调用消除就是类似于goto的函数的调用。当一个函数是另一个函数的最后一个动作时，该调用才算是一条尾调用。

```lua
function f(x)
    return g(x)
end
```
即f调用完g之后就再无其他事情可做，程序就不用返回那个'尾调用'所在的函数。所以尾调用之后，程序也不需要保存任何关于该函数的stack信息。当g返回时，执行的控制权可以猴子姐返回到调用f的那个点上。

在lua中只有 `return <func> (<args>)` 这样的形式的调用才算是一条尾调用。

lua会在函数调用前对具体参数求值