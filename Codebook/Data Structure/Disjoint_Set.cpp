struct disjointset { // union by rank
    int f[MAX], rank[MAX];
    void init(int N) {
        memset(rank,0,sizeof(rank));
        for(int i = 0; i <= N; i++) f[i] = i;
    }
    int find(int val) {
        return f[val] == val ? val : f[val] = find(f[val]);
    }
    bool same(int a, int b) { 
        return find(a) == find(b); 
    }
    void Union(int l, int r) {
        if(!same(l, r)) {
            if(rank[l] < rank[r]) swap(l, r);
            f[f[r]] = f[l];
            rank[l]++;
        }
    }
};