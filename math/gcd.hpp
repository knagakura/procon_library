#ifndef GCD_HPP
#define GCD_HPP
/*
@title 最大公約数(Greatest Common Divisor)
*/
template<typename T>
T gcd(T a,T b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
template<typename T>
T lcm(T a,T b){return a/gcd(a,b)*b;}
#endif