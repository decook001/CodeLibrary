
const int inf=2e9;
 
struct MCMF
{
    int n, st, en;
    VVI cap, flo, cost;
    VIN dis, par, inq;
    MCMF(int n, int st, int en)
    {
        n+=3;
        this->n=n;
        this->st=st;
        this->en=en;
        cap = VVI ( n, VIN (n) );
        flo = VVI ( n, VIN (n) );
        cost = VVI ( n, VIN ( n ) );
        
    }
 
    void add_edge( int u, int v, int cp, int c )
    {
        cap[u][v]=cp;
        cost[u][v]=c;
        cost[v][u]=-c;
    }
 
    void shortest_path()
    {
        dis=VIN ( n, inf );
        dis[st]=0;
        par=VIN (  n , -1 );
        inq=VIN( n, 0 );
        inq[ st ]=true;
        queue<int> q;
        q.push(st);
 
        while ( q.size() )
        {
            int now=q.front();
            q.pop();
            inq[now]=false;
 
            
            for( int nxt=0;nxt<n;nxt++ )
            {
                if( cap[now][nxt]>flo[now][nxt] && dis[ nxt ]> dis[now]+cost[now][nxt] )
                {
                    dis[ nxt ] = dis[now]+cost[now][nxt];
                    par[ nxt ] = now;
 
                    if( !inq[nxt] )
                    {
                        inq[nxt]=true;
                        q.push( nxt );
                    }
                }
            }
        }
    }
 
    PII calc()
    {
        int flow=0, mncost=0;
 
        while ( 1 )
        {
            shortest_path();
            if( dis[en] == inf) break;
 
            int nowflow=inf;
            for( int now=en;now!=st;now=par[now] )
            {
                nowflow=min( nowflow, cap[ par[now] ][now] - flo[ par[now] ][ now ] );
            }
 
            if( nowflow==inf ) break;
 
            flow+=nowflow;
            mncost+=dis[ en ];
 
            for( int now=en;now!=st;now=par[now] )
            {
                flo[ par[now] ][now] += nowflow;
                flo[ now ][ par[now] ] -= nowflow;
            }
 
        }
 
        return make_pair( flow, mncost );
        
    }
 
 
 
};
