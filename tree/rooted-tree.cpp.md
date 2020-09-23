---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_7_A.test.cpp
    title: test/ALDS1_7_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6839\u4ED8\u304D\u6728(Rooted Tree)"
    links: []
  bundledCode: "#line 1 \"tree/rooted-tree.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
    \n\n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
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
    \nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1, 0,\
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 4 \"tree/rooted-tree.cpp\"\
    \n\n/*\n@title \u6839\u4ED8\u304D\u6728(Rooted Tree)\n@category tree\n@ignore\n\
    */\nstruct Rooted_Tree{\n    int N;\n    vector<vector<int>> G;\n    vector<int>\
    \ par;\n    vector<int> depth;\n    vector<string> type;\n    vector<vector<int>>\
    \ childs;\n    Rooted_Tree(int _N):N(_N),G(_N), par(_N, -1),depth(_N,0), type(_N),\
    \ childs(_N){}\n    void add_directed_edge(int parent, int child){\n        G[parent].push_back(child);\n\
    \        par[child] = parent;\n    }\n    void dfs(int cur, int pre = -1){\n \
    \       for(auto nv: G[cur]){\n            if(nv == pre)continue;\n          \
    \  childs[cur].push_back(nv);\n            depth[nv] = depth[cur] + 1;\n     \
    \       dfs(nv, cur);\n        }\n        if(pre == -1)\n            type[cur]\
    \ = \"root\";\n        else if((int)childs[cur].size() == 0)\n            type[cur]\
    \ = \"leaf\";\n        else\n            type[cur] = \"internal node\";\n    }\n\
    \    void build(){\n        for(int i = 0; i < N; i++){\n            if(par[i]\
    \ == -1){\n                dfs(i);\n                break;\n            }\n  \
    \      }\n    }\n    void Cout(){\n        for(int i = 0; i < N; i++){\n     \
    \       prints(i);\n        }\n    }\n    void prints(int idx){\n        cout\
    \ << \"node \"     << idx          << \": \";\n        cout << \"parent = \" <<\
    \ par[idx]     << \", \";\n        cout << \"depth = \"  << depth[idx]   << \"\
    , \";\n        cout << type[idx]   << \", \";\n        cout << \"[\";\n      \
    \  for(int i = 0; i < (int)childs[idx].size();i++){\n            cout << childs[idx][i];\n\
    \            if(i < (int)childs[idx].size()-1)\n                cout << \", \"\
    ;\n        }\n        cout << \"]\" << endl;\n    }\n};\n\n\n"
  code: "#ifndef ROOTED_TREE_CPP\n#define ROOTED_TREE_CPP\n#include \"../macro/macros.hpp\"\
    \n\n/*\n@title \u6839\u4ED8\u304D\u6728(Rooted Tree)\n@category tree\n@ignore\n\
    */\nstruct Rooted_Tree{\n    int N;\n    vector<vector<int>> G;\n    vector<int>\
    \ par;\n    vector<int> depth;\n    vector<string> type;\n    vector<vector<int>>\
    \ childs;\n    Rooted_Tree(int _N):N(_N),G(_N), par(_N, -1),depth(_N,0), type(_N),\
    \ childs(_N){}\n    void add_directed_edge(int parent, int child){\n        G[parent].push_back(child);\n\
    \        par[child] = parent;\n    }\n    void dfs(int cur, int pre = -1){\n \
    \       for(auto nv: G[cur]){\n            if(nv == pre)continue;\n          \
    \  childs[cur].push_back(nv);\n            depth[nv] = depth[cur] + 1;\n     \
    \       dfs(nv, cur);\n        }\n        if(pre == -1)\n            type[cur]\
    \ = \"root\";\n        else if((int)childs[cur].size() == 0)\n            type[cur]\
    \ = \"leaf\";\n        else\n            type[cur] = \"internal node\";\n    }\n\
    \    void build(){\n        for(int i = 0; i < N; i++){\n            if(par[i]\
    \ == -1){\n                dfs(i);\n                break;\n            }\n  \
    \      }\n    }\n    void Cout(){\n        for(int i = 0; i < N; i++){\n     \
    \       prints(i);\n        }\n    }\n    void prints(int idx){\n        cout\
    \ << \"node \"     << idx          << \": \";\n        cout << \"parent = \" <<\
    \ par[idx]     << \", \";\n        cout << \"depth = \"  << depth[idx]   << \"\
    , \";\n        cout << type[idx]   << \", \";\n        cout << \"[\";\n      \
    \  for(int i = 0; i < (int)childs[idx].size();i++){\n            cout << childs[idx][i];\n\
    \            if(i < (int)childs[idx].size()-1)\n                cout << \", \"\
    ;\n        }\n        cout << \"]\" << endl;\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: tree/rooted-tree.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_7_A.test.cpp
documentation_of: tree/rooted-tree.cpp
layout: document
redirect_from:
- /library/tree/rooted-tree.cpp
- /library/tree/rooted-tree.cpp.html
title: "\u6839\u4ED8\u304D\u6728(Rooted Tree)"
---
