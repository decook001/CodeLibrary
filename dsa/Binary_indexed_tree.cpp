#include<bits/stdc++.h>
using namespace std;

//range update point query
// 1-indexed

struct Bit
{
    int n;
    vector<int> bit;
    
    Bit(int n)
    {
        this->n=n;
        bit=vector<int> (n+1);
    }

void update(int lb, int ub, int val)
{
    while(lb<=n)
    {
        bit[lb]+=val;
        lb+= lb & (-lb);
    }
    ub++;
    while(ub<=n)
    {
        bit[ub]-=val;
        ub+= ub & (-ub);
    }
}

int getval(int index)
{
    int sum=0;
    while(index>0)
    {
        sum += bit[index];
        index -= index &(-index);
    }
    return sum;
}
    
};


