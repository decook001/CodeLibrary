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

