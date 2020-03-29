#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
/*
@title 玉区別する、箱区別する、制限なし($k^{n}$)
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    cout << mint(k).modpow(n) << endl;
}