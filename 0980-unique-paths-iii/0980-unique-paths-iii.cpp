class Solution {
public:
    int solve(int sRow,int sCol,int eRow,int eCol,vector<vector<int>>&grid,vector<vector<bool>>&visit)
    {
        int n=grid.size();
        int m=grid[0].size();

        if(sRow==eRow && sCol==eCol) 
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if (grid[i][j] == 0 && !visit[i][j]) return 0;
                }
            }

            return 1;
        }

        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};

        int path=0;
        for(int i=0;i<4;i++)
        {
            int adjRow=sRow+drow[i];
            int adjCol=sCol+dcol[i];

            if(adjRow>=0 && adjCol>=0 && adjRow<n && adjCol<m && !visit[adjRow][adjCol] && grid[adjRow][adjCol]!=-1)
            {
                visit[adjRow][adjCol]=true;
                path+=solve(adjRow,adjCol,eRow,eCol,grid,visit);
                visit[adjRow][adjCol]=false;
            }
        }

        return path;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int sr,sc,er,ec;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                }

                if(grid[i][j]==2)
                {
                    er=i;
                    ec=j;
                }
            }
        }

        vector<vector<bool>>visit(n,vector<bool>(m,false));
        visit[sr][sc]=true;
        return solve(sr,sc,er,ec,grid,visit);

        
    }
};