
// it detects the minimum weighted edge while creating circle or not
// work with negative weight
// uses disjoint set union

struct Edge
{
    int src=0, des=0, wet=0;
    Edge(int x=0, int y=0, int z=0 )
    {
        src=x;
        des=y;
        wet=z;
    }
};


struct Kruskal
{
    Kruskal( vector<Edge> edge, int n)
    {
        this->edge=edge;
        this->n=n;
        setno=vector<int> ( n+1 );
        iota( setno.begin(), setno.end(), 0 );
        cal();
    }

    vector<Edge> mst;
private:
    vector<Edge> edge;
    vector<int> setno;
    int n;

    bool static comp(Edge a, Edge b)
    {
        return a.wet<b.wet;
    }

    int getset(int x)
    {
        if(x==setno[x])return x;
        setno[x]=getset(setno[x]);
        return setno[x];
    }

    bool unionset(int x, int y)
    {
        x=getset(x);
        y=getset(y);
        if(x==y)return false;
        setno[x]=y;
        return true;
    }

    void cal()
    {
        sort(edge.begin(), edge.end(), comp);

        for(auto [x,y,z]: edge )
        {
            if( unionset( x,y ) )
            {
                mst.push_back( {x,y,z} );
            }
        }
    }
};


//c++ stl uses balanced binary search tree for set and map
// heap for priority queue

