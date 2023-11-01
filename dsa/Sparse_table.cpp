//  https://cp-algorithms.com/data_structures/sparse-table.html
// works on only static data not on dynamic data
// 0-indexed
// range sum 

struct SparseTable
{
    int n,m;
    vector< vector<int> > spt;
    
    SparseTable( vector<int>& a  )
    {
        n=a.size()-1;
        m=log2(n);
        spt=vector< vector<int> > ( n+9, vector<int> (m+2) );
        for (int i = 1; i <= n; i++) spt[i][0] = a[i];
        cal();
    }

    int query( int l, int r )
    {
        int sum = 0;
        for (int j = m; j >= 0; j--)
        {
            if ((1 << j) <= r - l + 1 )
            {
                sum += spt[l][j];
                l += (1 << j) ;
            }
        }
        return sum;
    }

private:

    void cal()
    {
        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i + (1 << j) <= n+1; i++)
            {
                spt[i][j] = spt[i][j-1] + spt[i + (1 << (j - 1))][j - 1];
            }
        }
    }
};

