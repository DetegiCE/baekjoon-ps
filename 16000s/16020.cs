
using System;
class BOJ16020 {
    static int[,] rotate(int[,] a, int num) {
        int[,] ret = new int[num, num];
        int origi = 0;
        int origj = num-1;
        for(int i=0 ; i<num ; i++) {
            for(int j=0 ; j<num ; j++) {
                ret[i, j] = a[origi, origj];
                origi++;
            }
            origj--;
            origi = 0;
        }
        return ret;
    }
    
    static void Main() {
        int num = int.Parse(Console.ReadLine());
        int[,] a = new int[num, num];
        for(int i=0 ; i<num ; i++) {
            int[] v = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            for(int j=0 ; j<num ; j++) {
                a[i,j] = v[j];
            }
        }
        
        int flg = 0;
        for(int i=0 ; i<num ; i++) {
            int tflg = 0;
            for(int j=0 ; j<num-1 ; j++) {
                if(a[i,j] < a[i,j+1]) tflg++;
            }
            for(int j=0 ; j<num-1 ; j++) {
                if(a[j,i] < a[j+1,i]) tflg++;
            }
            if(tflg == 2*num-2) flg++;
        }
        if(flg == num) {
            for(int i=0 ; i<num ; i++) {
                for(int j=0 ; j<num ; j++) {
                    Console.Write($"{a[i,j]} ");
                }
                Console.WriteLine();
            }
            return;
        }
        a = rotate(a, num);
        
        flg = 0;
        for(int i=0 ; i<num ; i++) {
            int tflg = 0;
            for(int j=0 ; j<num-1 ; j++) {
                if(a[i,j] < a[i,j+1]) tflg++;
            }
            for(int j=0 ; j<num-1 ; j++) {
                if(a[j,i] < a[j+1,i]) tflg++;
            }
            if(tflg == 2*num-2) flg++;
        }
        if(flg == num) {
            for(int i=0 ; i<num ; i++) {
                for(int j=0 ; j<num ; j++) {
                    Console.Write($"{a[i,j]} ");
                }
                Console.WriteLine();
            }
            return;
        }
        a = rotate(a, num);
        
        flg = 0;
        for(int i=0 ; i<num ; i++) {
            int tflg = 0;
            for(int j=0 ; j<num-1 ; j++) {
                if(a[i,j] < a[i,j+1]) tflg++;
            }
            for(int j=0 ; j<num-1 ; j++) {
                if(a[j,i] < a[j+1,i]) tflg++;
            }
            if(tflg == 2*num-2) flg++;
        }
        if(flg == num) {
            for(int i=0 ; i<num ; i++) {
                for(int j=0 ; j<num ; j++) {
                    Console.Write($"{a[i,j]} ");
                }
                Console.WriteLine();
            }
            return;
        }
        a = rotate(a, num);
        
        flg = 0;
        for(int i=0 ; i<num ; i++) {
            int tflg = 0;
            for(int j=0 ; j<num-1 ; j++) {
                if(a[i,j] < a[i,j+1]) tflg++;
            }
            for(int j=0 ; j<num-1 ; j++) {
                if(a[j,i] < a[j+1,i]) tflg++;
            }
            if(tflg == 2*num-2) flg++;
        }
        if(flg == num) {
            for(int i=0 ; i<num ; i++) {
                for(int j=0 ; j<num ; j++) {
                    Console.Write($"{a[i,j]} ");
                }
                Console.WriteLine();
            }
            return;
        }
        a = rotate(a, num);
    }
}
