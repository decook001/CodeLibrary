

struct Prime
{
    int n;
    Prime(int n=0)
    {
        this->n=n;
        spf=vector<int> ( n+9 );
        sieve();
    }

    vector<int> spf; // smallest prime factor
    vi primes;

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

} numt(3) ;

