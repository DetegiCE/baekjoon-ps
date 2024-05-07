
using System;
class BOJ29736 {
    static void Main() {
        int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int a = line[0];
        int b = line[1];
        line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int k = line[0];
        int x = line[1];
        int cnt = 0;
        for(int i=k-x ; i<=k+x ; i++) {
            if(a <= i && i <= b) cnt++;
        }
        if(cnt == 0) Console.WriteLine("IMPOSSIBLE");
        else Console.WriteLine(cnt);
    }
}
