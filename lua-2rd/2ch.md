第 2 章 类型与值
================

8种基础数据类型

> 1. nil
> 2. boolean
> 3. number
> 4. string
> 5. userdata
> 6. function
> 7. thread
> 8. table


## 2\.1

`nil` 是一种类型，只有一个**nil**值，表示无效值

## 2\.2

`boolean` 含**false**和**true**，在**lua**中，只有**false**和**nil**表示假。其余都为真

`number` 表示实数

> TIP 
> 
>       发行版`luaconf.h`中，用其他类型表示整数。

> QUESTION
> 
>       双精度浮点数1014？

## 2\.3 
`string` 字符串，**lua**完全采用8位编码。**lua**字符串中的字符可以具有任何数值编码，包括数值0。而且可以将任意二进制数据存储到一个字符串中。

**lua**字符串是`不可变值(immutable value)`。若想修改，只能根据原字符串来建立一个新的字符串。

**lua**字符串可以包含类**C**中的转义序列。

**可以使用一堆匹配双括号来界定一个字母字符串**
```lua
page = [[           -- 若第一个字符是换行则会被忽略
    print('page')
    b = 12
]]
```

**若包含了注释的代码，可以在方括号中加入任意等量的`=`等号**
```lua
page = [==[
    --[[
        some code
    --]]
]==]
```

**lua**提供了运行时的数字与字符串的自动转换
```lua
"10" + 1
"10 + 1"
```

**字符串连接操作符** `..` 

**长度操作符** `#` 

```lua
tostring() -- 转字符串
tonumber() -- 转实数
```

## 2\.5 表

`table` 实现了 `关联数组(associative array)`
`io.read` 含义是 **io模块的read函数**，对于**lua**而言，这表示**使用字符串作为key(键)来索引tabel.io**，即索引`io表`

**table**创建是通过`构造表达式(constructor expression)`完成。
```lua
a = {}
a[1] = 1
a.x = 'str'
a['x'] = 'str'  --> 等同于 a.x
```

`#` **长度操作符作用于一个数组时需要保证该数组连续(无空隙)**

**table.maxn返回最大正索引数**

**table索引从1开始**

## 2\.6 function

函数作为第一类之来看待，这表示函数可以存储在变量中。可以作为参数传递给其他函数，也可以作为返回值。

## 2\.7 userdata, thread

`userdata` 可将任意的**C**语言数据存储到**lua**变量中。

`thread` 协同程序 `coroutine`