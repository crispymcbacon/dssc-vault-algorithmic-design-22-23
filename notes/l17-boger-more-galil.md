
# Boger-Moore
### 1. Right-to-left scan
- Advantage: ??
### 2. Bad character rule
Suppose the last char we read from $P$ is y and it's aligned with.
$x\not ={y}$ in $T$

Preprocessing
- $\varepsilon$ = alphabet of $T$, chars form 1  to $|\varepsilon|$
- Compute array $R$ of size $|\varepsilon|$
- $R[x]$ = position in P of the rightmost occurence of $x$ ($\empty$ if $x\notin P$)

Time Complexity $\Theta (|R|+|\varepsilon|)$

$R[x]=i \Leftrightarrow (P[i]=x)\wedge(P[j]\not ={x}\space\forall j>i)$

```py
ComputeR(P, e)
    Allocate R of |e| zeroes
    for i=|P| down to 1
        if R[P[i]]=0
            R[P[i]]<-i
    return R
```

Role: let $i$ be the first char such that $P[i]$ is a mismatch with $T[k]$
Then, shift P to the right by $max\lbrace 1, i-R[T[k]]\rbrace$ 

### 3. Good suffix rule
- We have matched $|P|-i$ chars of P
  - $P[i]$ is the first mismatch
- We want find the rightmost copy of t in P that is preceded bu a char $z\not ={y}$
- We compare an array $L$ of size $|P|$, and another $l$ of size $|P|$
  - $L[i]=j \Leftrightarrow j$ is the largest position in P such that $P[i,\dots,|P|]$ is equal to a suffix of $P[i,\dots, j]$ and the char before it is $\not ={P[i-1]}$

Time Complexity is $\Theta(|P|)$
- $l[i]$ = length of the largest suffix of $P[i,\dots, |P|]$ that is also a prefix of P

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

Time Complexity $\Theta(|P|\cdot{|T|})$