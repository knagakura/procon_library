---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: 最大公約数(Greatest Common Divisor)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 21:49:01+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/ALDS1_1_B.test.cpp.html">test/ALDS1_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
template<typename T,typename U>
T lcm(T a,T b){return a/gcd(a,b)*b;}
#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/gcd.hpp"


/*
@title 最大公約数(Greatest Common Divisor)
*/
template<typename T>
T gcd(T a,T b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
template<typename T,typename U>
T lcm(T a,T b){return a/gcd(a,b)*b;}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

