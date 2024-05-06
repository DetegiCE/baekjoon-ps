using System;
class BOJ7584 {
    static bool isOne(int[,] b, int val) {
        if(b[0,0] == b[0,1] && b[0,1] == b[0,2] && b[0,2] == val) return true;
        if(b[1,0] == b[1,1] && b[1,1] == b[1,2] && b[1,2] == val) return true;
        if(b[2,0] == b[2,1] && b[2,1] == b[2,2] && b[2,2] == val) return true;
        if(b[0,0] == b[1,0] && b[1,0] == b[2,0] && b[2,0] == val) return true;
        if(b[0,1] == b[1,1] && b[1,1] == b[2,1] && b[2,1] == val) return true;
        if(b[0,2] == b[1,2] && b[1,2] == b[2,2] && b[2,2] == val) return true;
        if(b[0,0] == b[1,1] && b[1,1] == b[2,2] && b[2,2] == val) return true;
        if(b[0,2] == b[1,1] && b[1,1] == b[2,0] && b[2,0] == val) return true;
        return false;
    }
    static void Main() {
        while(true) {
            string s = Console.ReadLine();
            if(s == "#") break;
            string[] p = s.Split(' ');
            int[,] board = new int[3,3];
            int start = 1; // O 1 X 2
            if(p[0] == "X") start = 2;
            
            bool flg = false;
            for(int i=1 ; i<p.Length ; i++) {
                int pos = int.Parse(p[i]);
                board[(pos-1)/3, (pos-1)%3] = start;
                start = 3 - start;
                if(isOne(board, 1)) {
                    flg = true;
                    Console.WriteLine("O");
                    break;
                }
                if(isOne(board, 2)) {
                    flg = true;
                    Console.WriteLine("X");
                    break;
                }
            }
            if(!flg) {
                Console.WriteLine("Draw");
            }
        }
    }
}
