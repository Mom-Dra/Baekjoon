using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11403 : Solution
    {
        public override void Solve()
        {
            int N;

            N = int.Parse(Console.ReadLine());

            int[,] arr = new int[N, N];

            for(int i = 0; i < N; ++i)
            {
                string readLine = Console.ReadLine();
                int[] tmp = readLine.Split(' ').Select(x => int.Parse(x)).ToArray();

                for(int j = 0; j < N; ++j)
                {
                    arr[i, j] = tmp[j];
                }
            }

            for(int k = 0; k < N; ++k)
            {
                for(int i = 0; i < N; ++i)
                {
                    for(int j = 0; j < N; ++j)
                    {
                        if (arr[i, k] == 1 && arr[k, j] == 1)
                        {
                            arr[i, j] = 1;
                        }
                    }
                }
            }

            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    Console.Write($"{arr[i, j]} ");
                }
                Console.WriteLine();
            }
        }
    }
}
