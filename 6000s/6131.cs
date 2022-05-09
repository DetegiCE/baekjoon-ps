using System;

namespace ConsoleApplication1
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int count = 0;
            for (int i = 1; i <= 1001; i++)
            {
                for (int j = i + 1; j <= 1002; j++)
                {
                    if (i * i + n == j * j)
                    {
                        count++;
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}