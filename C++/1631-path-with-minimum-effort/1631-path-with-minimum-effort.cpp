class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        //pq={diff,{row,col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>dist (n,vector<int>(m,1e9));

        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==m-1) return diff;

            for(int i=0;i<4;i++){
                int nrow=dr[i]+r;
                int ncol=dc[i]+c;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort=max(abs(heights[nrow][ncol]-heights[r][c]),diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};