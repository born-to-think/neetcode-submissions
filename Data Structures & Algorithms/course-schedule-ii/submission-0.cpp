

class Solution {
public:

    bool dfs(int curr, vector<vector<int>>&graph, vector<int>&visited,vector<int>& res){
        if(visited[curr] == 2 )return true;
        if(visited[curr] == 1)return false;

        visited[curr]=1;


        for(int pre:graph[curr]){
            if(!dfs(pre,graph,visited,res))return false;
        }
        visited[curr]=2;
        res.push_back(curr);
            return true;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(!prerequisites.size())return {};
        
        vector<vector<int>> graph(numCourses);
        for(vector<int>& edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> visited (numCourses,0);
        vector<int> res;
        for(int course = 0;course<numCourses;course++){
            if( ! dfs(course,graph,visited,res) )return {};
        }
        return res;
    }
};
