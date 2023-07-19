// undirected graph

struct ArtBridge
{

    ArtBridge( int n, vector< vector<int> > adj )
    {
        this->adj=adj;
        visited = vector<int> (n+1) ;
        tim = vector<int> (n+1) ;
        low = vector<int> (n+1,inf );
        timer=1;

        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i,0);
            }
        }
    }

    vector<pii> getres()
    {
        return ans;
    }

private:
    vector< vector< int > > adj;
    vector< int > visited, tim, low;
    int timer=1, inf=1e9;
    vector< pii > ans;
    void dfs(int node, int parent)
    {
        visited[node]=1;
        tim[node]=timer++;
        low[node]=tim[node];
        for(int x: adj[node])
        {
            if(x==parent)continue;
            else if(visited[x])
            {
                low[node]=min(low[node], tim[x]);
            }
            else
            {
                dfs(x, node);
                low[node]=min(low[node], low[x]);
                if(low[x]>tim[node])
                {
                    ans.push_back({node, x});
                }
            }
        }
    }
};


