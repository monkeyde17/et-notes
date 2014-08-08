第 8 章 编译，执行与错误
========================

## 8\.1 编译

* dofile        只是编译代码，多次调用一次编译
* loadfile      不会引发错误，多次调用多次编译
* loadstring    读入字符串，非文件。总是在全局环境中编译

```lua
function dofile (filename)
    local f = assert(loadfile(filename))
    return f()
end
```

loadstring 最典型的用处是执行外部代码

loadfile和loadstring在lua中正真原始函数是load，load接受一个读取器函数，读取器函数可以分几次返回一个程序块。

## 8\.2 C代码

lua为几种平台实现了一套`动态链接机制`。

lua提供所有关于动态链接的功能都聚集在一个函数中，即`package.loadlib(libpath, funcname)`

通常使用`require`来加载C程序库，这个函数会指定库，然后回通过`loadlib`来加载库，并返回初始化函数。这个初始化函数应将库中提供的函数注册到lua中，就像一段lua代码定义了其他函数一样。

## 8\.3 错误

`error函数` 传入一个错误消息参数

```lua
-- 十分常用
if not <condition> then
    error("...")
end

-- lua内建assert函数
assert(io.read("*number"), "invalid input")
```

## 8\.4 错误处理与异常

若要在lua中处理错误，则必须使用函数`pcall`来包装需要执行的代码。
