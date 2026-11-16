class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 1. Sort in descending order so the smallest string is at the end
        sort(tickets.rbegin(), tickets.rend());

        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res;
        dfs("JFK", res, adj);
        
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(const string& src, vector<string>& res,
             unordered_map<string, vector<string>>& adj) {
        
        // 2. Check if the vector is not empty
        while (!adj[src].empty()) {
            // 3. Access the smallest string from the back
            string next = adj[src].back();
            // 4. Remove in O(1) time
            adj[src].pop_back();
            
            dfs(next, res, adj);
        }
        res.push_back(src);
    }
};