


struct Point2d
{
    lint x,y;
    Point2d( lint x=0, lint y=0 )
    {
        this->x=x;
        this->y=y;
    }

    bool operator == ( Point2d p )
    {
        return ( x==p.x && y==p.y );
    }

    bool operator != (Point2d p)
    {
        return ( x!=p.x || y!=p.y );
    }

    void print(  )
    {
        cout<<x<<S<<y<<D;
    }
};


struct Line
{
    Point2d p1, p2, slope, cut;
    lint length;
    Line(Point2d p1, Point2d p2)
    {
        this->p1=p1;
        this->p2=p2;
        calc();
    }

    lint gcd( lint a, lint b)
    {
        return ( b? gcd( b, a%b ): a );
    }

    void calc()
    {

        lint x,y;
        y=p1.y-p2.y;
        x=p1.x-p2.x;
        length=x*x+y*y;
        if(x==0 && y==0) slope= Point2d(0,0);
        else
        {
            lint g=gcd( x,y );
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
            slope=Point2d(x,y);
        }

        if ( slope== Point2d(0,0) ) cut= slope;
        else if( slope== Point2d(0,1) ) cut= Point2d(p1.x,0)  ;
        else if( slope== Point2d(1,0) ) cut= Point2d( 0,p1.y ) ;
        else
        {
            cut.y=p1.y*slope.x-p1.x*slope.y;
            cut.x=slope.x;
            if( cut.y==0 ) cut.x=1;
            else if( cut.x*cut.y<0 )
            {
                cut.x = -abs( cut.x );
                cut.y = abs( cut.y );
            }
            else
            {
                cut.x=abs(cut.x);
                cut.y=abs(cut.y );
            }
            lint g=gcd( cut.x, cut.y );
            cut.x/=g;
            cut.y/=g;
        }
    }
};


struct Quad
{
    vector<Point2d> corner;
    vector<Line> arm, diag;
    Quad( Point2d p1, Point2d p2, Point2d p3, Point2d p4 )
    {
        vector<Point2d> v= {p1, p2, p3, p4} ;
        sort( v.begin(), v.end(), comp ) ;
        corner = v;
        calc();
    }


    void calc()
    {
        arm.push_back( Line( corner[0], corner[1] ) );
        arm.push_back( Line( corner[1], corner[3] ) );
        arm.push_back( Line( corner[3], corner[2] ) );
        arm.push_back( Line( corner[2], corner[0] ) );
        diag.push_back( Line( corner[0], corner[3] ) );
        diag.push_back( Line( corner[1], corner[2] ) );
    }

    bool is_square()
    {
        if( arm[0].length==0 || arm[1].length==0 || arm[2].length==0 || arm[3].length==0 ) return false;
        if( arm[0].length!=arm[1].length || arm[0].length!=arm[2].length || arm[0].length!=arm[3].length ) return false;
        if( arm[0].slope!= arm[2].slope || arm[1].slope!=arm[3].slope ) return false;
        if( arm[0].length+arm[1].length!=diag[0].length ) return false;
        return true;
    }

    static bool comp( Point2d a, Point2d b )
    {
        if( a.x==b.x ) return a.y<b.y;
        return a.x<b.x;
    }
};

bool operator < ( Point2d a, Point2d b )
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}



