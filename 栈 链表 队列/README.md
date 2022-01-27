## 链表

### 定义：

链表由一系列不必在内存中相连的结构组成。每一个结构均含有表元素和指向包含该元素后继元的结构的指针。我们称之为Next指针。最后一个单元的Next指针指向NULL；该值由C定义并且不能与其他指针混淆。ANSI C规定NULL为零。

### 哑元：

上面的描述实际上足以使每一部分都能正常工作，但还是有几处地方可能会出问题。

- 第一，并不存在从所给定义出发在表的起始段插入元素的真正线性的方法。

- 第二，从表的起始段实行删除是一个特殊情况，因为改变了表的起始段，编程中的疏忽将会造成表的丢失。

- 第三个问题涉及一般的删除。虽然上述指针的移动很简单，但是删除算法要求我们记住被删除元素前面的表元。

  事实上，稍微做一个简单的变化就能够解决上述三个问题。我们可以留出一个标志节点，有时候称之为表头（header）或者哑节点（dummy node）。

### 链表基本功能实现：

**创建**

```c
Position Creat(int n) {
	Position head, node, end;
	head = malloc(sizeof(struct Node));
	end = head;
	printf("%d\n", head->Element);
	for (int i = 0; i < n; i++) {
		node = malloc(sizeof(struct Node));
		node->Element = i;
		end->Next = node;
		end = node;
	}
	end->Next = NULL;
	return head;
}
```



**打印**

```c
void Show(List L) {
	Position node;
	node = L->Next;
	while (node != NULL) {
		printf("%d\n", node->Element);
		node = node->Next;
	}
}
```



**查找**

```c
Position Find(int X, List L) {//查找
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
```



**插入**

```c
void Insert(int X, List L, Position P) {//插入操作（插入到P的后面）
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)//节点申请失败
		FatalError("Out of space!!!");
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
```



**删除**

```c
void Delete(int X, List L) {
	Position P, TmpCell;
	P = FindPrevious(X, L);
	if (!IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
```

涉及何时使用或何时不使用malloc来获取一个新的单元。必须记住，声明指向一个结构的指针并不创建该结构，而只是给出足够的空间容纳结构可能会使用的地址。创建尚未被声明过的记录的唯一方法是使用malloc库函数。malloc(HowManyBytes)奇迹般的使用系统创建一个新的结构并返回指向该结构的指针。另一方面，如果你想使用一个指针变量沿着一个表行进，那就没有必要创建新的结构，此时不宜使用malloc。

当有些空间不在需要时，你可以用free命令通知系统来回收它。free(P)的结果是：P正在指向的地址没变，但在该地址处的数据此时已无定义了。

### 双链表

在链表的基础上再增加一个域，使它包含指向前一个单元的指针即可

### 循环链表

让最后的单元反过来直指第一个单元。它可以有表头也可以没有，并且还可以是双向链表。



## 栈（后进先出LIFO）

### 定义

栈是限制插入和删除只能再一个位置上进行的表，该位置是表的末端，叫做栈的顶（top）。

对栈的基本操作有Push（进栈）和Pop（出栈），前者相当于插入，后者则是删除最后插入的元素。

栈顶元素是唯一可见元素。

### 栈的链表实现
**创建一个空栈**

```c
Stack CreatStack(void) {//创建一个空栈
	Stack S;
	S = malloc(sizeof(struct Node));
	if (S == NULL)
		exit(0);
	S->Next = NULL;
	MakeEmpty(S);
	return S;
}
void MakeEmpty(Stack S) {//将栈置空
	if (S == NULL)
		printf("Must use CreatStack first");
	else
		while (!IsEmpty(S))
			Pop(S);
}
```
**入栈**
```c
void Push(int X, Stack S) {//入栈操作
	PtrToNode TmpCell;
	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL)
		exit(0);
	else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
```
**出栈**
```c
void Pop(Stack S) {//出栈操作
	PtrToNode FirstCell;
	if (IsEmpty(S))
		printf("Empty Stack");
	else {
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}
```
### 应用
**平衡符号**
		做一个空栈。读入字符直到文件尾。如果一个字符是一个开放符号，则将其推入栈中。如果字符是一个封闭符号，则当栈空时报错；否则，将元素弹出。如果弹出的符号不是对应的开放符号，则报错。在文件尾，如果栈非空则报错。

**后缀表达式（逆波兰式）**

当遇到一个数时就把他放入栈中；在遇到一个运算符时就作用于从该栈弹出的两个数上，计算并将所得结果推入栈中。

**函数调用**

当存在函数调用的时候，需要存储的所有重要信息，诸如寄存器的值和返回地址等，都要以抽象的方式存在“一张纸上”并被置于一个堆的顶部。然后控制转移到新函数，该函数自由的用他的一些值代替这些寄存器。如果他又进行其他函数的调用，那么也遵循相同的过程。当该函数要返回时，他查看堆顶部的那张纸并复原所有的寄存器。然后进行返回转移。显然所有的工作均可由一个栈来1完成。

## 队列

### 定义

像栈一样，队列也是表。然而，使用队列时插入在一端进行而删除则在另一端进行。

队列的基本操作是Enqueue（入队），它是在表的末端（也叫队尾（rear））插入一个元素，还有Dequeue（出队），它是删除或返回在表的开头（叫做对头（front））的元素。

### 对列的数组实现

**测试是否为空队列**

```c
int IsEmpty(Queue Q) {
	return Q->Size == 0;
}
```

**构造空队列**

```c
void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}
```

**入队**

```c
static int Succ(int Value, Queue Q) {
	if (++Value == Q->Capacity)
		Value = 0;
	return Value;
}
void Enqueue(int X, Queue Q) {
	if (IsFull(Q))
		Error("Full queue");
	else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}
```





## 注

- malloc函数返回值：分配内存，若分配成功，则返回指向被分配内存的指针，否则返回空指针NULL。

  在使用malloc开辟空间时，使用完成一定要释放空间（使用free函数），否则会造成内存泄漏。

- typedef可以声明新的类型名来代替已有的类型名，但却不能增加新的类型

  作用：给变量提供一个易记且意义明确的新名字，另一个时简化一些比较复杂的类型声明。

- #ifndef，#define与#endif成对出现，这是宏定义的一种，进行预处理
  ```c
  #ifndef X
  //先测试X是否被宏定义过
  #define X
  //如果没有宏定义下面就宏定义X并编译下面的语句
  .....
  .....
  .....
  #endif
  //如果已经定义了则编译#endif后面的语句.
  ```
  
- 注意程序的错误检查。
