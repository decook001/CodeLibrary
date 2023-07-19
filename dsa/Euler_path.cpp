

struct Euler
{
    vector<pii> edge;
    int n, is_euler;
    Euler( vector<pii> edge, int n )
    {
        this->edge=edge;
        this->n=n;
        cal();
    }

    void cal()
    {
        vector<int> deg(n+1,0), evod(2,0) ;

        for( auto [x,y]: edge )
        {
            evod[ deg[x]%2 ]--;
            evod[ deg[y]%2 ]--;
            deg[x]++;
            deg[y]++;
            evod[ deg[x]%2 ]++;
            evod[ deg[y]%2 ]++;
        }

        if(evod[1]==0) is_euler=2;
        else if(evod[1]<=2) is_euler=1;
        else is_euler=0;
    }
};


