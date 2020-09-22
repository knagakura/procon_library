---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':heavy_check_mark:'
    path: tree/rooted-tree.cpp
    title: "\u6839\u4ED8\u304D\u6728(Rooted Tree)"
  - icon: ':heavy_check_mark:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A
  bundledCode: "#line 1 \"test/ALDS1_7_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\"\
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
    \ dir = \"DRUL\";\n\n\n#line 1 \"tree/rooted-tree.cpp\"\n\n\n#line 4 \"tree/rooted-tree.cpp\"\
    \n\n/*\n@title \u6839\u4ED8\u304D\u6728(Rooted Tree)\n@category tree\n@ignore\n\
    */\nstruct Rooted_Tree{\n    int N;\n    vector<vector<int>> G;\n    vector<int>\
    \ par;\n    vector<int> depth;\n    vector<string> type;\n    vector<vector<int>>\
    \ childs;\n    Rooted_Tree(int _N):N(_N),G(_N), par(_N, -1),depth(_N,0), type(_N),\
    \ childs(_N){}\n    void add_directed_edge(int parent, int child){\n        G[parent].push_back(child);\n\
    \        par[child] = parent;\n    }\n    void dfs(int cur, int pre = -1){\n \
    \       for(auto nv: G[cur]){\n            if(nv == pre)continue;\n          \
    \  childs[cur].push_back(nv);\n            depth[nv] = depth[cur] + 1;\n     \
    \       dfs(nv, cur);\n        }\n        if(pre == -1)\n            type[cur]\
    \ = \"root\";\n        else if((int)childs[cur].size() == 0)\n            type[cur]\
    \ = \"leaf\";\n        else\n            type[cur] = \"internal node\";\n    }\n\
    \    void build(){\n        for(int i = 0; i < N; i++){\n            if(par[i]\
    \ == -1){\n                dfs(i);\n                break;\n            }\n  \
    \      }\n    }\n    void Cout(){\n        for(int i = 0; i < N; i++){\n     \
    \       prints(i);\n        }\n    }\n    void prints(int idx){\n        cout\
    \ << \"node \"     << idx          << \": \";\n        cout << \"parent = \" <<\
    \ par[idx]     << \", \";\n        cout << \"depth = \"  << depth[idx]   << \"\
    , \";\n        cout << type[idx]   << \", \";\n        cout << \"[\";\n      \
    \  for(int i = 0; i < (int)childs[idx].size();i++){\n            cout << childs[idx][i];\n\
    \            if(i < (int)childs[idx].size()-1)\n                cout << \", \"\
    ;\n        }\n        cout << \"]\" << endl;\n    }\n};\n\n\n#line 4 \"test/ALDS1_7_A.test.cpp\"\
    \n/*\n*/\n\nint main(){\n    int N;\n    cin >> N;\n    Rooted_Tree G(N);\n  \
    \  for(int i = 0; i < N;i++){\n        int from, k, to;\n        cin >> from >>\
    \ k;\n        for(int j = 0; j < k;j++){\n            cin >> to;\n           \
    \ G.add_directed_edge(from, to);\n        }\n    }\n    G.build();\n    G.Cout();\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_A\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../tree/rooted-tree.cpp\"\n/*\n\
    */\n\nint main(){\n    int N;\n    cin >> N;\n    Rooted_Tree G(N);\n    for(int\
    \ i = 0; i < N;i++){\n        int from, k, to;\n        cin >> from >> k;\n  \
    \      for(int j = 0; j < k;j++){\n            cin >> to;\n            G.add_directed_edge(from,\
    \ to);\n        }\n    }\n    G.build();\n    G.Cout();\n}"
  dependsOn:
  - macro/macros.hpp
  - tree/rooted-tree.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/ALDS1_7_A.test.cpp
  requiredBy: []
  timestamp: '2020-03-31 19:14:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALDS1_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/ALDS1_7_A.test.cpp
- /verify/test/ALDS1_7_A.test.cpp.html
title: test/ALDS1_7_A.test.cpp
---
