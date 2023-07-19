


// lb(fi>=v) , ub(fi>v) s
// lower_bound(a.begin(), a.end(), 4, com_srt)-a.begin()
// sort( a, a+n, com_srt)
// never use <=,>= sign in com_srt always use <,>

bool com_srt (int a, int b)
{
    return a>b; //descending
}

// priority_queue < int, vector<int>, com_pq > pq

struct com_pq
{
    bool operator()(const int& p1, const int& p2)
    {
        return p1>p2; //ascending
    }
};

// use <= for the duplicates
// set< pii, comp> s;
// map< pii, int, comp> s;
struct comp
{
    bool operator( ) ( pii l, pii r )
    {
        return l.second<r.second;
    }
};


//--------------------------declare---------------------------------------

void declare()
{
    vector<int> a,b;
    int ind = find(a.begin(), a.end(), 2) - a.begin();                   // finds element in unsorted array
    sort(a.begin(), a.end(), com_srt);
    sort(a.rbegin(), a.rend()); // decreasing order
    ind=lower_bound(a.begin(), a.end(), 2, com_srt)-a.begin();   // finds eement in sorted array
    partial_sum(a.begin(), a.end(), b.begin());  //a's partial sum at b
    vector< vector< vector<int> > > vec(10, vector< vector<int> > (5,  vector<int> (2,3) )  );
    int mx=*max_element(a.begin(), a.end());
    int cnt=count( a.begin(), a.end(), 1 );        // counts element in unsorted array
    rotate(a.begin(), a.begin()+2, a.end() );    // replace first 2 elements and append them back
    ll sum= accumulate(a.begin(), a.end(), 0);
}
