

struct Totient
{
    vi totient;
    void build_totient(int n)
    {
        totient=vi (n+9);
        iota( totient.begin(), totient.end(), 0 );
        for(int i=1; i<=n; i++)
        {
            for(int j=i*2; j<=n; j+=i)
            {
                totient[j]-=totient[i];
            }
        }
    }

    
};
