# Binary Search

- Sorted array A, key q

### Time Complexity
- $O(\log n)$ because we divide in half when we cross the tree
- **Worst case** $O(\log n)$: Search an element not in the array

# Binary Search Tree
- Each node has a key 
- Node $x$ has:
	- `key(x)`
	- pointers:
		- `parent(x)`
		- `left(x)`
		- `right(x)`

### Invariant
$\forall x$, if y is in left subtree $\Rightarrow  key(y)\leq key(y)$
	if y is in right subtree $\Rightarrow  key(y)\geq key(y)$

### Search
- **Time Complexity**: $O(h)$

### Insert
- **Time Complexity** $h(T) = h \Rightarrow O(h)$  
	- **Worst case** $O(h)$: Sorted or inverse sorted  

### Sorting
- // insert BST sort code
- $O(\log n)\leq n \texttt{insert}\leq O(n^2)$ 
	- $O(n^2)$ is when the tree is unbalanced to one side

### Real world Example
**Runway Preservation system**
- $t=$ continuous time
- add $t$ to a set of requests $R$, if no other landing is scheduled within $k$ minutes
- Implement a $O(\log n)$ structure where $|R|=n$

### QuickSort and BST
They do the same comparisons but in a different order

### Deletion
1. $z$ has no children $\Rightarrow$ delete $z$ and replace the pointer from `parent(z)` to $z$ with $nil$ 
2. $z$ has one child $\Rightarrow$ replace $z$ by $z$'s child
3. $z$ has two children $\Rightarrow$ 
// combine with next slide



