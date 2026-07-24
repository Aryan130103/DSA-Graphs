class disjointset{
    public:
    vector<int> size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i]=i;
    }

    int ult_p(int n){
        if(n==parent[n]) return n;
        return parent[n]=ult_p(parent[n]);
    }

    void unionbysize(int u,int v){
        int UP=ult_p(u);
        int VP=ult_p(v);
        if(UP==VP) return;
        
        if(size[UP]<size[VP]){
            parent[UP]=parent[VP];
            size[VP]+=size[UP];
        }
        else{
            parent[VP]=parent[UP];
            size[UP]+=size[VP];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0,maxcol=0;
        for(auto& it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjointset ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenodes;
        for(auto& it:stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionbysize(noderow,nodecol);
            stonenodes[noderow]=1;
            stonenodes[nodecol]=1;
        }
       
        int NC=0;
        for(auto& it:stonenodes){
            if(ds.ult_p(it.first)==it.first) NC++;
        }

        return n-NC;
    }
};