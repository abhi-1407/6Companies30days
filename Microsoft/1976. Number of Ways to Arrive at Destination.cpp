class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=pow(10,9)+7;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int destination=n-1;
        vector<pair<int,int>> adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> distance(n,1e9);
        vector<int> ways(n,0);
        pq.push({0,0});
        ways[0]=1;
        distance[0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int weight=it.first;
            int node=it.second;
            for(auto i:adj[node])
            {
                int adjnode=i.first;
                int adjw=i.second;
                if(distance[adjnode] > weight + adjw) 
                {
                        distance[adjnode]=weight+adjw;
                        pq.push({weight+adjw,adjnode});
                        ways[adjnode]=ways[node];
                }                
                else if(distance[adjnode] == weight + adjw)
                {
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};