
struct Prime
{
    
    Prime(int n)
    {
        this->n=n;
        sieve();
    }
    
bool is_prime(int a)
{
    for(int i=2; i*i<=a; i++)
    {
        if(a%i==0)return false;
    }
    return true;
}

vector<int> isprime(1e6+9,1);
int n;
private:
    
void sieve()
{
    isprime[1]=isprime[0]=0;
    for(int i=2; i<=1e6; i++)
    {
        if(isprime[i]==1)
        {
            for(int j=i+i; j<=1e6; j+=i )
            {
                isprime[j]=0;
            }
        }
    }
}
};

