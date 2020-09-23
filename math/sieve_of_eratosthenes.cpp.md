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
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 4 \"math/sieve_of_eratosthenes.cpp\"\
    \n\n/*\n@title \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9(Sieve of\
    \ Eratosthenes)\n@category math\n@brief \u8A08\u7B97\u91CF$O($NloglogN$)$\n\n\
    */\ntemplate<typename T>\nvector<bool> sieve(T x){\n    vector<bool> is_prime(x\
    \ + 1, true);\n    if(x >= 0)is_prime[0] = false;\n    if(x >= 1)is_prime[1] =\
    \ false;\n    for(T i = 2; i * i <= x;i++){\n        if(!is_prime[i])continue;\n\
    \        for(T j = i + i; j <= x;j+=i){\n            is_prime[j] = false;\n  \
    \      }\n    }\n    return is_prime;\n}\n\n"
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
  timestamp: '2020-09-23 15:05:49+09:00'
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
