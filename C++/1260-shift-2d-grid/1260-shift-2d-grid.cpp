class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(!k) return grid;
        int n=grid.size();
        int m=grid[0].size();
        int total=n*m;

        k%=total;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int oldIndex = i*m+j;
                int newIndex = (oldIndex+k)%total;

                int row=newIndex/m;
                int col=newIndex%m;
                ans[row][col]=grid[i][j];
            }
        }
        
        return ans;
    }
};