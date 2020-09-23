---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3\u95A2\u4FC2"
    links: []
  bundledCode: "#line 1 \"math/factorize.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\n\
    \n\n\n/*\n@title Macro\n@category template\n*/\n#include <bits/stdc++.h>\nusing\
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
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 4 \"math/factorize.cpp\"\
    \n\n/*\n@title \u7D20\u56E0\u6570\u5206\u89E3\u95A2\u4FC2\n@category math\n@brief\
    \ \n\n*/\n\nstruct Prime{\n    int MAXN;\n    vector<int> primes;\n    vector<int>\
    \ spf;\n    Prime(int MAXN_): MAXN(MAXN_), spf(MAXN_+1){\n        spf_init();\n\
    \    }\n    static map<int, int> factorize(int x){\n        map<int,int> mp;\n\
    \        for (int i = 2; i*i <= x; i++){\n            while (x%i == 0) {\n   \
    \             x /= i;\n                mp[i]++;\n            }\n            if\
    \ (x == 1) break;\n        }\n        if (x != 1) mp[x]++;\n        return mp;\n\
    \    }\n    static bool isprime(int v) {\n        if (v <= 1) return false;\n\
    \        if (v == 2) return true;\n        for (int i = 2; 1LL * i*i <= v; i++)\
    \ if (v%i == 0) return false;\n        return true;\n    }\n\n    // smallest\
    \ prime factor\n    void spf_init(){\n        for (int i = 0; i <= MAXN; i++)\
    \ spf[i] = i;\n        for (int i = 2; i * i <= MAXN; i++) {\n            // \u7D20\
    \u6570\u3060\u3063\u305F\u3089\n            if (spf[i] == i) {\n             \
    \   primes.emplace_back(i);\n                for (int j = i * i; j <= n; j +=\
    \ i) {\n                    // i\u3092\u6301\u3064\u6574\u6570\u304B\u3064\u307E\
    \u3060\u7D20\u6570\u304C\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u306A\u3089\
    \n                    if (spf[j] == j) {\n                        spf[j] = i;\n\
    \                    }\n                }\n            }\n        }\n    }\n \
    \   // x <= MAXN\n    map<int, int> fast_factorize(int x){\n        map<int, int>\
    \ mp;\n        while(x != 1){\n            mp[spf[x]]++;\n            x /= spf[x];\n\
    \        }\n        return mp;\n    }\n};\n\n\n"
  code: "#ifndef FACTORIZE_CPP\n#define FACTORIZE_CPP\n#include \"../macro/macros.hpp\"\
    \n\n/*\n@title \u7D20\u56E0\u6570\u5206\u89E3\u95A2\u4FC2\n@category math\n@brief\
    \ \n\n*/\n\nstruct Prime{\n    int MAXN;\n    vector<int> primes;\n    vector<int>\
    \ spf;\n    Prime(int MAXN_): MAXN(MAXN_), spf(MAXN_+1){\n        spf_init();\n\
    \    }\n    static map<int, int> factorize(int x){\n        map<int,int> mp;\n\
    \        for (int i = 2; i*i <= x; i++){\n            while (x%i == 0) {\n   \
    \             x /= i;\n                mp[i]++;\n            }\n            if\
    \ (x == 1) break;\n        }\n        if (x != 1) mp[x]++;\n        return mp;\n\
    \    }\n    static bool isprime(int v) {\n        if (v <= 1) return false;\n\
    \        if (v == 2) return true;\n        for (int i = 2; 1LL * i*i <= v; i++)\
    \ if (v%i == 0) return false;\n        return true;\n    }\n\n    // smallest\
    \ prime factor\n    void spf_init(){\n        for (int i = 0; i <= MAXN; i++)\
    \ spf[i] = i;\n        for (int i = 2; i * i <= MAXN; i++) {\n            // \u7D20\
    \u6570\u3060\u3063\u305F\u3089\n            if (spf[i] == i) {\n             \
    \   primes.emplace_back(i);\n                for (int j = i * i; j <= n; j +=\
    \ i) {\n                    // i\u3092\u6301\u3064\u6574\u6570\u304B\u3064\u307E\
    \u3060\u7D20\u6570\u304C\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u306A\u3089\
    \n                    if (spf[j] == j) {\n                        spf[j] = i;\n\
    \                    }\n                }\n            }\n        }\n    }\n \
    \   // x <= MAXN\n    map<int, int> fast_factorize(int x){\n        map<int, int>\
    \ mp;\n        while(x != 1){\n            mp[spf[x]]++;\n            x /= spf[x];\n\
    \        }\n        return mp;\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3\u95A2\u4FC2"
---
