---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: "\u5408\u540C\u7B97\u8853(Modular Arithmetic)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DPL_5_L.test.cpp
    title: "\u7389\u533A\u5225\u3057\u306A\u3044\u3001\u7BB1\u533A\u5225\u3057\u306A\
      \u3044\u30011\u500B\u4EE5\u4E0A(\u5206\u5272\u6570$P(n-k,k)$)"
  - icon: ':heavy_check_mark:'
    path: test/DPL_5_J.test.cpp
    title: "\u7389\u533A\u5225\u3057\u306A\u3044\u3001\u7BB1\u533A\u5225\u3057\u306A\
      \u3044\u3001\u5236\u9650\u306A\u3057(\u5206\u5272\u6570$P(n,k)$)"
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: ../docs/math/partition-number.md
    document_title: "\u5206\u5272\u6570(Partition Number)"
    links: []
  bundledCode: "#line 1 \"math/partition-number.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    ;\n\n\n#line 1 \"math/mint.hpp\"\n\n\n\n#line 5 \"math/mint.hpp\"\n/*\n@title\
    \ \u5408\u540C\u7B97\u8853(Modular Arithmetic)\n*/\nstruct mint {\n    long long\
    \ x;\n    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}\n    mint operator-() const\
    \ { return mint(-x);}\n    mint& operator+=(const mint a) {\n        if ((x +=\
    \ a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint a) {\n        if ((x += MOD-a.x) >= MOD) x -= MOD;\n        return *this;\n\
    \    }\n    mint& operator*=(const mint a) {\n        (x *= a.x) %= MOD;\n   \
    \     return *this;\n    }\n    mint operator+(const mint a) const {\n       \
    \ mint res(*this);\n        return res+=a;\n    }\n    mint operator-(const mint\
    \ a) const {\n        mint res(*this);\n        return res-=a;\n    }\n    mint\
    \ operator*(const mint a) const {\n        mint res(*this);\n        return res*=a;\n\
    \    }\n    mint modpow(long long t) const {\n        if (!t) return 1;\n    \
    \    mint a = modpow(t>>1);\n        a *= a;\n        if (t&1) a *= *this;\n \
    \       return a;\n    }\n    // for prime MOD\n    mint inv() const {\n     \
    \   return modpow(MOD-2);\n    }\n    mint& operator/=(const mint a) {\n     \
    \   return (*this) *= a.inv();\n    }\n    mint operator/(const mint a) const\
    \ {\n        mint res(*this);\n        return res/=a;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& a){\n        os << a.x;\n        return\
    \ os;\n    }\n};\n\n#line 5 \"math/partition-number.cpp\"\n\n/*\n@title \u5206\
    \u5272\u6570(Partition Number)\n@category \u5199\u50CF12\u76F8\n@docs ../docs/math/partition-number.md\n\
    */\n\ntemplate<typename T = mint>\nstruct Partition{\n    int N,K;\n    vector<vector<mint>>\
    \ Par;\n    Partition(int _N, int _K):N(_N),K(_K),Par(N+1, vector<mint>(K+1, 0)){\n\
    \        build();\n    }\n    void build(){\n        for(int k = 0; k <= K;k++)Par[0][k]\
    \ = 1;\n        for(int n = 1; n <= N; n++){\n            for(int k = 1; k <=\
    \ K; k++){\n                if(k-1 >= 0)Par[n][k] += Par[n][k-1];\n          \
    \      if(n-k >= 0)Par[n][k] += Par[n-k][k];\n            }\n        }\n    }\n\
    \    mint get(int n, int k){\n        if(n < 0 || k < 0)return 0;\n        return\
    \ Par[n][k];\n    }\n};\n\n\n"
  code: "#ifndef PARTITION_NUMBER_CPP\n#define PARTITION_NUMBER_CPP\n#include \"../macro/macros.hpp\"\
    \n#include \"mint.hpp\"\n\n/*\n@title \u5206\u5272\u6570(Partition Number)\n@category\
    \ \u5199\u50CF12\u76F8\n@docs ../docs/math/partition-number.md\n*/\n\ntemplate<typename\
    \ T = mint>\nstruct Partition{\n    int N,K;\n    vector<vector<mint>> Par;\n\
    \    Partition(int _N, int _K):N(_N),K(_K),Par(N+1, vector<mint>(K+1, 0)){\n \
    \       build();\n    }\n    void build(){\n        for(int k = 0; k <= K;k++)Par[0][k]\
    \ = 1;\n        for(int n = 1; n <= N; n++){\n            for(int k = 1; k <=\
    \ K; k++){\n                if(k-1 >= 0)Par[n][k] += Par[n][k-1];\n          \
    \      if(n-k >= 0)Par[n][k] += Par[n-k][k];\n            }\n        }\n    }\n\
    \    mint get(int n, int k){\n        if(n < 0 || k < 0)return 0;\n        return\
    \ Par[n][k];\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  - math/mint.hpp
  isVerificationFile: false
  path: math/partition-number.cpp
  requiredBy: []
  timestamp: '2020-03-31 04:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DPL_5_L.test.cpp
  - test/DPL_5_J.test.cpp
documentation_of: math/partition-number.cpp
layout: document
redirect_from:
- /library/math/partition-number.cpp
- /library/math/partition-number.cpp.html
title: "\u5206\u5272\u6570(Partition Number)"
---
