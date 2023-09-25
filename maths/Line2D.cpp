


struct Point2d
{
    int x,y;
    Point2d( int x=0, int y=0 )
    {
        this->x=x;
        this->y=y;
    }
};


struct Line
{
    Point2d p1, p2;
    pii slope, cut;
    int length;
    Line(Point2d p1, Point2d p2)
    {
        this->p1=p1;
        this->p2=p2;
        calc();
    }

    int gcd(int a, int b)
    {
        return ( b? gcd( b, a%b ): a );
    }

    void calc()
    {
        length=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
        int x,y;
        y=p1.y-p2.y;
        x=p1.x-p2.x;
        if(x==0 && y==0) slope= {0,0};
        else
        {
            int g=gcd( x,y );
            x/=g;
            y/=g;
            if(x==0) y=1;
            else if(y==0) x=1;
            else if(x*y>0)
            {
                x=abs(x);
                y=abs(y);
            }
            else
            {
                x=-abs(x);
                y=abs(y);
            }
            slope.first=x;
            slope.second=y;
        }

        if ( slope.first==0 && slope.second==0 ) cut= {0,0};
        else if( slope.first==0 && slope.second==1 ) cut={ p1.x,0 };
        else if( slope.first==1 && slope.second==0 ) cut={ 0, p1.y };
        else
        {
            cut.second=p1.y*slope.first-p1.x*slope.second;
            cut.first=slope.first;
            if( cut.second==0 ) cut.first=1;
            else if( cut.first*cut.second<0 )
            {
                cut.first= -abs( cut.first );
                cut.second= abs( cut.second );
            }
            else
            {
                cut.first=abs(cut.first);
                cut.second=abs(cut.second );
            }
            int g=gcd( cut.first, cut.second );
            cut.first/=g;
            cut.second/=g;
        }
    }
};


