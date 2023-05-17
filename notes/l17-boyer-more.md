# Boyer-Moore Algorithm

The **Boyer-Moore algorithm** is a string searching algorithm that efficiently finds occurrences of a pattern within a text. It employs two main rules: the *bad character rule* and the *good suffix rule*.

## 1. Right-to-left scan

The Boyer-Moore algorithm starts by scanning the text from *right to left*. This scanning direction has the advantage of skipping larger portions of the text when a mismatch occurs, as the rightmost characters in the pattern tend to vary less frequently in different patterns.

## 2. Bad character rule

The **bad character rule** helps determine the shift distance when a mismatch occurs between the pattern and the text. It considers the last character read from the pattern (denoted as 'y') and its alignment in the text ('x'). The rule is as follows:

- *Preprocessing*:
  - Define the alphabet of the text as ε, which includes characters from 1 to $|\Sigma|$.
  - Compute an array R of size $|\Sigma|$.
  - R[x] represents the position in the pattern of the rightmost occurrence of character x (or is empty if x is not in the pattern).
  - *Time complexity: Θ(|R| + $|\Sigma|$)*

```py
ComputeR(P, e)
    R <- array of size |e| initialized with 0
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
            k <- k+1
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

The Boyer-Moore algorithm is a special way to find words or patterns in a bunch of text. It has some rules that help it work faster and find things quickly.

Here's how it works:

1. First, it starts looking at the text from the **right side** and moves to the **left side**. This way, it can skip big parts of the text when it sees something that doesn't match the pattern.

2. It has a rule called the "**bad character rule**." This rule helps the algorithm know how much to move when it finds a letter that doesn't match the pattern. It looks at the last letter it read from the pattern and where it is in the text. Then it figures out how much to move the pattern to the right to keep looking.

3. It also has a rule called the "**good suffix rule**." This rule helps when the end of the pattern matches part of the text, but the letter before it is different. It uses two arrays called L and l to figure out the best way to move the pattern.

4. The Boyer-Moore algorithm can be made even better by using **Galil's rule**. This rule takes advantage of something called the "period" of a string. The period is the smallest number of characters that keeps repeating in a string. By finding the period of the pattern, the algorithm can move faster when it finds a match and only needs to check a few letters.

By using these rules together, the Boyer-Moore algorithm becomes really good at finding words or patterns in text quickly and efficiently.

### Useful links:
- [ADS1: Boyer-Moore: basics (YouTube)](https://youtu.be/4Xyhb72LCX4)
- [ADS1: Boyer-Moore: putting it all together (YouTube)](https://www.youtube.com/watch?v=Wj606N0IAsw)
- [ADS1: Boyer-Moore: Preprocessing (YouTube)](https://youtu.be/HGVQi5xX44M)