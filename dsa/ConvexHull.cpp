
// includes colinear

struct ConvexHull
{
    ConvexHull( vector<pii> points )
    {
        this->points=points;
        np=points.size();
        if(np<2) ans=points;
        else preprocess();
    }

    static int orientation( vector<pii> v )
    {
        v.push_back( v[0] );
        int ans=0;
        for(int i=0; i<3; i++) ans += v[i].first*v[i+1].second;
        for( int i=0; i<3; i++ ) ans -= v[i].second*v[i+1].first;
        return ( ans==0? ans: ans/abs(ans) ) ;
    }

    static int dist(pii l, pii r)
    {
        return (l.first-r.first)*( l.first-r.first )+(l.second-r.second)*(l.second-r.second);
    }

    void preprocess( )
    {
        for(int i=1; i<np; i++ )
            if( points[i].second<points[0].second ||
                    ( points[i].second==points[0].second &&
                      points[i].first<points[0].first ) ) swap( points[0], points[i] );

        pivot=points[0];
        auto comp = [&] ( pii l, pii r )->bool
        {
            int ori=orientation( { pivot, l, r } );
            if( ori==0 ) return dist( pivot, l ) < dist( pivot, r );
            return ori>0;
        };

        sort( points.begin()+1, points.end(), comp );
        stack<pii> s;
        s.push( points[0] );
        s.push( points[1] );

        for(int i=2; i<np; i++)
        {
            pii p3=points[i];
            while(1)
            {
                pii p2=s.top();
                s.pop();
                pii p1=s.top();
                int ori=orientation( {p1, p2, p3} );
                if( ori>=0 )
                {
                    s.push( p2 );
                    s.push( p3 );
                    break;
                }
            }
        }

        pii last=s.top();
        if( orientation( { pivot, points[1], last } )!=0 )
        {
            s.pop();
            for( int i=np-1; i>0; i-- )
            {
                if( orientation( { pivot, last, points[i] } )==0 ) s.push( points[i] );
                else break;
            }
        }

        ans.clear();
        while(s.size())
        {
            ans.push_back( s.top() );
            s.pop();
        }
        reverse( ans.begin(), ans.end() );
    }

    vector<pii> points, ans;
    int np;
    pii pivot;
};


// exclude colinear


struct ConvexHull
{
    ConvexHull( vector<pii> points )
    {
        this->points=points;
        np=points.size();
        if(np<2) ans=points;
        else preprocess();
    }

    static int orientation( vector<pii> v )
    {
        v.push_back( v[0] );
        int ans=0;
        for(int i=0; i<3; i++) ans += v[i].first*v[i+1].second;
        for( int i=0; i<3; i++ ) ans -= v[i].second*v[i+1].first;
        return ( ans==0? ans: ans/abs(ans) ) ;
    }

    static int dist(pii l, pii r)
    {
        return (l.first-r.first)*( l.first-r.first )+(l.second-r.second)*(l.second-r.second);
    }

    void preprocess( )
    {
        for(int i=1; i<np; i++ )
            if( points[i].second<points[0].second ||
                    ( points[i].second==points[0].second &&
                      points[i].first<points[0].first ) ) swap( points[0], points[i] );

        pivot=points[0];
        auto comp = [&] ( pii l, pii r )->bool
        {
            int ori=orientation( { pivot, l, r } );
            if( ori==0 ) return dist( pivot, l ) < dist( pivot, r );
            return ori>0;
        };

        sort( points.begin()+1, points.end(), comp );
        stack<pii> s;
        s.push( points[0] );
        s.push( points[1] );

        for( int i=2; i<np ; i++ )
        {
            pii p3=points[i];
            while(1)
            {
                if(s.size()<2)
                {
                    s.push(p3);
                    break;
                }
                pii p2=s.top();
                s.pop();
                pii p1=s.top();
                int ori=orientation( {p1, p2, p3} );
                if( ori>0 )
                {
                    s.push( p2 );
                    s.push( p3 );
                    break;
                }
            }
        }

        ans.clear();
        while(s.size())
        {
            ans.push_back( s.top() );
            s.pop();
        }
        reverse( ans.begin(), ans.end() );
    }

    vector<pii> points, ans;
    int np;
    pii pivot;
};


