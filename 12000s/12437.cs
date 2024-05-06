using System;
class BOJ12437 {
    static void Main() {
        int t = int.Parse(Console.ReadLine());
        for(int tc=1 ; tc<=t ; tc++) {
            int[] line = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int month = line[0];
            int day = line[1];
            int week = line[2];
            
            int count = 0;
            int start = 0;
            for(int i=0 ; i<month ; i++) {
                start += day;
                count += (start + week - 1) / week;
                start %= week;
            }
            Console.Write($"Case #{tc}: {count}\n");
        }
    }
}
