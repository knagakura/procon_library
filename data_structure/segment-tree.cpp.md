---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DSL_2_A.test.cpp
    title: test/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DSL_2_B_2.test.cpp
    title: test/DSL_2_B_2.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u62BD\u8C61\u5316\u30BB\u30B0\u6728"
    links: []
  bundledCode: "#line 1 \"data_structure/segment-tree.cpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 4 \"data_structure/segment-tree.cpp\"\
    \n\n/*\n@title \u62BD\u8C61\u5316\u30BB\u30B0\u6728\n@category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n*/\ntemplate<typename T>\nclass SegTree {\n  public:\n    int N;//\u8449\
    \u306E\u6570\n    vector<T> data;//\u914D\u5217\n    T unit;//\u5358\u4F4D\u5143\
    \n    function<T(T,T)> op;//\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\
    \u7406\n    function<T(T,T)> update;//\u70B9\u66F4\u65B0\u3067\u4F7F\u3046\u51E6\
    \u7406\n    T _query(int a, int b, int k, int l, int r) {\n        if(r <= a ||\
    \ b <= l)return unit;\n        if(a <= l && r <= b){\n            return data[k];\n\
    \        }\n        else{\n            T c1 = _query(a, b, 2 * k + 1, l, (l +\
    \ r) / 2); //\u5DE6\u306E\u5B50\n            T c2 = _query(a, b, 2 * k + 2, (l\
    \ + r) / 2, r); //\u5DE6\u306E\u5B50\n            return op(c1, c2);\n       \
    \ }\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u30FC\n    //_N:\
    \ \u5FC5\u8981\u30B5\u30A4\u30BA, _unit: \u521D\u671F\u5024\u304B\u3064\u5358\u4F4D\
    \u5143, _op: \u30AF\u30A8\u30EA\u95A2\u6570, _update: \u66F4\u65B0\u95A2\u6570\
    \n    SegTree(int _N, T _unit, function<T(T, T)> _op, function<T(T, T)> _update)\
    \ \n        :unit(_unit), op(_op), update(_update){\n        N = 1;\n        while(N\
    \ < _N)N *= 2;\n        data.assign(2 * N - 1, unit);\n    }\n    //i(0-indexed)\u306E\
    \u5024\u306Bupdate\u95A2\u6570\u3092\u9069\u7528\n    void change(int i, T x){\n\
    \        i += N - 1;\n        data[i] = update(data[i], x);\n        while(i >\
    \ 0){\n            i = (i - 1) / 2;\n            data[i] = op(data[i * 2 + 1],\
    \ data[i * 2 + 2]);\n        }\n    }\n    //[a, b)\u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u306E\u5B9F\u884C\n    T query(int a, int b){\n        return _query(a,\
    \ b, 0, 0, N);\n    }\n    //\u6DFB\u5B57\u3067\u30A2\u30AF\u30BB\u30B9\n    T\
    \ operator[](int i) {\n        return data[i + N - 1];\n    }\n};\n\n\n\n\n"
  code: "#ifndef SEGMENT_TREE_CPP\n#define SEGMENT_TREE_CPP\n#include \"../macro/macros.hpp\"\
    \n\n/*\n@title \u62BD\u8C61\u5316\u30BB\u30B0\u6728\n@category \u30C7\u30FC\u30BF\
    \u69CB\u9020\n*/\ntemplate<typename T>\nclass SegTree {\n  public:\n    int N;//\u8449\
    \u306E\u6570\n    vector<T> data;//\u914D\u5217\n    T unit;//\u5358\u4F4D\u5143\
    \n    function<T(T,T)> op;//\u533A\u9593\u30AF\u30A8\u30EA\u3067\u4F7F\u3046\u51E6\
    \u7406\n    function<T(T,T)> update;//\u70B9\u66F4\u65B0\u3067\u4F7F\u3046\u51E6\
    \u7406\n    T _query(int a, int b, int k, int l, int r) {\n        if(r <= a ||\
    \ b <= l)return unit;\n        if(a <= l && r <= b){\n            return data[k];\n\
    \        }\n        else{\n            T c1 = _query(a, b, 2 * k + 1, l, (l +\
    \ r) / 2); //\u5DE6\u306E\u5B50\n            T c2 = _query(a, b, 2 * k + 2, (l\
    \ + r) / 2, r); //\u5DE6\u306E\u5B50\n            return op(c1, c2);\n       \
    \ }\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u30FC\n    //_N:\
    \ \u5FC5\u8981\u30B5\u30A4\u30BA, _unit: \u521D\u671F\u5024\u304B\u3064\u5358\u4F4D\
    \u5143, _op: \u30AF\u30A8\u30EA\u95A2\u6570, _update: \u66F4\u65B0\u95A2\u6570\
    \n    SegTree(int _N, T _unit, function<T(T, T)> _op, function<T(T, T)> _update)\
    \ \n        :unit(_unit), op(_op), update(_update){\n        N = 1;\n        while(N\
    \ < _N)N *= 2;\n        data.assign(2 * N - 1, unit);\n    }\n    //i(0-indexed)\u306E\
    \u5024\u306Bupdate\u95A2\u6570\u3092\u9069\u7528\n    void change(int i, T x){\n\
    \        i += N - 1;\n        data[i] = update(data[i], x);\n        while(i >\
    \ 0){\n            i = (i - 1) / 2;\n            data[i] = op(data[i * 2 + 1],\
    \ data[i * 2 + 2]);\n        }\n    }\n    //[a, b)\u306E\u533A\u9593\u30AF\u30A8\
    \u30EA\u306E\u5B9F\u884C\n    T query(int a, int b){\n        return _query(a,\
    \ b, 0, 0, N);\n    }\n    //\u6DFB\u5B57\u3067\u30A2\u30AF\u30BB\u30B9\n    T\
    \ operator[](int i) {\n        return data[i + N - 1];\n    }\n};\n\n\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: data_structure/segment-tree.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DSL_2_A.test.cpp
  - test/DSL_2_B_2.test.cpp
documentation_of: data_structure/segment-tree.cpp
layout: document
redirect_from:
- /library/data_structure/segment-tree.cpp
- /library/data_structure/segment-tree.cpp.html
title: "\u62BD\u8C61\u5316\u30BB\u30B0\u6728"
---
