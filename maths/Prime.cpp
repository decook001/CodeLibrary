#include<bits/stdc++.h>
using namespace std;


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

    vector<int> isprime;
    int n;
    private:
    
    void sieve()
    {
        isprime.resize(n+1,1);
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

