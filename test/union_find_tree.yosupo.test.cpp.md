---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: data_structure/unionfind.cpp
    title: "\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020(UnionFind Tree)"
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/union_find_tree.yosupo.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n#line 1 \"macro/macros.hpp\"\n\
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
    ;\n\n\n#line 1 \"data_structure/unionfind.cpp\"\n\n\n#line 4 \"data_structure/unionfind.cpp\"\
    \n\nstruct UnionFind{\n    int n;\n    vector<int> Parent;\n    vector<int> sizes;\n\
    \    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }\n\
    \    //find the root of x\n    int root(int x){\n        if(x!=Parent[x]){\n \
    \       Parent[x] = root(Parent[x]);\n        }\n        return Parent[x];\n \
    \   }\n    //merge x and y\n    void unite(int x,int y){\n        x = root(x);\n\
    \        y = root(y);\n        if(x == y) return;\n        if(sizes[x] < sizes[y])\
    \ swap(x, y);\n        Parent[y] = x;\n        sizes[x] += sizes[y];\n    }\n\
    \    bool same(int x,int y){ return root(x) == root(y); }\n    int size(int x){\
    \ return sizes[root(x)]; }\n    int group_num(){\n        set<int> s;\n      \
    \  for(int i = 0; i < n; ++i){\n            s.insert(root(i));\n        }\n  \
    \      return int(s.size());\n    }\n};\n\n#line 4 \"test/union_find_tree.yosupo.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    int n, q; cin >> n >> q;\n    UnionFind\
    \ uft(n);\n    rep (i, q) {\n        int t, u, v; cin >> t >> u >> v;\n      \
    \  if (t == 0) {\n            uft.unite(u, v);\n        } else if (t == 1) {\n\
    \            cout << uft.same(u, v) << endl;\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../macro/macros.hpp\"\n#include \"../data_structure/unionfind.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    int n, q; cin >> n >> q;\n    UnionFind uft(n);\n\
    \    rep (i, q) {\n        int t, u, v; cin >> t >> u >> v;\n        if (t ==\
    \ 0) {\n            uft.unite(u, v);\n        } else if (t == 1) {\n         \
    \   cout << uft.same(u, v) << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - macro/macros.hpp
  - data_structure/unionfind.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/union_find_tree.yosupo.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 16:57:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find_tree.yosupo.test.cpp
layout: document
redirect_from:
- /verify/test/union_find_tree.yosupo.test.cpp
- /verify/test/union_find_tree.yosupo.test.cpp.html
title: test/union_find_tree.yosupo.test.cpp
---
