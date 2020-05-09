#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#include "../macro/macros.hpp"
#include "../geometory/template.cpp"

int main(){
    cout << fixed << setprecision(20);
    int xp1,yp1,xp2,yp2;
    cin >> xp1 >> yp1 >> xp2 >> yp2;
    Point p1(xp1,yp1);
    Point p2(xp2,yp2);
    Segment l = make_pair(p1, p2);
    int q;
    cin >> q;
    rep(_,q){
        int px, py;
        cin >> px >> py;
        Point p(px, py);
        Point ans = projection(l, p);
        cout << ans.real() << " " << ans.imag() << endl;
    }
}