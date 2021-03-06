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
/*
https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
二つの線分の交差判定
*/
bool isinterSS(const Segment &a, const Segment &b){
    double ok[2];
    ok[0] = ccw(a.first, a.second, b.first)*ccw(a.first, a.second, b.second);
    ok[1] = ccw(b.first, b.second, a.first)*ccw(b.first, b.second, a.second);
    return ok[0] <= 0 && ok[1] <= 0;
}
/*
https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
二つの線分の交点
*/
Point cross_point(const Segment &a, const Segment &b){
    double d1 = abs(cross(b.second-b.first, a.first-b.first));
    double d2 = abs(cross(b.second-b.first, a.second-b.first));
    return a.first + (d1/(d1+d2)) * (a.second-a.first);
}
#endif

