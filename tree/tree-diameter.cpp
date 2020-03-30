/*
@title 木の直径/Diameter of a Tree (全方位木DP/Rerooting ver.)
@category tree
@docs ../docs/tree/tree-diameter.md
*/
#include "../macro/macros.hpp"
#include "template.cpp"

template<typename T>
class Diameter :  public Tree<T>{
  public:
    using Tree<T>::N;
    using Tree<T>::G;
    vector<T> dp;
    vector<T> dp2;
    T diameter;
    Diameter(int _N):Tree<T>::Tree(_N), dp(_N,0), dp2(_N){}
    //Calc distance and start Rerooting
    void build(int start = 0, int pre = -1, bool debug = false){
        dfs1(start, pre);
        dfs2(start, pre);
        if(debug){
            print(dp);
            print(dp2);
        }
        diameter = *max_element(dp2.begin(), dp2.end());
    }
    //calculate the distance from start
    void dfs1(int cur = 0, int pre = -1){
        dp[cur] = 0;
        for(edge<T>& ne: G[cur]){
            if(ne.to == pre)continue;
            dfs1(ne.to, cur);
            dp[cur] = max(dp[cur],dp[ne.to] + ne.cost);
        }
    }
    void dfs2(int cur = 0, int pre = -1, T d_par = 0){
        //rerooting
        vector<pair<T,int>> childs;
        childs.push_back({0, -1}); //番兵 次数が1だと壊れるので
        for(auto ne: G[cur]){
            if(ne.to == pre)
                childs.push_back({d_par + ne.cost, ne.to});
            else 
                childs.push_back({dp[ne.to] + ne.cost, ne.to});
        }
        //大きい二つ
        sort(all(childs), greater<pair<T, int>>());
        dp2[cur] = childs[0].first + childs[1].first;
        for(auto ne: G[cur]){
            if(ne.to == pre)continue;
            //降りる辺が最大値
            if(childs[0].second == ne.to)
                dfs2(ne.to, cur, childs[1].first);
            else 
                dfs2(ne.to, cur, childs[0].first);
        }
    }
    T get_diameter(){
        return diameter;
    }
};
