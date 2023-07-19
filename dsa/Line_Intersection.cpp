

struct Line2d
{
    pii p1,p2;
    Line2d(pii p1, pii p2)
    {
        this->p1=p1;
        this->p2=p2;
    }

    int do_intersect(Line2d l)
    {
        if( orientation( {p1, p2, l.p1} ) == orientation( {p1, p2, l.p2} ) ) return 0;
        if( orientation( {l.p1, l.p2, p1} ) == orientation( {l.p1, l.p2, p2} ) ) return 0;
        return 1;
    }

    int orientation( vector<pii> v )
    {
        v.push_back( v[0] );
        int ans=0;
        for(int i=0; i<3; i++) ans += v[i].first*v[i+1].second;
        for( int i=0; i<3; i++ ) ans -= v[i].second*v[i+1].first;
        return ( ans==0? ans: ans/abs(ans) ) ;
    }

};


