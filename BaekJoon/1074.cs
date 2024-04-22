using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1074 : Solution
    {
        public override void Solve()
        {
            int N;
            int r;
            int c;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            r = int.Parse(splited[1]);
            c = int.Parse(splited[2]);

            int count = 0;

            int powed = 1;
            for(int i = 0; i < N; ++i)
            {
                powed *= 2;
            }

            bool solved = false;

            //Foo(powed, r, c, 0, 0, ref count, ref solved);
            Foo2(powed, r, c, 0, 0, ref count);


            Console.WriteLine(count);
        }

        private void Foo(int N, int r, int c, int a, int b, ref int count, ref bool solved)
        {
            if (solved) return;

            if(N == 1)
            {
                if (r == a && c == b)
                {
                    solved = true;
                    return;
                }

                ++count;
                return;
            }

            int divided = N / 2;

            Foo(divided, r, c, a, b, ref count, ref solved);
            Foo(divided, r, c, a, b + divided, ref count, ref solved);
            Foo(divided, r, c, a + divided, b, ref count, ref solved);  
            Foo(divided, r, c, a + divided, b + divided, ref count, ref solved);
        }

        private void Foo2(int N, int r, int c, int a, int b, ref int count)
        {
            //Console.WriteLine($"N: {N}, a: {a}, b: {b}");

            if (r == a && c == b)
            { 
                return;
            }

            // 1, 2, 3, 4 사분면 어딘지 판별할 것
            // 판별하면 count 증가 할 것

            int half = N / 2;
            int quater = half * half;

            if (r < half + a && c < half + b)
            {
                // 1 사분면
                //Console.WriteLine("1 gogo");
                Foo2(half, r, c, a, b, ref count);
            }
            else if (r < half + a && c >= half + b)
            {
                // 2 사분면
                //Console.WriteLine("2 gogo");
                count += quater;
                Foo2(half, r, c, a, b + half, ref count);
            }
            else if (r >= half + a && c < half + b)
            {
                // 3 사분면
                //Console.WriteLine("3 gogo");
                count += quater;
                count += quater;
                Foo2(half, r, c, a + half, b, ref count);
            }
            else if (r >= half + a && c >= half + b)
            {
                // 4 사분면
                //Console.WriteLine("4 gogo");
                count += quater;
                count += quater;
                count += quater;
                Foo2(half, r, c, a + half, b + half, ref count);
            }

            // 판별한 곳에서 다시 재귀할 것
        }
    }
}
