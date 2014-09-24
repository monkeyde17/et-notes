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


### \_\_name\_\_

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

## os模块

* os.name()字符串指示你正在使用的平台。比如对于Windows，它是'nt'，而对于Linux/Unix用户，它是'posix'。
* os.getcwd()函数得到当前工作目录，即当前Python脚本工作的目录路径。
* os.getenv()和os.putenv()函数分别用来读取和设置环境变量。
* os.listdir()返回指定目录下的所有文件和目录名。
* os.remove()函数用来删除一个文件。
* os.system()函数用来运行shell命令。
* os.linesep()字符串给出当前平台使用的行终止符。例如，Windows使用'\r\n'，Linux使用'\n'而Mac使用'\r'。
* os.path.split()函数返回一个路径的目录名和文件名。
* os.path.isfile()和os.path.isdir()函数分别检验给出的路径是一个文件还是目录。
* os.path.exists()函数用来检验给出的路径是否真地存在。
