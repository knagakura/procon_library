#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C"
#include "../macro/macros.hpp"
#include "../geometory/template.cpp"
#define ERROR "1e-8"
int main(){
    int q;
    cin >> q;
    while(q--){
        vector<Point> ps;
        rep(i,4){
            int x, y;
            cin >> x >> y;
            ps.emplace_back(x,y);
        }
        Segment s[] = {make_pair(ps[0], ps[1]), make_pair(ps[2], ps[3])};
        Point ans = cross_point(s[0],s[1]);
        cout << setprecision(20) << ans.real() << " " << ans.imag() << endl;
    }
}