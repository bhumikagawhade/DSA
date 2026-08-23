class Solution {
public:
    bool dfs(int row,int col ,int r,int c,int pr,int pc,char val,vector<vector<char>>&grid,vector<vector<int>>& vis){

        vis[r][c] = true;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            if(nr>=0 && nr<row && nc>=0 && nc<col && grid[nr][nc] == val){
                if(nr == pr && nc == pc){
                    continue;
                }

                if(vis[nr][nc]){
                    return true;
                }

                if(dfs(row,col,nr,nc,r,c,val,grid,vis)){
                    return true;
                }
            }
        }

        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(!vis[r][c]){
                    if(dfs(n,m,r,c,-1,-1,grid[r][c],grid,vis)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};