---
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
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: "Dikstra\u6CD5"
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Class
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
  bundledCode: "#line 1 \"test/GRL_1_A_2.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n*/\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n\
    #define rep1(i,N) for(int i=1;i<int(N);++i)\n#define all(a) (a).begin(),(a).end()\n\
    #define print(v) { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<_<<\", \"; cerr<<\"\
    ]\"<<endl; }\n#define printpair(v) { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<\"\
    {\"<<_.first<<\",\"<<_.second<<\"}\"<<\", \"; cerr<<\"]\"<<endl; }\n#define dump(x)\
    \ cerr<<#x<<\": \"<<x<<endl;\n#define bit(k) (1LL<<(k))\n#define Yes \"Yes\"\n\
    #define No \"No\"\n#define YES \"YES\"\n#define NO \"NO\"\ntypedef long long ll;\n\
    \ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << \"{\" <<p.first << \", \" << p.second << \"}\"\
    ;\n  return os;\n}\ntemplate <class T> using vec = vector<T>;\ntemplate <class\
    \ T> using vvec = vector<vec<T>>;\n\ntemplate<class T> inline bool chmax(T& a,\
    \ T b) { if (a < b) { a = b; return true; } return false; }\ntemplate<class T>\
    \ inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n\nconst int INF = (ll)1e9;\nconst ll INFLL = (ll)1e18+1;\nconst ll MOD =\
    \ (ll)1e9+7;\n\nconst double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1,\
    \ 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string\
    \ dir = \"DRUL\";\n\n\n#line 1 \"graph/template.hpp\"\n\n\n#line 4 \"graph/template.hpp\"\
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
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n#line 1 \"graph/shortest_path/dijkstra.hpp\"\
    \n\n\n#line 5 \"graph/shortest_path/dijkstra.hpp\"\n/*\n@title Dikstra\u6CD5\n\
    @category \u30B0\u30E9\u30D5/\u6700\u77ED\u7D4C\u8DEF\u554F\u984C\n\n*/\ntemplate<typename\
    \ T>\nclass Dijkstra : public Graph<T>{\n  public:\n    using Graph<T>::G;\n \
    \   using Graph<T>::N;\n    T inf;\n    vector<T> d;\n    Dijkstra(int _N, T _inf):\
    \ Graph<T>::Graph(_N), inf(_inf), d(_N,_inf){\n    }\n    vector<T> solve(int\
    \ start = 0){\n        rep(i,N) d[i] = inf;\n        priority_queue<pair<T, int>,\
    \ vector<pair<T, int>>, greater<pair<T, int>>> pq;\n        d[start] = 0;\n  \
    \      pq.push({0, start});\n        while (!pq.empty()) {\n            T v =\
    \ pq.top().first;\n            int from = pq.top().second;\n            pq.pop();\n\
    \            for (auto u : G[from]) {\n                T w = v + u.cost;\n   \
    \             if (chmin(d[u.to], w)) {\n                    pq.push({w, u.to});\n\
    \                }\n            }\n        }\n        return d;\n    }\n};\n\n\
    #line 5 \"test/GRL_1_A_2.test.cpp\"\n\nint main() {\n    int V, E, r;\n    cin\
    \ >> V >> E >> r;\n    Dijkstra<long long> G(V, INFLL);\n    G.input(E, 0, true,\
    \ true);\n    G.solve(r);\n    for(int i = 0; i < V; i++){\n        if(G.d[i]\
    \ == INFLL)cout << \"INF\" << endl;\n        else cout << G.d[i] << endl;\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../graph/template.hpp\"\n#include\
    \ \"../graph/shortest_path/dijkstra.hpp\"\n\nint main() {\n    int V, E, r;\n\
    \    cin >> V >> E >> r;\n    Dijkstra<long long> G(V, INFLL);\n    G.input(E,\
    \ 0, true, true);\n    G.solve(r);\n    for(int i = 0; i < V; i++){\n        if(G.d[i]\
    \ == INFLL)cout << \"INF\" << endl;\n        else cout << G.d[i] << endl;\n  \
    \  }\n}"
  dependsOn:
  - macro/macros.hpp
  - graph/template.hpp
  - macro/macros.hpp
  - graph/shortest_path/dijkstra.hpp
  - macro/macros.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/GRL_1_A_2.test.cpp
  requiredBy: []
  timestamp: '2020-04-06 10:26:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GRL_1_A_2.test.cpp
layout: document
redirect_from:
- /verify/test/GRL_1_A_2.test.cpp
- /verify/test/GRL_1_A_2.test.cpp.html
title: test/GRL_1_A_2.test.cpp
---
