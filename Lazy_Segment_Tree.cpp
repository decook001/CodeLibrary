struct RainWater
{
    VPI mxtree;
    VIN  extra;
    set<int> idx;
    ll sum,n;
 
    RainWater( VIN& a )
    {
        n=a.size()-1;
        mxtree= VPI ( n*4+9 );
        extra= VIN ( n*4+9 );
        
 
        ll mx=0;
        idx.clear();
        sum=0;
        for( int i=1;i<=n; i++ ) 
        {
            if( a[i]>mx ) 
            {
                mx=a[i];
                idx.insert( i );
            }
            sum += mx;
        }
 
        auto build=[&] ( auto& self, int i, int l, int r )->void
        {
            if( l==r )
            {
                mxtree[i]=PII( a[l], -l );
                return;
            }
            int mid=(l+r)/2;
            self( self, i*2, l, mid );
            self( self, i*2+1, mid+1, r );
            mxtree[i]=max( mxtree[i*2], mxtree[i*2+1] );
        };
 
        build( build, 1, 1, n );
 
 
    }
 
    PII query(int i, int l, int r, int ql, int qr)
    {
        if( ql<=l && r<=qr ) return mxtree[i];
        if( ql>r || qr<l ) return PII( -1,0 );
 
        int mid=( l+r )/2;
        PII aha = max( query( i*2, l, mid, ql, qr ), query( i*2+1, mid+1, r, ql, qr ) );
        aha.first+=extra[i];
        return aha;
    }
 
    void upd(int l, int r)
    {
        upd2( 1, 1, n, l, r, 1 );
        auto it=idx.lower_bound( l );
 
        if( it!=idx.end() && *it==l );
        else if( it!=idx.end() && *it<=r )
        {
            PII q1=query( 1, 1, n, l, *it-1 );
            PII q2=query( 1, 1, n, 1, l-1 );
            if( q1.first > q2.first ) idx.insert( -q1.second );
        }
        else
        {
            PII q1=query( 1, 1, n, l, r );
            PII q2=query( 1, 1, n, 1, l-1 );
            if( q1.first>q2.first ) idx.insert( -q1.second );
        }
 
        it=idx.lower_bound(l);
 
        if( it!=idx.end() && *it<=r )
        {
            int x=*it, y;
            it=idx.lower_bound(r+1);
 
            if( it!=idx.end() ) y=*it;
            else y=n+1;
 
            sum += y-x;
            
        }
 
        it= idx.lower_bound( r+1 );
        if( it!=idx.end() )
        {
            PII q1=query( 1, 1, n, 1, r );
            PII q2=query( 1, 1, n, *it, *it );
            if( q1.first>=q2.first ) idx.erase( *it );
        }
 
 
 
    }
 
    void upd2(int i, int l, int r, int ql, int qr, int v)
    {
        if( ql<=l && r<=qr ) 
        {
            extra[i]+=v;
            mxtree[i].first+=v;
            return;
        }
        if( ql>r || l>qr ) return;
        int mid=(l+r)/2;
        upd2( i*2, l, mid, ql, qr, v );
        upd2( i*2+1, mid+1, r, ql, qr, v );
        mxtree[i]=max( mxtree[i*2], mxtree[i*2+1] );
        mxtree[i].first += extra[i];
    }
 
 
};
