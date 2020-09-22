---
title: Ford Fulkerson法
documentation_of: ./flow/ford-fulkerson.cpp
---

## 説明
### 計算量
最大流の流量を$F$、辺数を$E$とすると、$O(FE)$。

### 説明
- 使い方
```cpp
    FuldFulkerson<ll> G(N, INFLL);
    G.add_edge(a, b, cap);
    G.max_flow(source, sink);
```
### 参考
- 蟻本 p188 ~ 191

### 手動verify

- [No.654 Air E869120](https://yukicoder.me/problems/no/654)
    - [Submission](https://yukicoder.me/submissions/557019)