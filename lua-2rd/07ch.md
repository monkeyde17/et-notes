第 7 章 迭代器与泛型for
=======================


## 7\.1 迭代器与closure

```lua
function values(t)
    local i = 0
    return function()
        i = i + 1
        return t[i]
    end
end
```

需要结合每个新的循环都创建一个closure

## 7\.2 泛型for语义

泛型for在循环过程内部保存了迭代器函数。实际上，他保存了一个值，一个迭代器函数、一个恒定状态和一个控制变量

```lua
for <var-list> in <exp-list> do
    <body>
end
```

for做的第一件事情是对`exp-list`求值

```lua
do
    local _f, _s, _var = <explist>
    while true do
        local var_1 ... var_n = _f(_s, _var)
        _var = var_1
        if _var == nil then
            break
        end
        <body>
    end
end
```

## 7\.3 无状态的迭代器

每次迭代中，for循环都会用恒定状态和控制变量来调用迭代函数。一个无状态的迭代器可以根据这两个值来生成下一个元素。这类迭代器的一个典型例子就是`ipairs`

函数ipairs与pairs类似，但pairs是用了lua中的next

```lua
function pairs(t)
    return next, t, nil --> 迭代函数，恒定状态，控制变量
end
```

在调用next(t, k)时，k是table的一个键。此调用会以table中的任意次序返回一组值(key, value)

而调用next(t, nil)时，则返回第一组值
```lua
for k, v int next, t do
    <body>
end
```

