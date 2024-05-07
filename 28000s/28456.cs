
using System;
class BOJ28456 {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        int[,] a = new int[n,n];
        for(int i=0 ; i<n ; i++) {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            for(int j=0 ; j<n ; j++)
                a[i,j] = line[j];
        }
        int q = int.Parse(Console.ReadLine());
        for(int t=0 ; t<q ; t++) {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            if(line[0] == 1) {
                int tmp = a[line[1]-1,n-1];
                for(int i=n-2 ; i>=0 ; i--) 
                    a[line[1]-1,i+1] = a[line[1]-1,i];
                a[line[1]-1,0] = tmp;
            }
            else {
                int[,] b = new int[n,n];
                for(int i=0 ; i<n ; i++) {
                    for(int j=0 ; j<n ; j++) {
                        b[j,n-i-1] = a[i,j];
                    }
                }
                for(int i=0 ; i<n ; i++) {
                    for(int j=0 ; j<n ; j++) {
                        a[i,j] = b[i,j];
                    }
                }
            }
        }
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                Console.Write(a[i,j] + " ");
            }
            Console.WriteLine();
        }
    }
}
