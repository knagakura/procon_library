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

Point reflection(const Segment &l, const Point &p){
    return p + (projection(l,p)-p)*2.0;
}

bool is_intersected_ls(Point a1, Point a2, Point b1, Point b2){
    return (cross(a2-a1, b1-a1)*cross(a2-a1, b2-b1) < EPS) && (cross(b2-b1, a1-b1)*cross(b2-b1, a2-b1) < EPS);
}
#endif

