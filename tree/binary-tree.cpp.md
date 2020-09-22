---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_7_B.test.cpp
    title: test/ALDS1_7_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u4E8C\u5206\u6728(Binary Tree)"
    links: []
  bundledCode: "#line 1 \"tree/binary-tree.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    ;\n\n\n#line 4 \"tree/binary-tree.cpp\"\n\n/*\n@title \u4E8C\u5206\u6728(Binary\
    \ Tree)\n@category tree\n@ignore\n*/\nstruct Binary_Tree{\n    int N;\n    vector<vector<int>>\
    \ G;\n    vector<int> par, sibling, depth, height;\n    vector<string> type;\n\
    \    Binary_Tree(int _N):N(_N),G(_N), par(_N, -1), sibling(_N, -1), depth(_N,0),height(_N),\
    \ type(_N){}\n    void add_directed_edge(int from, int to){\n        G[from].push_back(to);\n\
    \        par[to] = from;\n    }\n    void set_sibling(int l, int r){\n       \
    \ sibling[l] = r;\n        sibling[r] = l;\n    }\n    int dfs(int cur, int pre\
    \ = -1){\n        int res = 0;\n        for(auto nv: G[cur]){\n            depth[nv]\
    \ = depth[cur] + 1;\n            res = max(res, dfs(nv, cur) + 1);\n        }\n\
    \        if(pre == -1)\n            type[cur] = \"root\";\n        else if((int)G[cur].size()\
    \ == 0)\n            type[cur] = \"leaf\";\n        else\n            type[cur]\
    \ = \"internal node\";\n        return height[cur] = res;\n    }\n    void build(){\n\
    \        for(int i = 0; i < N; i++){\n            if(par[i] == -1){\n        \
    \        dfs(i);\n                break;\n            }\n        }\n    }\n  \
    \  void Cout(){\n        for(int i = 0; i < N; i++){\n            prints(i);\n\
    \        }\n    }\n    void prints(int idx){\n        cout << \"node \"      \
    \   << idx              << \": \";\n        cout << \"parent = \"     << par[idx]\
    \         << \", \";\n        cout << \"sibling = \"    << sibling[idx]     <<\
    \ \", \";\n        cout << \"degree = \"     << G[idx].size()    << \", \"; \n\
    \        cout << \"depth = \"      << depth[idx]       << \", \";\n        cout\
    \ << \"height = \"     << height[idx]      << \", \";\n        cout << type[idx]\
    \       << endl;\n    }\n};\n\n\n"
  code: "#ifndef BINARY_TREE_CPP\n#define BINARY_TREE_CPP\n#include \"../macro/macros.hpp\"\
    \n\n/*\n@title \u4E8C\u5206\u6728(Binary Tree)\n@category tree\n@ignore\n*/\n\
    struct Binary_Tree{\n    int N;\n    vector<vector<int>> G;\n    vector<int> par,\
    \ sibling, depth, height;\n    vector<string> type;\n    Binary_Tree(int _N):N(_N),G(_N),\
    \ par(_N, -1), sibling(_N, -1), depth(_N,0),height(_N), type(_N){}\n    void add_directed_edge(int\
    \ from, int to){\n        G[from].push_back(to);\n        par[to] = from;\n  \
    \  }\n    void set_sibling(int l, int r){\n        sibling[l] = r;\n        sibling[r]\
    \ = l;\n    }\n    int dfs(int cur, int pre = -1){\n        int res = 0;\n   \
    \     for(auto nv: G[cur]){\n            depth[nv] = depth[cur] + 1;\n       \
    \     res = max(res, dfs(nv, cur) + 1);\n        }\n        if(pre == -1)\n  \
    \          type[cur] = \"root\";\n        else if((int)G[cur].size() == 0)\n \
    \           type[cur] = \"leaf\";\n        else\n            type[cur] = \"internal\
    \ node\";\n        return height[cur] = res;\n    }\n    void build(){\n     \
    \   for(int i = 0; i < N; i++){\n            if(par[i] == -1){\n             \
    \   dfs(i);\n                break;\n            }\n        }\n    }\n    void\
    \ Cout(){\n        for(int i = 0; i < N; i++){\n            prints(i);\n     \
    \   }\n    }\n    void prints(int idx){\n        cout << \"node \"         <<\
    \ idx              << \": \";\n        cout << \"parent = \"     << par[idx] \
    \        << \", \";\n        cout << \"sibling = \"    << sibling[idx]     <<\
    \ \", \";\n        cout << \"degree = \"     << G[idx].size()    << \", \"; \n\
    \        cout << \"depth = \"      << depth[idx]       << \", \";\n        cout\
    \ << \"height = \"     << height[idx]      << \", \";\n        cout << type[idx]\
    \       << endl;\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: tree/binary-tree.cpp
  requiredBy: []
  timestamp: '2020-03-31 19:14:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_7_B.test.cpp
documentation_of: tree/binary-tree.cpp
layout: document
redirect_from:
- /library/tree/binary-tree.cpp
- /library/tree/binary-tree.cpp.html
title: "\u4E8C\u5206\u6728(Binary Tree)"
---
