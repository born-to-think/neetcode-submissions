class Solution {
public:

    bool dfs(int curr, vector<vector<int>>&graph, vector<bool>&visited){
        if(visited[curr] )return true;
        
        visited[curr]=true;
        bool flag = false;
        for(int pre:graph[curr]) flag|= dfs(pre,graph,visited);
        return flag;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> visited (numCourses);

        for(vector<int>& edge:prerequisites){
            graph[edge[0]].push_back(edge[1]);
        }

        for(int course = 0;course<numCourses;course++){
            if(visited[course])continue;
            if(  dfs(course,graph,visited) )return false;
        }
        return true;
    }
};
