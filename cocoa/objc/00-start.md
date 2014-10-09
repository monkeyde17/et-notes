Objective-C ---- 神奇
=====================

先来段`hello world`的代码看看

```objc
#import <Foundation/Foundation.h>

int main(int argc, const char * argv[])
{
    @autoreleasepool {

        NSString *pStr = [[NSString alloc] initWithUTF8String:"It's preaty awesome!"];
        NSLog(@"%@", pStr);

    }

    return 0;
}
```

首次接触OC的话，自然是惊叹于各种`[`和`]`。

1. OC的@

    a. `@autoreleasepool` 垃圾自动回收，OC一些关键字以@开头

    b. 字符串加了`@`前缀的，表示是一个`NSString`字符串

    c. `%@`在NSLog内打印对象，实际上是向对象发送`description`消息

2. 消息

    a. 例如`[NSString alloc]`表示向`NSString`对象发送`alloc`消息。

    b. 消息的参数

--------------------------------------------

> PS : 各个类的NS前缀是NeXTSTEP的缩写。


