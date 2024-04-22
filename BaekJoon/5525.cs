using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _5525 : Solution
    {
        public override void Solve()
        {
            int N;
            int M;
            string s;

            N = int.Parse(Console.ReadLine());

            M = int.Parse(Console.ReadLine());

            s = Console.ReadLine();

            int count = default;
            int subCount = default;

            for(int i = 0; i < M - 2; ++i)
            {
                //Console.WriteLine($"i: {i}, {s.Substring(i, 3)}");

                if (s.Substring(i, 3).Equals("IOI"))
                {
                    ++subCount;
                    ++i;

                    if(subCount == N)
                    {
                        ++count;
                        --subCount;
                    }
                }
                else
                {
                    subCount = 0;
                }
            }

            Console.WriteLine(count);
        }
    }
}
