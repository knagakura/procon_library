---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_1_B.test.cpp
    title: test/ALDS1_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u6700\u5927\u516C\u7D04\u6570(Greatest Common Divisor)"
    links: []
  bundledCode: "#line 1 \"math/gcd.hpp\"\n\n\n/*\n@title \u6700\u5927\u516C\u7D04\u6570\
    (Greatest Common Divisor)\n*/\ntemplate<typename T>\nT gcd(T a,T b){\n    if(b\
    \ == 0) return a;\n    return gcd(b, a%b);\n}\ntemplate<typename T>\nT lcm(T a,T\
    \ b){return a/gcd(a,b)*b;}\n\n"
  code: "#ifndef GCD_HPP\n#define GCD_HPP\n/*\n@title \u6700\u5927\u516C\u7D04\u6570\
    (Greatest Common Divisor)\n*/\ntemplate<typename T>\nT gcd(T a,T b){\n    if(b\
    \ == 0) return a;\n    return gcd(b, a%b);\n}\ntemplate<typename T>\nT lcm(T a,T\
    \ b){return a/gcd(a,b)*b;}\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: math/gcd.hpp
  requiredBy: []
  timestamp: '2020-03-31 16:47:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_1_B.test.cpp
documentation_of: math/gcd.hpp
layout: document
redirect_from:
- /library/math/gcd.hpp
- /library/math/gcd.hpp.html
title: "\u6700\u5927\u516C\u7D04\u6570(Greatest Common Divisor)"
---
