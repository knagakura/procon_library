#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D"

#include "../data_structure/inversion-num.cpp"

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    cout << Inversion_num(A) << endl;
}