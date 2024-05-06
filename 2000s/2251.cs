using System;
class BOJ2251 {
    static bool[,,] chk = new bool[201,201,201];
    static bool[] cchk = new bool[201];
    static int asz, bsz, csz;
    
    internal static int max(int a, int b) {
        return a > b ? a : b;
    }
    internal static int min(int a, int b) {
        return a > b ? b : a;
    }
    
    static void pour(int a, int b, int c) {
        if(chk[a,b,c]) return;
        chk[a,b,c] = true;
        if(a == 0 && !cchk[c]) cchk[c] = true;
        
        int aava = asz - a;
        int bava = bsz - b;
        int cava = csz - c;
        pour(max(0, a - bava), b + min(a, bava), c); // a b
        pour(max(0, a - cava), b, c + min(a, cava)); // a c
        pour(a + min(b, aava), max(0, b - aava), c); // b a
        pour(a, max(0, b - cava), c + min(b, cava)); // b c
        pour(a + min(c, aava), b, max(0, c - aava)); // c a
        pour(a, b + min(c, bava), max(0, c - bava)); // c b
    }
    
    static void Main() {
        int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        asz = line[0];
        bsz = line[1];
        csz = line[2];
        
        pour(0, 0, csz);
        for(int i=0 ; i<=csz ; i++) {
            if(cchk[i]) Console.Write(i + " ");
        }
    }
}
