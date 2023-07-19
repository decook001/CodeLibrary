// articulation point in undirected grapf


struct ArtPoint
{
    ArtPoint(int n, vector< vector<int> > adm )
    {
        this->n=n;
        this->adm=adm;
        visited=vector<int> (n+1,0) ;
        low=vector<int> (n+1,1e9) ;
        tim=vector<int> (n+1,0) ;
        timer=1;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i,0);
            }
        }
    }

    vector<int> getres(  )
    {
        return ans;
    }



private:

    vector< vector< int> > adm;
    vector<int> visited, low, tim;
    int timer, n;
    vector<int> ans;

    void dfs(int node, int parent)
    {
        //cout<<node<<"a\n";
        visited[node]=1;
        tim[node]=timer++;
        low[node]=tim[node];
        int child=0;
        for(int x: adm[node])
        {
            if(x==parent)continue;
            else if(visited[x])
            {
                low[node]=min(low[node],tim[x]);
            }
            else
            {
                child++;
                dfs(x,node);
                low[node]= min(low[node], low[x]);
                if(low[x]>=tim[node] && parent)
                {
                    ans.push_back(node);
                }

            }
        }

        if(parent<0 && child>1)
        {
            ans.push_back(node);
        }
    }

};


