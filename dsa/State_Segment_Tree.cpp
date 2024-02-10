struct StateSegTree
{
    
    struct Info
    {
        ll dtt[2][2];
        Info()
        { 
            for( int i=0;i<2;i++ ) for( int j=0;j<2;j++ ) dtt[i][j]=inf;
        }
    };
    

    VIN a;
    int n;
    vector<Info> tree;

    void calc( int i, int l, int r )
    {
        Info aha;
        if( l==r-2 )
        {
            
            aha.dtt[0][0]=inf;
            aha.dtt[0][1]=a[l+1];
            aha.dtt[1][0]=a[l];
            aha.dtt[1][1]=a[r];
        }
        else if( l==r-3 )
        {
            aha.dtt[0][0]=a[l+1];
            aha.dtt[1][0]=a[l]+a[l+1];
            aha.dtt[0][1]=a[l+1]+a[l+2];
            aha.dtt[1][1]=a[l]+a[l+2];
        }
        else
        {
            Info lft=tree[i*2], rit=tree[i*2+1];
            Info aha;
            for( int i=0;i<2;i++ ) for( int j=0;j<2;j++ ) for( int k=0;k<2;k++ ) for( int l=0;l<2;l++ )
            {
                if(l+k==0) continue;
                aha.dtt[i][j]=min( aha.dtt[i][j], lft.dtt[i][k]+rit.dtt[l][j] );
            }
        }

        tree[i]=aha;

    }

    StateSegTree( int n, VIN& a )
    {
        this->n=n;
        this->a=a;
        tree=vector<Info> (n*4+9);

        auto build=[&] ( auto& self, int i, int l, int r ) -> void
        {
            if( l>=r-3 )
            {
                calc(i,l,r);
                return ;
            }
            int mid=(l+r)/2;
            self( self, i*2, l, mid );
            self( self, i*2+1, mid+1, r );
            calc( i, l, r );
        };

        build( build, 1, 1, n );

    }

    ll query( int pos, int val )
    {
        a[pos]=val;
        update( 1,1,n, pos );
        return tree[1].dtt[1][1];
    }

    void update( int i, int l, int r, int pos )
    {
        if( pos>r || pos<l ) return;
        if( l>=r-3 )
        {
            calc(i,l,r);
            return;
        }
        int mid=(l+r)/2;
        update( i*2 ,l, mid, pos );
        update( i*2+1, mid+1, r, pos );
        calc( i,l,r );
    }


};
