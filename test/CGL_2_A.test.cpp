#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"
#include "../macro/macros.hpp"
#include "../geometory/template.cpp"

int main(){
    int q;
    cin >> q;
    while(q--){
        int x[4],y[4];
        rep(i,4)cin >> x[i] >> y[i];
        Point p1(x[1]-x[0], y[1]-y[0]);
        Point p2(x[3]-x[2], y[3]-y[2]);
        if(dot(p1,p2)==0)cout<<1<<endl;
        else if(cross(p1,p2)==0)cout<<2<<endl;
        else cout << 0 << endl;
    }
}