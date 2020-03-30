### 計算量
$O(\min(N,K) \log N)$

### 説明
[第二種スターリング数](https://knagakura.github.io/procon_library/library/math/stiring-number-second.cpp.html)を$S(n, k)$とすると、ベル数は

$B(n, k) := \sum_{j = 0}^{k}S(n, j)$

と表される。第二種スターリング数を「ちょうど$k$個のグループに分ける場合の数」だと考えると、ベル数は「$k$個以下のグループに分ける場合の数」と考えることができるからである。

愚直に計算すると$O(NK\log N)$かかる計算量が、以下のような式変形により、第二種スターリング数の直接計算と同等の計算量に落ちる。

$B(n, k)$

$= \sum_{j = 0}^{k}S(n, j)$

$=  \sum_{j = 0}^{k} \frac{1}{j!}\sum_{i=0}^{j} (-1)^{j-i} {}_{j} C _{i} {i}^n$

$= \sum_{i = 0}^{k} \frac{1}{j!}\sum_{j=i}^{k} (-1)^{j-i} {}_{j} C _{i} {i}^n$　　　　($\sum$の入れ替え。$i \leq j$が保たれていればよい)

$= \sum_{i = 0}^{k} \sum_{j=i}^{k} \frac{1}{j!}(-1)^{j-i} {}_{j} C _{i} {i}^n$

$= \sum_{i = 0}^{k} \sum_{j=i}^{k} \frac{1}{j!}(-1)^{j-i} \frac{j!}{i!(j-i)!} {i}^n$

$= \sum_{i = 0}^{k} \sum_{j=i}^{k}  \frac{(-1)^{j-i}}{i!(j-i)!} {i}^n$　　 

$ = \sum_{i = 0}^{k} \sum_{j=0}^{k-i} \frac{(-1)^{j}}{i!{j}!} {i}^n$　　　　($j' = j - i$と変数変換し、$j' = j$と置き換える)


$ = \sum_{i = 0}^{k}\frac{i^n}{i!} \sum_{j=0}^{k-i} \frac{(-1)^j}{j!}$



$\sum_{j=0}^{k-i} \frac{(-1)^{j}}{j!}$については前処理により$O(K)$で計算可能なので、ベル数$B(n, k)$を$k$個の足し算で計算できる。$i^n$に$O(\log N)$だけかかるので、全体として$O(\min(N,K) \log N)$である。
