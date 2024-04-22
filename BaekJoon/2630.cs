using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2630 : Solution
    {
        public override void Solve()
        {
            int N;

            string readLine =  Console.ReadLine();
            N = int.Parse(readLine);

            int[,] arr = new int[N, N];

            for(int i = 0; i < N; ++i)
            {
                string line = Console.ReadLine();
                string[] splited = line.Split();

                for(int j = 0; j < N; ++j)
                {
                    arr[i, j] = int.Parse(splited[j]);
                }
            }

            int blueCount = 0;
            int whiteCount = 0;

            Cut(arr, 0, 0, N, ref blueCount, ref whiteCount);

            Console.WriteLine(whiteCount);
            Console.WriteLine(blueCount);
        }

        private void Cut(int[,] arr, int i, int j, int N, ref int blueCount, ref int whiteCount)
        {
            //Console.WriteLine($"i: {i}, j: {j}, N: {N}");

            if (N == 1)
            {
                if(arr[i, j] == 1)
                {
                    ++blueCount;
                }
                else
                {
                    ++whiteCount;
                }

                return;
            }

            bool isblue = true;
            bool isWhite = true;
            
            for(int a = i; a < i + N; ++a)
            {
                for(int b = j; b < j + N; ++b)
                {
                    if (arr[a, b] == 0)
                    { 
                        isblue = false;
                        //Console.WriteLine($"not Blue! i: {a}, j: {b}");
                        break;
                    }
                }

                if (!isblue) break;
            }

            for(int a = i; a < i + N; ++a)
            {
                for(int b = j; b < j + N; ++b)
                {
                    if (arr[a, b] == 1)
                    {
                        isWhite = false;
                        break;
                    }
                }

                if (!isWhite) break;
            }

            if (isblue)
            {
                ++blueCount;
                //Console.WriteLine("blue wmdrk");
            }
            else if (isWhite)
            {
                ++whiteCount;
            }
            else
            {
                int half = N / 2;

                Cut(arr, i, j, half, ref blueCount, ref whiteCount);
                Cut(arr, i + half, j, half, ref blueCount, ref whiteCount);
                Cut(arr, i, j + half, half, ref blueCount, ref whiteCount);
                Cut(arr, i + half, j + half, half, ref blueCount, ref whiteCount);
            }
        }
    }
}
