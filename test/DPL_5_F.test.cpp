#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"
/*
@title 玉区別しない、箱区別する、1個以上(${}_{n-k} H _k$)
@category 写像12相
*/

combination C(200100);
int main(){
    int n, k;
    cin >> n >> k;
    cout << C.H(n-k, k) << endl;
}
