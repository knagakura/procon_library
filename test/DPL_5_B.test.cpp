#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B"
#include "../macro/macros.hpp"
#include "../math/mint.hpp"
#include "../math/comb.hpp"

combination C(200100);
int main(){
    int n, k;
    cin >> n >> k;
    cout << C.Perm(k, n) << endl;
}
