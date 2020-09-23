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
    - 応用問題

- [F - RPG](https://atcoder.jp/contests/wupc2019/tasks/wupc2019_f)
    - [Submission](https://atcoder.jp/contests/wupc2019/submissions/16961850)
    - 応用問題。

- [C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)
    - [Submission](https://atcoder.jp/contests/abc091/submissions/16966878)
    - 二部マッチング
