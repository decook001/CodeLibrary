struct Kmp2d
{
    string pattern;
    int n;
    vvi prefixsuf; // [i][j] length of max common prefix-suffix if j comes after prefix of i length
    vi proprefix; // [i] length of max proper common prefix-suffix of prefix of length i
    Kmp2d( string pattern )
    {
        this->pattern=pattern;
        n=pattern.size();
        prefixsuf=vvi ( n+9, vi (30) );
        proprefix=vi (n+9);
        build();
    }

    void build(  )
    {
        proprefix[1]=0;
        prefixsuf[0][ pattern[0]-'a' ]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if( j==pattern[i]-'a' )
                {
                    prefixsuf[i][j]=i+1;
                    proprefix[i+1]= prefixsuf[ proprefix[ i ] ][j];
                }
                else
                {
                    prefixsuf[i][j]= prefixsuf[ proprefix[i] ][j];
                }
            }
        }

    }

    vi matchidx( string txt )
    {
        int len=0;
        vi ans;
        int ntxt=txt.size();
        for(int i=0;i<ntxt;i++)
        {
            int j=txt[i]-'a';
            len=prefixsuf[len][j];
            if(len==n)
            {
                ans.push_back(i);
                len=proprefix[n];
                //cout<<len<<D;
            }
        }
        return ans;
    }


};
