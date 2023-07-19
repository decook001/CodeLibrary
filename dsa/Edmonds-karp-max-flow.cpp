// directed graph 
// do not forget to enter a revrese edge for every edge with null capacity

struct MaxFlow
{
    vvi cap, adj;
    int n, ans=0, src, des;
    vi parent;
    MaxFlow( vvi cap, vvi adj, int src, int des )
    {
        this->cap=cap;
        this->adj=adj;
        this->src=src;
        this->des=des;
        n=adj.size();
        cal();
    }

    void cal()
    {
        ans=0;
        int newflow;
        while(1)
        {
            newflow=bfs();
            if(newflow==0) return;
            ans+=newflow;
            for(int p=des; p!=src ; p=parent[p] )
            {
                cap[ parent[p] ][p] -= newflow;
                cap[p][ parent[p] ] += newflow;
            }
        }
    }

    int bfs()
    {
        parent = vi(26,-1);
        parent[src]=src;
        queue<pii> q;
        q.push( {src, 2e9} );
        while(q.size())
        {
            pii nxt=q.front();
            q.pop();
            if(nxt.first==des) return nxt.second;
            for(auto nei: adj[ nxt.first ])
            {
                if( cap[ nxt.first ][nei]>0 && parent[nei]==-1 )
                {
                    parent[nei]=nxt.first;
                    pii jabe={ nei, min( nxt.second, cap[nxt.first][nei] ) };
                    q.push(jabe);
                }
            }
        }
        return 0;
    }
};
