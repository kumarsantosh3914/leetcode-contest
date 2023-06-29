int shortestPathAllKeys(vector<string>& grid) {
    int m=grid.size(), n = m ? grid[0].size() : 0;
    if(!m || !n) return 0;
    int path=0, K=0;
    vector<int> dirs={0,-1,0,1,0};
    //at most 6 keys, using bitmap 111111
    vector<vector<vector<bool>>> visited(m,vector<vector<bool>>(n,vector<bool>(64,0))); 
    queue<pair<int,int>> q; //<postion, hold keys mapping>
    
    // Find the starting position and count the total number of keys
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                q.push({i * n + j, 0});
                visited[i][j][0]=1;                    
            }
            if(grid[i][j]>='A' && grid[i][j]<='F') K++; //total alpha number
        }
    }
    
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int a=q.front().first/n, b=q.front().first%n;
            int carry=q.front().second;
            q.pop();        
            
            // Check if all the keys are held, if so, return the path
            if(carry==((1<<K)-1)) return path;
            
            // Explore the four adjacent directions
            for(int j=0;j<4;j++){
                int x=a+dirs[j], y=b+dirs[j+1], k=carry;
                if(x<0 || x>=m || y<0 || y>=n || grid[x][y]=='#') continue;
                
                // Update the keys held if a new key is encountered
                if(grid[x][y]>='a' && grid[x][y]<='f'){
                    k=carry|(1<<(grid[x][y]-'a')); //update hold keys
                }
                // Skip if a door is encountered and the key to open it is not held
                else if(grid[x][y]>='A' && grid[x][y]<='F'){
                    if(!(carry & (1<<(grid[x][y]-'A')))) continue;
                }
                
                // If the cell has not been visited with the current keys held, 
                // mark it visited and add it to the queue
                if(!visited[x][y][k]){
                    visited[x][y][k]=1;
                    q.push({x*n+y,k});
                }                
            }
        }
        path++;
    }
    // If there is no path to collect all the keys, return -1
    return -1;
}