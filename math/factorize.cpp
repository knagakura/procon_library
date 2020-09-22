#ifndef FACTORIZE_CPP
#define FACTORIZE_CPP
#include "../macro/macros.hpp"

/*
@title 素因数分解関係
@category math
@brief 

*/

struct Prime{
    int MAXN;
    vector<int> primes;
    vector<int> spf;
    Prime(int MAXN_): MAXN(MAXN_), spf(MAXN_+1){
        spf_init();
    }
    static map<int, int> factorize(int x){
        map<int,int> mp;
        for (int i = 2; i*i <= x; i++){
            while (x%i == 0) {
                x /= i;
                mp[i]++;
            }
            if (x == 1) break;
        }
        if (x != 1) mp[x]++;
        return mp;
    }
    static bool isprime(int v) {
        if (v <= 1) return false;
        if (v == 2) return true;
        for (int i = 2; 1LL * i*i <= v; i++) if (v%i == 0) return false;
        return true;
    }

    // smallest prime factor
    void spf_init(){
        for (int i = 0; i <= MAXN; i++) spf[i] = i;
        for (int i = 2; i * i <= MAXN; i++) {
            // 素数だったら
            if (spf[i] == i) {
                primes.emplace_back(i);
                for (int j = i * i; j <= n; j += i) {
                    // iを持つ整数かつまだ素数が決まっていないなら
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    // x <= MAXN
    map<int, int> fast_factorize(int x){
        map<int, int> mp;
        while(x != 1){
            mp[spf[x]]++;
            x /= spf[x];
        }
        return mp;
    }
};

#endif