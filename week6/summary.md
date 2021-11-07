### 贪婪算法（希望局部最优为全局最优）

贪婪算法分阶段的工作。在每一个阶段，可以认为所作决定是好的，而不考虑将来的后果。一般来说，这意味着选择的是某个局部的最优。这种眼下能够拿到的就拿的策略即是这类算法名称的来源。当算法终止时，我们希望局部最优就是全局最优。如果是这样的话，那么算法就是正确的；否则，算法得到一个次优解。如果不要求绝对最佳答案，那么有时会用简单的贪婪算法来生成近似答案，而不是使用一般产生准确答案所需要的复杂算法。

- **操作系统的作业调度问题**

- **Huffman编码**

  ##### 文件压缩

  利用编码技术进行文件压缩
  如果一个文件中所有字符都以相同的频率出现，那么要节省空间是不可能的。
  ##### 前缀编码
  
  只要没有字符代码是别的字符代码的前缀就是前缀编码
  
  
  
- **近似装箱问题**

  ##### 1.下项适合算法

  ##### 2.首次适合算法

  ##### 3.最佳适合算法

  ##### 4.首次适合递减算法（效果很好）

  ##### 5.最佳适合递减算法
### 分治算法

分：递归解决较小的问题

治：然后，从子问题的解构建原问题的解

#### 运行时间

运用算法设计与分析中，分治算法运行时间一般是求递归运行时间，可以用递归算法公式求得运行时间。

- **最近点问题**

- **选择问题**

- **一些运算问题的改进**

  ##### 整数相乘

  把一个整数相乘问题，划分为几个子问题，这样只适合一些非常大的数，小的数反而会增加开销。

  ##### 矩阵相乘

  长期以来认为矩阵乘法需要工作量Ω（N^3）的。

  `Strassen`算法打破了屏障，它的基本思想是把每一个矩阵都分成四块，比如两个N×N矩阵乘法，划分为8个N/2×N/2阶矩阵，这样花费依然没变，为了减少开销，我们需要把子问题简化到8个以下。最后简化到7个乘法，8个加法得到最终答案。

  我们可以很容易直到矩阵加法比矩阵乘法花费小。最终`Strassen`算法性能为O（N^2.81）。

  和整数相乘一样，`Strassen`算法在N不够大时不如矩阵直接相乘。而且只有有限的适用性。

### 动态规划

**定义：**将递归算法重新写成非递归算法，把子问题的答案系统地记录在一个表内，这种方法的一种技巧叫作动态规划。

#### 斐波那契数列

- 递归算法

  ```c
  int Fib(int n)
  {
  	if (n <= 1)
  		return 1;
  	else
  		return Fib(n - 1) + Fib(n - 2);
  }
  ```

- 线性算法实现斐波那契数列

  ```c
  int fib(int n)
  {
  	if (n < 2)
  		return n;
  	int Last,NextToLast,Answer;
  	Last = NextToLast = 1;
  	for (int i = 2; i <= n; i++)
  	{
  		Answer = Last + NextToLast;
  		NextToLast = Last;
  		Last = Answer;
  	}
  	return Answer;
  }
  ```

#### 矩阵乘法的顺序安排

一个好的矩阵乘法的顺序可以有效优化运行时间

```c
void OptMatrix(const long C[],int N,TwoDimArry M,TwoDimArry LastChange)
{
    int i,k,Left,Right;
    long ThisM;
    
    for(Left=1;Left<=N;Left++)
        M[Left][Left]=0;
    for(k=1;k<N;k++)
        for(Left=1;Left<=N-k;Left++)
        {
            Right=Left+k;
            M[Left][Right]=Infinity;
            for(i=Left;i<Right;i++)
            {
                ThisM=M[Left][i]+M[i+1][Right]+C[Left-1]*C[i]*C[Right];
                if(ThisM<M[Left][Right])
                {
                    M[Left][Right]=ThisM;
                    LastChange[Left][Right]=i;
                }
            }
        }
}
```



#### 最优二叉查找树

给定一列单词和它们出现的频率。问题是要一种方法在一棵二叉查找树中安防这些单词使得总的期望存取时间最小。在一棵二叉查找树中，访问深度d处的一个元素所需要的比较次数是d+1，因此如果w被放在深度d上那么我们就要将Σp（1+d）极小化。

