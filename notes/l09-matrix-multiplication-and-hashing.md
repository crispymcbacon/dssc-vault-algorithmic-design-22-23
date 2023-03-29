# Matrix multiplication

## Strassen
$$
\begin{align}
P_{1}=a(f-h) \\
P_{2}=(a+b)h \\
P_{3}=(c+d)e \\
P_{4}=d(g-e) \\
p_{5}(a+d)(e+h)\\
P_{6}(b-d)(g+h)\\
P_{7}(a-c)(e+f)\\
\end{align}

$$
$$
\begin{align}
r=P_{5}+P_{4}-P_{2}+P_{6}\\
s=P_{1}+P_{2}\\
t=P_{3}+P_{4}\\
u=P_{5}+P_{1}-P_{3}-P_{7}\\
\end{align}
$$
*1*
$$
a(f-)
$$

#### Algorithm
- Divides $A,B$ into 4 blocks
- Computes the terms of $P_{i's}$
	- Due to sums $\Theta(n^2)$
- Conquer by recursively compute $P_{i's}$
- Combine into $r,s,t,u$
	- $\Theta(n^2)$

$$
T(n)=7T(\frac{n}{2})+\Theta(n^2)
$$
- At level $i$ , the work is $7c(\frac{n}{2^i})^2$
- At the leaves, $c\frac{7}{4}^{\log n}$ 

# Dictionaries

- Look for $\Theta(1)$ in expectation
	- insertion of items
	- deletion of items
	- `search(key)` return item with a given key or report it does not exist

- Assumptions
	- Keys are integers $\geq 0$
	- Keys are distinct

- es python
```python
D[key] # search
D[key]=value # insert
del D[key] # delete
```

- For dictionaries, items (key, value)
	- `D.items`

## Direct access table
- Drawback
	1. Huge space waste
	2. Key may not be integers $\geq 0$ 

- What if keys are not int$\geq 0$ ?
	- In theory, take the string of bits representing your key
	- In general, there prehash function ph $U\Rightarrow N$
- Reduce space waste with hashing

## Hashing
m=$\Theta(n)$ , where n=# items$^{m-1}$ 

$$
\forall 
$$