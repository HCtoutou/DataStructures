- 优先队列ADT的有效实现
- 优先队列的使用
- 优先队列的高级实现
### 模型
优先队列是允许至少下列两种操作的数据结构：Insert（插入），它的工作是显而易见的；以及DeleteMin（删除最小者），它的工作是找出，返回和删除队列中最小的元素。Insert操作等价于Enqueue（入队），而DeleteMin则是队列中Dequeue（出队）在优先队列中的等价操作。DeleteMin函数也变更它的输入。

### 二叉堆

当不加修饰的使用堆（heap）这个词时一般都是指二叉堆这种数据结构的实现。同二叉查找树一样，堆也有两个性质，即结构性和堆序性。正如AVL树一样，对堆的一次操作可能破坏这两个性质中的一个。因此，堆的操作必须要到堆的所有性质都被满足时才能终止。

#### 结构性质

堆是一棵被完全填满的二叉树，有可能的例外是在底层，底层上的元素从左到右填入。这样的树称为完全二叉树。

容易证明一棵高为h的完全二叉树有2^k到2^(k+1)-1个节点。这意味着完全二叉树的高是logN

完全二叉树可用一个数组表示而不需要指针。

对于数组中任意位置i上的元素，其左儿子在位置2i上，右儿子在左儿子后的单元（2i+1）上，它的父亲节点则在int（i/2）上。因此遍历起来也很方便，层序遍历即可。这种实现方法的唯一问题就是，因为是用数组实现，所以这个树的大小需要提前确定。

#### 堆序性质

使操作快速执行的性质是堆序性。由于我们想要快速的找出最小元，因此最小元应该在根上。如果我们将任意子树也视为一个堆，那么任意节点就应该小于它的所有后裔。

#### 基本操作

**插入操作(Insert)**：将一个元素插入到堆中，我们在下一个空闲位置创建一个空穴，否则该堆将不是完全树。如果X可以放在该空穴中而不破坏堆的序，那么操作成功。否则就要进行上滤操作。

**删除最小元(DeleteMin)**:当删除最小元时，在根节点产生了一个空穴。由于现在堆少了一个元素，因此堆中最后一个元素X必须移动到该堆的某个位置。如果X可以直接放到空穴中，那么DeleteMin完成。不过这一般不可能，因此我们将空穴的两个儿子中较小者移入空穴，这样就把空穴向下推了一层。重复该步骤直到x可以放入空穴中。因此，我们的作法是将X置入沿着从根开始包含最小儿子的一条路径上的一个正确位置。我们一般把这个操作叫做下滤。

**降低关键字的值（DecreaseKey）:**该操作对系统管理程序是有用的，系统管理程序能够使它们以最高的优先级运行。

**增加关键字的值(IncreaseKey)**：许多调度程序自动的降低正在过多的消耗CPU时间的进程的优先级。

### 左式堆

我们把任意节点X的零路径长Npl(X)定义为从X到一个没有两个儿子的节点的最短路径的长。因此具有0个或1个儿子的节点的Npl为0，而Npl(NULL)=-1.

#### 性质

左式堆的性质是：对于堆中的每一个节点X，左儿子的零路径长至少与右儿子的零路径长一样大。这个性质实际上超出了他确保不平衡的要求，因为它显然更偏重于使树向左增加深度。

因为左式堆趋向于加深左路径，所以右路径应该很短。事实上，沿左式堆的右路径确实是该堆中最短的路径。否则，就会存在一条路径通过某个节点X并取得左儿子。此时的X则破坏了左式堆的性质。

#### 定理

在右路径上有r个节点的左式树必然至少有2^r - 1个节点。

#### 合并操作

对左式堆的基本操作是合并。注意，插入只是合并的特殊情形，因为我们可以把插入操作看成单节点堆与一个大的堆的Merge。首先，我们给出一个简单的递归解法，然后介绍如何能够非递归的施行该解法。我们输入是两个左式堆H1和H2，除数据，左指针和右指针所用空间外，每个单元还要有一个指示零路径长的项。

如果这两个堆中有一个堆是空的，那么我们可以返回另外一个堆。否则，为了合并这两个堆，我们需要比较它们的根。首先，我们将具有大的根值得堆与小的根值得堆的右子堆合并。由于这棵树是递归地形成的，而我们尚未对算法描述完毕，因此，我们现在还不能说明该堆是如何得到的。不过，有理由假设，最后的结果是一棵左式堆，因为它是通过递归的步骤得到的。现在我们让这个新的堆成为H1的右儿子。

虽然最后得到的堆满足堆序的性质，但是，他不是左式堆，因为根的左子树的零路径长为1而根的右子树的零路径长为2.因此，左式的性质在根处被破坏。不过，容易看到，树的其余部分必然是左式的。由于递归步骤，根的右子树是左式的。根的左子树没变化，当然也是左式的。这样一来我们只要对根进行调整就可以了。使整个树是左式的做法如下：只要交换根的左儿子和右儿子并更新零路径长，就完成了Merge，新的零路径长是新的右儿子的零路径长加1.注意，如果零路径长不更新，那么所有的零路径长都将是0，而堆将不是左式的，只是随机的。



### 斜堆

#### 定义

斜堆是左式堆的自调形式。斜堆是具有堆序的二叉树，但是不存在对树的结构限制。不同于左式堆，关于任意节点的零路径长的任何信息都不保留。斜堆的右路径在任何时刻都可以任意长，因此，所有操作的最坏情形运行时间为O(N)。然而，正如伸展树一样，可以证明任意M次连续操作，总的最坏情形运行时间是O(M logN)，因此，斜堆每次操作的摊还时间为O(log N)。

#### 合并操作

合并操作与左式堆类似，但是有一个例外，即对于左式堆，我们查看是否左儿子和右儿子满足左式堆堆序性质并交换那些不满足该性质者；但对于斜堆，我们除了这些右路径上所有节点的最大者不交换它们的左右儿子外，交换是无条件的。

### 二项队列

二项队列不同于我们已经看到的所有优先队列的实现之处在于，一个二项队列不是一颗堆序的树，而是堆序树的结合，称为森林。堆序树中的每一棵都是有约束的形式，叫做二项树。每一个高度上至多存在一棵二项树。高度为0的二项树是一棵单节点树；高度为k的二项树Bk通过将一棵二项树Bk-1附接到另一棵二项树Bk-1的根上而构成。

#### 二项队列的操作

此时，最小元可以通过搜索所有的树的根来找出。由于最多有logN棵不同的树，因此最小元可以在O（logN）时间内找到。另外，如果我们记得当最小元在其他操作期间变化时更新它，那么我们也可保留最小元的信息并以O(1)时间执行该操作。

合并操作基本上是通过将两个队列加到一起来完成的。

DeleteMin可以通过首先找出一棵具有最小的二项树来完成。令该树为Bk，并令原始的优先队列为H。我们从H的树的森林中除去二项树Bk，形成新的二项树队列H。在除去Bk的根，得到一些二项树B0，B1........，Bk-1，它们共同形成优先队列。最后合并两个队列，操作结束。整个DeleteMin操作花费O(log N)时间。