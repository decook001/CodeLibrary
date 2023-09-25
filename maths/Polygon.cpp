

struct Polygon
{
    vector<Point2d> v;
    int n;
    Polygon( vector<Point2d> v )
    {
        this->v=v;
        n=v.size();
    }

    double area()
    {
        vector<Point2d> a=v;
        a.push_back(a[0]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i].x*a[i+1].y;
        }

        for(int i=0;i<n;i++)
        {
            ans-=a[i].y*a[i+1].x;
        }
        return 0.5*ans;

    }

};


