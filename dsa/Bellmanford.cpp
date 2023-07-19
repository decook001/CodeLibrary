// single source shortest path on directed graph
// works on negative edge
// detect negative cycle
// works on undirected graph without negative edge

struct Edge
{
    int src,des,weight;
    Edge(int x=0,int y=0,int z=0)
    {
        src=x;
        des=y;
        weight=z;
    }
};

struct BellmanFord
{

    BellmanFord(int n,  vector<Edge> edge, int src )
    {
        this->n=n;
        this->edge=edge;
        this->src=src;
        dis=vector<int> (n+1, inf );
        cal();
    }

    bool negative_cycle()
    {
        return iscycle;
    }

    vector<int> distan()
    {
        return dis;
    }


private:

    int n, src, inf=2e9 ;
    vector<Edge> edge ;
    vector<int> dis ;
    bool iscycle;
    void cal()
    {
        dis[src]=0;
        for(int j=1; j<n ; j++)
        {
            for(int i=0; i<edge.size(); i++)
            {
                int src=edge[i].src;
                int des=edge[i].des;
                int weight=edge[i].weight;

                if(dis[src]!=inf && dis[des]>dis[src]+weight)
                {
                    dis[des]=dis[src]+weight;
                }
            }
        }

        for(int i=0; i<edge.size(); i++)
        {
            int src=edge[i].src;
            int des=edge[i].des;
            int weight=edge[i].weight;
            if(dis[src]!=inf && dis[des]>dis[src]+weight)
            {
                iscycle=true;
                return;
            }
        }
        iscycle=false;
    }
};


