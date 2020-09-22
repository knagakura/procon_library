---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: data_structure/bit.cpp
    title: BIT(Binary Indexed Tree)
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_5_D.test.cpp
    title: test/ALDS1_5_D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: ../docs/data_structure/inversion-num.md
    document_title: "\u8EE2\u5012\u6570(The Number of Inversion)"
    links: []
  bundledCode: "#line 1 \"data_structure/inversion-num.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    ;\n\n\n#line 1 \"data_structure/bit.cpp\"\n\n\n#line 4 \"data_structure/bit.cpp\"\
    \n/*\n@title BIT(Binary Indexed Tree)\n@category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n*/\ntemplate<typename T>\nclass BIT{\n  public:\n    int N;\n    vector<T> data;\n\
    \    BIT(T _N):N(_N){\n        data.assign(N+1, 0);\n    };\n    \n    // a is\
    \ 1-indexed\n    void add(int a, T w){\n        for(int x = a; x <= N; x += x\
    \ & -x)data[x] += w;\n    }\n    // 1-indexed sum of prefix [0, a]\n    T sum(int\
    \ a){\n        T res = 0;\n        for(int x = a; x > 0; x -= x & -x)res += data[x];\n\
    \        return res;\n    }\n    // 1-indexed sum of range [l, r]\n    T sum(int\
    \ l, int r){return sum(r) - sum(l-1);}\n\n    // 0-indexed add\n    void add0(int\
    \ a, T w){add(a + 1, w);}\n    // 0-indexed sum\n    T sum0(int a){return sum(a\
    \ + 1);}\n    // 0-indexed sum of range\n    T sum0(int l, int r){return sum0(r)\
    \ - sum0(l-1);}\n    // show the value\n    void debug(){print(data);}\n};\n\n\
    \n#line 5 \"data_structure/inversion-num.cpp\"\n/*\n@title \u8EE2\u5012\u6570\
    (The Number of Inversion)\n@category \u30C7\u30FC\u30BF\u69CB\u9020\n@docs ../docs/data_structure/inversion-num.md\n\
    */\ntemplate<typename T> \nT Inversion_num(vector<T>& v){\n    int N = v.size();\n\
    \    BIT<T> Tree(N);\n    vector<int> B(N);\n    vector<pair<T, int>> ap;\n  \
    \  for(int i = 0; i < N; i++){\n        ap.push_back(make_pair(v[i],i));\n   \
    \ }\n    sort(ap.begin(), ap.end());\n    for(int i = 0; i < N; i++){\n      \
    \  B[ap[i].second] =  i;\n    }\n    T res = 0;\n    for(int i = 0; i < N; i++){\n\
    \        res += i - Tree.sum0(B[i]);\n        Tree.add0(B[i], 1);\n    }\n   \
    \ return res;\n}\n\n"
  code: "#ifndef INVERSION_NUM_CPP\n#define INVERSION_NUM_CPP\n#include \"../macro/macros.hpp\"\
    \n#include \"../data_structure/bit.cpp\"\n/*\n@title \u8EE2\u5012\u6570(The Number\
    \ of Inversion)\n@category \u30C7\u30FC\u30BF\u69CB\u9020\n@docs ../docs/data_structure/inversion-num.md\n\
    */\ntemplate<typename T> \nT Inversion_num(vector<T>& v){\n    int N = v.size();\n\
    \    BIT<T> Tree(N);\n    vector<int> B(N);\n    vector<pair<T, int>> ap;\n  \
    \  for(int i = 0; i < N; i++){\n        ap.push_back(make_pair(v[i],i));\n   \
    \ }\n    sort(ap.begin(), ap.end());\n    for(int i = 0; i < N; i++){\n      \
    \  B[ap[i].second] =  i;\n    }\n    T res = 0;\n    for(int i = 0; i < N; i++){\n\
    \        res += i - Tree.sum0(B[i]);\n        Tree.add0(B[i], 1);\n    }\n   \
    \ return res;\n}\n#endif"
  dependsOn:
  - macro/macros.hpp
  - data_structure/bit.cpp
  - macro/macros.hpp
  isVerificationFile: false
  path: data_structure/inversion-num.cpp
  requiredBy: []
  timestamp: '2020-03-31 20:30:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_5_D.test.cpp
documentation_of: data_structure/inversion-num.cpp
layout: document
redirect_from:
- /library/data_structure/inversion-num.cpp
- /library/data_structure/inversion-num.cpp.html
title: "\u8EE2\u5012\u6570(The Number of Inversion)"
---
