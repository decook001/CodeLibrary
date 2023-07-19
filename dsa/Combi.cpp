

struct Combi
{

    Combi(int n, int mod)
    {
        this->n=n;
        this->mod=mod;
        infact=vector<int> (n+10);
        fact=vector<int> (n+10);
        cal_fact();
    }

    int n, mod;
    vector<int> fact, infact;

    ll powm( int a, int b)
    {
        // (a^b) % mod
        ll res = 1;
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
        infact[0]=fact[0]=1ll;

        for(ll i=1; i<=n; i++)
            fact[i]=(fact[i-1]*i)%mod;

        infact[n]=powm(fact[n], mod-2);       // (1/x!)= (x!)^(mod-2)  % mod

        for(ll i=n-1; i>0; i--)
        {
            infact[i]=(infact[i+1]*(i+1))%mod;
        }
    }


    int nPr(int n, int r)
    {
        return (fact[n]*infact[n-r])%mod;
    }

    int nCr(int n, int r)
    {
        return ( nPr(n,r)*infact[r] )%mod;
    }
};


