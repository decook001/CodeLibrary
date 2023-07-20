#include<bits/stdc++.h>
using namespace std;

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL);                   \
    cout<< fixed << setprecision(32);

//------------------------------------------------------------------------------------------------------------------------

#define     int      long long
#define     ll       long long
#define     N             "\n"
#define     S             " "
#define     D             "   d\n"
#define     F             "   f\n"
#define     yap      cout<<"yap\n"
#define     E            " e "
#define     vi       vector<int>
#define     vb       vector<bool>
#define     vvi      vector<vector<int>>
#define     pii      pair<int,int>
#define     szo(a)   (sizeof(a)/sizeof(a[0]))
#define     bpc(x)   __builtin_popcountll(x)
#define     ctz(x)   __builtin_ctzll(x)
#define     clz(x)   __builtin_clzll(x)
#define     yno(f)   cout<<(f?"YES\n":"NO\n")
#define     bin(x)   bitset<64>(x)

//#######################################_shoaib_221######################################################################

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
} modint( 2 ) ;


//######################################################################################################################

struct NumTheo
{
    int n;
    NumTheo(int n=0)
    {
        this->n=n;
        spf=vector<int> ( n+9 );
        sieve();
    }

    vector<int> spf; // smallest prime factor
    vi primes;

    map<int,int> prime_fctr_cnt(int x, map<int, int>& mapu )
    {
        while( x>1 )
        {
            mapu[ spf[x] ]++;
            x/=spf[x];
        }
    }

    ll powm( ll a, ll b, ll mod )
    {
        ll res=1;
        while( b )
        {
            if(b&1) res=res*a % mod;
            a=a*a%mod;
            b=b>>1;
        }
        return res;
    }

    void sieve()
    {

        for(int i=2; i<=n; i++)
        {
            if( spf[i]==0 )
            {
                primes.push_back(i);
                spf[i]=i;
            }

            for(int p: primes)
            {
                if(i*p>n) break;
                spf[ i*p ]=p;
                if( i%p==0 ) break;
            }
        }
    }

    bool is_prime(int a)
    {
        if(a==1) return false;
        for(int i=2; i*i<=a; i++)
        {
            if(a%i==0)return false;
        }
        return true;
    }

    int gcd( int x, int y)
    {
        x=abs(x);
        y=abs(y);
        return y?gcd(y, x%y):x;
    }

    int lcm( int x, int y)
    {
        x=abs(x);
        y=abs(y);
        if(!x && !y) return 0;
        if( !x || !y ) return max( x,y );
        return x/gcd(x,y)*y;
    }

    int cntdig( int n )
    {
        if(n==0)return 1LL;
        int ans=0;
        while(n)
        {
            ans++;
            n/=10;
        }
        return ans;
    }
} numt(3) ;


//######################################################################################################################


struct Combi
{
    int n, mod;
    vector<int> fact, infact, invrs;

    Combi(int n=9, int mod=2)
    {
        this->n=n;
        this->mod=mod;
        fact=vi (n+9);
        infact=vi (n+9);
        invrs=vi (n+9);
        cal_fact();
    }

    int powm( int a, int b)
    {
        int res = 1;
        while (b > 0)
        {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b = b >> 1;
        }
        return res;
    }

    void cal_fact()
    {
        infact[0]=fact[0]=1;
        for(int i=1; i<=n; i++) fact[i]=(fact[i-1]*i)%mod;
        infact[n]=powm(fact[n], mod-2);
        for(int i=n-1; i>0; i--)
        {
            infact[i]=infact[i+1]*(i+1)%mod;
            invrs[i]=infact[i]*fact[i-1]%mod;
        }
    }
    int nPr(int n, int r)
    {
        if( n<0 || r<0 || n<r ) return 0;
        return fact[n]*infact[n-r]%mod;
    }
    int nCr(int n, int r)
    {
        if( n<0 || r<0 || n<r ) return 0;
        return nPr(n,r)*infact[r]%mod;
    }
} combi( 100, 7 ) ;


//######################################################################################################################

// lb(fi>=v) , ub(fi>v) s
// lower_bound(a.begin(), a.end(), 4, com_srt)-a.begin()
// sort( a, a+n, com_srt)
// never use <=,>= sign in com_srt always use <,>

bool com_srt (int a, int b)
{
    return a<b; //sscending
}

// priority_queue < int, vector<int>, com_pq > pq

struct com_pq
{
    bool operator()(const int& p1, const int& p2)
    {
        return p1>p2; //ascending
    }
};


// set<int, com_set> sat;
struct com_set
{
    bool operator()(const int& p1, const int& p2)
    {
        return p1<p2; //ascending
    }
};


//#############################################################################################################

void declare()
{
    vector<int> a,b;
    int ind = find(a.begin(), a.end(), 2) - a.begin();                   // finds element in unsorted array
    sort(a.begin(), a.end(), com_srt);
    sort(a.rbegin(), a.rend()); // decreasing order
    ind=lower_bound(a.begin(), a.end(), 2, com_srt)-a.begin();   // finds eement in sorted array
    partial_sum(a.begin(), a.end(), b.begin());  //a's partial sum at b
    vector< vector< vector<int> > > vec(10, vector< vector<int> > (5,  vector<int> (2,3) )  );
    int mx=*max_element(a.begin(), a.end());
    int cnt=count( a.begin(), a.end(), 1 );        // counts element in unsorted array
    rotate(a.begin(), a.begin()+2, a.end() );    // replace first 2 elements and append them back
    ll sum= accumulate(a.begin(), a.end(), 0);
    function<bool (int, int) > aha=[&] ( int l, int r ) -> bool { return 0; };
}

//##############################################################################################

struct Pos
{

    int x,y;

    Pos()
    {
        x=0;
        y=0;
    }

    Pos (int a, int b)
    {
        x=a;
        y=b;
    }

    Pos(const Pos& a)
    {
        x=a.x;
        y=a.y;
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

    void print()
    {
        cout<<x<<S<<y<<N;
    }

};

bool operator < (const Pos& p1, const Pos&p2 )
{
    if(p1.x==p2.x)return p1.y<p2.y;
    return p1.x<p2.x;
}

//###############################################################################################################

int prnt(int arg_count, ...)
{
    int i;
    int min, a;
    va_list ap;
    va_start(ap, arg_count);
    for (i = 0; i <= arg_count; i++) cout<<va_arg(ap, int)<<S;
    cout<<N;
}

//##################################################value/reference##############################################

void test()
{

    int a=10;
    int* b= &a; // pointer

    *b=1;
    cout<<a<<S<< *b << N;

    a=10;

    cout<<a <<S<< *b<<N;
    b=new int(2);
    cout<<a <<S<< *b << N;
    *b=3;
    cout<< a <<S<< *b<<N;

    int &c=a;  // reference
    cout<< a <<S<< *b <<S<<  c<<N;

    int d=-1;
    c=d;
    cout<<a <<S<< *b <<S<< c <<S<< d<<N;

}

//############################################################################################################

class Cls
{
    int x;
};

struct Strct
{
    int x;
};

void case()
{

}




//###########################################################################################################

int32_t main()
{

}
