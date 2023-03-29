# Amortised Analysis
- $n =$ # of items
- $\alpha=\frac{n}{m}=$ load factor
- Expected time $\Theta(1+\alpha)$
- Space $\Theta(m+n)$

- Idea: grow/shrink table
- $m\geq n$ 
- $m^{'}=2m$
- whenever $n>m \Rightarrow$ increase size
- $n\rightarrow m^{'}>m$ $T \rightarrow T^{'}$
- Make new table of size $m^{'}$
- Build new hash function $h^{'}$
- rehash:
```
for item in T
	T'.insert(item)
```
- $\Theta(n+m+m^{'})$

$$
\Theta(1+2+4+8+16+\dots \quad \cdot n) = \Theta\left( \sum_{i=1}^{\log n} 2^{i}\right)=\frac{\Theta(n)}{n}=\Theta(1)
$$

Def: operations take "$T(n)$ amortised" time if $k\geq 1$ operations take $k\cdot T(n)$ time

#### Deletions
- if $m=2n \rightarrow$ shrink
	- problem: linear time in insertion and deletion

- if $m=4n \rightarrow$ halve
- $m^{'}=\frac{m}{2}$
- $\Theta(m+n)$
- if $m < n$ double
- $n\leq m \leq 4n$ 

### Amortised bounds
- Assign amortised cost to each operation state that it "preserves the sum"
	- $\\sum_{nr. op}$ amortised cost $\geq \\sum_{nr. op}$  actual cost

#### Aggregate analysis
- Stack `S`, operations:
	- `push(x)` $\Theta(1)$
	- `pop(S)` $\Theta(1)$
	- `Mpop(s,k)` = pops $k$ items, $\Theta(min\left\lbrace k, |S| \right\rbrace) \rightarrow \Theta(n)$ 
- Total cost of $n$ operations $\rightarrow O(n^2)$
	- time(pop)$\leq$time(push) = $\Theta(n) \Rightarrow \Theta(1)$ amortised per operation