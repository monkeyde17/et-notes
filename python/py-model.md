python模块
==========

## 模块

> 模块 : 函数 + 变量

```py
import sys

print 'the args are'

for i in sys.argv:
	print i

print 'sys.path', sys.path, '\n'
```

```py
# 直接引用模块变量
from sys import argv

# 建议用这种，不容易引起命名冲突
import sys
```

> arg 从0开始，arg[0]表示本身，同c/c++

> 字节编译的.pyc文件 ---- 快！


### __name__

```py
# 用户单独运行该模块
if __name == '__main__':
	print 'this program is being run by itself'
# 该模块被其他模块调用
else:
	print 'i am being imported from another module'
```

> 使用dir()可以返回模块的所有标识 ---- 函数，类，变量

```py
import sys

print dir(sys)
```

