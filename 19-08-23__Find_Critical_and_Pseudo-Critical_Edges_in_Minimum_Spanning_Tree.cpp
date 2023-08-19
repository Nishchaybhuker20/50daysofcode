class UnionFind {    
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        for (int i = 0; i <n; i++) 
            root[i] = i;
    }

    int Find(int x) {
        if (x == root[x]) return x;
        else return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)  return;
        if (rank[rX] > rank[rY]) swap(rX, rY);   
        root[rX] = rY;
        if (rank[rX]==rank[rY]) rank[rY]++;
    }

    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }

};
class Solution {
public:
    int e;
    int Kruskal(int n, vector<vector<int>>& edges, int removal=-1, int inclusive=-1)   
    {
        UnionFind uf(n);
        int dist=0;
        if (inclusive!=-1){
            auto& edge=edges[inclusive];
            int d=edge[0], v=edge[2], w=edge[3];
            uf.Union(v, w);
            dist+=d;
        }
        for(int i=0; i<e; i++){
            auto& edge=edges[i];
            int d=edge[0], v=edge[2], w=edge[3];
            if (i==removal || i==inclusive) continue;
            if (uf.Find(v) == uf.Find(w)) continue;
            uf.Union(v, w);
            dist+=d;
        }
        for(int i=1; i<n; i++)
            if (!uf.connected(0, i)) return INT_MAX;//disconnected
        return dist;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        e=edges.size();
        for(int i=0; i<e; i++){
            vector<int>& edge=edges[i];
            vector<int> e2={edge[2], i, edge[0], edge[1]};
            edge=e2;
        }
        sort(edges.begin(), edges.end());

        int minWeight= Kruskal(n, edges);
        cout<<minWeight<<endl;
   
        vector<int> critical, pseudo_crt;
        
        for(int j=0; j<e; j++){ 
            int i=edges[j][1];
            int no_j=Kruskal(n, edges, j), w_j=Kruskal(n, edges, -1, j);
            if(minWeight<no_j)
                critical.push_back(i);
            else if (minWeight==w_j)
                pseudo_crt.push_back(i);
        }
        return {critical, pseudo_crt};
    }
};