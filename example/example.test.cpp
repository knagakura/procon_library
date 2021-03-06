#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"
#include "../macro/macros.hpp"
/*
@title example(二分探索)
@category example
@brief test用。
*/
int main() {
    int n; cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n;++i){
        cin >> s[i];
    }
    int q; cin >> q;
    int cnt = 0;
    while (q --) {
        int t_i; cin >> t_i;
        cnt += binary_search(s.begin(), s.end(), t_i);
    }
    cout << cnt << endl;
    return 0;
}