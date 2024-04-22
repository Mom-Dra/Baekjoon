using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    class _6064 : Solution
    {
        public override void Solve()
        {
            int T;
            T = int.Parse(Console.ReadLine());

            for(int i = 0; i < T; ++i)
            {
                string readLine = Console.ReadLine();
                int[] arr = readLine.Split(' ').Select(x => int.Parse(x)).ToArray();

                // M, N, X, Y
                int M = arr[0];
                int N = arr[1];
                int X = arr[2];
                int Y = arr[3];

                int x = 1;
                int y = 1;

                int year = 1;

                while(!(x == X && y == Y))
                {
                    x = x == M ? 1 : x + 1;
                    y = y == N ? 1 : y + 1;
                }

                Console.WriteLine(year);
            }
        }
    }
}
