
// all pair shortest path
// O(v^3)
// dont work on negative cycle but on negative weight
// can detect negative cycle by negative self distance
// works on undirected graph

struct Edge
{
    int src, des, wt;
    Edge(int x=0,int y=0,int z=0)
    {
        src=x;
        des=y;
        wt=z;
    }
};

struct FloydWarshall
{
    FloydWarshall( int n, vector< Edge > adj )
    {
        this->n=n;
        adm=vector<vector<int> > (n+1, vector<int> (n+1,inf) );
        for(int i=0; i<=n; i++) adm[i][i]=0;
        for(auto [x,y,z]: adj ) adm[x][y]=z;
        cal();
    }

    int dur(int l, int r)
    {
        return adm[l][r];
    }

private:
    vector< vector<int> > adm;
    int inf=2e9,n;

    void cal()
    {
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(adm[i][k]!=inf && adm[k][j]!=inf)
                    {
                        adm[i][j]=min(adm[i][j], adm[i][k]+adm[k][j] );
                    }
                }
            }
        }
    }
};


