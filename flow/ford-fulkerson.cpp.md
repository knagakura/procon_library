---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GRL_7_A.test.cpp
    title: test/GRL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_6_A.test.cpp
    title: test/GRL_6_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)"
    links: []
  bundledCode: "#line 1 \"flow/ford-fulkerson.cpp\"\n\n\n\n#line 1 \"macro/macros.hpp\"\
    \n\n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\ntypedef long long ll;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n\
    #define rep1(i,N) for(int i=1;i<int(N);++i)\n#define all(a) (a).begin(),(a).end()\n\
    #define bit(k) (1LL<<(k))\n#define SUM(v) accumulate(all(v), 0LL)\n\ntypedef pair<int,\
    \ int> i_i;\ntypedef pair<ll, ll> l_l;\ntemplate <class T> using vec = vector<T>;\n\
    template <class T> using vvec = vector<vec<T>>;\nstruct fast_ios{ fast_ios(){\
    \ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);\
    \ }; }fast_ios_;\n\ntemplate<class T> inline bool chmax(T& a, T b) { if (a < b)\
    \ { a = b; return true; } return false; }\ntemplate<class T> inline bool chmin(T&\
    \ a, T b) { if (a > b) { a = b; return true; } return false; }\n\n#define TOSTRING(x)\
    \ string(#x)\ntemplate <typename T> istream &operator>>(istream &is, vector<T>\
    \ &vec) { for (T &x : vec) is >> x; return is; }\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, const vector<T> &v) { os  << \"[\"; for(auto _: v)\
    \ os << _ << \", \"; os << \"]\"; return os; };\ntemplate <typename T> ostream\
    \ &operator<<(ostream &os, set<T> &st) { os << \"(\"; for(auto _: st) { os <<\
    \ _ << \", \"; } os << \")\";return os;}\ntemplate <typename T, typename U> ostream\
    \ &operator<<(ostream &os, const pair< T, U >& p){os << \"{\" <<p.first << \"\
    , \" << p.second << \"}\";return os; }\ntemplate <typename T, typename U> ostream\
    \ &operator<<(ostream &os, const map<T, U> &mp){ os << \"[\"; for(auto _: mp){\
    \ os << _ << \", \"; } os << \"]\" << endl; return os; }\n\n#define DUMPOUT cerr\n\
    void dump_func(){ DUMPOUT << endl; }\ntemplate <class Head, class... Tail> void\
    \ dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail)\
    \ > 0) { DUMPOUT << \", \"; } dump_func(std::move(tail)...); }\n\n#ifdef DEBUG\n\
    #define dbg(...) dump_func(__VA_ARGS__)\n#define dump(...) DUMPOUT << string(#__VA_ARGS__)\
    \ << \": \"; dump_func(__VA_ARGS__)\n#else\n#define dbg(...)\n#define dump(...)\n\
    #endif\n\nconst int INF = (ll)1e9;\nconst ll INFLL = (ll)1e18+1;\nconst ll MOD\
    \ = 1000000007;\n// const ll MOD = 998244353;\nconst long double PI = acos(-1.0);\n\
    \nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1, 0,\
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 5 \"flow/ford-fulkerson.cpp\"\
    \n/*\n\n@title \u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)\n@category \u30CD\u30C3\
    \u30C8\u30EF\u30FC\u30AF\u30D5\u30ED\u30FC\n\n*/\n\n\ntemplate<typename T>\nstruct\
    \ edge{\n    int to;\n    T cap;\n    int rev;\n};\ntemplate<typename T>\nstruct\
    \ FordFulkerson{\n    int V;\n    vector<vector<edge<T>>> G;\n    vector<bool>\
    \ used;\n    T inf;\n    FordFulkerson(int V_, T inf_):V(V_), inf(inf_){\n   \
    \     G.resize(V);\n        used.assign(V, false);\n    }\n    void add_edge(int\
    \ from, int to, T cap){\n        G[from].push_back((edge<T>){to, cap, (int)G[to].size()});\n\
    \        G[to].push_back((edge<T>){from, 0, (int)G[from].size()-1});\n    }\n\
    \    T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] =\
    \ true;\n        for(auto &&e: G[v]){\n            if(used[e.to])continue;\n \
    \           if(e.cap <= 0)continue;\n            T d = dfs(e.to, t, min(f, e.cap));\n\
    \            if(d > 0){\n                e.cap -= d;\n                G[e.to][e.rev].cap\
    \ += d;\n                return d;\n            }\n        }\n        return 0;\n\
    \    }\n    T max_flow(int s, int t){\n        T flow = 0;\n        for( ; ; ){\n\
    \            used.assign(V, false);\n            T f = dfs(s, t, inf);\n     \
    \       if(f == 0)return flow;\n            flow += f;\n        }\n    }\n};\n\
    \n\n\n"
  code: "#ifndef MAX_FLOW\n#define MAX_FLOW\n\n#include \"../macro/macros.hpp\"\n\
    /*\n\n@title \u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)\n@category \u30CD\u30C3\u30C8\
    \u30EF\u30FC\u30AF\u30D5\u30ED\u30FC\n\n*/\n\n\ntemplate<typename T>\nstruct edge{\n\
    \    int to;\n    T cap;\n    int rev;\n};\ntemplate<typename T>\nstruct FordFulkerson{\n\
    \    int V;\n    vector<vector<edge<T>>> G;\n    vector<bool> used;\n    T inf;\n\
    \    FordFulkerson(int V_, T inf_):V(V_), inf(inf_){\n        G.resize(V);\n \
    \       used.assign(V, false);\n    }\n    void add_edge(int from, int to, T cap){\n\
    \        G[from].push_back((edge<T>){to, cap, (int)G[to].size()});\n        G[to].push_back((edge<T>){from,\
    \ 0, (int)G[from].size()-1});\n    }\n    T dfs(int v, int t, T f){\n        if(v\
    \ == t)return f;\n        used[v] = true;\n        for(auto &&e: G[v]){\n    \
    \        if(used[e.to])continue;\n            if(e.cap <= 0)continue;\n      \
    \      T d = dfs(e.to, t, min(f, e.cap));\n            if(d > 0){\n          \
    \      e.cap -= d;\n                G[e.to][e.rev].cap += d;\n               \
    \ return d;\n            }\n        }\n        return 0;\n    }\n    T max_flow(int\
    \ s, int t){\n        T flow = 0;\n        for( ; ; ){\n            used.assign(V,\
    \ false);\n            T f = dfs(s, t, inf);\n            if(f == 0)return flow;\n\
    \            flow += f;\n        }\n    }\n};\n\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: flow/ford-fulkerson.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GRL_7_A.test.cpp
  - test/GRL_6_A.test.cpp
documentation_of: ./flow/ford-fulkerson.cpp
layout: document
title: "Ford Fulkerson\u6CD5"
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