

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
} mi( 2 ) ;

//-----------------------------------------------------------------

struct ModInt
{
private:
    const int mod=998244353;
    int val=0;

public:

    ModInt() {}
    ModInt(int val)
    {
        rinse(val);
        this->val=val;
    }
    ModInt( const ModInt& dan )
    {
        val=dan.val;
    }
    int getval()
    { 
        return val; 
    }
    int setval(int x)
    {
        rinse(x);
        val=x;
        return x;
    }
    void rinse(int& x)
    {
        x%=mod;
        x+=mod;
        x%=mod;
    }
    ModInt invers()
    {
        ModInt ans(1);
        ModInt a(val);
        int b=mod-2;
        while(b)
        {
            if( b&1 ) ans*=a;
            a*=a;
            b=b>>1;
        }
        return ans;
    }
    ModInt power(int b)
    {
        ModInt ans(1);
        ModInt a(val);
        while(b)
        {
            if( b&1 ) ans*=a;
            a*=a;
            b=b>>1;
        }
        return ans;
    }
    ModInt operator = ( ModInt dan )
    {
        val=dan.val;
        return *this;
    }
    ModInt operator + ( ModInt dan )
    {
        ModInt ans;
        ans.val=( val+dan.val ) % mod;
        return ans;
    }
    ModInt operator += ( ModInt dan )
    {
        val=( val+dan.val ) % mod;
        return *this;
    }
    ModInt operator - ( ModInt dan )
    {
        ModInt ans;
        ans.val=( val-dan.val+mod ) % mod;
        return ans;
    }
    ModInt operator -= ( ModInt dan )
    {
        val=( val-dan.val+mod ) % mod;
        return *this;
    }
    ModInt operator *= ( ModInt dan )
    {
        val=val*dan.val % mod;
        return *this;
    }
    ModInt operator * ( ModInt dan )
    {
        ModInt ans;
        ans.val=val*dan.val % mod;
        return ans;
    }
    ModInt operator / ( ModInt dan )
    {
        ModInt ans;
        dan=dan.invers();
        ans.val=val*dan.val%mod;
        return ans;
    }
    ModInt operator /= ( ModInt dan )
    {
        dan=dan.invers();
        val=val*dan.val%mod;
        return *this;
    }
    bool operator == ( ModInt dan )
    {
        return val==dan.val;
    }
    bool operator != ( ModInt dan )
    {
        return val!=dan.val;
    }
    bool operator < ( ModInt dan )
    {
        return val<dan.val;
    }
    bool operator > ( ModInt dan )
    {
        return val>dan.val;
    }

} mint ;





