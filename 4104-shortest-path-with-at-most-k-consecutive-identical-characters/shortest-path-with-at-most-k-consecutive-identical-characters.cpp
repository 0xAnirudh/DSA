class Solution {
public:
#define ll long long
    int shortestPath(int n, vector<vector<int>>& edges, string s, int k) {
        vector<vector<pair<ll,ll>>>p(n+1);
        for(auto it:edges){
            p[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
        vector<vector<ll>>dis(n+1,vector<ll>(k+1,1e15));
        dis[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto it=pq.top();
            ll x=it.first;
            ll y=it.second.first;
            ll z=it.second.second;
            pq.pop();
            if(dis[y][z]<x)continue;
            for(auto child:p[y]){
                ll nex=z;
                if(s[child.first]==s[y])nex++;
                else nex=1;
                if(nex>k)continue;
                if(child.second+x<dis[child.first][nex]){
                    dis[child.first][nex]=child.second+x;
                    pq.push({dis[child.first][nex],{child.first,nex}});
                }
            }
        }
        ll mini=1e15;
        for(auto it:dis[n-1]){
            mini=min(mini,it);
        }
        if(mini>=1e15)return -1;
        return mini;
    }
};