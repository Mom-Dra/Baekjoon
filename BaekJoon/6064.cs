using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
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

                Console.WriteLine(Calculate(M, N, X, Y));
            }
        }

        private int Calculate(int M, int N, int X, int Y)
        {
            int year = X;

            while(year <= M * N)
            {
                if ((year - X) % M == 0 && (year - Y) % N == 0)
                    return year;

                year += M;
            }

            return -1;
        }

        // 시간 초과되는 함수
        private int Find(int X, int Y, int M, int N)
        {
            int x = 1;
            int y = 1;
            int year = 1;

            while (true)
            {
                if (x == X && y == Y) return year;

                x = x == M ? 1 : x + 1;
                y = y == N ? 1 : y + 1;
                ++year;

                if (x == 1 && y == 1) return -1;
            }
        }
    }
}
