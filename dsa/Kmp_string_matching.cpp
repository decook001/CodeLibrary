// single pattern string matching
// pre-process pattern


struct Kmp
{
    Kmp(string s)
    {
        pattern=s;
        n=s.size();
        lps= vector<int> (n+1,0);
        build_lps();
    }

    int kmp_search(string text)
    {
        int txtlen=text.size();
        int indexes=0;
        for(int i=0,j=0; i<txtlen ; i++)
        {
            while(j>0 && text[i]!=pattern[j]) j=lps[j-1];

            if(text[i]==pattern[j]) j++;

            if(j==n)
            {
                indexes++;
                j=lps[n-1];
            }
        }
        return indexes;
    }

private:

    string pattern;
    vector<int> lps;
    int n;

    void build_lps()
    {
        string s=pattern;
        for(int i=1; i<n; i++)
        {
            int j= lps[i-1];
            while( j>0 && s[j]!=s[i]) j=lps[j-1];

            if(s[j]==s[i]) lps[i]=j+1;
            else lps[i]=0;
        }
    }


};
