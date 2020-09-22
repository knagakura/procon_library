---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: data_structure/stack.hpp
    title: stack
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp
  bundledCode: "#line 1 \"test/ALDS1_3_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp\"\
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
    \ dir = \"DRUL\";\n\n\n#line 1 \"data_structure/stack.hpp\"\n\n\n#line 4 \"data_structure/stack.hpp\"\
    \n/*\n@title stack\n@category \u30C7\u30FC\u30BF\u69CB\u9020\n@ignore\n*/\ntemplate<\
    \ typename T >\nclass Stack{\n  public:\n    int N;\n    int top = 0;\n    T data[20000];\n\
    \    Stack(int sz):N(sz), top(0){}\n    void push(int x){\n        if(isFull()){\n\
    \            cerr << \"\u3053\u308C\u4EE5\u4E0A\u5165\u308A\u307E\u305B\u3093\"\
    \ << endl;\n            return;\n        }\n        data[top] = x;\n        top++;\n\
    \    }\n    int pop(){\n        if(isEmpty()){\n            cerr << \"\u4E2D\u8EAB\
    \u306F\u7A7A\u3067\u3059\" << endl;\n            return -1;\n        }\n     \
    \   top--;\n        return data[top];\n    }\n    bool isFull(){\n        return\
    \ top >= N;\n    }\n    bool isEmpty(){\n        return top == 0;\n    }\n   \
    \ void show(){\n        dump(top);\n        for(int i = 0; i < top;i++){\n   \
    \         cerr << data[i] << \" \";\n        }\n        cerr << endl;\n    }\n\
    };\n\n#line 4 \"test/ALDS1_3_A.test.cpp\"\n\nint main(){\n    Stack<int> S(1000);\n\
    \    string c;\n    while(cin >> c){\n        if(c == \"+\"){\n            int\
    \ a = S.pop();\n            int b = S.pop();\n            S.push(b + a);\n   \
    \     }\n        else if(c == \"-\"){\n            int a = S.pop();\n        \
    \    int b = S.pop();\n            S.push(b - a);\n        }\n        else if(c\
    \ == \"*\"){\n            int a = S.pop();\n            int b = S.pop();\n   \
    \         S.push(b * a);\n        }\n        else{\n            int x = stoi(c);\n\
    \            S.push(x);\n        }\n    }\n    cout << S.pop() << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../data_structure/stack.hpp\"\n\
    \nint main(){\n    Stack<int> S(1000);\n    string c;\n    while(cin >> c){\n\
    \        if(c == \"+\"){\n            int a = S.pop();\n            int b = S.pop();\n\
    \            S.push(b + a);\n        }\n        else if(c == \"-\"){\n       \
    \     int a = S.pop();\n            int b = S.pop();\n            S.push(b - a);\n\
    \        }\n        else if(c == \"*\"){\n            int a = S.pop();\n     \
    \       int b = S.pop();\n            S.push(b * a);\n        }\n        else{\n\
    \            int x = stoi(c);\n            S.push(x);\n        }\n    }\n    cout\
    \ << S.pop() << endl;\n}\n"
  dependsOn:
  - macro/macros.hpp
  - data_structure/stack.hpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/ALDS1_3_A.test.cpp
  requiredBy: []
  timestamp: '2020-03-31 17:09:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALDS1_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/ALDS1_3_A.test.cpp
- /verify/test/ALDS1_3_A.test.cpp.html
title: test/ALDS1_3_A.test.cpp
---
