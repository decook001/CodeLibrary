struct Catalan
{
    Catalan(int n)
    {
        this->n=n;
        v.push_back(1);
        v.push_back(1);
        for(int i=1;i<=n;i++)
        {
            v.push_back( v.back()* 2 * (2*i+1)/ (i+2) );
        }
    }
    int n;
    vector<int> v;

};
