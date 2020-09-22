---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: flow/ford-fulkerson.cpp
    title: "\u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \n\n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n\
    */\n#include <bits/stdc++.h>\nusing namespace std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n\
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
    \ dir = \"DRUL\";\n\n\n#line 1 \"flow/ford-fulkerson.cpp\"\n\n\n\n#line 5 \"flow/ford-fulkerson.cpp\"\
    \n/*\n\n@title \u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)\n@category \u30CD\u30C3\
    \u30C8\u30EF\u30FC\u30AF\u30D5\u30ED\u30FC\n\n*/\n\nstruct edge{\n    int to,\
    \ cap, rev;\n};\n\nstruct FordFulkerson{\n    int V;\n    vector<vector<edge>>\
    \ G;\n    vector<bool> used;\n    FordFulkerson(int V_):V(V_){\n        G.resize(V);\n\
    \        used.assign(V, false);\n    }\n    void add_edge(int from, int to, int\
    \ cap){\n        G[from].push_back((edge){to, cap, (int)G[to].size()});\n    \
    \    G[to].push_back((edge){from, 0, (int)G[from].size()-1});\n    }\n    int\
    \ dfs(int v, int t, int f){\n        if(v == t)return f;\n        used[v] = true;\n\
    \        for(auto &&e: G[v]){\n            if(used[e.to])continue;\n         \
    \   if(e.cap <= 0)continue;\n            int d = dfs(e.to, t, min(f, e.cap));\n\
    \            if(d > 0){\n                e.cap -= d;\n                G[e.to][e.rev].cap\
    \ += d;\n                return d;\n            }\n        }\n        return 0;\n\
    \    }\n    int max_flow(int s, int t){\n        int flow = 0;\n        for( ;\
    \ ; ){\n            used.assign(V, false);\n            int f = dfs(s, t, INF);\n\
    \            if(f == 0)return flow;\n            flow += f;\n        }\n    }\n\
    };\n\n\n#line 5 \"test/GRL_6_A.test.cpp\"\n\nint main() {\n    int V, E;\n   \
    \ cin >> V >> E;\n    FordFulkerson G(V);\n    rep(i,E){\n        int u, v, c;\n\
    \        cin >> u >> v >> c;\n        G.add_edge(u, v, c);\n    }\n    cout <<\
    \ G.max_flow(0, V-1) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n\n\
    #include \"../macro/macros.hpp\"\n#include \"../flow/ford-fulkerson.cpp\"\n\n\
    int main() {\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson G(V);\n   \
    \ rep(i,E){\n        int u, v, c;\n        cin >> u >> v >> c;\n        G.add_edge(u,\
    \ v, c);\n    }\n    cout << G.max_flow(0, V-1) << endl;\n}\n"
  dependsOn:
  - macro/macros.hpp
  - flow/ford-fulkerson.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 16:18:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/GRL_6_A.test.cpp
- /verify/test/GRL_6_A.test.cpp.html
title: test/GRL_6_A.test.cpp
---
