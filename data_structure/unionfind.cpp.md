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
  - icon: ':x:'
    path: test/union_find_tree.yosupo.test.cpp
    title: test/union_find_tree.yosupo.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data_structure/unionfind.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    \n/*\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n*/\n\n\n#line 4 \"data_structure/unionfind.cpp\"\
    \n\nstruct UnionFind{\n    int n;\n    vector<int> Parent;\n    vector<int> sizes;\n\
    \    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }\n\
    \    //find the root of x\n    int root(int x){\n        if(x!=Parent[x]){\n \
    \       Parent[x] = root(Parent[x]);\n        }\n        return Parent[x];\n \
    \   }\n    //merge x and y\n    void unite(int x,int y){\n        x = root(x);\n\
    \        y = root(y);\n        if(x == y) return;\n        if(sizes[x] < sizes[y])\
    \ swap(x, y);\n        Parent[y] = x;\n        sizes[x] += sizes[y];\n    }\n\
    \    bool same(int x,int y){ return root(x) == root(y); }\n    int size(int x){\
    \ return sizes[root(x)]; }\n    int group_num(){\n        set<int> s;\n      \
    \  for(int i = 0; i < n; ++i){\n            s.insert(root(i));\n        }\n  \
    \      return int(s.size());\n    }\n};\n\n"
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
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/DSL_1_A.test.cpp
  - test/union_find_tree.yosupo.test.cpp
documentation_of: ./data_structure/unionfind.cpp
layout: document
title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(UnionFind Tree)"
---

## UnionFind木が出題された問題
- [D-Decayed Bridges](https://beta.atcoder.jp/contests/abc120)
UnionFind木は繋がりを断つことはできないが、構成することはできるので、逆からやるやつ。
- [D-Equals](https://beta.atcoder.jp/contests/abc097)
swapすればそれらは行き来可能になるので、実質パイプ。
- [B-Union Find](https://beta.atcoder.jp/contests/atc001)
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
- [B-道路工事](https://beta.atcoder.jp/contests/arc032/)
すべての点に対して根を考えることで、グループが幾つに分かれているかを知ることができる
- [D-連結](https://beta.atcoder.jp/contests/abc049)
[解説](http://drken1215.hatenablog.com/entry/2019/06/29/182300)
二つのUnionFind木を管理して、同時に繋がっていることを根のPairを持ってmapで管理すると良い
- [D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)
[提出](https://atcoder.jp/contests/abc157/submissions/10460043)
友達関係のグルーピングに使う。sizeも用いた。
- [E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)
[提出](https://atcoder.jp/contests/abc126/submissions/10649376)
集合の数を管理するgroup_numを実装した
- [A - Reachable Towns](https://atcoder.jp/contests/acl1/tasks/acl1_a)
uniteした後、y座標が最小のものにグループを代表させる
