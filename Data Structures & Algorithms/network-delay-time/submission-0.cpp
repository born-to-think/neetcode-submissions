class Solution {
public:
    int INF = 1e9+7;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(const auto& t:times){
            graph[t[0]].emplace_back(t[1],t[2]);
        }

        vector<int> distance(n+1,INF);
        distance[k]=0;

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>  > heap;
        heap.push({0,k});
        while(!heap.empty()){
            auto [cd, cn] = heap.top();heap.pop();
            if(cd > distance[cn])continue;  /////this step ensures we dont double evaluate from same node with some higher cd value [ happens when a higher value was already added in heap and then some lower cd value wins the race but prev higher cd value was never erased ]
            
            for(const auto[adj,wt] : graph[cn]){
                int newDis = cd + wt;
                if(newDis < distance[adj]){
                    distance[adj] = newDis;
                    heap.push({newDis,adj});
                }
            }

        } 

        int res = 0;
        for(int i=1;i<=n;i++){
            res = max(res, distance[i]);
        }
        if(res==INF)return -1;
        return res;



    }
};