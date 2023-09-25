// 2d point on eucledian space


struct Point2
{
    double x,y;
    Point2( double x=0, double y=0 )
    {
        this->x=x;
        this->y=y;
    }

    Point2 operator - ( Point2 p )
    {
        Point2 ans;
        ans.x=x-p.x;
        ans.y=y-p.y;
        return ans;
    }

    Point2 operator += (Point2 p)
    {
        x+=p.x;
        y+=p.y;
        return *this;
    }

    Point2 operator *= ( double mul )
    {
        x*=mul;
        y*=mul;
        return *this;
    }

    bool operator == ( Point2 a )
    {
        if( x==a.x && y==a.y ) return true;
        return false;
    }

    double value()
    {
        return sqrt( x*x+y*y );
    }

    double dotpro( Point2 p )
    {
        return x*p.x+y*p.y;
    }

    double anglebetween( Point2 p )
    {
        return acos( dotpro(p)/value()/p.value() )/pie*180;
    }

    void print()
    {
        cout<<x<<S<<y<<N;
    }
};


