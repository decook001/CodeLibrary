// strongly connected component directed graph


struct Scc
{
    Scc( vector< vector< int> > adj, int n )
    {
        adm=adj;
        this->n=n;
        visited=vector<int> (n+1);
        radm=vector<vector<int> > (n+1);
        cal();
    }

    vector< vector<int> > ans;
private:
    vector< vector<int> > adm,radm;
    vector<int> sorted;
    vector<int> visited;
    int n;

    void cal()
    {
        for(int i=0; i<=n; i++)
            for(auto x: adm[i])
                radm[x].push_back(i);

        for(int i=0; i<=n; i++)
            if(!visited[i]) dfs1(i);

        visited=vector<int> (n+1);
        reverse(sorted.begin(), sorted.end());

        for(auto node: sorted)
        {
            if(!visited[node])
            {
                vector<int> car;
                dfs2(node, car);
                ans.push_back(car);
            }
        }
    }

    void dfs1(int node)
    {
        visited[node]=1;
        for(auto x: adm[node])
            if(!visited[x]) dfs1(x);
        
        sorted.push_back(node);
    }

    void dfs2(int node, vector<int>& car)
    {
        car.push_back(node);
        visited[node]=1;
        for(auto x: radm[node])
            if(!visited[x]) dfs2(x,car);
         
    }
};

