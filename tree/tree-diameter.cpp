/*
@title 木の直径/Diameter of a Tree (全方位木DP/Rerooting ver.)
@category tree
*/
#include "../macro/macros.hpp"
#include "template.cpp"

template<typename T>
class Diameter :  public Tree<T>{
  public:
    using Tree<T>::N;
    using Tree<T>::G;
    vector<T> d;
    vector<T> ans;
    T diameter;
    Diameter(int _N):Tree<T>::Tree(_N), d(_N,0), ans(_N){}
    //Calc distance and start Rerooting
    void build(int start = 0, int pre = -1, bool debug = false){
        dfs1(start, pre);
        dfs2(start, pre);
        if(debug){
            print(d);
            print(ans);
        }
        diameter = *max_element(ans.begin(), ans.end());
    }
    //calculate the distance from start
    void dfs1(int cur = 0, int pre = -1){
        d[cur] = 0;
        for(edge<T>& ne: G[cur]){
            if(ne.to == pre)continue;
            dfs1(ne.to, cur);
            d[cur] = max(d[cur],d[ne.to] + ne.cost);
        }
    }
    void dfs2(int cur = 0, int pre = -1, T d_par = 0){
        //rerooting
        vector<pair<T,int>> childs;
        childs.push_back({0, -1}); //番兵 次数が1だと壊れるので
        for(auto ne: G[cur]){
            if(ne.to == pre)childs.push_back({d_par + ne.cost, ne.to});
            else childs.push_back({d[ne.to] + ne.cost, ne.to});
        }
        sort(all(childs), greater<pair<T, int>>());
        //大きい二つ
        ans[cur] = childs[0].first + childs[1].first;
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
