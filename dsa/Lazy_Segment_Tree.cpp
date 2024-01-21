
struct LazySegTree
{
    VIN tree, lazy ;
    int n;
    LazySegTree( int n )
    {
        tree=VIN ( n*4+9 );
        this->n=n;
        lazy=VIN ( n*4+9 );
    }
 
    void update( int node, int l, int r, int ql, int qr, int val )
    {
        if( l>qr || ql>r ) return;
        if( ql<=l && r<=qr )
        {
            lazy[node]+=val;
            tree[node]+=val;
            return;
        }
        int mid=( l+r )/2;
        update( node*2, l, mid, ql, qr, val );
        update( node*2+1, mid+1, r, ql, qr, val );
        tree[node]=max( tree[ node*2 ], tree[ node*2+1 ] );
        tree[node]+=lazy[node];
    }
 
    int query( int node, int l, int r, int ql, int qr )
    {
        if( ql<=l && r<=qr ) return tree[node];
        if( ql>r || l>qr ) return 0;
        int mid=(l+r)/2;
        int aha=max( query( node*2, l, mid, ql, qr ), query( node*2+1, mid+1, r, ql, qr ) );
        aha+=lazy[node];
        return aha;
    }
};

