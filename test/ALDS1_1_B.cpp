#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_B"

#include "../macro/macros.hpp"
#include "../math/gcd.hpp"

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}