#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"
#include "../math/stiring-number-second-dp.cpp"

/*
@title 玉区別する、箱区別しない、1個以上(第二種スターリング数(DP))
@category 写像12相
*/
int main(){
    int n, k;
    cin >> n >> k;
    Stiring_dp<mint> Sl(n);
    cout << Sl.get(n, k) <<endl;
}