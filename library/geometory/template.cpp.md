---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Geometory/template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#952c4b3955adb7d8aa8e139cd4391db8">Geometory</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometory/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 18:58:19+09:00




## Depends on

* :heavy_check_mark: <a href="../macro/macros.hpp.html">Macro</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/CGL_1_A.test.cpp.html">test/CGL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/CGL_1_B.test.cpp.html">test/CGL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/CGL_1_C.test.cpp.html">test/CGL_1_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef GEOMETORY_TEMPLATE_CPP
#define GEOMETORY_TEMPLATE_CPP
#include "../macro/macros.hpp"
#include <complex>
/*
@title Geometory/template.cpp
@category Geometory
*/

typedef complex<double> Point;
typedef pair<Point, Point> Segment;
#define EPS (1e-10)
#define EQ(a, b) (abs((a) - (b)) < EPS)
Point operator*(const Point &p, const double &d) {
  return Point(real(p) * d, imag(p) * d);
}
// 内積
double dot(Point a, Point b){
    return (a.real() * b.real() + a.imag() * b.imag());
}
//外積
double cross(const Point &a, const Point &b){
    return (a.real() * b.imag() - a.imag() * b.real());
}

/*
"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_1_A"
直線 l に p から引いた交点を求める
*/
Point projection(const Segment &l, const Point &p){
    double t = dot(p - l.first, l.second - l.first) / norm(l.second - l.first);
    return l.first + t * (l.second - l.first);
}
/*
直線 l に関して線対称な点を求める
*/
Point reflection(const Segment &l, const Point &p){
    return p + (projection(l,p)-p)*2.0;
}
/*
https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
crockwise
*/
int ccw(const Point &a, const Point &b, const Point &c){
    Point x = b - a;
    Point y = c - a;
    if(cross(x,y) > EPS)return 1;   //時計回り
    if(cross(x,y) < -EPS)return -1; //反時計回り
    if(dot(x,y) < -EPS)return +2;   //後ろ
    if(norm(x) < norm(y))return -2; //前
    return 0;                       //中
}
bool is_intersected_ls(Point a1, Point a2, Point b1, Point b2){
    return (cross(a2-a1, b1-a1)*cross(a2-a1, b2-b1) < EPS) && (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS);
}
#endif


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "geometory/template.cpp"


#line 1 "macro/macros.hpp"



/*
@title Macro
@category template
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;

const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";


#line 5 "geometory/template.cpp"
/*
@title Geometory/template.cpp
@category Geometory
*/

typedef complex<double> Point;
typedef pair<Point, Point> Segment;
#define EPS (1e-10)
#define EQ(a, b) (abs((a) - (b)) < EPS)
Point operator*(const Point &p, const double &d) {
  return Point(real(p) * d, imag(p) * d);
}
// 内積
double dot(Point a, Point b){
    return (a.real() * b.real() + a.imag() * b.imag());
}
//外積
double cross(const Point &a, const Point &b){
    return (a.real() * b.imag() - a.imag() * b.real());
}

/*
"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_1_A"
直線 l に p から引いた交点を求める
*/
Point projection(const Segment &l, const Point &p){
    double t = dot(p - l.first, l.second - l.first) / norm(l.second - l.first);
    return l.first + t * (l.second - l.first);
}
/*
直線 l に関して線対称な点を求める
*/
Point reflection(const Segment &l, const Point &p){
    return p + (projection(l,p)-p)*2.0;
}
/*
https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
crockwise
*/
int ccw(const Point &a, const Point &b, const Point &c){
    Point x = b - a;
    Point y = c - a;
    if(cross(x,y) > EPS)return 1;   //時計回り
    if(cross(x,y) < -EPS)return -1; //反時計回り
    if(dot(x,y) < -EPS)return +2;   //後ろ
    if(norm(x) < norm(y))return -2; //前
    return 0;                       //中
}
bool is_intersected_ls(Point a1, Point a2, Point b1, Point b2){
    return (cross(a2-a1, b1-a1)*cross(a2-a1, b2-b1) < EPS) && (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS);
}



```
{% endraw %}

<a href="../../index.html">Back to top page</a>

