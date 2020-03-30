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


# :heavy_check_mark: test/ALDS1_3_A.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ALDS1_3_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-29 17:06:20+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data_structure/stack.hpp.html">stack</a>
* :question: <a href="../../library/macro/macros.hpp.html">macro/macros.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp"
#include "../macro/macros.hpp"
#include "../data_structure/stack.hpp"

int main(){
    Stack<int> S(1000);
    string c;
    while(cin >> c){
        if(c == "+"){
            int a = S.pop();
            int b = S.pop();
            S.push(b + a);
        }
        else if(c == "-"){
            int a = S.pop();
            int b = S.pop();
            S.push(b - a);
        }
        else if(c == "*"){
            int a = S.pop();
            int b = S.pop();
            S.push(b * a);
        }
        else{
            int x = stoi(c);
            S.push(x);
        }
    }
    cout << S.pop() << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/ALDS1_3_A.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp"
#line 1 "macro/macros.hpp"



#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;

const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";


#line 1 "data_structure/stack.hpp"


#line 4 "data_structure/stack.hpp"
/*
@title stack
*/
template< typename T >
class Stack{
  public:
    int N;
    int top = 0;
    T data[20000];
    Stack(int sz):N(sz), top(0){}
    void push(int x){
        if(isFull()){
            cerr << "これ以上入りません" << endl;
            return;
        }
        data[top] = x;
        top++;
    }
    int pop(){
        if(isEmpty()){
            cerr << "中身は空です" << endl;
            return -1;
        }
        top--;
        return data[top];
    }
    bool isFull(){
        return top >= N;
    }
    bool isEmpty(){
        return top == 0;
    }
    void show(){
        dump(top);
        for(int i = 0; i < top;i++){
            cerr << data[i] << " ";
        }
        cerr << endl;
    }
};

#line 4 "test/ALDS1_3_A.test.cpp"

int main(){
    Stack<int> S(1000);
    string c;
    while(cin >> c){
        if(c == "+"){
            int a = S.pop();
            int b = S.pop();
            S.push(b + a);
        }
        else if(c == "-"){
            int a = S.pop();
            int b = S.pop();
            S.push(b - a);
        }
        else if(c == "*"){
            int a = S.pop();
            int b = S.pop();
            S.push(b * a);
        }
        else{
            int x = stoi(c);
            S.push(x);
        }
    }
    cout << S.pop() << endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

