---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALDS1_3_A.test.cpp
    title: test/ALDS1_3_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: stack
    links: []
  bundledCode: "#line 1 \"data_structure/stack.hpp\"\n\n\n#line 1 \"macro/macros.hpp\"\
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
    \ -1, 1, 1, -1, -1};\nconst string dir = \"DRUL\";\n\n\n#line 4 \"data_structure/stack.hpp\"\
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
    };\n\n"
  code: "#ifndef INCLUDED_STACK_HPP\n#define INCLUDED_STACK_HPP\n#include \"../macro/macros.hpp\"\
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
    };\n#endif"
  dependsOn:
  - macro/macros.hpp
  isVerificationFile: false
  path: data_structure/stack.hpp
  requiredBy: []
  timestamp: '2020-09-23 15:05:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ALDS1_3_A.test.cpp
documentation_of: data_structure/stack.hpp
layout: document
redirect_from:
- /library/data_structure/stack.hpp
- /library/data_structure/stack.hpp.html
title: stack
---
