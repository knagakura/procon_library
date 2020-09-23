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
    path: math/stiring-number-second-dp.cpp
    title: "\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(Stirling-Number-Of-The-Second-Kind)\
      \ DP ver."
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B(Combination)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I
    document_title: "\u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\
      \u3044\u30011\u500B\u4EE5\u4E0A(\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\
      \u30B0\u6570(DP))"
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I
  bundledCode: "#line 1 \"test/DPL_5_I_DP.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I\"\
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
    ;\n*/\n\n\n#line 1 \"math/mint.hpp\"\n\n\n\n#line 5 \"math/mint.hpp\"\n/*\n@title\
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
    \ os;\n    }\n};\n\n#line 1 \"math/comb.hpp\"\n\n\n#line 5 \"math/comb.hpp\"\n\
    \n/*\n@title \u7D44\u307F\u5408\u308F\u305B(Combination)\n*/\nstruct combination\
    \ {\n    vector<mint> fact, ifact;\n    combination(int n):fact(n+1),ifact(n+1)\
    \ {\n        assert(n < MOD);\n        fact[0] = 1;\n        for (int i = 1; i\
    \ <= n; ++i) fact[i] = fact[i-1]*i;\n        ifact[n] = fact[n].inv();\n     \
    \   for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;\n    }\n    mint Comb(int\
    \ n, int k) {\n        if (k < 0 || k > n) return 0;\n        return fact[n]*ifact[k]*ifact[n-k];\n\
    \    }\n    mint H(int n, int m){\n        return Comb(n + m - 1, n);\n    }\n\
    \    //nPk\n    mint Perm(int n, int k){\n        if (k < 0 || n < k) return 0;\n\
    \        return fact[n]*ifact[n-k];\n    }\n};\n\n#line 1 \"math/stiring-number-second-dp.cpp\"\
    \n\n\n#line 6 \"math/stiring-number-second-dp.cpp\"\n\n/*\n@title \u7B2C\u4E8C\
    \u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(Stirling-Number-Of-The-Second-Kind)\
    \ DP ver.\n@category \u5199\u50CF12\u76F8\n@docs ../docs/math/stiring-number-second-dp.md\n\
    */\ntemplate<typename T = mint>\nstruct Stiring_dp{\n    int N;\n    vector<vector<mint>>\
    \ S;\n    Stiring_dp(int _N):N(_N), S(N+1, vector<mint>(N+1, 0)){\n        build();\n\
    \    }\n    void build(){\n        S[0][0] = 1;\n        for(int i = 1; i <= N;\
    \ i++){\n            for(int j = 1; j <= N; j++){\n                S[i][j] = S[i-1][j-1]\
    \ + mint(j)*S[i-1][j];\n            }\n        }\n    }\n    mint get(int n, int\
    \ k){\n        if(n < 0 || k < 0 || n < k)return 0;\n        return S[n][k];\n\
    \    }\n};\n\n\n#line 6 \"test/DPL_5_I_DP.test.cpp\"\n\n/*\n@title \u7389\u533A\
    \u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\u30011\u500B\u4EE5\
    \u4E0A(\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570(DP))\n@category\
    \ \u5199\u50CF12\u76F8\n*/\nint main(){\n    int n, k;\n    cin >> n >> k;\n \
    \   Stiring_dp<mint> Sl(n);\n    cout << Sl.get(n, k) <<endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../math/mint.hpp\"\n#include \"\
    ../math/comb.hpp\"\n#include \"../math/stiring-number-second-dp.cpp\"\n\n/*\n\
    @title \u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\
    \u30011\u500B\u4EE5\u4E0A(\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
    \u6570(DP))\n@category \u5199\u50CF12\u76F8\n*/\nint main(){\n    int n, k;\n\
    \    cin >> n >> k;\n    Stiring_dp<mint> Sl(n);\n    cout << Sl.get(n, k) <<endl;\n\
    }"
  dependsOn:
  - macro/macros.hpp
  - math/mint.hpp
  - macro/macros.hpp
  - math/comb.hpp
  - math/mint.hpp
  - math/stiring-number-second-dp.cpp
  - math/comb.hpp
  isVerificationFile: true
  path: test/DPL_5_I_DP.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DPL_5_I_DP.test.cpp
layout: document
redirect_from:
- /verify/test/DPL_5_I_DP.test.cpp
- /verify/test/DPL_5_I_DP.test.cpp.html
title: "\u7389\u533A\u5225\u3059\u308B\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\u3001\
  1\u500B\u4EE5\u4E0A(\u7B2C\u4E8C\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\
  (DP))"
---
