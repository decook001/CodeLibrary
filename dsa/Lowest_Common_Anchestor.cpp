//  https://cp-algorithms.com/graph/lca.html

struct Lca
{
    vi euler, first, height, segtree, parent;
    int m;
    Lca( vvi& adj, int n, int root )
    {

        first= vi (n+9);
        height= vi (n+9);
        parent= vi (n+9, -1);
        auto dfs=[&] (auto self, int nod, int h)->int
        {

            height[nod]=h;
            first[nod]=euler.size();
            euler.push_back( nod );

            for( int nxt: adj[nod] )
            {
                if( nxt==parent[nod] ) continue;
                parent[nxt]=nod;
                self( self, nxt, h+1 );
                euler.push_back( nod );
            }
            return 0;
        };

        dfs( dfs, root, 0 );
        m=euler.size();
        segtree= vi (m*4);
        build( 0, 0, m-1 );

    }

    int qry( int u, int v )
    {
        u=first[u];
        v=first[v];

        if( u>v ) swap(u,v);
        return qry( 0, 0, m-1, u, v );
    }



private:

    int qry( int idx, int l, int r, int lb, int rb )
    {
        if( l>rb || lb>r ) return -1;
        if( lb<=l && r<=rb ) return segtree[idx];

        int mid=(l+r)/2;
        int lval=qry( idx*2+1, l, mid, lb, rb );
        int rval=qry( idx*2+2, mid+1, r, lb, rb );

        if( lval==-1 ) return rval;
        if( rval==-1 ) return lval;

        return ( height[lval]<=height[rval]? lval: rval );

    }

    int build( int idx, int l, int r )
    {
        if( l==r )
        {
            segtree[idx]=euler[l];
            return euler[l];
        }

        int mid=(l+r)/2;
        int lv=build( idx*2+1, l, mid );
        int rv=build( idx*2+2, mid+1, r );
        if( height[lv]<=height[rv] ) segtree[idx]=lv;
        else segtree[idx]=rv;

        return segtree[idx];
    }

};
