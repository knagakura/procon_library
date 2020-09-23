---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: "\u6700\u5927\u516C\u7D04\u6570(Greatest Common Divisor)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B
  bundledCode: "#line 1 \"test/ALDS1_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B\"\
    \n\n#line 1 \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n\
    */\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\n#define\
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
    \ long double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\n\
    const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\
    \n\n#line 1 \"math/gcd.hpp\"\n\n\n/*\n@title \u6700\u5927\u516C\u7D04\u6570(Greatest\
    \ Common Divisor)\n*/\ntemplate<typename T>\nT gcd(T a,T b){\n    if(b == 0) return\
    \ a;\n    return gcd(b, a%b);\n}\ntemplate<typename T>\nT lcm(T a,T b){return\
    \ a/gcd(a,b)*b;}\n\n#line 5 \"test/ALDS1_1_B.test.cpp\"\n\nint main(){\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << gcd(a, b) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B\"\
    \n\n#include \"../macro/macros.hpp\"\n#include \"../math/gcd.hpp\"\n\nint main(){\n\
    \    int a, b;\n    cin >> a >> b;\n    cout << gcd(a, b) << endl;\n}"
  dependsOn:
  - macro/macros.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/ALDS1_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALDS1_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/ALDS1_1_B.test.cpp
- /verify/test/ALDS1_1_B.test.cpp.html
title: test/ALDS1_1_B.test.cpp
---
