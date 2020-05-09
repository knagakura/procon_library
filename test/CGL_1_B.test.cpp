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