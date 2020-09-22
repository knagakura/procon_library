#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../macro/macros.hpp"
#include "../math/extended-euclid-algorithm.cpp"

int main(){
    ll a, b;
    cin >> a >> b;
    ll x, y;
    extGCD(a, b, x, y);
    cout << x << " " << y << endl;
}



