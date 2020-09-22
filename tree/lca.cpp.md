---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: tree/template.cpp
    title: Tree Class
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Class
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GRL_5_C.test.cpp
    title: test/GRL_5_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5C0F\u5171\u901A\u7956\u5148/LCA(Lowest Common Acestor)"
    links: []
  bundledCode: "#line 1 \"tree/lca.cpp\"\n/*\n@title \u6700\u5C0F\u5171\u901A\u7956\
    \u5148/LCA(Lowest Common Acestor)\n*/\n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n\
    @title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n#define rep1(i,N) for(int\
    \ i=1;i<int(N);++i)\n#define all(a) (a).begin(),(a).end()\n#define print(v) {\
    \ cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<_<<\", \"; cerr<<\"]\"<<endl; }\n\
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
    ;\n\n\n#line 1 \"tree/template.cpp\"\n\n\n#line 1 \"graph/template.hpp\"\n\n\n\
    #line 4 \"graph/template.hpp\"\n\n/*\n@title Graph Class\n@category template\n\
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
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n\n#line 6 \"tree/lca.cpp\"\
    \n\ntemplate<typename T>\nclass LCA :  public Tree<T>{\n  public:\n    using Tree<T>::N;\n\
    \    using Tree<T>::G;\n    int bitlen = 1;\n    vector<int> d; //depth\n    vector<vector<int>>\
    \ anc; // bitlen * N\n    LCA(int _N):Tree<T>::Tree(_N){\n        init(_N);\n\
    \    }\n    void init(int n){\n        while((1 << bitlen) < n){\n           \
    \ bitlen++;\n        }\n        d.assign(n, 0);\n        anc.assign(bitlen, vector<int>(n,-1));\n\
    \    }\n    void dfs(int v = 0, int p = -1){\n        anc[0][v] = p;\n       \
    \ for(int i = 0; i+1 < bitlen; ++i){\n            anc[i+1][v] = (anc[i][v] >=\
    \ 0) ? anc[i][anc[i][v]] : -1;\n        }\n        for(auto ne: G[v]) if(ne.to\
    \ != p){\n            d[ne.to] = d[v]+1;\n            dfs(ne.to, v);\n       \
    \ }\n    }\n    int lca(int u, int v){\n        if(d[u] > d[v]) swap(u, v);\n\
    \        for(int i = 0; i < bitlen;i++){\n            if((d[v] - d[u]) & (1<<i)){\n\
    \                v = anc[i][v];\n            }\n        }\n        if(u == v)\
    \ return u;\n        for(int i = bitlen-1; i >= 0;i--){\n            if(anc[i][u]\
    \ != anc[i][v]){\n                u = anc[i][u];\n                v = anc[i][v];\n\
    \            }\n        }\n        return anc[0][u];\n    }\n    int calc_dist(int\
    \ u, int v) {\n\t\tint l = lca(u, v);\n\t\treturn d[u] + d[v] - d[l] * 2;\n  \
    \  }\n};\n"
  code: "/*\n@title \u6700\u5C0F\u5171\u901A\u7956\u5148/LCA(Lowest Common Acestor)\n\
    */\n#include \"../macro/macros.hpp\"\n#include \"template.cpp\"\n\ntemplate<typename\
    \ T>\nclass LCA :  public Tree<T>{\n  public:\n    using Tree<T>::N;\n    using\
    \ Tree<T>::G;\n    int bitlen = 1;\n    vector<int> d; //depth\n    vector<vector<int>>\
    \ anc; // bitlen * N\n    LCA(int _N):Tree<T>::Tree(_N){\n        init(_N);\n\
    \    }\n    void init(int n){\n        while((1 << bitlen) < n){\n           \
    \ bitlen++;\n        }\n        d.assign(n, 0);\n        anc.assign(bitlen, vector<int>(n,-1));\n\
    \    }\n    void dfs(int v = 0, int p = -1){\n        anc[0][v] = p;\n       \
    \ for(int i = 0; i+1 < bitlen; ++i){\n            anc[i+1][v] = (anc[i][v] >=\
    \ 0) ? anc[i][anc[i][v]] : -1;\n        }\n        for(auto ne: G[v]) if(ne.to\
    \ != p){\n            d[ne.to] = d[v]+1;\n            dfs(ne.to, v);\n       \
    \ }\n    }\n    int lca(int u, int v){\n        if(d[u] > d[v]) swap(u, v);\n\
    \        for(int i = 0; i < bitlen;i++){\n            if((d[v] - d[u]) & (1<<i)){\n\
    \                v = anc[i][v];\n            }\n        }\n        if(u == v)\
    \ return u;\n        for(int i = bitlen-1; i >= 0;i--){\n            if(anc[i][u]\
    \ != anc[i][v]){\n                u = anc[i][u];\n                v = anc[i][v];\n\
    \            }\n        }\n        return anc[0][u];\n    }\n    int calc_dist(int\
    \ u, int v) {\n\t\tint l = lca(u, v);\n\t\treturn d[u] + d[v] - d[l] * 2;\n  \
    \  }\n};\n"
  dependsOn:
  - macro/macros.hpp
  - tree/template.cpp
  - graph/template.hpp
  - macro/macros.hpp
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2020-03-31 04:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GRL_5_C.test.cpp
documentation_of: tree/lca.cpp
layout: document
redirect_from:
- /library/tree/lca.cpp
- /library/tree/lca.cpp.html
title: "\u6700\u5C0F\u5171\u901A\u7956\u5148/LCA(Lowest Common Acestor)"
---