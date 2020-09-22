---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/template.cpp
    title: Tree Class
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148/LCA(Lowest Common Acestor)"
  - icon: ':heavy_check_mark:'
    path: tree/tree-diameter-height.cpp
    title: "\u6728\u306E\u76F4\u5F84\u3068\u9AD8\u3055/Diameter and Height of a Tree\
      \ (\u5168\u65B9\u4F4D\u6728DP/Rerooting ver.)"
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs.hpp
    title: "\u5E45\u512A\u5148\u63A2\u7D22(Breadth-first search)"
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/warshall-floyd.cpp
    title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dikstra\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GRL_1_A_2.test.cpp
    title: test/GRL_1_A_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_1_A_2.test.cpp
    title: test/GRL_1_A_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_11_C.test.cpp
    title: test/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_11_C.test.cpp
    title: test/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_1_C.test.cpp
    title: test/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_1_C.test.cpp
    title: test/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_5_C.test.cpp
    title: test/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_5_A.test.cpp
    title: test/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/GRL_5_B.test.cpp
    title: test/GRL_5_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: Graph Class
    links: []
  bundledCode: "#line 1 \"graph/template.hpp\"\n\n\n#line 1 \"macro/macros.hpp\"\n\
    \n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
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
    ;\n\n\n#line 4 \"graph/template.hpp\"\n\n/*\n@title Graph Class\n@category template\n\
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
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n"
  code: "#ifndef GRAPH_TEMPLATE_HPP\n#define GRAPH_TEMPLATE_HPP\n#include \"../macro/macros.hpp\"\
    \n\n/*\n@title Graph Class\n@category template\n*/\ntemplate<typename T = int>\n\
    struct edge{\n    int to;\n    T cost;\n    int id;\n    edge(int _to, T _cost\
    \ = 1, int _id = -1) :to(_to), cost(_cost), id(_id) {}\n};\n\ntemplate<class T>\n\
    class Graph {\n  public:\n    int N;\n    vvec<edge<T>> G;\n    Graph(int _N):\
    \ N(_N),G(_N){\n    }\n    void add_Directed_edge(int from, int to, T cost = 1,\
    \ int id = -1){\n        G[from].push_back({to, cost, id});\n    }\n    void add_edge(int\
    \ v1, int v2, T cost = 1, int id = -1){\n        add_Directed_edge(v1, v2, cost,\
    \ id);\n        add_Directed_edge(v2, v1, cost, id);\n    }\n    //standard input\n\
    \    void input(int M, int padding = -1, bool weighted = false, bool directed\
    \ = false){\n        while(M--){\n            int a, b;\n            cin >> a\
    \ >> b;\n            a += padding;\n            b += padding;\n            T c\
    \ = T(1);\n            if(weighted)cin >> c;\n            if(directed)add_Directed_edge(a,b,c);\n\
    \            else add_edge(a,b,c);\n        }\n    }\n};\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - tree/template.cpp
  - tree/lca.cpp
  - tree/tree-diameter-height.cpp
  - graph/shortest_path/bfs.hpp
  - graph/shortest_path/warshall-floyd.cpp
  - graph/shortest_path/dijkstra.hpp
  timestamp: '2020-03-31 04:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GRL_1_A_2.test.cpp
  - test/GRL_1_A_2.test.cpp
  - test/ALDS1_11_C.test.cpp
  - test/ALDS1_11_C.test.cpp
  - test/GRL_1_C.test.cpp
  - test/GRL_1_C.test.cpp
  - test/GRL_5_C.test.cpp
  - test/GRL_5_A.test.cpp
  - test/GRL_5_B.test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: Graph Class
---
