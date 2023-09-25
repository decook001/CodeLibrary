

struct UnionRectangle
{
    vvi lines;
    int mod=1e9+7, ans;
    UnionRectangle( vvi v )
    {
        for(auto x: v)
        {
            lines.push_back( { x[1], x[0], x[2], 1 } );
            lines.push_back( { x[3], x[0], x[2], 0 } );
        }
        calc();
    }

    void calc()
    {
        sort( lines.begin(), lines.end(), [&] (vi l, vi r)->bool { return l[0]<r[0]; } );
        multiset<pii> ms;

        int prey=0, totx=0;
        ans=0;
        for( auto line : lines )
        {
            int y=line[0], l=line[1], r=line[2], op=line[3];
            ans = (ans + ((y-prey)*totx)%mod ) %mod;
            
            prey=y;
            if(op) ms.insert( {l,r} );
            else ms.erase( ms.find( {l,r} ) );

            int prex=0;
            totx=0;
            for(pii cup: ms )
            {
                if( cup.first<prex) totx+=max( 0ll , cup.second - prex );
                else totx+= cup.second-cup.first ;
                prex=max( prex, cup.second );
            }
        }
    }
};



