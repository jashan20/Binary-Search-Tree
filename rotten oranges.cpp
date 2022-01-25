bool isvalid(vector<vector<int>>& grid, int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j]==0)
            return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh = 0,min = 0;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0)
            return 0;
        
        while(!q.empty())
        {
            int s = q.size();
            if(fresh == 0)
                return min;
            while(s--)
            {
                auto p = q.front();
                q.pop();
                int i = p.first;
                int j = p.second;
                
                
                if(isvalid(grid,i+1,j) && grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                    fresh--;
                }
                if(isvalid(grid,i,j+1) && grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                    fresh--;
                }
                if(isvalid(grid,i-1,j) && grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    q.push({i-1,j});
                    fresh--;
                }
                if(isvalid(grid,i,j-1) && grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                    fresh--;
                }
            }
            min++;
        }
        if(fresh != 0)
            return -1;
        return min;
