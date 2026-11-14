class Solution {
public:
    struct DSU{
        vector<int> parent,size;
        DSU(int n) :parent(n),size(n,1){
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int v){
            if(parent[v]==v)return v;
            return parent[v] = find(parent[v]);
        }

        bool unite(int a, int b){
            a = find(a);
            b = find(b);
            if(a==b)return false;
            if(size[a]<size[b])swap(a,b);
            size[a]=+size[b];
            parent[b]=a;
            return true;
        }

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for(const auto& e:edges){
            int i=e[0], j=e[1];
            if(!dsu.unite(i,j)){
                return e;
            }
        }
    }
};
