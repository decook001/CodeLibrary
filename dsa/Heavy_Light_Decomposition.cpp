struct HLD 
{

    int n;
    VIN siz, top, dep, parent, in, out, seq;
    VVI adj;
    int cur;
    
    HLD() {}
    HLD(int n) 
	{
        this->n = n;
        siz=VIN(n+1);
        top=VIN (n+1);
        dep=VIN (n+1);
        parent=VIN (n+1);
        in=VIN(n+1);
        out=VIN (n+1);
        seq=VIN (n+1);
        cur = 0;
        adj= VVI (n+1);
    }

    void addEdge(int u, int v) 
	{
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void go(int root = 0) 
	{
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }

    void dfs1(int u) 
	{
        if (parent[u] != -1) 
		{
            adj[u].erase(find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        siz[u] = 1;
        for (auto &v : adj[u]) 
		{
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) 
			{
                swap(v, adj[u][0]);
            }
        }
    }

    void dfs2(int u) 
	{
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) 
		{
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }

    int lca(int u, int v) 
	{
        while (top[u] != top[v]) 
		{
            if (dep[top[u]] > dep[top[v]]) u = parent[top[u]];
			else v = parent[top[v]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) 
	{
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jumpupper(int u, int dupper) 
	{
        if (dep[u] < dupper) return -1;
        int dis = dep[u] - dupper;
        while (dep[top[u]] > dis) u = parent[top[u]];
        return seq[in[u] - dep[u] + dis];
    }
    
    bool isAncester(int anc, int desc) 
	{
        return in[anc] <= in[desc] && in[desc] < out[anc];
    }
    
    int rootedParent(int u, int v) 
	{
        if (u == v) return u;
        if (!isAncester(u, v)) return parent[u];
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, 
		[&](int x, int y) { return in[x] < in[y]; }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) 
	{
        if (u == v) return n;
        if (!isAncester(v, u)) return siz[v];
        return n - siz[rootedParent(v, u)];
    }
    
    int rootedLca(int a, int b, int c) 
	{
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};