#### 随机化算法

- 在算法期间随机数至少有一次用于决策。该算法运行时间不止依赖于特定的输入，而且依赖于所发生的随机数。
- 一个随机化算法的最坏情形运行时间几乎总是和非随机化算法的最坏情形运行时间相同。重要的区别在于，好的随机化算法没有不好的输入，而只有坏的随机数（相对于特定的输入）。
- 比如快排中枢纽元的选取，方法A是用第一个元素作为枢纽元，方法B是随机选取

**1.随机数发生器**

```c
static unsigned long Seed = 1;

#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)
double Random(void)
{
	long TmpSeed;

	TmpSeed = A * (Seed%Q) - R * (Seed / Q);
	if (TmpSeed >= 0)
		Seed = TmpSeed;
	else
		Seed = TmpSeed + M;

	return (double) Seed / M;

}
void Initialize(unsigned long InitVal)
{
	Seed = InitVal;
}
```

**2.素数测试**

```c
HugeInt Witness(HugeInt a, HugeInt i, HugeInt N)
{
	HugeInt X, Y;
	if (i == 0)
		return 1;
	X = Witness(a, i / 2, N);
	if (X == 0)
		return 0;

	Y = (X*X) % N;
	if (Y == 1 && X != 1 && X != N - 1)
		return 0;

	if (i % 2 != 0)
		Y = (a*Y) % N;

	return Y;
}

int IsPrime(HugeInt N)
{
	return Witness((long)Random() % N, N - 1, N) == 1;
}
```



### 回溯算法

回溯算法相当于穷举搜索的巧妙实现，但性能一般不理想。不过，情况并不总是如此，即使如此，在某些情形下它相比蛮力穷举搜索，工作量也有显著的节省。

#### 极小极大三连游戏棋算法

```c
void FindCompMove(BoardType Board,int *BestMove,int *Value)
{
    int Dc,i,Response;
    if(FullBoard(Board))
        *Value=Draw;
    else
        if(ImmediateCompWin(Board,BestMove))
            *Value=CompWin;
    else
    {
        *value=CompLoss;
        for(i=1;i<=9;i++)
        {
            if(IsEmpty(Board,i))
            {
                Place(Board,i,Comp);
                FindHumanMove(Board,&Dc,&Response);
                Unplace(Board,i);
                
                if(Response>*Value)
                {
                    *Value=Response;
                    *BestMove=i;
                }
            }
        }
    }
}
```

第1-4行直接给赢棋或平局赋值。如果这两个情况都不使用，那么这个位置就是非终端位置。注意到Value的值应该包括所有可能后继位置的最大值。第五行把它初始化为最小的可能值，第6-13行的循环则为了改进而进行搜索。每一个后继位置递归的依次由第8-10行算出值来。因为我们将看到过程FindHumanMove调用FindCompMove，所以这是递归的。如果下棋人对一步棋的应招给计算机留下比计算机在前面最佳棋步所得到的位置更好的位置，那么Value和BestValue将被更新。



#### 带有α-β裁减的极小极大三连游戏算法

```c
void FindCompMove(BoardType Board,int *BestMove,int *Value)
{
    int Dc,i,Response;
    if(FullBoard(Board))
        *Value=Draw;
    else
        if(ImmediateCompWin(Board,BestMove))
            *Value=CompWin;
    else
    {
        *value=CompLoss;
        for(i=1;i<=9&&*Value<Beta;i++)
        {
            if(IsEmpty(Board,i))
            {
                Place(Board,i,Comp);
                FindHumanMove(Board,&Dc,&Response,*Value,Beta);
                Unplace(Board,i);
                
                if(Response>*Value)
                {
                    *Value=Response;
                    *BestMove=i;
                }
            }
        }
    }
}
```

在实践中，α-β裁减把搜索范围限制在只有O(N^1/2)个节点上，这里N是整个博弈树的大小。这是巨大的节约，它意味着使用α-β裁减的搜索与非裁剪树相比能够进行到两倍的深度。我们的三连游戏棋例子不是理想的，因为存在太多相同的值，但即使是这样，最初对97162个节点的搜索还是被减少到了4493个节点。