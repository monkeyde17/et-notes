第 14 章 环境
=============

lua将其所有的全局变量保存在一个常规table中，该table成为`环境`
优点：

* 无需为全局变量创造新数据结构，简化lua内部实现
* 可像其他table一样操作该table(_G)


##　14\.1 具有动态名字的全局变量

对于访问和设置全局变量，通常赋值就可以了。不过有时也会用到元编程。

```lua
value = loadstring("return " .. varname)()
value = _G[varname]
```

但_G["io.read"]不会从io.table中得到字段read



