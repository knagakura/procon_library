---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: flow/ford-fulkerson.cpp
    title: "Ford Fulkerson\u6CD5"
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
  bundledCode: "#line 1 \"test/GRL_7_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\
    \n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n*/\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\n#define\
    \ rep(i,N) for(int i=0;i<int(N);++i)\n#define rep1(i,N) for(int i=1;i<int(N);++i)\n\
    #define all(a) (a).begin(),(a).end()\n#define bit(k) (1LL<<(k))\n#define SUM(v)\
    \ accumulate(all(v), 0LL)\n\ntypedef pair<int, int> i_i;\ntypedef pair<ll, ll>\
    \ l_l;\ntemplate <class T> using vec = vector<T>;\ntemplate <class T> using vvec\
    \ = vector<vec<T>>;\nstruct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false);\
    \ cout << fixed << setprecision(20); }; }fast_ios_;\n\ntemplate<class T> inline\
    \ bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }\n\
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;\
    \ } return false; }\n\n#define TOSTRING(x) string(#x)\ntemplate <typename T> istream\
    \ &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return\
    \ is; }\ntemplate <typename T> ostream &operator<<(ostream &os, const vector<T>\
    \ &v) { os  << \"[\"; for(auto _: v) os << _ << \", \"; os << \"]\"; return os;\
    \ };\ntemplate <typename T> ostream &operator<<(ostream &os, set<T> &st) { os\
    \ << \"(\"; for(auto _: st) { os << _ << \", \"; } os << \")\";return os;}\ntemplate\
    \ <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >&\
    \ p){os << \"{\" <<p.first << \", \" << p.second << \"}\";return os; }\ntemplate\
    \ <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){\
    \ os << \"[\"; for(auto _: mp){ os << _ << \", \"; } os << \"]\" << endl; return\
    \ os; }\n\n#define DUMPOUT cerr\nvoid dump_func(){ DUMPOUT << endl; }\ntemplate\
    \ <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT\
    \ << head; if (sizeof...(Tail) > 0) { DUMPOUT << \", \"; } dump_func(std::move(tail)...);\
    \ }\n\n#ifdef DEBUG\n#define dbg(...) dump_func(__VA_ARGS__)\n#define dump(...)\
    \ DUMPOUT << string(#__VA_ARGS__) << \": \"; dump_func(__VA_ARGS__)\n#else\n#define\
    \ dbg(...)\n#define dump(...)\n#endif\n\nconst int INF = (ll)1e9;\nconst ll INFLL\
    \ = (ll)1e18+1;\nconst ll MOD = 1000000007;\n// const ll MOD = 998244353;\nconst\
    \ long double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\n\
    const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\
    \n\n#line 1 \"flow/ford-fulkerson.cpp\"\n\n\n\n#line 5 \"flow/ford-fulkerson.cpp\"\
    \n/*\n\n@title \u6700\u5927\u6D41(Ford-Fulkerson\u6CD5)\n@category \u30CD\u30C3\
    \u30C8\u30EF\u30FC\u30AF\u30D5\u30ED\u30FC\n\n*/\n\n\ntemplate<typename T>\nstruct\
    \ edge{\n    int to;\n    T cap;\n    int rev;\n};\ntemplate<typename T>\nstruct\
    \ FordFulkerson{\n    int V;\n    vector<vector<edge<T>>> G;\n    vector<bool>\
    \ used;\n    T inf;\n    FordFulkerson(int V_, T inf_):V(V_), inf(inf_){\n   \
    \     G.resize(V);\n        used.assign(V, false);\n    }\n    void add_edge(int\
    \ from, int to, T cap){\n        G[from].push_back((edge<T>){to, cap, (int)G[to].size()});\n\
    \        G[to].push_back((edge<T>){from, 0, (int)G[from].size()-1});\n    }\n\
    \    T dfs(int v, int t, T f){\n        if(v == t)return f;\n        used[v] =\
    \ true;\n        for(auto &&e: G[v]){\n            if(used[e.to])continue;\n \
    \           if(e.cap <= 0)continue;\n            T d = dfs(e.to, t, min(f, e.cap));\n\
    \            if(d > 0){\n                e.cap -= d;\n                G[e.to][e.rev].cap\
    \ += d;\n                return d;\n            }\n        }\n        return 0;\n\
    \    }\n    T max_flow(int s, int t){\n        T flow = 0;\n        for( ; ; ){\n\
    \            used.assign(V, false);\n            T f = dfs(s, t, inf);\n     \
    \       if(f == 0)return flow;\n            flow += f;\n        }\n    }\n};\n\
    \n\n\n#line 4 \"test/GRL_7_A.test.cpp\"\n\nint main() {\n    int X, Y, E;\n  \
    \  cin >> X >> Y >> E;\n    FordFulkerson<int> G(X+Y+2, INF);\n    int s = X +\
    \ Y;\n    int t = s + 1;\n    rep(i,X)G.add_edge(s, i, 1);\n    rep(j,Y)G.add_edge(j+X,\
    \ t, 1);\n    for(int i = 0; i < E; i++){\n        int x, y;\n        cin >> x\
    \ >> y;\n        y += X;\n        G.add_edge(x, y, 1);\n    }\n    cout << G.max_flow(s,\
    \ t) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\n#include\
    \ \"../macro/macros.hpp\"\n#include \"../flow/ford-fulkerson.cpp\"\n\nint main()\
    \ {\n    int X, Y, E;\n    cin >> X >> Y >> E;\n    FordFulkerson<int> G(X+Y+2,\
    \ INF);\n    int s = X + Y;\n    int t = s + 1;\n    rep(i,X)G.add_edge(s, i,\
    \ 1);\n    rep(j,Y)G.add_edge(j+X, t, 1);\n    for(int i = 0; i < E; i++){\n \
    \       int x, y;\n        cin >> x >> y;\n        y += X;\n        G.add_edge(x,\
    \ y, 1);\n    }\n    cout << G.max_flow(s, t) << endl;\n}"
  dependsOn:
  - macro/macros.hpp
  - flow/ford-fulkerson.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/GRL_7_A.test.cpp
- /verify/test/GRL_7_A.test.cpp.html
title: test/GRL_7_A.test.cpp
---
