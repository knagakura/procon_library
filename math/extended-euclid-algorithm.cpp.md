---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/NTL_1_E.test.cpp
    title: test/NTL_1_E.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/NTL_1_E.test.cpp
documentation_of: math/extended-euclid-algorithm.cpp
layout: document
redirect_from:
- /library/math/extended-euclid-algorithm.cpp
- /library/math/extended-euclid-algorithm.cpp.html
title: math/extended-euclid-algorithm.cpp
---
