#include<bits/stdc++.h>
using namespace std;


// works with negative weight
// uses dijkstra
// dijkstra from any node will span the mst

struct Edge
{
    int src=0, des=0, wet=0;
    edge(int x=0, int y=0, int z=0 )
    {
        src=x;
        des=y;
        wet=z;
    }
};

struct Comp
{
    bool operator()(Edge a, Edge b)
    {
        return a.wet>b.wet;
    }
};

struct PrimsAlgo
{
    PrimsAlgo( vector< vector< pii> > adj, int n  )
    {
        this->adj=adj;
        this->n=n;
        cal();
    }

    vector<Edge> mst;

private:
    vector< vector<pii> > adj;
    int n;

    void cal()
    {
        priority_queue< Edge, vector<Edge>, Comp> pq;
        pq.push( {-1,1,0} );
        vector<int> taken(n+1);

        while(pq.size())
        {
            Edge x=pq.top();
            pq.pop();
            int node=x.des;
            if(taken[node])continue;
            mst.push_back( x );
            taken[node]=1;
            int covered=x.wet;
            for(auto [d,w]: adj[node] )
            {
                pq.push( {node, d, covered+w} );
            }
        }
    }
};

/*
input

7 8
1 2 1
1 3 2
2 4 3
3 4 1
4 5 2
4 6 2
5 7 3
6 7 4

answer
11
*/
