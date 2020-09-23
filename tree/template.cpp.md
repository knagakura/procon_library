---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Class
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148/LCA(Lowest Common Acestor)"
  - icon: ':x:'
    path: tree/tree-diameter-height.cpp
    title: "\u6728\u306E\u76F4\u5F84\u3068\u9AD8\u3055/Diameter and Height of a Tree\
      \ (\u5168\u65B9\u4F4D\u6728DP/Rerooting ver.)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GRL_5_C.test.cpp
    title: test/GRL_5_C.test.cpp
  - icon: ':x:'
    path: test/GRL_5_A.test.cpp
    title: test/GRL_5_A.test.cpp
  - icon: ':x:'
    path: test/GRL_5_A.test.cpp
    title: test/GRL_5_A.test.cpp
  - icon: ':x:'
    path: test/GRL_5_B.test.cpp
    title: test/GRL_5_B.test.cpp
  - icon: ':x:'
    path: test/GRL_5_B.test.cpp
    title: test/GRL_5_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Tree Class
    links: []
  bundledCode: "#line 1 \"tree/template.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\n\n\
    \n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
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
    \ 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n*/\n\n\n#line 1 \"graph/template.hpp\"\
    \n\n\n#line 4 \"graph/template.hpp\"\n\n/*\n@title Graph Class\n@category template\n\
    */\ntemplate<typename T = int>\nstruct edge{\n    int to;\n    T cost;\n    int\
    \ id;\n    edge(int _to, T _cost = 1, int _id = -1) :to(_to), cost(_cost), id(_id)\
    \ {}\n};\n\ntemplate<class T>\nclass Graph {\n  public:\n    int N;\n    vvec<edge<T>>\
    \ G;\n    Graph(int _N): N(_N),G(_N){\n    }\n    void add_Directed_edge(int from,\
    \ int to, T cost = 1, int id = -1){\n        G[from].push_back({to, cost, id});\n\
    \    }\n    void add_edge(int v1, int v2, T cost = 1, int id = -1){\n        add_Directed_edge(v1,\
    \ v2, cost, id);\n        add_Directed_edge(v2, v1, cost, id);\n    }\n    //standard\
    \ input\n    void input(int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n        while(M--){\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)cin >> c;\n            if(directed)add_Directed_edge(a,b,c);\n\
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n#line 5 \"tree/template.cpp\"\
    \n\n/*\n@title Tree Class\n@category template\n*/\ntemplate<class T>\nclass Tree\
    \ {\n  public:\n    int N;\n    vvec<edge<T>> G;\n    Tree(int _N): N(_N),G(_N){\n\
    \    }\n    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){\n\
    \        G[from].push_back({to, cost, id});\n    }\n    void add_edge(int v1,\
    \ int v2, T cost = 1, int id = -1){\n        add_Directed_edge(v1, v2, cost, id);\n\
    \        add_Directed_edge(v2, v1, cost, id);\n    }\n    //standard input\n \
    \   void input(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false){\n        while(M--){\n            int a, b;\n            cin >> a >>\
    \ b;\n            a += padding;\n            b += padding;\n            T c =\
    \ T(1);\n            if(weighted)cin >> c;\n            if(directed)add_Directed_edge(a,b,c);\n\
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n\n"
  code: "#ifndef TREE_TEMPLATE_CPP\n#define TREE_TEMPLATE_CPP\n#include \"../macro/macros.hpp\"\
    \n#include \"../graph/template.hpp\"\n\n/*\n@title Tree Class\n@category template\n\
    */\ntemplate<class T>\nclass Tree {\n  public:\n    int N;\n    vvec<edge<T>>\
    \ G;\n    Tree(int _N): N(_N),G(_N){\n    }\n    void add_Directed_edge(int from,\
    \ int to, T cost = 1, int id = -1){\n        G[from].push_back({to, cost, id});\n\
    \    }\n    void add_edge(int v1, int v2, T cost = 1, int id = -1){\n        add_Directed_edge(v1,\
    \ v2, cost, id);\n        add_Directed_edge(v2, v1, cost, id);\n    }\n    //standard\
    \ input\n    void input(int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n        while(M--){\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)cin >> c;\n            if(directed)add_Directed_edge(a,b,c);\n\
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  - graph/template.hpp
  - macro/macros.hpp
  isVerificationFile: false
  path: tree/template.cpp
  requiredBy:
  - tree/lca.cpp
  - tree/tree-diameter-height.cpp
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/GRL_5_C.test.cpp
  - test/GRL_5_A.test.cpp
  - test/GRL_5_A.test.cpp
  - test/GRL_5_B.test.cpp
  - test/GRL_5_B.test.cpp
documentation_of: tree/template.cpp
layout: document
redirect_from:
- /library/tree/template.cpp
- /library/tree/template.cpp.html
title: Tree Class
---
