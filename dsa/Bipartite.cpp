

struct Bipartite 
{

    Bipartite( vvi graph)
    {
        n=graph.size() ;
        this->graph=graph;
        vis = vi (n) ;
        color = vi (n,-1);
      
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if( dfs( i, 0)==false ) isBipartite=0;
            }
        }
    }
  
    int n, isBipartite=1;
    vector<int> vis, color ;
    vvi graph;
        
        bool dfs( int nd, int col)
        {
            vis[nd]=1;
            color[nd]=col;
            for(auto x: graph[nd] )
            {
                if(!vis[x] && !dfs(x, 1-col ) )return false;
                else if( color[x]==col ) return false;
            }
            return true;
        }
};


