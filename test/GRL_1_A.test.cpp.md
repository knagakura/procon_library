---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.cpp
    title: "Dijkstra\u6CD5(Simple Class)"
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
  bundledCode: "#line 1 \"test/GRL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
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
    \ long double PI = acos(-1.0);\n\n/*\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1,\
    \ 1};\nconst int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\"\
    ;\n*/\n\n\n#line 1 \"graph/shortest_path/dijkstra.cpp\"\n\n\n#line 4 \"graph/shortest_path/dijkstra.cpp\"\
    \n/*\n@title Dijkstra\u6CD5(Simple Class)\n@category \u30B0\u30E9\u30D5/\u6700\
    \u77ED\u7D4C\u8DEF\u554F\u984C\n*/\ntemplate<class T> class Dijkstra {\npublic:\n\
    \    int N;\n    T inf;\n    vector<T> cost;\n    vector<vector<pair<T, int>>>\
    \ edge;\n \n    Dijkstra(const int _N, T _inf = INFLL) : N(_N), inf(_inf),cost(N),\
    \ edge(N) {\n    }\n \n    void make_edge(int from, int to, T w) {\n        edge[from].push_back({\
    \ w,to });\n    }\n \n    void solve(int start) {\n        for(int i = 0; i <\
    \ N; ++i) cost[i] = inf;\n \n        priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n        cost[start] = 0;\n        pq.push({\
    \ 0,start });\n \n        while (!pq.empty()) {\n            T v = pq.top().first;\n\
    \            int from = pq.top().second;\n            pq.pop();\n            for\
    \ (auto u : edge[from]) {\n                T w = v + u.first;\n              \
    \  int to = u.second;\n                if (w < cost[to]) {\n                 \
    \   cost[to] = w;\n                    pq.push({ w,to });\n                }\n\
    \            }\n        }\n        return;\n    }\n};\n\n#line 4 \"test/GRL_1_A.test.cpp\"\
    \n\nint main() {\n    const long long INFLL = (long long)1e18+1;\n    int V, E,\
    \ r;\n    cin >> V >> E >> r;\n\n    Dijkstra<long long> G(V, INFLL);\n\n    for(int\
    \ _ = 0; _ < E; _++){\n        int s, t;\n        long long d;\n        cin >>\
    \ s >> t >> d;\n        G.make_edge(s, t, d);\n    }\n\n    G.solve(r);\n\n  \
    \  for(int i = 0; i < V; i++){\n        if(G.cost[i] == INFLL)cout << \"INF\"\
    \ << endl;\n        else cout << G.cost[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../graph/shortest_path/dijkstra.cpp\"\
    \n\nint main() {\n    const long long INFLL = (long long)1e18+1;\n    int V, E,\
    \ r;\n    cin >> V >> E >> r;\n\n    Dijkstra<long long> G(V, INFLL);\n\n    for(int\
    \ _ = 0; _ < E; _++){\n        int s, t;\n        long long d;\n        cin >>\
    \ s >> t >> d;\n        G.make_edge(s, t, d);\n    }\n\n    G.solve(r);\n\n  \
    \  for(int i = 0; i < V; i++){\n        if(G.cost[i] == INFLL)cout << \"INF\"\
    \ << endl;\n        else cout << G.cost[i] << endl;\n    }\n}"
  dependsOn:
  - macro/macros.hpp
  - graph/shortest_path/dijkstra.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/GRL_1_A.test.cpp
- /verify/test/GRL_1_A.test.cpp.html
title: test/GRL_1_A.test.cpp
---
