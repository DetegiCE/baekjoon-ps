using System;
class BOJ11762 {
    static void Main() {
        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        for(int i=0 ; i<4 ; i++) {
            for(int j=i+1 ; j<5 ; j++) {
                for(int k=j+1 ; k<6 ; k++) {
                    if(a[i] + a[j] + a[k] == a[6]) {
                        int[] one = {a[i], a[j], a[k]};
                        int[] two = new int[3];
                        int tpos = 0;
                        for(int l=0 ; l<6 ; l++) {
                            if(l != i && l != j && l != k) {
                                two[tpos++] = a[l];
                            }
                        }
                        Array.Sort(one);
                        Array.Sort(two);
                        for(int l=2 ; l>=0 ; l--) 
                            Console.Write(one[l] + " ");
                        for(int l=2 ; l>=0 ; l--) 
                            Console.Write(two[l] + " ");
                        return;
                    }
                }
            }
        }
    }
}
