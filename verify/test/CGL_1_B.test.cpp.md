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


# :heavy_check_mark: test/CGL_1_B.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/CGL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-09 18:58:19+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/geometory/template.cpp.html">Geometory/template.cpp</a>
* :heavy_check_mark: <a href="../../library/macro/macros.hpp.html">Macro</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
#include "../macro/macros.hpp"
#include "../geometory/template.cpp"

#define ERROR "1e-8"
int main(){
    cout << fixed << setprecision(20);
    int xp1, yp1, xp2, yp2;
    cin >> xp1 >> yp1 >> xp2 >> yp2;
    Point p1(xp1, yp1);
    Point p2(xp2, yp2);
    Segment l = make_pair(p1, p2);
    int q;
    cin >> q;
    rep(_, q){
        int px, py;
        cin >> px >> py;
        Point p(px, py);
        Point ans = reflection(l, p);
        cout << ans.real() << " " << ans.imag() << endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/CGL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B"
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


#line 1 "geometory/template.cpp"


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


#line 4 "test/CGL_1_B.test.cpp"

#define ERROR "1e-8"
int main(){
    cout << fixed << setprecision(20);
    int xp1, yp1, xp2, yp2;
    cin >> xp1 >> yp1 >> xp2 >> yp2;
    Point p1(xp1, yp1);
    Point p2(xp2, yp2);
    Segment l = make_pair(p1, p2);
    int q;
    cin >> q;
    rep(_, q){
        int px, py;
        cin >> px >> py;
        Point p(px, py);
        Point ans = reflection(l, p);
        cout << ans.real() << " " << ans.imag() << endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

