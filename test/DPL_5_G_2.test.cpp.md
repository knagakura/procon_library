---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: "\u5408\u540C\u7B97\u8853(Modular Arithmetic)"
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B(Combination)"
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: "\u5408\u540C\u7B97\u8853(Modular Arithmetic)"
  - icon: ':heavy_check_mark:'
    path: math/stiring-number-second.cpp
    title: "\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(Stirling-Number-Of-The-Second-Kind)"
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B(Combination)"
  - icon: ':heavy_check_mark:'
    path: math/bell-number-2.cpp
    title: "\u30D9\u30EB\u6570(Bell Number) slower ver."
  - icon: ':heavy_check_mark:'
    path: math/stiring-number-second.cpp
    title: "\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(Stirling-Number-Of-The-Second-Kind)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
    document_title: "\u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\
      \u3044\u3001\u5236\u9650\u306A\u3057(\u30D9\u30EB\u6570($O(NKlog N$))"
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G
  bundledCode: "#line 1 \"test/DPL_5_G_2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n*/\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n\
    #define rep1(i,N) for(int i=1;i<int(N);++i)\n#define all(a) (a).begin(),(a).end()\n\
    #define print(v) { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<_<<\", \"; cerr<<\"\
    ]\"<<endl; }\n#define printpair(v) { cerr<<#v<<\": [ \"; for(auto _ : v) cerr<<\"\
    {\"<<_.first<<\",\"<<_.second<<\"}\"<<\", \"; cerr<<\"]\"<<endl; }\n#define dump(x)\
    \ cerr<<#x<<\": \"<<x<<endl;\n#define bit(k) (1LL<<(k))\n#define Yes \"Yes\"\n\
    #define No \"No\"\n#define YES \"YES\"\n#define NO \"NO\"\ntypedef long long ll;\n\
    \ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << \"{\" <<p.first << \", \" << p.second << \"}\"\
    ;\n  return os;\n}\ntemplate <class T> using vec = vector<T>;\ntemplate <class\
    \ T> using vvec = vector<vec<T>>;\n\ntemplate<class T> inline bool chmax(T& a,\
    \ T b) { if (a < b) { a = b; return true; } return false; }\ntemplate<class T>\
    \ inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false;\
    \ }\n\nconst int INF = (ll)1e9;\nconst ll INFLL = (ll)1e18+1;\nconst ll MOD =\
    \ (ll)1e9+7;\n\nconst double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1,\
    \ 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string\
    \ dir = \"DRUL\";\n\n\n#line 1 \"math/mint.hpp\"\n\n\n\n#line 5 \"math/mint.hpp\"\
    \n/*\n@title \u5408\u540C\u7B97\u8853(Modular Arithmetic)\n*/\nstruct mint {\n\
    \    long long x;\n    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}\n    mint operator-()\
    \ const { return mint(-x);}\n    mint& operator+=(const mint a) {\n        if\
    \ ((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    mint& operator-=(const\
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
    \ os;\n    }\n};\n\n#line 1 \"math/comb.hpp\"\n\n\n#line 5 \"math/comb.hpp\"\n\
    \n/*\n@title \u7D44\u307F\u5408\u308F\u305B(Combination)\n*/\nstruct combination\
    \ {\n    vector<mint> fact, ifact;\n    combination(int n):fact(n+1),ifact(n+1)\
    \ {\n        assert(n < MOD);\n        fact[0] = 1;\n        for (int i = 1; i\
    \ <= n; ++i) fact[i] = fact[i-1]*i;\n        ifact[n] = fact[n].inv();\n     \
    \   for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;\n    }\n    mint Comb(int\
    \ n, int k) {\n        if (k < 0 || k > n) return 0;\n        return fact[n]*ifact[k]*ifact[n-k];\n\
    \    }\n    mint H(int n, int m){\n        return Comb(n + m - 1, n);\n    }\n\
    \    //nPk\n    mint Perm(int n, int k){\n        if (k < 0 || n < k) return 0;\n\
    \        return fact[n]*ifact[n-k];\n    }\n};\n\n#line 1 \"math/stiring-number-second.cpp\"\
    \n\n\n#line 6 \"math/stiring-number-second.cpp\"\n\n/*\n@title \u7B2C\u4E8C\u7A2E\
    \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(Stirling-Number-Of-The-Second-Kind)\n\
    @category \u5199\u50CF12\u76F8\n@docs ../docs/math/stiring-number-second.md\n\
    */\nmint stirling_number_second(int n, int k){\n    combination C(k+1);\n    mint\
    \ res = 0;\n    for(int i = 0; i <= k;i++){\n        mint x = C.Comb(k, i) * mint(i).modpow(n);\n\
    \        res += ((k-i) & 1) ? -x:x;\n    }\n    res *= C.ifact[k];\n    return\
    \ res;\n}\n\n\n#line 1 \"math/bell-number-2.cpp\"\n\n\n#line 7 \"math/bell-number-2.cpp\"\
    \n/*\n@title \u30D9\u30EB\u6570(Bell Number) slower ver.\n@category \u5199\u50CF\
    12\u76F8\n@docs ../docs/math/bell-number-2.md\n*/\nmint bell_number_2(int n, int\
    \ k){\n    mint res = 0;\n    for(int j = 0; j <= k;j++){\n        res += stirling_number_second(n,\
    \ j);\n    }\n    return res;\n}\n\n\n#line 7 \"test/DPL_5_G_2.test.cpp\"\n/*\n\
    @title \u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\
    \u3001\u5236\u9650\u306A\u3057(\u30D9\u30EB\u6570($O(NKlog N$))\n@category \u5199\
    \u50CF12\u76F8\n*/\nint main(){\n    int n, k;\n    cin >> n >> k;\n    cout <<\
    \ bell_number_2(n, k) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../math/mint.hpp\"\n#include \"\
    ../math/comb.hpp\"\n#include \"../math/stiring-number-second.cpp\"\n#include \"\
    ../math/bell-number-2.cpp\"\n/*\n@title \u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\
    \u533A\u5225\u3057\u306A\u3044\u3001\u5236\u9650\u306A\u3057(\u30D9\u30EB\u6570\
    ($O(NKlog N$))\n@category \u5199\u50CF12\u76F8\n*/\nint main(){\n    int n, k;\n\
    \    cin >> n >> k;\n    cout << bell_number_2(n, k) << endl;\n}\n"
  dependsOn:
  - macro/macros.hpp
  - math/mint.hpp
  - macro/macros.hpp
  - math/comb.hpp
  - math/mint.hpp
  - math/stiring-number-second.cpp
  - math/comb.hpp
  - math/bell-number-2.cpp
  - math/stiring-number-second.cpp
  isVerificationFile: true
  path: test/DPL_5_G_2.test.cpp
  requiredBy: []
  timestamp: '2020-03-31 04:16:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DPL_5_G_2.test.cpp
layout: document
redirect_from:
- /verify/test/DPL_5_G_2.test.cpp
- /verify/test/DPL_5_G_2.test.cpp.html
title: "\u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\u3001\
  \u5236\u9650\u306A\u3057(\u30D9\u30EB\u6570($O(NKlog N$))"
---
