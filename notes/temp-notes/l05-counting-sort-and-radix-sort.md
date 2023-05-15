# Counting Sort
- **Assumptions**:
	- $n$ integers to be sorted
	- Ram model
	- All integers $\in [0,k-1]$ 

### Algorithm
- Use **auxiliary array** $C$ of size $k$
- When we read $i$, increase $C[i]$

//TODO add example

### Time Complexity
- if $k=O(n) \Rightarrow c.s. \Theta(n)$
- **Time Complexity** $\Theta(k+n)$

### Properties
- **Not in place**
	- Since $k$ is not constant
- **Stable**
	- Due to the linked list storing


# Radix Sort
...
- $d$ is number of digits

### Algorithm
- Represent integer in base $b$ 
- Make $d$ sorts
	- Sort int by least significant digit
	- ...
	- Sort int by most significant digit
- Sort using Counting Sort
	- This allow to preserve the number order

### Time Complexity
- $d= \log_{b}(k+1)$ 
- Time: $O(d(n+b))=O(\log_{b}(k) (n+b))=O(\log_{n}(k) (n))=O(\log_{n}(n^{\Theta(1)}) (n))=O(n)$ 
- $\Theta(n), \forall k=O(n^{O(1)})$ 

### Properties
- **Not in place**
- **Stable**

## Exercises
...