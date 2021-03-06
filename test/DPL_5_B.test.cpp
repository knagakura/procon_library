#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"

/*
@title 玉区別する、箱区別する、1個以内(${}_k P _n$)
@category 写像12相
*/

combination C(200100);
int main(){
    int n, k;
    cin >> n >> k;
    cout << C.Perm(k, n) << endl;
}
