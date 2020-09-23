---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/NTL_1_E.test.cpp
    title: test/NTL_1_E.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/extended-euclid-algorithm.cpp\"\n\n\n\nlong long extGCD(long\
    \ long a, long long b, long long &x, long long &y) {\n    if (b == 0) {\n    \
    \    x = 1;\n        y = 0;\n        return a;\n    }\n    long long d = extGCD(b,\
    \ a%b, y, x);\n    y -= a/b * x;\n    return d;\n}\n\n\n"
  code: "#ifndef EXTENDED_EUCLIDE_ALGORITHM_CPP\n#define EXTENDED_EUCLIDE_ALGORITHM_CPP\n\
    \nlong long extGCD(long long a, long long b, long long &x, long long &y) {\n \
    \   if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n    }\n\
    \    long long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n}\n\
    \n#endif"
  dependsOn: []
  isVerificationFile: false
  path: math/extended-euclid-algorithm.cpp
  requiredBy: []
  timestamp: '2020-09-22 18:18:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/NTL_1_E.test.cpp
documentation_of: ./math/extended-euclid-algorithm.cpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---

### 計算量
$\log{a}$

### 説明
返り値: $a$と$b$の最大公約数

$ax + by = gcd(a, b)$を満たす解$(x, y)$が格納される

### 参考
- [拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜](https://qiita.com/drken/items/b97ff231e43bce50199a)