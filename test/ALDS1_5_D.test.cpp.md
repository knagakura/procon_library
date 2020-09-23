---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/inversion-num.cpp
    title: "\u8EE2\u5012\u6570(The Number of Inversion)"
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: data_structure/bit.cpp
    title: BIT(Binary Indexed Tree)
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"test/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#line 1 \"data_structure/inversion-num.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    \n/*\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\nconst int dy[8] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n*/\n\n\n#line 1 \"data_structure/bit.cpp\"\
    \n\n\n#line 4 \"data_structure/bit.cpp\"\n/*\n@title BIT(Binary Indexed Tree)\n\
    @category \u30C7\u30FC\u30BF\u69CB\u9020\n*/\ntemplate<typename T>\nclass BIT{\n\
    \  public:\n    int N;\n    vector<T> data;\n    BIT(T _N):N(_N){\n        data.assign(N+1,\
    \ 0);\n    };\n    \n    // a is 1-indexed\n    void add(int a, T w){\n      \
    \  for(int x = a; x <= N; x += x & -x)data[x] += w;\n    }\n    // 1-indexed sum\
    \ of prefix [0, a]\n    T sum(int a){\n        T res = 0;\n        for(int x =\
    \ a; x > 0; x -= x & -x)res += data[x];\n        return res;\n    }\n    // 1-indexed\
    \ sum of range [l, r]\n    T sum(int l, int r){return sum(r) - sum(l-1);}\n\n\
    \    // 0-indexed add\n    void add0(int a, T w){add(a + 1, w);}\n    // 0-indexed\
    \ sum\n    T sum0(int a){return sum(a + 1);}\n    // 0-indexed sum of range\n\
    \    T sum0(int l, int r){return sum0(r) - sum0(l-1);}\n    // show the value\n\
    \    void debug(){print(data);}\n};\n\n\n#line 5 \"data_structure/inversion-num.cpp\"\
    \ntemplate<typename T> \nT Inversion_num(vector<T>& v){\n    int N = v.size();\n\
    \    BIT<T> Tree(N);\n    vector<int> B(N);\n    vector<pair<T, int>> ap;\n  \
    \  for(int i = 0; i < N; i++){\n        ap.push_back(make_pair(v[i],i));\n   \
    \ }\n    sort(ap.begin(), ap.end());\n    for(int i = 0; i < N; i++){\n      \
    \  B[ap[i].second] =  i;\n    }\n    T res = 0;\n    for(int i = 0; i < N; i++){\n\
    \        res += i - Tree.sum0(B[i]);\n        Tree.add0(B[i], 1);\n    }\n   \
    \ return res;\n}\n\n#line 4 \"test/ALDS1_5_D.test.cpp\"\n\nint main(){\n    int\
    \ N;\n    cin >> N;\n    vector<ll> A(N);\n    rep(i,N)cin>>A[i];\n    cout <<\
    \ Inversion_num(A) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include \"../data_structure/inversion-num.cpp\"\n\nint main(){\n    int N;\n\
    \    cin >> N;\n    vector<ll> A(N);\n    rep(i,N)cin>>A[i];\n    cout << Inversion_num(A)\
    \ << endl;\n}"
  dependsOn:
  - data_structure/inversion-num.cpp
  - macro/macros.hpp
  - data_structure/bit.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 14:39:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/ALDS1_5_D.test.cpp
- /verify/test/ALDS1_5_D.test.cpp.html
title: test/ALDS1_5_D.test.cpp
---
