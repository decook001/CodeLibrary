// prefix sum


struct FenwickTree2D {
    vector<vector<int>> bit; //0-indexed binary indexed tree
    int n, m;
    
    FenwickTree2D(int n, int m)
    {
        this->n=n;
        this->m=m;
        bit=vector< vector<int> > (n, vector<int> (m) );
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};


