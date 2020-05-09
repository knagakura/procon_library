#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include "../macro/macros.hpp"
#include "../geometory/template.cpp"

int main(){
    cout << fixed << setprecision(20);
    int xp1, yp1, xp2, yp2;
    cin >> xp1 >> yp1 >> xp2 >> yp2;
    Point p1(xp1, yp1);
    Point p2(xp2, yp2);
    int q;
    cin >> q;
    rep(_, q){
        int px, py;
        cin >> px >> py;
        Point p(px, py);
        int res = ccw(p1, p2, p);
        if (res == +1)cout << "COUNTER_CLOCKWISE" << endl;
        if (res == -1)cout << "CLOCKWISE" << endl;
        if (res == +2)cout << "ONLINE_BACK" << endl;
        if (res == -2)cout << "ONLINE_FRONT" << endl;
        if (res == +0)cout << "ON_SEGMENT" << endl;
    }
}