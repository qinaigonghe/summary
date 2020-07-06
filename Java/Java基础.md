# Java基础

## 0常见知识

a.1个源程序只能包含一个与文件名相同的public类，其他可以有多个类

b.GC也会有内存泄漏，引用的无用信息不被清除

c.重载

## 1 平台无关与虚拟机

通过编译，Java源文件（.java）被编译成字节码（.class）

虚拟机是可执行Java字节码的虚拟机进程（机器码）

不同平台有不同版本的jvm，可以统一识别java文件

jdk中包含编译java源码的编译器javac与一些调试程序和文档，同时包含了jre，有虚拟机与类库

## 2 static

成员变量可在没有所属的类的实例变量的情况下访问

编译时静态绑定，无法被覆盖，同时载入时对static初始化，没办法访问非static变量

private在其它类继承后无法访问，也不能覆盖

## 3 自动拆箱装箱

八种类型自动拆装箱，基本数据类型到对象包装类型

非基本类型为引用类型，JVM虚拟栈存放的是地址，对象在堆中

## 4 构造方法

对象创建时调用，可进行重载（参数不同）

## 5 接口和抽象类

二者都不能被实例化

类不可以多继承，接口可以

接口可以继承/实现多个接口，抽象类也可以继承实现类

！！！接口方法都是抽象的且都为public，抽象类可以包含非抽象方法

## 6多态

编译多态：

运行多态

Bigdecimal：浮点型数据的运算

## 7 final

不可被继承、重写、改变（引用地址或内容）、JVM对该方法实现内联提高效率，变量放入常量区

String是final的数组，每次对其操作都是新的String对象，StringBuffer线程安全，加入了，StringBuilder效率高

## 8 深度克隆

实现serializable接口，在编译时检查，好过重写object的clone

## 9 ArrayList与LinkedList

顺序实现与双向链表

vector实现线程同步，效率比arraylist慢

LinkedList可以当作堆栈双向队列来使用

## 10 HashTable（线程安全）与HashMap（高效）

Hashtable比HashMap多提供了elments() 和contains() 两个方法。 elments() 方法继承自Hashtable的父类Dictionnary。elements() 方法用于返回此Hashtable中的value的枚举。

contains()方法判断该Hashtable是否包含传入的value。它的作用与containsValue()一致。事实上contansValue() 就只是调用了一下contains() 方法。

## 11 泛型

我们提供了泛指的概念，但具体执行的时候却可以有具体的规则来约束，比如我们用的非常多的ArrayList就是个泛型类，ArrayList作为集合可以存放各种元素，如Integer, String，自定义的各种类型等，但在我们使用的时候通过具体的规则来约束，如我们可以约束集合中只存放Integer类型的元素

## 12 Set

对象的相等性本质是对象 hashCode 值（java 是依据对象的内存地址计算出的此序号） 判断的， 如果

想要让两个不同的对象视为相等的，就必须覆盖 Object 的 hashCode 方法和 equals 方法