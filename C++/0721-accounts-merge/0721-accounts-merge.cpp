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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointset ds(n);
        map<string,int> mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())
                    mapMailNode[mail]=i;
                else
                    ds.unionbysize(i,mapMailNode[mail]);
            }
        }

        vector<string> MergeMail[n];
        for(auto it:mapMailNode){
            int node=ds.ult_p(it.second);
            string mail=it.first;
            MergeMail[node].push_back(mail);
        }  

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(MergeMail[i].size()==0) continue;
            sort(MergeMail[i].begin(),MergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:MergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }   
        return ans;
    }
};