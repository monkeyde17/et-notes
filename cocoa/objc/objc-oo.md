面向对象
========

## 头文件

`Head.h`

```objc
#import <Foundation/Foundation.h>

/* interface -- 接口摸摸大 */
@interface Head : NSObject {
    int a;
    int b;
    int c;
    NSString *d;
}

/* 类方法，类似于c++中的static方法 */
+ (void) getInstance;

/* 实例方法，类似于c++的成员函数 */
/* 给参数起一个别名，可以直接通过别名查找参数 */
- (void) function:(int)a second:(int)b;

/* 特有关键字 */
@end
```


## m文件

objc的话文件后缀是`.m`，objc++的话则是`.mm`，不知何意。

```objc
/* 这里也可以用include的，import可以防止重复引用 */
#import "Head.h"

+ (void) getInstance
{
   /* code */ 
}

- (void) function:(int a) second:(int)b
{
    /* print a and b */
}
```

## main.m

```objc
#import <Foundation/Foundation.h>
#import "Head.h"

int main(void)
{
    @autoreleasepool {

        [Head getInstance];
        /* 我就这么随便写写，不要随便就信了 */
        [[[Head alloc] init] function:1
                               second:2]; 
    }

    return 0;
}
```

---------------------------------------------------

