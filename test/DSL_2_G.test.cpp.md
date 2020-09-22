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
    \ dir = \"DRUL\";\n\n\n#line 1 \"data_structure/lazy-segment-tree-raq.cpp\"\n\n\
    \n#line 4 \"data_structure/lazy-segment-tree-raq.cpp\"\n\n/*\n@title \u9045\u5EF6\
    \u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(Lazy Segment Tree) \u533A\u9593\
    \u52A0\u7B97\n@category \u30C7\u30FC\u30BF\u69CB\u9020\n*/\ntemplate<typename\
    \ T>\nclass LazySegTree {\n  public:\n    int N;//\u8449\u306E\u6570\n    vector<T>\
    \ data;//\u914D\u5217\n    vector<T> lazy;//\u9045\u5EF6\u8A55\u4FA1\n    void\
    \ _add(int a, int b, T x, int k, int l, int r){\n        eval(k, l, r);\n    \
    \    if(b <= l || r <= a)return;\n        if(a <= l && r <= b){\n            lazy[k]\
    \ += (r - l) * x;\n            eval(k, l, r);\n        }\n        else{\n    \
    \        _add(a, b, x, 2*k+1, l, (l+r)/2);\n            _add(a, b, x, 2*k+2, (l+r)/2,\
    \ r);\n            data[k] = data[2*k+1] + data[2*k+2];\n        }\n    }\n  \
    \  T _query(int a, int b, int k, int l, int r) {\n        if(r <= a || b <= l)\
    \ return 0;\n        eval(k, l, r);\n        if(a <= l && r <= b) return data[k];\n\
    \        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);\n        T c2 = _query(a, b,\
    \ 2*k+2, (l+r)/2, r);\n        return c1 + c2;\n    }\n    //\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u30FC\n    LazySegTree(vector<T> v){\n        int sz\
    \ = v.size();\n        N = 1;\n        while(N < sz)N *= 2;\n        data.assign(2\
    \ * N - 1, 0);\n        lazy.assign(2 * N - 1, 0);\n        for(int i = 0; i <\
    \ sz; i++) data[N-1+i] = v[i];\n        for(int i = N - 2; i >= 0; i--) data[i]\
    \ = data[i*2+1] + data[i*2+2];\n    }\n    //\u9045\u5EF6\u8A55\u4FA1\n    void\
    \ eval(int k, int l, int r){\n        if(lazy[k] == 0)return;\n        data[k]\
    \ += lazy[k];\n        if(r - l > 1){\n            lazy[2*k+1] += lazy[k] / 2;\n\
    \            lazy[2*k+2] += lazy[k] / 2;\n        }\n        lazy[k] = 0;\n  \
    \  }\n    void add(int a, int b, T x){\n        _add(a, b, x, 0, 0, N);\n    }\n\
    \    //[a, b)\u306E\u533A\u9593\u30AF\u30A8\u30EA\u306E\u5B9F\u884C\n    T query(int\
    \ a, int b){\n        return _query(a, b, 0, 0, N);\n    }\n    //\u6DFB\u5B57\
    \u3067\u30A2\u30AF\u30BB\u30B9\n    T operator[](int i) {\n        return data[i\
    \ + N - 1];\n    }\n};\n\n\n#line 4 \"test/DSL_2_G.test.cpp\"\n\n\nint main(){\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<long long> v(N,0);\n    LazySegTree<long\
    \ long> Seg(v);\n    while(Q--){\n        int ord;\n        cin >> ord;\n    \
    \    if(ord == 0){\n            int s, t;\n            long long x;\n        \
    \    cin >> s >> t >> x;\n            s--;t--;\n            Seg.add(s, t+1, x);\n\
    \        }\n        if(ord == 1){\n            int s, t;\n            cin >> s\
    \ >> t;\n            s--;t--;\n            cout << Seg.query(s, t+1) << endl;\n\
    \        }\n    }\n}\n"
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
  timestamp: '2020-04-03 02:57:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/DSL_2_G.test.cpp
- /verify/test/DSL_2_G.test.cpp.html
title: test/DSL_2_G.test.cpp
---
