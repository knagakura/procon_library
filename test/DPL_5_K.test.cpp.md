---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_K
    document_title: "\u7389\u533A\u5225\u3057\u306A\u3044\u3001\u7BB1\u533A\u5225\u3057\
      \u306A\u3044\u30011\u500B\u4EE5\u5185(0 or 1)"
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_K
  bundledCode: "#line 1 \"test/DPL_5_K.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_K\"\
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
    \ dir = \"DRUL\";\n\n\n#line 3 \"test/DPL_5_K.test.cpp\"\n\n/*\n@title \u7389\u533A\
    \u5225\u3057\u306A\u3044\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\u30011\u500B\
    \u4EE5\u5185(0 or 1)\n@category \u5199\u50CF12\u76F8\n*/\nint main(){\n    int\
    \ n, k;\n    cin >> n >> k;\n    cout << ((n <= k) ? 1: 0) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_K\"\
    \n#include \"../macro/macros.hpp\"\n\n/*\n@title \u7389\u533A\u5225\u3057\u306A\
    \u3044\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\u30011\u500B\u4EE5\u5185(0 or\
    \ 1)\n@category \u5199\u50CF12\u76F8\n*/\nint main(){\n    int n, k;\n    cin\
    \ >> n >> k;\n    cout << ((n <= k) ? 1: 0) << endl;\n}"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: true
  path: test/DPL_5_K.test.cpp
  requiredBy: []
  timestamp: '2020-03-31 04:16:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DPL_5_K.test.cpp
layout: document
redirect_from:
- /verify/test/DPL_5_K.test.cpp
- /verify/test/DPL_5_K.test.cpp.html
title: "\u7389\u533A\u5225\u3057\u306A\u3044\u3001\u7BB1\u533A\u5225\u3057\u306A\u3044\
  \u30011\u500B\u4EE5\u5185(0 or 1)"
---
