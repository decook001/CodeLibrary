

// single source shortest path
// works on positive weight, not negative weight
// undirected graph
// O(VlogV)

struct Edge
{
    int src=0, des=0, wet=0;
    edge(int x=0, int y=0, int z=0 )
    {
        src=x;
        des=y;
        wet=z;
    }
};

struct Comp
{
    bool operator()(Edge a, Edge b)
    {
        return a.wet>b.wet;
    }
};

struct Dijkastra
{
    Dijkastra( vector< vector< pii> > adj, int n, int src  )
    {
        this->adj=adj;
        this->n=n;
        this->src=src;
        dis=vector<int> (n+1);
        parent=vector<int> (n+1);
        cal();
    }

    vector<int> dis, parent;

private:
    vector< vector<pii> > adj;
    int n,src;

    void cal()
    {
        priority_queue< Edge, vector<Edge>, Comp> pq;
        pq.push( {-1,src,0} );
        dis[src]=0;
        vector<int> taken(n+1);

        while(pq.size())
        {
            Edge x=pq.top();
            pq.pop();
            int node=x.des;
            if(taken[node])continue;
            parent[node]=x.src;
            dis[node]=x.wet;
            taken[node]=1;
            int covered=x.wet;
            for(auto [d,w]: adj[node] )
            {
                pq.push( {node, d, covered+w} );
            }
        }
    }
};


