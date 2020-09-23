---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy-segment-tree-raq.cpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(Lazy Segment\
      \ Tree) \u533A\u9593\u52A0\u7B97"
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
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
    \ long double PI = acos(-1.0);\n\nconst int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};\n\
    const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\
    \n\n#line 1 \"data_structure/lazy-segment-tree-raq.cpp\"\n\n\n#line 4 \"data_structure/lazy-segment-tree-raq.cpp\"\
    \n\n/*\n@title \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(Lazy\
    \ Segment Tree) \u533A\u9593\u52A0\u7B97\n@category \u30C7\u30FC\u30BF\u69CB\u9020\
    \n*/\ntemplate<typename T>\nclass LazySegTree {\n  public:\n    int N;//\u8449\
    \u306E\u6570\n    vector<T> data;//\u914D\u5217\n    vector<T> lazy;//\u9045\u5EF6\
    \u8A55\u4FA1\n    void _add(int a, int b, T x, int k, int l, int r){\n       \
    \ eval(k, l, r);\n        if(b <= l || r <= a)return;\n        if(a <= l && r\
    \ <= b){\n            lazy[k] += (r - l) * x;\n            eval(k, l, r);\n  \
    \      }\n        else{\n            _add(a, b, x, 2*k+1, l, (l+r)/2);\n     \
    \       _add(a, b, x, 2*k+2, (l+r)/2, r);\n            data[k] = data[2*k+1] +\
    \ data[2*k+2];\n        }\n    }\n    T _query(int a, int b, int k, int l, int\
    \ r) {\n        if(r <= a || b <= l) return 0;\n        eval(k, l, r);\n     \
    \   if(a <= l && r <= b) return data[k];\n        T c1 = _query(a, b, 2*k+1, l,\
    \ (l+r)/2);\n        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);\n        return c1\
    \ + c2;\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u30FC\n    LazySegTree(vector<T>\
    \ v){\n        int sz = v.size();\n        N = 1;\n        while(N < sz)N *= 2;\n\
    \        data.assign(2 * N - 1, 0);\n        lazy.assign(2 * N - 1, 0);\n    \
    \    for(int i = 0; i < sz; i++) data[N-1+i] = v[i];\n        for(int i = N -\
    \ 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];\n    }\n    //\u9045\u5EF6\
    \u8A55\u4FA1\n    void eval(int k, int l, int r){\n        if(lazy[k] == 0)return;\n\
    \        data[k] += lazy[k];\n        if(r - l > 1){\n            lazy[2*k+1]\
    \ += lazy[k] / 2;\n            lazy[2*k+2] += lazy[k] / 2;\n        }\n      \
    \  lazy[k] = 0;\n    }\n    void add(int a, int b, T x){\n        _add(a, b, x,\
    \ 0, 0, N);\n    }\n    //[a, b)\u306E\u533A\u9593\u30AF\u30A8\u30EA\u306E\u5B9F\
    \u884C\n    T query(int a, int b){\n        return _query(a, b, 0, 0, N);\n  \
    \  }\n    //\u6DFB\u5B57\u3067\u30A2\u30AF\u30BB\u30B9\n    T operator[](int i)\
    \ {\n        return data[i + N - 1];\n    }\n};\n\n\n#line 4 \"test/DSL_2_G.test.cpp\"\
    \n\n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> v(N,0);\n\
    \    LazySegTree<long long> Seg(v);\n    while(Q--){\n        int ord;\n     \
    \   cin >> ord;\n        if(ord == 0){\n            int s, t;\n            long\
    \ long x;\n            cin >> s >> t >> x;\n            s--;t--;\n           \
    \ Seg.add(s, t+1, x);\n        }\n        if(ord == 1){\n            int s, t;\n\
    \            cin >> s >> t;\n            s--;t--;\n            cout << Seg.query(s,\
    \ t+1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../data_structure/lazy-segment-tree-raq.cpp\"\
    \n\n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long> v(N,0);\n\
    \    LazySegTree<long long> Seg(v);\n    while(Q--){\n        int ord;\n     \
    \   cin >> ord;\n        if(ord == 0){\n            int s, t;\n            long\
    \ long x;\n            cin >> s >> t >> x;\n            s--;t--;\n           \
    \ Seg.add(s, t+1, x);\n        }\n        if(ord == 1){\n            int s, t;\n\
    \            cin >> s >> t;\n            s--;t--;\n            cout << Seg.query(s,\
    \ t+1) << endl;\n        }\n    }\n}"
  dependsOn:
  - macro/macros.hpp
  - data_structure/lazy-segment-tree-raq.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/DSL_2_G.test.cpp
- /verify/test/DSL_2_G.test.cpp.html
title: test/DSL_2_G.test.cpp
---
