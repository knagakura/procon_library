---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"data_structure/lazy-segment-tree-ruq.cpp\"\n\n\n#line 1\
    \ \"macro/macros.hpp\"\n\n\n\n/*\n@title Macro\n@category template\n*/\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define rep(i,N) for(int i=0;i<int(N);++i)\n\
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
    \ dir = \"DRUL\";\n\n\n#line 4 \"data_structure/lazy-segment-tree-ruq.cpp\"\n\n\
    /*\n@\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728(Lazy Segment\
    \ Tree) \u533A\u9593\u66F4\u65B0\n*/\ntemplate<typename T>\nclass LazySegTree\
    \ {\n  public:\n    int N;//\u8449\u306E\u6570\n    int cnt;\n    vector<T> data;//\u914D\
    \u5217\n    vector<T> lazy;//\u9045\u5EF6\u8A55\u4FA1\n    void _change(int a,\
    \ int b, T x, int k, int l, int r){\n        //eval(k, l, r);\n        if(b <=\
    \ l || r <= a)return;\n        if(a <= l && r <= b){\n            lazy[k] = x;\n\
    \            //eval(k, l, r);\n        }\n        else{\n            _change(a,\
    \ b, x, 2*k+1, l, (l+r)/2);\n            _change(a, b, x, 2*k+2, (l+r)/2, r);\n\
    \        }\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u30FC\n  \
    \  LazySegTree(N){\n        int sz = v.size();\n        N = 1;\n        while(N\
    \ < sz)N *= 2;\n        data.assign(2 * N - 1, 0);\n        lazy.assign(2 * N\
    \ - 1, 0);\n        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];\n        for(int\
    \ i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];\n    }\n    //\u9045\
    \u5EF6\u8A55\u4FA1\n    void eval(int k, int l, int r){\n        if(lazy[k] ==\
    \ 0)return;\n        data[k] += lazy[k];\n        if(r - l > 1){\n           \
    \ lazy[2*k+1] += lazy[k] / 2;\n            lazy[2*k+2] += lazy[k] / 2;\n     \
    \   }\n        lazy[k] = 0;\n    }\n    void change(int a, int b, T x){\n    \
    \    _change(a, b, x, 0, 0, N);\n    }\n\n    //\u6DFB\u5B57\u3067\u30A2\u30AF\
    \u30BB\u30B9\n    T operator[](int i) {\n        return data[i + N - 1];\n   \
    \ }\n};\n\n\n"
  code: "#ifndef LAZY_SEGMENT_TREE_RUQ_CPP\n#define LAZY_SEGMENT_TREE_RUQ_CPP\n#include\
    \ \"../macro/macros.hpp\"\n\n/*\n@\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728(Lazy Segment Tree) \u533A\u9593\u66F4\u65B0\n*/\ntemplate<typename\
    \ T>\nclass LazySegTree {\n  public:\n    int N;//\u8449\u306E\u6570\n    int\
    \ cnt;\n    vector<T> data;//\u914D\u5217\n    vector<T> lazy;//\u9045\u5EF6\u8A55\
    \u4FA1\n    void _change(int a, int b, T x, int k, int l, int r){\n        //eval(k,\
    \ l, r);\n        if(b <= l || r <= a)return;\n        if(a <= l && r <= b){\n\
    \            lazy[k] = x;\n            //eval(k, l, r);\n        }\n        else{\n\
    \            _change(a, b, x, 2*k+1, l, (l+r)/2);\n            _change(a, b, x,\
    \ 2*k+2, (l+r)/2, r);\n        }\n    }\n    //\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u30FC\n    LazySegTree(N){\n        int sz = v.size();\n        N = 1;\n\
    \        while(N < sz)N *= 2;\n        data.assign(2 * N - 1, 0);\n        lazy.assign(2\
    \ * N - 1, 0);\n        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];\n    \
    \    for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];\n  \
    \  }\n    //\u9045\u5EF6\u8A55\u4FA1\n    void eval(int k, int l, int r){\n  \
    \      if(lazy[k] == 0)return;\n        data[k] += lazy[k];\n        if(r - l\
    \ > 1){\n            lazy[2*k+1] += lazy[k] / 2;\n            lazy[2*k+2] += lazy[k]\
    \ / 2;\n        }\n        lazy[k] = 0;\n    }\n    void change(int a, int b,\
    \ T x){\n        _change(a, b, x, 0, 0, N);\n    }\n\n    //\u6DFB\u5B57\u3067\
    \u30A2\u30AF\u30BB\u30B9\n    T operator[](int i) {\n        return data[i + N\
    \ - 1];\n    }\n};\n\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: data_structure/lazy-segment-tree-ruq.cpp
  requiredBy: []
  timestamp: '2020-09-22 16:27:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/lazy-segment-tree-ruq.cpp
layout: document
redirect_from:
- /library/data_structure/lazy-segment-tree-ruq.cpp
- /library/data_structure/lazy-segment-tree-ruq.cpp.html
title: data_structure/lazy-segment-tree-ruq.cpp
---
