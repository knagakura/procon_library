---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_1_C.test.cpp
    title: test/ALDS1_1_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9(Sieve\
      \ of Eratosthenes)"
    links: []
  bundledCode: "#line 1 \"math/sieve_of_eratosthenes.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    ;\n\n\n#line 4 \"math/sieve_of_eratosthenes.cpp\"\n\n/*\n@title \u30A8\u30E9\u30C8\
    \u30B9\u30C6\u30CD\u30B9\u306E\u7BE9(Sieve of Eratosthenes)\n@category math\n\
    @brief \u8A08\u7B97\u91CF$O($NloglogN$)$\n\n*/\ntemplate<typename T>\nvector<bool>\
    \ sieve(T x){\n    vector<bool> is_prime(x + 1, true);\n    if(x >= 0)is_prime[0]\
    \ = false;\n    if(x >= 1)is_prime[1] = false;\n    for(T i = 2; i * i <= x;i++){\n\
    \        if(!is_prime[i])continue;\n        for(T j = i + i; j <= x;j+=i){\n \
    \           is_prime[j] = false;\n        }\n    }\n    return is_prime;\n}\n\n"
  code: "#ifndef SIEVE_OF_ERATOSTHENES_CPP\n#define SIEVE_OF_ERATOSTHENES_CPP\n#include\
    \ \"../macro/macros.hpp\"\n\n/*\n@title \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9(Sieve of Eratosthenes)\n@category math\n@brief \u8A08\u7B97\u91CF\
    $O($NloglogN$)$\n\n*/\ntemplate<typename T>\nvector<bool> sieve(T x){\n    vector<bool>\
    \ is_prime(x + 1, true);\n    if(x >= 0)is_prime[0] = false;\n    if(x >= 1)is_prime[1]\
    \ = false;\n    for(T i = 2; i * i <= x;i++){\n        if(!is_prime[i])continue;\n\
    \        for(T j = i + i; j <= x;j+=i){\n            is_prime[j] = false;\n  \
    \      }\n    }\n    return is_prime;\n}\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: math/sieve_of_eratosthenes.cpp
  requiredBy: []
  timestamp: '2020-03-31 16:47:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_1_C.test.cpp
documentation_of: math/sieve_of_eratosthenes.cpp
layout: document
redirect_from:
- /library/math/sieve_of_eratosthenes.cpp
- /library/math/sieve_of_eratosthenes.cpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9(Sieve of Eratosthenes)"
---
