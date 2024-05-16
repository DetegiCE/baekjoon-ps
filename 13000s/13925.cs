using System;
class BOJ13925 {
    static long[] arr;
    static long[] tree;
    static long[,] lazy;
    static long MOD = 1000000007;
    
    static long init(int pos, int s, int e) {
        if(s == e) {
            return tree[pos] = arr[s];
        }
        int m = (s + e) / 2;
        return tree[pos] = (init(pos*2, s, m) + init(pos*2+1, m+1, e)) % MOD;
    }
    
    static void lazy_update(int pos, int s, int e) {
        if(lazy[pos, 0] == 1 && lazy[pos, 1] == 0) return;
        if(s != e) {
            lazy[pos*2, 0] = (lazy[pos, 0] * lazy[pos*2, 0]) % MOD;
            lazy[pos*2, 1] = (lazy[pos, 0] * lazy[pos*2, 1] + lazy[pos, 1]) % MOD;
            lazy[pos*2+1, 0] = (lazy[pos, 0] * lazy[pos*2+1, 0]) % MOD;
            lazy[pos*2+1, 1] = (lazy[pos, 0] * lazy[pos*2+1, 1] + lazy[pos, 1]) % MOD;
        }
        tree[pos] = (lazy[pos, 0] * tree[pos] + (e - s + 1) * lazy[pos, 1]) % MOD;
        lazy[pos, 0] = 1;
        lazy[pos, 1] = 0;
    }
    
    static void update(int pos, int s, int e, long l, long r, long mul, long sum) {
        lazy_update(pos, s, e);
        if(r < s || l > e) return;
        if(l <= s && e <= r) {
            lazy[pos, 0] = (lazy[pos, 0] * mul) % MOD;
            lazy[pos, 1] = (lazy[pos, 1] * mul) % MOD;
            lazy[pos, 1] = (lazy[pos, 1] + sum) % MOD;
            lazy_update(pos, s, e);
            return;
        }
        
        int m = (s + e) / 2;
        update(pos*2, s, m, l, r, mul, sum);
        update(pos*2+1, m+1, e, l, r, mul, sum);
        tree[pos] = (tree[pos*2] + tree[pos*2+1]) % MOD;
    }
    
    static long query(int pos, int s, int e, long l, long r) {
        lazy_update(pos, s, e);
        if(r < s || l > e) return 0;
        if(l <= s && e <= r) return tree[pos] % MOD;
        int m = (s + e) / 2;
        return (query(pos*2, s, m, l, r) + query(pos*2+1, m+1, e, l, r)) % MOD;
    }
    
    static void Main() {
        arr = new long[110000];
        tree = new long[440000];
        lazy = new long[440000,2];
        
        int N = int.Parse(Console.ReadLine());
        long[] line = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
        for(int i=1 ; i<=N ; i++) {
            arr[i] = line[i-1];
        }
        init(1, 1, N);
        for(int i=0 ; i<440000 ; i++) {
            lazy[i, 0] = 1;
            lazy[i, 1] = 0;
        }
        
        int M = int.Parse(Console.ReadLine());
        for(int i=0 ; i<M ; i++) {
            line = Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
            if(line[0] == 1) update(1, 1, N, line[1], line[2], 1, line[3]);
            else if(line[0] == 2) update(1, 1, N, line[1], line[2], line[3], 0);
            else if(line[0] == 3) update(1, 1, N, line[1], line[2], 0, line[3]);
            else Console.WriteLine(query(1, 1, N, line[1], line[2]));
        }
    }
}
