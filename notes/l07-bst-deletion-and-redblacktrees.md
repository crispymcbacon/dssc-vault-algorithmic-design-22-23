Remember by BST:
$\forall x$, if y is in left subtree $\Rightarrow  key(y)\leq key(y)$
	if y is in right subtree $\Rightarrow  key(y)\geq key(y)$

### Deletion
`Successor(x)` return the node $y$ s.t:
$y=min\left\lbrace z\mid key(z)\geq key(x) \right\rbrace$

#### Algorithm:
- if $x$ has a right child $\Rightarrow$ return the min of its right subtree
- otherwise return the lowest ancestor of x whose left child is also ancestor of $x$ 
- `if Successor(z)=right(z)` $\Rightarrow$ replace $z$ by `right(z)`
- `if Successor(z)≠right(z)` $\Rightarrow$ replace $z$ by `Successor(z)` by `right(Successor(z))`, then replace $z$ by `Successor(z)`

#### Time Complexity
- `Transplant()` $O(n)$ 
- `Successor()` $O(h)$

# Red Black Trees
They are Binary Search Trees with an extra color field satisfying properties:
1. Every node is either **black** or **red**
2. The root and the leaves are black
3. Every red node has a black parent
4. All paths from $x$ to a leaf below $x$ has the same number of black nodes

- `bh(x)` is **black height** = # of black nodes on a path from $x$ to a leaf, without including $x$ and including the leaf
- Red nodes are at most half of the total # of nodes

### Theorem
A Red-Black-Tree with $n$ nodes has a height $h \leq 2 \log(n+1)$

#### Demonstration
- Merge the nodes with their black parent, to create a 2-3-4 Tree that have the following properties:
	- All the leaves have the same level (= `bh(root)` )
	- Bounded number of children (at most 3?)
- $n$ = # of keys
- $h$ = height of RBT
- ${h}'$ = height of merged 2-3-4-Tree

- The # of leaves in either tree is $n+1$ (Induction proof)
- Max and min # of leaves in a 2-3-4-Tree of height ${h}'$ is: $2^{{h}'} \leq nr. leaves \leq 4^{{h}'}$ so:
	- $2^{{h}'} \leq n+1 \Rightarrow {h}'\leq \log(n+1)$ 
- The max height of a RBT is then:
	- $h \leq 2{h}' \Rightarrow h \leq 2 \log(n+1)$

### Time Complexity
-  Insertion/Deletion $O(\log n)$

### Insertion
1. Insert $x$ like in a BST 
2. Color change (conserve properties)
3. Restructure links via rotations

# Exercises

es. A B C D

