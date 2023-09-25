

struct compare
{
    bool operator() ( pii l, pii r )
    {
        if( l.second=r.second ) return l.first<r.first;
        return l.second<r.second;
    }
};

struct ClosestPair
{

    ClosestPair(vector<pii> v )
    {
        this->v=v;
        n=v.size();
        calc();
    }


    void calc()
    {
        sort( v.begin(), v.end(), [&] (pii l, pii r)->bool{ return l.first<r.first; } ) ;
        set<pii, compare > s;
        s.insert( v[0] );
        int ans=2e9;
        for( int i=1, l=0; i<v.size() ; i++ )
        {

            while( l<i && v[l].first<v[i].first-ans )
            {
                s.erase( v[l] );
                l++;
            }

            for( auto it= s.lower_bound( { -2e9, v[i].second-ans } ); it!=s.end() && it->second<=v[i].second+ans; it++ )
            {

                if(ans> abs( v[i].first-it->first )+ abs( v[i].second-it->second ) )
                {
                    ans=abs( v[i].first-it->first )+ abs( v[i].second-it->second );
                    closest_pairs.clear();
                    closest_pairs.push_back( v[i] );
                    closest_pairs.push_back( *it );
                }
            }
            s.insert( v[i] );
        }
    }

    vector<pii> closest_pairs;
    int n;
    vector<pii> v;
};

