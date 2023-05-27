## Heap Sort

### Heaps

A **heap** is a data structure that represents a nearly complete binary tree containing n keys, each of which must satisfy the following property:
- Each node in the tree corresponds to an element in the array.
- The array has two attributes: **length** (number of elements in the array) and **heap-size** (number of elements stored within the heap in the array).
- The **root** is at index 1, and parent, left child, and right child indices can be easily computed given a node's index:
  - `Parent(i)`$=\lfloor i/2\rfloor$
  - `Left(i)`$=2i$
  - `Right(i)`$=2i+1$

The **height of a node** is the number of edges on the longest simple downward path from the node to a leaf, and we define the **height of the heap** to be the height of its root.\
Since a heap of $n$ elements is based on a complete binary tree, its height is $\Theta (\log n)$

There are two kinds of binary heaps. For each, the values in the nodes satisfy a **heap property**:

**Max-heap**\
The max-heap property is that for every node i other than the root:\
$A[\text{Parent}(i)]\ge A[i]$ \
Thus, the **largest element** in a max-heap is stored at the $root$, and the subtree rooted at a node contains values no larger than that contained at the node itself:\
$\text{key}(i)\ge\text{key}(\text{left(i)}),\text{key}(\text{right(i)})$

**Min-heap**\
Is organized the opposite way.

?example image of heaps tree?

#### Maintaining the heap property
The **max-heapify** procedure is used to maintain the max-heap property.\
`MaxHeapify(A, i)` *assumes* that the binary trees rooted at the left and right children of $i$ are already max-heaps. However, if the value at $A[i]$ is smaller than its children, max-heapify allows $A[i]$ to "float down" in the heap, ensuring that the subtree rooted at $i$ maintains the max-heap property.

?example?

```py
MaxHeapify(A, i)
  l = Left(i)
  r = Right(i)
  if l <= A.heap_size and A[l] > A[i]
    largest = l
  else
    largest = i
  if r <= A.heap_size and A[r] > A[largest]
    largest = r
  if largest != i
    exchange A[i] with A[largest]
    MaxHeapify(A, largest)
```

#### Building a heap

```py
BuildMaxHeap(A)
  A.heap_size = A.length
  for i = floor(A.length/2) downto 1
    MaxHeapify(A, i)
```


### Priority queues
A **priority queue** is a data structure for maintaining a set $S$ of elements, each with an associated value called a $key$.\
*One of the most popular applications of a heap.*

A **max-priority queue** supports the following operations:
- `Insert(S, x)`: inserts the element $x$ into the set $S$, which is equivalent to the operation $S=S\cup \{x\}$.
- `Maximum(S)`: returns the element of $S$ with the largest key.
- `ExtractMax(s)`: removes and returns the element of $S$ with the largest key.
- `IncreaseKey(S, x, k)`: increases the value of element $x$’s key to the new value $k$, which is assumed to be at least as large as $x$’s current key value.