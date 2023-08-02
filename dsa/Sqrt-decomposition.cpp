https://cp-algorithms.com/data_structures/sqrt_decomposition.html

struct SqrtDecomp
{
    SqrtDecomp(vector<int> v)
    {
        this->v=v;
        n=v.size();
        blksz=sqrt(n);
        dpv=vector<int> ( 2*blksz ) ;
        cal();
    }

    void update(int ind, int val)
    {
        dpv[ ind/blksz ] += val-v[ind] ;
        v[ind]=val;
    }

    int query(int l, int r)
    {
        int sum=0;
        while( l<=r  && l%blksz!=0 ) sum += v[l], l++;
        while( l+blksz-1<= r ) sum += dpv[l/blksz], l+=blksz;
        while( l<=r ) sum+=v[l] ,l++;
        return sum;
    }

private:

    void cal()
    {
        for(int i=0;i<n;i++) dpv[ i/blksz ] += v[i];
    }

    vector<int> v, dpv;
    int n, blksz;

};

// mo's algorithm
