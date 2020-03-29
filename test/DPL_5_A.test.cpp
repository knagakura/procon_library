#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"

int main(){
    int n, x;
    cin >> n >> x;
    cout << mint(x).modpow(n) << endl;
}