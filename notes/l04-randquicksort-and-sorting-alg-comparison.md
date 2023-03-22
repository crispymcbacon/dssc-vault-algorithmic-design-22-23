# Randomized quicksort

- **Idea:** Choose pivot randomly
- Leads to change in **time complexity**

### Algortihm

**Repeat**
- Pick $x$ at random
- Partition with respect to $x$
**Until**
- The resulting partition is still $x$

### Time complexity analysis

##### Worst case
...

##### Time complexity calculation
$T(n)=T\left (\frac{n}{4}  \right )+T\left (\frac{3}{4}n  \right )+E\left [ \texttt{nr. iteration of choosing pivot} \right ]\cdot c\cdot n$

```mermaid
graph TD;

id1((2*c*n)) --> id2(("2c(1/4)n"));

id1(("2*c*n")) --> id3(("2c(3/4)n"));

id2(("2c(1/4)n")) --> id4(("2c(1/(4^2))n"));

id2(("2c(1/4)n")) --> id5(("2c(3/(4^2))n"));

id3(("2c(3/4)n")) --> id6(("2c(3/(4^2))n"));

id3(("2c(3/4)n")) --> id7(("2c((3^2)/(4^2))n"));
```

$T(n)=O(n logn)$ in Expectation (but worst case is still $O(n^2)$ )

> [!NOTE]
> - $n$ is due to partition function
> - In expectation the E[ ] term become 2 due to P(good)
> - $O(n)$ per level
> - $log\frac{4}{3}(2cn)$ is the height of the worst case (rightmost branch)
> - $log\frac{4}{3}(2cn)=O(log_{2}n)$

### Properties
- Is **Stable** (preserves keys order)

# Sorting algortihms comparison


