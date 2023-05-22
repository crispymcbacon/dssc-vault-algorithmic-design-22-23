# Algorithm

## What is an algorithm
An **algorithm** is any well-defined computational procedure that takes some value, or set of values, as **input** and produces some value, or set of values, as **output**.\
*An algorithm is thus a sequence of computational steps that transform the input into the output.*
#### Pseudocode
Reading instance of a problem (simulate)

## Time Complexity

### Order of Growth
- Linear, Quadratic, Log, ...
- ?Plot?

### Notation
- $O \le$, $o <$
- $\Omega \ge$, $\omega >$
- $\Theta =$

#### O (Big O):
$f(n)=O(g(n))$ \
\
$\exist \space c>0, \space n_0>0$ \
s.t. $0\le f(n)\le c\cdot g(n) \quad \forall n>n_0$
- Eg.: $2n^2 = O(n^3)$

#### $\Omega$ (Omega):
$f(n)=\Omega(g(n))$ \
\
$\exist \space c>0, \space n_0>0$ \
s.t. $0\le c\cdot g(n)\le  f(n) \quad \forall n>n_0$

- Eg.: $n=\Omega(log(n))$

#### $\Theta$ (Theta):
$f(n)=\Theta(g(n))$ \
\
$\exist \space c_1,c_2>0, \space n_0>0$ \
s.t. $c_1\cdot g(n)\le f(n)\le c_2\cdot g(n) \quad \forall n>n_0$

#### o (little o):
$f(n)=o(g(n))$ \
\
$\forall \space c>0 \quad \exist \space n_0>0$ \
s.t. $f(n)<c\cdot g(n)  \quad \forall n>n_0$

- Eg.: $2n^2$=$o(n^3)$
- Eg.: $6n^2=\Theta(n^2)$ but NOT $o(n^2)$

#### $\omega$ (little omega):
$f(n)=o(g(n))$ \
\
$\forall \space c>0 \quad \exist \space n_0>0$ \
s.t. $c\cdot g(n)<f(n)  \quad \forall n>n_0$

#### Examples
- $log_{10}(n)=\Theta(log(n))$ -> $log_{10}(n)$ = $log_2(n) \over c*log_{10}(10)$
- $\Theta(1)$ means constant
- Log base doesn't count: $log_{10}(n) = Theta(log(n))$

## Random-Access Machine (RAM)

The **RAM (Random-Access Machine)** model of computation is a theoretical model used to analyze algorithms. It assumes a generic one-processor system where instructions are executed sequentially, without concurrent operations.\
*It provides a simplified representation of a computer's memory and processing capabilities for algorithmic analysis.*

- Access $\Theta(1)$ elements in $\Theta(1)$ time (elements = $w$ bits)
- Do $\Theta(1)$ computations in $\Theta(1)$ time
- Write $\Theta(1)$ elements in $\Theta(1)$ time

## Loop Invariant

A **loop invariant** is a condition or property that remains true before and after each iteration of a loop. \
*It is a useful tool for reasoning about the correctness and behavior of a loop-based algorithm.*

To establish the correctness of a loop invariant:
- **Initialization**: It is true prior to the first iteration of the loop.
- **Maintenance**: If it is true before an iteration of the loop, it remains true before the
next iteration.
- **Termination**: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.
  