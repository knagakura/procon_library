#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"
#include "../math/sieve_of_eratosthenes.cpp"

int main(){
    vector<bool> is_prime = sieve(100100100);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int x;
        cin >> x;
        ans += is_prime[x];
    }
    cout << ans << endl;
}