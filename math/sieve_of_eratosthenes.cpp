#ifndef SIEVE_OF_ERATOSTHENES_CPP
#define SIEVE_OF_ERATOSTHENES_CPP
#include "../macro/macros.hpp"

/*
@title エラトステネスの篩(Sieve of Eratosthenes)
@category math
@brief 計算量$O($NloglogN$)$

*/
template<typename T>
vector<bool> sieve(T x){
    vector<bool> is_prime(x + 1, true);
    if(x >= 0)is_prime[0] = false;
    if(x >= 1)is_prime[1] = false;
    for(T i = 2; i * i <= x;i++){
        if(!is_prime[i])continue;
        for(T j = i + i; j <= x;j+=i){
            is_prime[j] = false;
        }
    }
    return is_prime;
}
#endif