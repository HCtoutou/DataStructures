散列表的实现常常叫作散列。散列是一种以常数平均时间执行插入，删除和查找的技术。但是，那些需要元素间任何排序信息的操作将不会得到有效的支持。因此，诸如FindMin，FindMax以及以线性时间将排过序的整个表进行打印的操作都是散列所不支持的。

- 看到实现散列表的几种方法。
- 分析比较这些方法。
- 介绍散列表的多种应用。
- 将散列表和二叉查找树进行比较。

### 一般想法

理想的散列表数据结构只不过是一个含有关键字的具有固定大小的数组。典型情况下，一个关键字就是一个带有相关值的字符串。我们把表的大小记作TableSize，并将其理解为散列数据结构的一部分而不仅仅是浮动于全局的某个变量。

将每个关键字映射到从0到TableSize-1这个范围中的某个数，并且放到适当的单元中，这个映射就叫做散列函数，理想情况下它应该运算简单并且应该保证任何两个不同的关键字映射到不同的单元。不过这是不可能的，因为单元的数目是有限的，而关键字实际上是无穷无尽的。因此我们寻找一个散列函数，该函数要在单元之间均匀的分配关键字。

这就是散列的基本想法。剩下的问题则是要选择一个函数，决定当两个关键字散列到同一个值的时候应该做什么以及如何确定散列表的大小

### 散列函数

一个好的散列表应该有一个好的散列函数，如果输入的关键字是一个整数，则一般合理的方法就是直接返回“Key mod TableSize”的结果，除非Key碰巧具有某些不理想的性质。表的大小最好为一个素数。

通常，关键字是字符串，在这种情况下，散列函数需要仔细的选择。

一种选择方法是把字符串中的字符的ASCLL码值加起来。

下面就是一个好的散列函数

```c
Index Hash(const char *Key,int TableSize){
    unsigned int HashVal = 0;
    while(*Key!='\0')
        HashVal = (HashVal << 5) + *key++;
    return HashVal % TableSize;
}
```

### 冲突解决方法

- 分离链接法
- 开放定址法
- 再散列

#### 分离连接法

将散列到同一个值得所有元素保存在一个表中。为方便起见，这些表都有表头

#### 开放定址法

分离链接法的缺点是需要指针，由于给新单元分配地址需要时间，因此这就导致算法的速度多少有些慢，同时算法实际上还要求实现另一种数据结构。除使用链表解决冲突外，开放定址散列法是另外一种用链表解决冲突的方法。

开放定址散列法中，如果有冲突发生，那么就要尝试新的单元，直到找出空的单元为止

其中主要有三种解决冲突的方法：

- 线性探测法：F是i的线性函数
- 平方探测法：消除线性探测中一次聚集的问题。如果使用平方探测法，且表的大小是素数，那么当表至少有一半是空的时候，总能够插入一个新的元素。
- 双散列：F(i)=i*hash2(X)。这个公式是说，我们将第二个散列函数应用到X并在距离hash2(X),2hash2(X)等处探测。
### 再散列

对于使用平方探测的开放定址散列法，如果表的元素填的太满，那么操作的运行时间将开始消耗过长，且Insert操作可能失败。这可能发生在有太多的移动和插入混合的场合。此时，一种解决方法是建立另外一个大约两倍大的表(而且使用一个相关的新散列函数)，扫描整个原始散列表，计算每个(未删除)元素的新散列值并将其插入到新表中。这个操作就叫作再散列。

再散列可以用平方探测以多种方法实现。一种做法是只要表填满一半就再散列。另一种极端的方法是只有当插入失败时才再散列。第三种方法是途中策略：当表到达某一个装填因子时在进行再散列。由于随着装填因子的增加，表的性能的确有下降，因此，以好的截至手段实现的第三种策略可能是最好的策略。

### 可扩散列

与前面一样，我们假设在任意时刻都有N个记录要存储，N的值随时间而变化。此外，最多可把M个记录放入一个磁盘区块。本节将设M=4.

如果使用开放定址散列法或分离链接散列法，那么主要问题在于，一次Find操作期间，冲突可能引起多个区块被考察，甚至对于理想分布的散列表也在所难免。不仅如此，当表变得过满的时候，必须执行代价巨大的再散列这一步，他需要O(N)次磁盘访问。

一种聪明的选择叫做可扩散列，它允许用两次磁盘访问执行一次Find。插入操作也需要很少的磁盘访问。