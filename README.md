# 2019.12.17
程序开发：程序开发是基于数据和逻辑。
数据：决定了程序的数据类型，引发如何构造合适的数据类型。
    数据结构：在构建数据结构时采用面向对象的思路， 属性，方法。
逻辑：也会影响到数据类型的构建，同时决定了代码的实现。
模块化：根据功能进行模块化，每个模块拥有自己的数据结构，和处理逻辑
    模块之间的联系：通过数据进行交互。达到数据之间的松耦合。
    模块内部之间的联系：通过定义的数据结构。进行交互。
编程思想：安全性，结构化，回调思想。

# C Language
指针(pointer):
    存储变量的地址的变量,可以指向C语言中一切对象。按地址查询数据。指针变量包含两部分，指针本身的地址(pt_address), 指向对象的地址(object_address).
    *,运算符的理解，拿到object_address,按object_address地址改变object_address地址存储的内容。
两指针指向同一个地址空间：
    free(pt)(任何一个)会释放地址空间，两个指针都失效,另一个被称为野指针。
    指针越界：访问了部署于指针指向地址的空间，利用使用malloc(char)分配地址，赋值时，没有在结尾输入('\0'), printf("%s",pt)会导致指针越界。
    
    指针是C语言中最强大的工具，使用时要十分小心，要考虑，指针是否初始化，遍历指针是否越界。
空指针指向具体结构后，在使用时，还是要显示的转换成对应的结构体(voin *pt; int a = 10; pt=&a; printf("%d",*((int *)pt))
结构体(struct): 是自定义实现丰富数据类型的基础。通过包含函数指针，可以实现结构体为对象。


 
    