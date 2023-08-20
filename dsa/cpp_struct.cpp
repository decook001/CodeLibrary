struct Pos
{

    int x,y;

    Pos() { x=0; y=0; }
    Pos(int a, int b) { x=a; y=b; }

    Pos(const Pos& a)
    {
        x=a.x;
        y=a.y;
    }

    Pos operator = ( Pos dan )  
    {
        x=dan.x;
        y=dan.y;
    }

    Pos(char c)
    {
        if(c=='L')x=-1,y=0;
        if(c=='R')x=1,y=0;
        if(c=='U')x=0,y=1;
        if(c=='D')x=0,y=-1;
    }

    Pos operator + (Pos l)
    {
        Pos res;
        res.x=x+l.x;
        res.y=y+l.y;
        return res;
    }

    Pos operator - (Pos a)
    {
        Pos res;
        res.x=x-a.x;
        res.y=y-a.y;
        return res;
    }

    Pos operator += (Pos a)
    {
        x+=a.x;
        y+=a.y;
        return *this;
    }

    bool operator == (Pos a)
    {
        if(x==a.x && y==a.y)return true;
        return false;
    }

    bool operator != (Pos a)
    {
        if(x!=a.x || y!=a.y )return true;
        return false;
    }

    bool operator < (Pos dan )
    {
        return y<dan.y;
    }

    void print()
    {
        cout<<x<<S<<y<<N;
    }

};

