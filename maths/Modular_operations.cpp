

struct ModInt
{
    int m;

    ModInt(int mod)
    {
        this->m=mod;
    }
    ll add( ll a, ll b )
    {
        a%=m;
        b%=m;
        a=(a+m)%m;
        b=(b+m)%m;
        return (a+b)%m;
    }
    ll sub( ll a, ll b )
    {
        a%=m;
        b%=m;
        a=(a+m)%m;
        b=(b+m)%m;
        a=(a-b)%m;
        return ( a+m )%m;
    }
    ll mulp( ll a, ll b )
    {
        a%=m;
        b%=m;
        a=(a+m)%m;
        b=(b+m)%m;
        return a*b%m;
    }
    ll powmod( ll a, ll b )
    {
        a%=m;
        b%=m;
        a=(a+m)%m;
        b=(b+m)%m;

        ll res=1;
        while(b)
        {
            if( b&1 ) res=res*a%m;
            a=a*a%m;
            b=b>>1;
        }
        return res;
    }

    ll div( ll a, ll b )
    {
        a%=m;
        b%=m;
        a=(a+m)%m;
        b=(b+m)%m;
        return a*powmod(b, m-2)%m;
    }

} mint( 2 ) ;
