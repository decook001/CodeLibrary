

struct Position
{

    int x,y;

    Position()
    {
        x=0;
        y=0;
    }

    Position (int a, int b)
    {
        x=a;
        y=b;
    }

    Position (const Position& a)
    {
        x=a.x;
        y=a.y;
    }

    Position (char c)
    {
        if(c=='L')x=-1,y=0;
        if(c=='R')x=1,y=0;
        if(c=='U')x=0,y=1;
        if(c=='D')x=0,y=-1;
    }

    Position operator + (Position l)
    {
        Position res;
        res.x=x+l.x;
        res.y=y+l.y;
        return res;
    }

    Position operator - (Position a)
    {
        Position res;
        res.x=x-a.x;
        res.y=y-a.y;
        return res;
    }

    Position operator += (Position a)
    {
        x+=a.x;
        y+=a.y;
        return *this;
    }

    bool operator == (Position a)
    {
        if(x==a.x && y==a.y)return true;
        return false;
    }

    bool operator != (Position a)
    {
        if(x!=a.x || y!=a.y )return true;
        return false;
    }

    void print()
    {
        cout<<x<<S<<y<<N;
    }

};

bool operator < (const Position& p1, const Position& p2 )
{
    if(p1.x==p2.x)return p1.y<p2.y;
    return p1.x<p2.x;
}


