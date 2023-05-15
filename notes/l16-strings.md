- **Strings**:
	- a sequence of characters from an alphabet $\varepsilon=\left\lbrace 0,1 \right\rbrace, \left\lbrace a,b,c,\dots \right\rbrace,\dots,\mathbb{N}$ 
- **Length of S**:
	- $|S|$ = \# of chars
- **Concatenation**:
	- eg. $S=AACGT, T=CTE \to ST=S\cdot T=AACGTCTE$
- **Indexing**:
	- $S = S[1, ..., |S|], S[i]$  es. $S[3]=c$ 
- **Substring**:
	- $S[i,j]=S[i,\dots,j]$ eg. S\[2,4\]=ACG
	- **Length**: $S[i,j]$ l = j-i+1
- **Proper substring**:
	- $i\leq j$ (otherwise empty $\varepsilon$) & $[i,j]\neq[i,|S|]$ (not the whole string)
- **Prefix**:
	- $S[1,i]$
- **Suffix**:
	- $S[j,|S|]$

Eg.
$T=abcabaabca$ \
$P=abaa$ \
$P$ occurs in $T$ at position $i$ iff $T[i,\dots,i+|P|-1]=P\left[ i,\dots,|P| \right]$ \
$P$ occurs in $T$ at 4 with shift 3 & occurs in 10 with shift 9 ($i-1$)

Pattern matching problem \
*IN*: $T,P$ \
*OUT*: all the occurrences of $P$ in $T$

**Naive Algorithm**
```sql
Naive(T, P)
sol<-empty
for S=0 to |T|-|P|
	i<-1
	while i<=|P| and T[S+i]=P[i]
		i<-i+1
	if i>|P|
		sol.append(s)
return sol
```

**Time Complexity**
$|P|=m, |T|=n$ \
$O((n-m)m)=O(n\cdot m)$

We aim to $O(n+m)$

**Idea**: skip useless comparisons by spending time learning the structure of $P/T$ (**preprocess**)

**Knuth-Moms-Pratt (KMP)**
1. Preprocess $P$
2. Use it in a smart way
**Idea:** How does $P$ match against shifts of itself?

$\Pi[i]$ = length of the longest suffix of $P[1,\dots,i]$ which is equal to a prefix of P\
$|\Pi|=|P|$

How do we use $\Pi$?
1. If $q$ ??? of $P$ matched with a shift $S$. The next potentially valid shift is $S^{'}=S+(q-\Pi[q])$
2. Skip comparing the first $\Pi[q]$ chars with shift $S^{'}$

---

Naive:
- Check all prefixes
- Check all suffixes of the prefix

Time Complexity: $\Theta(|P|^2)$
- For a prefix of length $k$ check $k-1$ suffixes
- There are $|P|$ prefixes to check $\sum_{i=1}^{P}{(i-1)}=P^2$

Compute $\Pi$
```sql
COMPUTE_PI(P)
	allocate pi[i,...,|P|]
	pi[1]<-0
	k<-0
	for q=2 to |P|
		while k>0 and P[k+1]!=P[q]
			k<-pi[k]
		if P[k+1]=P[q]
			k<-k+1
		pi[q]<-k
	return pi

COMPUTE_PI(P)
	allocate pi[i,...,|P|]
	pi[1]<-0
	k<-0
	for q=2 to |P|
		while k>0 and P[k+1]!=P[q]
			k<-pi[k]
		if P[k+1]=P[q]
			k<-k+1
		pi[q]<-k
	return pi
```

```sql
KMP(T, P)
	pi<-compute_prefix(P);
	q<-0
	sol<-empty
	for i=1 to |T|
		while q>0 and P[q+1]!=T[i]
			q <-pi[q]
		if P[q+1]=T[i]
			q<-q+1
		if q=|P|
			sol.append(i-|P|)
			q<-pi[q]
	return sol

```