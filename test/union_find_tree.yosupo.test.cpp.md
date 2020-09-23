---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':question:'
    path: data_structure/unionfind.cpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(UnionFind Tree)"
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/union_find_tree.yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"macro/macros.hpp\"\n\
    \n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
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
    \ 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n*/\n\n\n#line 1 \"data_structure/unionfind.cpp\"\
    \n\n\n#line 4 \"data_structure/unionfind.cpp\"\n\nstruct UnionFind{\n    int n;\n\
    \    vector<int> Parent;\n    vector<int> sizes;\n    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){\
    \ rep(i,n)Parent[i]=i; }\n    //find the root of x\n    int root(int x){\n   \
    \     if(x!=Parent[x]){\n        Parent[x] = root(Parent[x]);\n        }\n   \
    \     return Parent[x];\n    }\n    //merge x and y\n    void unite(int x,int\
    \ y){\n        x = root(x);\n        y = root(y);\n        if(x == y) return;\n\
    \        if(sizes[x] < sizes[y]) swap(x, y);\n        Parent[y] = x;\n       \
    \ sizes[x] += sizes[y];\n    }\n    bool same(int x,int y){ return root(x) ==\
    \ root(y); }\n    int size(int x){ return sizes[root(x)]; }\n    int group_num(){\n\
    \        set<int> s;\n        for(int i = 0; i < n; ++i){\n            s.insert(root(i));\n\
    \        }\n        return int(s.size());\n    }\n};\n\n#line 4 \"test/union_find_tree.yosupo.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    int n, q; cin >> n >> q;\n    UnionFind\
    \ uft(n);\n    rep (i, q) {\n        int t, u, v; cin >> t >> u >> v;\n      \
    \  if (t == 0) {\n            uft.unite(u, v);\n        } else if (t == 1) {\n\
    \            cout << uft.same(u, v) << endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../macro/macros.hpp\"\n#include \"../data_structure/unionfind.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    int n, q; cin >> n >> q;\n    UnionFind uft(n);\n\
    \    rep (i, q) {\n        int t, u, v; cin >> t >> u >> v;\n        if (t ==\
    \ 0) {\n            uft.unite(u, v);\n        } else if (t == 1) {\n         \
    \   cout << uft.same(u, v) << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - macro/macros.hpp
  - data_structure/unionfind.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/union_find_tree.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/union_find_tree.yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/union_find_tree.yosupo.test.cpp
- /verify/test/union_find_tree.yosupo.test.cpp.html
title: test/union_find_tree.yosupo.test.cpp
---
