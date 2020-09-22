---
category: "\u30B0\u30E9\u30D5/\u6700\u77ED\u7D4C\u8DEF\u554F\u984C"
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Class
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_11_C.test.cpp
    title: test/ALDS1_11_C.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/bfs.hpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    ;\n\n\n#line 1 \"graph/template.hpp\"\n\n\n#line 4 \"graph/template.hpp\"\n\n\
    /*\n@title Graph Class\n@category template\n*/\ntemplate<typename T = int>\nstruct\
    \ edge{\n    int to;\n    T cost;\n    int id;\n    edge(int _to, T _cost = 1,\
    \ int _id = -1) :to(_to), cost(_cost), id(_id) {}\n};\n\ntemplate<class T>\nclass\
    \ Graph {\n  public:\n    int N;\n    vvec<edge<T>> G;\n    Graph(int _N): N(_N),G(_N){\n\
    \    }\n    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){\n\
    \        G[from].push_back({to, cost, id});\n    }\n    void add_edge(int v1,\
    \ int v2, T cost = 1, int id = -1){\n        add_Directed_edge(v1, v2, cost, id);\n\
    \        add_Directed_edge(v2, v1, cost, id);\n    }\n    //standard input\n \
    \   void input(int M, int padding = -1, bool weighted = false, bool directed =\
    \ false){\n        while(M--){\n            int a, b;\n            cin >> a >>\
    \ b;\n            a += padding;\n            b += padding;\n            T c =\
    \ T(1);\n            if(weighted)cin >> c;\n            if(directed)add_Directed_edge(a,b,c);\n\
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n#line 5 \"graph/shortest_path/bfs.hpp\"\
    \n\ntemplate<typename T>\nclass BFS : public Graph<T>{\n  public:\n    using Graph<T>::N;\n\
    \    using Graph<T>::G;\n    vector<T> d;\n    BFS(int _N):Graph<T>::Graph(_N),\
    \ d(_N,-1){\n    }\n    vec<T> bfs(int start = 0){\n        queue<int> q;\n  \
    \      q.push(start);\n        d[start] = 0;\n        while(!q.empty()){\n   \
    \         int cur = q.front(); q.pop();\n            for(auto nv: G[cur]){\n \
    \               if(d[nv.to] != -1)continue;\n                d[nv.to] = d[cur]\
    \ + nv.cost;\n                q.push(nv.to);\n            }\n        }\n     \
    \   return d;\n    }\n};\n\n"
  code: "#ifndef BFS_HPP\n#define BFS_HPP\n#include \"../../macro/macros.hpp\"\n#include\
    \ \"../template.hpp\"\n\ntemplate<typename T>\nclass BFS : public Graph<T>{\n\
    \  public:\n    using Graph<T>::N;\n    using Graph<T>::G;\n    vector<T> d;\n\
    \    BFS(int _N):Graph<T>::Graph(_N), d(_N,-1){\n    }\n    vec<T> bfs(int start\
    \ = 0){\n        queue<int> q;\n        q.push(start);\n        d[start] = 0;\n\
    \        while(!q.empty()){\n            int cur = q.front(); q.pop();\n     \
    \       for(auto nv: G[cur]){\n                if(d[nv.to] != -1)continue;\n \
    \               d[nv.to] = d[cur] + nv.cost;\n                q.push(nv.to);\n\
    \            }\n        }\n        return d;\n    }\n};\n#endif"
  dependsOn:
  - macro/macros.hpp
  - graph/template.hpp
  - macro/macros.hpp
  isVerificationFile: false
  path: graph/shortest_path/bfs.hpp
  requiredBy: []
  timestamp: '2020-09-22 18:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_11_C.test.cpp
documentation_of: ./graph/shortest_path/bfs.hpp
layout: document
title: "\u5E45\u512A\u5148\u63A2\u7D22(Breadth-first search)"
---

### 計算量
$O(V+E)$

### 使用問題
- [ABC070 D - Transit Tree Path](https://atcoder.jp/contests/abc070/tasks/abc070_d)