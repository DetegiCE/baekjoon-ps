using System;
class BOJ18691 {
    static void Main() {
        int t = int.Parse(Console.ReadLine());
        for(int tc=0 ; tc<t ; tc++) {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int g = line[0];
            int c = line[1];
            int e = line[2];
            if(c >= e) Console.WriteLine(0);
            else {
                if(g == 1) Console.WriteLine(e - c);
                else if(g == 2) Console.WriteLine((e-c)*3);
                else Console.WriteLine((e-c)*5);
            }
        }
    }
}
