# Algorithms

## What is an algorithm
An **algorithm** is any well-defined computational procedure that takes some value, or set of values, as **input** and produces some value, or set of values, as **output**.\
*An algorithm is thus a sequence of computational steps that transform the input into the output.*
### Pseudocode

**Pseudocode** is a method of representing algorithms using a combination of natural language and programming language-like constructs. \
*It provides a high-level description of the algorithm's logic and structure.*

When writing pseudocode, consider the following elements:

- **Problem definition**: Clearly define the problem that the algorithm aims to solve.
- **Variable initialization**: Declare and assign initial values to variables used in the algorithm.
- **Return statement**: Specify the output or result that the algorithm should produce.
- **Indentation**: Use proper indentation to indicate the hierarchical structure and flow of the algorithm.

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
- $log_{10}(n)=\Theta(log(n))$ (The base of the logarithm is not considered.)
- $\Theta(1)$ denotes a constant time complexity.
- The base of the logarithm does not affect the complexity: $log_{10}(n) = \Theta(log(n))$

## Random-Access Machine (RAM)

The **RAM (Random-Access Machine)** model of computation is a theoretical model used to analyze algorithms. It assumes a generic one-processor system where instructions are executed sequentially, without concurrent operations.\
*It provides a simplified representation of a computer's memory and processing capabilities for algorithmic analysis.*

- Accessing elements in memory takes constant time $\Theta(1)$ (elements = $w$ bits).
- Performing computations and operations on the elements also take constant time $\Theta(1)$.
- Writing elements to memory takes constant time  $\Theta(1)$.

## Loop Invariant

A **loop invariant** is a condition or property that remains true before and after each iteration of a loop. \
*It is a useful tool for reasoning about the correctness and behavior of a loop-based algorithm.*

By demonstrating these aspects, we can establish the correctness and reliability of the loop invariant, ensuring that the algorithm behaves as intended:

- **Initialization**: It is true prior to the first iteration of the loop.
- **Maintenance**: If it is true before an iteration of the loop, it remains true before the
next iteration.
- **Termination**: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.

