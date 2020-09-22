---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: tree/template.cpp
    title: Tree Class
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Class
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: tree/tree-diameter-height.cpp
    title: "\u6728\u306E\u76F4\u5F84\u3068\u9AD8\u3055/Diameter and Height of a Tree\
      \ (\u5168\u65B9\u4F4D\u6728DP/Rerooting ver.)"
  - icon: ':heavy_check_mark:'
    path: tree/template.cpp
    title: Tree Class
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B
  bundledCode: "#line 1 \"test/GRL_5_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B\"\
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
    \ dir = \"DRUL\";\n\n\n#line 1 \"tree/template.cpp\"\n\n\n#line 1 \"graph/template.hpp\"\
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
    \            else add_edge(a,b,c);\n        }\n    }\n};\n\n\n#line 1 \"tree/tree-diameter-height.cpp\"\
    \n/*\n@title \u6728\u306E\u76F4\u5F84\u3068\u9AD8\u3055/Diameter and Height of\
    \ a Tree (\u5168\u65B9\u4F4D\u6728DP/Rerooting ver.)\n@category tree\n@docs ../docs/tree/tree-diameter-height.md\n\
    */\n#line 8 \"tree/tree-diameter-height.cpp\"\n\ntemplate<typename T>\nclass Tree_DH\
    \ :  public Tree<T>{\n  public:\n    using Tree<T>::N;\n    using Tree<T>::G;\n\
    \    vector<T> dp, dp2, height;\n    T diameter;\n    Tree_DH(int _N):Tree<T>::Tree(_N),\
    \ dp(_N,0), dp2(_N), height(_N){}\n    //Calc distance and start Rerooting\n \
    \   void build(int start = 0, int pre = -1, bool debug = false){\n        dfs1(start,\
    \ pre);\n        dfs2(start, pre);\n        if(debug){\n            print(dp);\n\
    \            print(dp2);\n            print(height);\n        }\n        diameter\
    \ = *max_element(dp2.begin(), dp2.end());\n    }\n    //calculate the distance\
    \ from start\n    void dfs1(int cur = 0, int pre = -1){\n        dp[cur] = 0;\n\
    \        for(edge<T>& ne: G[cur]){\n            if(ne.to == pre)continue;\n  \
    \          dfs1(ne.to, cur);\n            dp[cur] = max(dp[cur],dp[ne.to] + ne.cost);\n\
    \        }\n    }\n    void dfs2(int cur = 0, int pre = -1, T d_par = 0){\n  \
    \      //rerooting\n        vector<pair<T,int>> childs;\n        childs.push_back({0,\
    \ -1}); //\u756A\u5175 \u6B21\u6570\u304C1\u3060\u3068\u58CA\u308C\u308B\u306E\
    \u3067\n        for(auto ne: G[cur]){\n            if(ne.to == pre)\n        \
    \        childs.push_back({d_par + ne.cost, ne.to});\n            else \n    \
    \            childs.push_back({dp[ne.to] + ne.cost, ne.to});\n        }\n    \
    \    //\u5927\u304D\u3044\u4E8C\u3064\n        sort(all(childs), greater<pair<T,\
    \ int>>());\n        dp2[cur] = childs[0].first + childs[1].first;\n        height[cur]\
    \ = childs[0].first;\n        for(auto ne: G[cur]){\n            if(ne.to == pre)continue;\n\
    \            //\u964D\u308A\u308B\u8FBA\u304C\u6700\u5927\u5024\n            if(childs[0].second\
    \ == ne.to)\n                dfs2(ne.to, cur, childs[1].first);\n            else\
    \ \n                dfs2(ne.to, cur, childs[0].first);\n        }\n    }\n   \
    \ T get_diameter(){\n        return diameter;\n    }\n    vector<T> get_height(){\n\
    \        return height;\n    }\n};\n#line 5 \"test/GRL_5_B.test.cpp\"\n\n\nint\
    \ main(){\n    int N;\n    cin >> N;\n    Tree_DH<long long> G(N);\n    G.input(N-1,\
    \ 0, true, false);\n    G.build();\n    auto ans = G.get_height();\n    for(auto\
    \ x: ans){\n        cout << x << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../tree/template.cpp\"\n#include\
    \ \"../tree/tree-diameter-height.cpp\"\n\n\nint main(){\n    int N;\n    cin >>\
    \ N;\n    Tree_DH<long long> G(N);\n    G.input(N-1, 0, true, false);\n    G.build();\n\
    \    auto ans = G.get_height();\n    for(auto x: ans){\n        cout << x << endl;\n\
    \    }\n}"
  dependsOn:
  - macro/macros.hpp
  - tree/template.cpp
  - macro/macros.hpp
  - graph/template.hpp
  - macro/macros.hpp
  - tree/tree-diameter-height.cpp
  - tree/template.cpp
  isVerificationFile: true
  path: test/GRL_5_B.test.cpp
  requiredBy: []
  timestamp: '2020-03-31 06:16:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GRL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/GRL_5_B.test.cpp
- /verify/test/GRL_5_B.test.cpp.html
title: test/GRL_5_B.test.cpp
---
