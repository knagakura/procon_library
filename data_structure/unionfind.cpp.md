---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DSL_1_A.test.cpp
    title: test/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/union_find_tree.yosupo.test.cpp
    title: test/union_find_tree.yosupo.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data_structure/unionfind.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
    \n\n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n#define rep1(i,N)\
    \ for(int i=1;i<int(N);++i)\n#define all(a) (a).begin(),(a).end()\n#define print(v)\
    \ { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<_<<\", \"; cerr<<\"]\"<<endl; }\n\
    #define printpair(v) { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<\"{\"<<_.first<<\"\
    ,\"<<_.second<<\"}\"<<\", \"; cerr<<\"]\"<<endl; }\n#define dump(x) cerr<<#x<<\"\
    : \"<<x<<endl;\n#define bit(k) (1LL<<(k))\n#define Yes \"Yes\"\n#define No \"\
    No\"\n#define YES \"YES\"\n#define NO \"NO\"\ntypedef long long ll;\n\ntemplate<\
    \ typename T1, typename T2 >\nostream &operator<<(ostream &os, const pair< T1,\
    \ T2 >& p) {\n  os << \"{\" <<p.first << \", \" << p.second << \"}\";\n  return\
    \ os;\n}\ntemplate <class T> using vec = vector<T>;\ntemplate <class T> using\
    \ vvec = vector<vec<T>>;\n\ntemplate<class T> inline bool chmax(T& a, T b) { if\
    \ (a < b) { a = b; return true; } return false; }\ntemplate<class T> inline bool\
    \ chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }\n\nconst\
    \ int INF = (ll)1e9;\nconst ll INFLL = (ll)1e18+1;\nconst ll MOD = (ll)1e9+7;\n\
    \nconst double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1,\
    \ 1};\nconst int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\"\
    ;\n\n\n#line 4 \"data_structure/unionfind.cpp\"\n\nstruct UnionFind{\n    int\
    \ n;\n    vector<int> Parent;\n    vector<int> sizes;\n    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){\
    \ rep(i,n)Parent[i]=i; }\n    //find the root of x\n    int root(int x){\n   \
    \     if(x!=Parent[x]){\n        Parent[x] = root(Parent[x]);\n        }\n   \
    \     return Parent[x];\n    }\n    //merge x and y\n    void unite(int x,int\
    \ y){\n        x = root(x);\n        y = root(y);\n        if(x == y) return;\n\
    \        if(sizes[x] < sizes[y]) swap(x, y);\n        Parent[y] = x;\n       \
    \ sizes[x] += sizes[y];\n    }\n    bool same(int x,int y){ return root(x) ==\
    \ root(y); }\n    int size(int x){ return sizes[root(x)]; }\n    int group_num(){\n\
    \        set<int> s;\n        for(int i = 0; i < n; ++i){\n            s.insert(root(i));\n\
    \        }\n        return int(s.size());\n    }\n};\n\n"
  code: "#ifndef INCLUDED_UNIONFIND_CPP\n#define INCLUDED_UNIONFIND_CPP\n#include\
    \ \"../macro/macros.hpp\"\n\nstruct UnionFind{\n    int n;\n    vector<int> Parent;\n\
    \    vector<int> sizes;\n    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i;\
    \ }\n    //find the root of x\n    int root(int x){\n        if(x!=Parent[x]){\n\
    \        Parent[x] = root(Parent[x]);\n        }\n        return Parent[x];\n\
    \    }\n    //merge x and y\n    void unite(int x,int y){\n        x = root(x);\n\
    \        y = root(y);\n        if(x == y) return;\n        if(sizes[x] < sizes[y])\
    \ swap(x, y);\n        Parent[y] = x;\n        sizes[x] += sizes[y];\n    }\n\
    \    bool same(int x,int y){ return root(x) == root(y); }\n    int size(int x){\
    \ return sizes[root(x)]; }\n    int group_num(){\n        set<int> s;\n      \
    \  for(int i = 0; i < n; ++i){\n            s.insert(root(i));\n        }\n  \
    \      return int(s.size());\n    }\n};\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: data_structure/unionfind.cpp
  requiredBy: []
  timestamp: '2020-09-22 16:57:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DSL_1_A.test.cpp
  - test/union_find_tree.yosupo.test.cpp
documentation_of: ./data_structure/unionfind.cpp
layout: document
title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(UnionFind Tree)"
---

## UnionFind木が出題された問題
1. [D-Decayed Bridges](https://beta.atcoder.jp/contests/abc120)

    UnionFind木は繋がりを断つことはできないが、構成することはできるので、逆からやるやつ。

1. [D-Equals](https://beta.atcoder.jp/contests/abc097)

    swapすればそれらは行き来可能になるので、実質パイプ。

1. [B-Union Find](https://beta.atcoder.jp/contests/atc001)

    典型問題。uniteして、繋がってるか聞かれたら答えるだけ。

1. [B-道路工事](https://beta.atcoder.jp/contests/arc032/)

    すべての点に対して根を考えることで、グループが幾つに分かれているかを知ることができる


1. [D-連結](https://beta.atcoder.jp/contests/abc049)

    - [解説](http://drken1215.hatenablog.com/entry/2019/06/29/182300)

    二つのUnionFind木を管理して、同時に繋がっていることを根のPairを持ってmapで管理すると良い


1. [D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)

    - [提出](https://atcoder.jp/contests/abc157/submissions/10460043)

    友達関係のグルーピングに使う。sizeも用いた。


1. [E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)
    - [提出](https://atcoder.jp/contests/abc126/submissions/10649376)

    集合の数を管理するgroup_numを実装した
