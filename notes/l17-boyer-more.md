# Boyer-Moore Algorithm

The **Boyer-Moore algorithm** is a string searching algorithm that efficiently finds occurrences of a pattern within a text. It employs two main rules: the *bad character rule* and the *good suffix rule*.

## 1. Right-to-left scan

The Boyer-Moore algorithm starts by scanning the text from *right to left*. This scanning direction has the advantage of skipping larger portions of the text when a mismatch occurs, as the rightmost characters in the pattern tend to vary less frequently in different patterns.

## 2. Bad character rule

The **bad character rule** helps determine the shift distance when a mismatch occurs between the pattern and the text. It considers the last character read from the pattern (denoted as 'y') and its alignment in the text ('x'). The rule is as follows:

- *Preprocessing*:
  - Define the alphabet of the text as ε, which includes characters from 1 to |ε|.
  - Compute an array R of size |ε|.
  - R[x] represents the position in the pattern of the rightmost occurrence of character x (or is empty if x is not in the pattern).
  - *Time complexity: Θ(|R| + |ε|)*

```py
ComputeR(P, e)
    R <- array of size |e| initialized with -1
    for i=|P| down to 1
        if R[P[i]]=0
            R[P[i]]<-i
    return R
```

The role of the bad character rule is to shift the pattern to the right by a distance of *max(1, i - R[T[k]])*, where i is the position of the first character that mismatches with T[k] in the pattern.

## 3. Good suffix rule

The **good suffix rule** is used to handle cases where a suffix of the pattern matches a substring of the text, but the preceding character is different. The rule involves two arrays: L and l.

- L[i] represents the largest position in the pattern such that the substring P[i, ..., |P|] is equal to a suffix of P[i, ..., j], and the preceding character is different from P[i-1]. In other words, L[i] stores the rightmost occurrence of the substring P[i, ..., |P|] that has a different preceding character in the pattern P.
- l[i] represents the length of the largest suffix of P[i, ..., |P|] that is also a prefix of P.

The time complexity of computing the good suffix arrays is *Θ(|P|)*.

## Boyer-Moore Galil's rule

In addition to the bad character and good suffix rules, Boyer-Moore algorithm can be further enhanced with **Galil's rule**. Galil's rule takes advantage of the concept of the *period* of a string.

- The period of a string S is the smallest integer p such that S[i] = S[i+p] for all i in the range [0, |S| - p].

To apply Galil's rule, the period q of the pattern P is computed during the preprocessing step, which can be done in *Θ(|P|)* time.

When an occurrence of the pattern is found, instead of shifting by one position, the pattern is shifted by *q* positions. Moreover, when checking for matches, only the last *q* characters of the pattern need to be compared.

```py
B-M(P, T)
    Compute R,L,l
    sol <- empty
    k <- |P| # k reads chars of T
    while k<=|T|
        i <- |P|
        h <- k
        while i>0 and P[i]=T[h]
            i <- i-1
            h <- i
        if i=0 then
            sol.append(k-|P|+1)
        else if i=|P| then
            k<-k+1
        else
            badc <- max(1, i-R[T[h]])
            if L[i+1]>0
                goods <- |P|-L[i+1]
            else
                goods <- |P|-l[i+1]
        k <- k+max(goods, badc)
    return sol
```
By incorporating Galil's rule, the Boyer-Moore algorithm can achieve further improvements in terms of efficiency.

## Summary

The Boyer-Moore algorithm with Galil's rule follows the steps:

1. **Right-to-left scan**: Scan the text from right to left.
2. **Bad character rule**: Determine the shift distance based on the rightmost occurrence of the character and the mismatch position in the pattern.
3. **Good suffix rule**: Handle cases where a suffix of the pattern matches a substring of the text but has a different preceding character.
4. **Galil's rule**: Shift the pattern by *q* positions and check only the last *q* characters of the pattern when a match is found.

This combination of rules makes the Boyer-Moore algorithm with Galil's rule a powerful and efficient string searching algorithm.
