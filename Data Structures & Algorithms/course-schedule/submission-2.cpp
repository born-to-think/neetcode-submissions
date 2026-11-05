class Solution {
public:

    bool dfs(int curr, vector<vector<int>>&graph, vector<int>&visited){
        if(visited[curr] == 2 )return true;
        if(visited[curr] == 1)return false;

        visited[curr]=1;


        for(int pre:graph[curr]){
            if(!dfs(pre,graph,visited))return false;
        }
        visited[curr]=2;
            return true;
        
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visited (numCourses,0);

        for(vector<int>& edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        for(int course = 0;course<numCourses;course++){
            if( ! dfs(course,graph,visited) )return false;
        }
        return true;
    }
};
