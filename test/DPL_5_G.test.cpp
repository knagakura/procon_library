#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_G"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"
#include "../math/bell-number.cpp"
/*
@title 玉区別する、箱区別しない、制限なし(ベル数($O(\min(N,K)log N$))
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    cout << bell_number(n, k) << endl;
}
