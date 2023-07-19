


struct SegmentTree
{

    SegmentTree(vector<int> v)
    {
        n=v.size();
        car=v;
        segtree=vector<int> (n*4);
        lazy=vector<int> (n*4,0);
        build(0, 0, n-1);
    }

    int query(int lq, int uq)
    {
        return query__(0, 0, n-1, lq, uq);
    }

    int update( int val, int lb, int rb )
    {
        update__( 0, 0, n-1, lb, rb, val );
    }

private:

    vector<int> car,segtree, lazy;
    int n;

    int update__(int node, int l, int r, int lb, int rb, int val)
    {
        if( lazy[node] ) segtree[node]=(r-l+1)*lazy[node];
        if( r<lb || rb<l ) return segtree[node] ;
        if( lb<=l && r<=rb )
        {
            segtree[node]=(r-l+1)*val;
            lazy[node]=val;
            return segtree[node];
        }

        int mid=(l+r)/2;
        if(lazy[node])
        {
            lazy[node*2+1]=lazy[node*2+2]=lazy[node];
            lazy[node]=0;
        }

        segtree[node]= update__( node*2+1, l, mid, lb, rb, val )+
                        update__( node*2+2, mid+1, r, lb, rb, val );

        return segtree[node];
    }

    int query__(int node, int l, int r, int lb, int rb)
    {
        if( lazy[node] ) segtree[node]=lazy[node]*( r-l+1 );
        if( l>rb || r<lb ) return 0;
        if( lb<=l && rb<=r ) return segtree[node];

        int mid=(l+r)/2;
        if(lazy[node])
        {
            lazy[node*2+1]=lazy[node*2+2]=lazy[node];
            lazy[node]=0;
        }

        return query__( node*2+1, l, mid, lb, rb )+
                query__( node*2+2, mid+1, r, lb, rb );

    }

    int build(int node, int l, int r)
    {
        if(l==r)
        {
            segtree[node]=car[l];
            return segtree[node];
        }

        int mid=(l+r)/2;
        segtree[node]=build(node*2+1,l,mid)+build(node*2+2, mid+1, r);
        return segtree[node];
    }
};


