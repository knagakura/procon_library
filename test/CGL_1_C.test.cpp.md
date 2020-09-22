---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  - icon: ':question:'
    path: geometory/template.cpp
    title: Geometory/template.cpp
  - icon: ':question:'
    path: macro/macros.hpp
    title: Macro
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"test/CGL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
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
    \ dir = \"DRUL\";\n\n\n#line 1 \"geometory/template.cpp\"\n\n\n#line 5 \"geometory/template.cpp\"\
    \n/*\n@title Geometory/template.cpp\n@category Geometory\n*/\n\ntypedef complex<double>\
    \ Point;\ntypedef pair<Point, Point> Segment;\n#define EPS (1e-10)\n#define EQ(a,\
    \ b) (abs((a) - (b)) < EPS)\nPoint operator*(const Point &p, const double &d)\
    \ {\n  return Point(real(p) * d, imag(p) * d);\n}\n// \u5185\u7A4D\ndouble dot(Point\
    \ a, Point b){\n    return (a.real() * b.real() + a.imag() * b.imag());\n}\n//\u5916\
    \u7A4D\ndouble cross(const Point &a, const Point &b){\n    return (a.real() *\
    \ b.imag() - a.imag() * b.real());\n}\n\n/*\n\"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_1_A\"\
    \n\u76F4\u7DDA l \u306B p \u304B\u3089\u5F15\u3044\u305F\u4EA4\u70B9\u3092\u6C42\
    \u3081\u308B\n*/\nPoint projection(const Segment &l, const Point &p){\n    double\
    \ t = dot(p - l.first, l.second - l.first) / norm(l.second - l.first);\n    return\
    \ l.first + t * (l.second - l.first);\n}\n/*\n\u76F4\u7DDA l \u306B\u95A2\u3057\
    \u3066\u7DDA\u5BFE\u79F0\u306A\u70B9\u3092\u6C42\u3081\u308B\n*/\nPoint reflection(const\
    \ Segment &l, const Point &p){\n    return p + (projection(l,p)-p)*2.0;\n}\n/*\n\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\ncrockwise\n\
    */\nint ccw(const Point &a, const Point &b, const Point &c){\n    Point x = b\
    \ - a;\n    Point y = c - a;\n    if(cross(x,y) > EPS)return 1;   //\u6642\u8A08\
    \u56DE\u308A\n    if(cross(x,y) < -EPS)return -1; //\u53CD\u6642\u8A08\u56DE\u308A\
    \n    if(dot(x,y) < -EPS)return +2;   //\u5F8C\u308D\n    if(norm(x) < norm(y))return\
    \ -2; //\u524D\n    return 0;                       //\u4E2D\n}\n/*\nhttps://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B\n\
    \u4E8C\u3064\u306E\u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\n*/\nbool isinterSS(const\
    \ Segment &a, const Segment &b){\n    double ok[2];\n    ok[0] = ccw(a.first,\
    \ a.second, b.first)*ccw(a.first, a.second, b.second);\n    ok[1] = ccw(b.first,\
    \ b.second, a.first)*ccw(b.first, b.second, a.second);\n    return ok[0] <= 0\
    \ && ok[1] <= 0;\n}\n/*\nhttps://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C\n\
    \u4E8C\u3064\u306E\u7DDA\u5206\u306E\u4EA4\u70B9\n*/\nPoint cross_point(const\
    \ Segment &a, const Segment &b){\n    double d1 = abs(cross(b.second-b.first,\
    \ a.first-b.first));\n    double d2 = abs(cross(b.second-b.first, a.second-b.first));\n\
    \    return a.first + (d1/(d1+d2)) * (a.second-a.first);\n}\n\n\n#line 4 \"test/CGL_1_C.test.cpp\"\
    \n\nint main(){\n    cout << fixed << setprecision(20);\n    int xp1, yp1, xp2,\
    \ yp2;\n    cin >> xp1 >> yp1 >> xp2 >> yp2;\n    Point p1(xp1, yp1);\n    Point\
    \ p2(xp2, yp2);\n    int q;\n    cin >> q;\n    rep(_, q){\n        int px, py;\n\
    \        cin >> px >> py;\n        Point p(px, py);\n        int res = ccw(p1,\
    \ p2, p);\n        if (res == +1)cout << \"COUNTER_CLOCKWISE\" << endl;\n    \
    \    if (res == -1)cout << \"CLOCKWISE\" << endl;\n        if (res == +2)cout\
    \ << \"ONLINE_BACK\" << endl;\n        if (res == -2)cout << \"ONLINE_FRONT\"\
    \ << endl;\n        if (res == +0)cout << \"ON_SEGMENT\" << endl;\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n#include \"../macro/macros.hpp\"\n#include \"../geometory/template.cpp\"\n\n\
    int main(){\n    cout << fixed << setprecision(20);\n    int xp1, yp1, xp2, yp2;\n\
    \    cin >> xp1 >> yp1 >> xp2 >> yp2;\n    Point p1(xp1, yp1);\n    Point p2(xp2,\
    \ yp2);\n    int q;\n    cin >> q;\n    rep(_, q){\n        int px, py;\n    \
    \    cin >> px >> py;\n        Point p(px, py);\n        int res = ccw(p1, p2,\
    \ p);\n        if (res == +1)cout << \"COUNTER_CLOCKWISE\" << endl;\n        if\
    \ (res == -1)cout << \"CLOCKWISE\" << endl;\n        if (res == +2)cout << \"\
    ONLINE_BACK\" << endl;\n        if (res == -2)cout << \"ONLINE_FRONT\" << endl;\n\
    \        if (res == +0)cout << \"ON_SEGMENT\" << endl;\n    }\n}"
  dependsOn:
  - macro/macros.hpp
  - geometory/template.cpp
  - macro/macros.hpp
  isVerificationFile: true
  path: test/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 16:04:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/CGL_1_C.test.cpp
- /verify/test/CGL_1_C.test.cpp.html
title: test/CGL_1_C.test.cpp
---
