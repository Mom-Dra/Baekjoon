using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1003 : Solution
    {
        private class Count
        {
            public int zeroCount;
            public int oneCount;

            public Count(int zeroCount, int oneCount)
            {
                this.zeroCount = zeroCount;
                this.oneCount = oneCount;
            }
        }

        public override void Solve()
        {
            int T;

            string readLine = Console.ReadLine();

            T = int.Parse(readLine);

            Count[] counts = new Count[41];
            counts[0] = new Count(1, 0);
            counts[1] = new Count(0, 1);

            for(int i = 0; i < T; ++i)
            {
                int n;

                string line = Console.ReadLine();
                n = int.Parse(line);

                int zeroCount = 0;
                int oneCount = 0;

                Fibo(n, ref zeroCount, ref oneCount, counts);

                Console.WriteLine($"{zeroCount} {oneCount}");
            }
        }

        private void Fibo(int n, ref int zeroCount, ref int oneCount, Count[] counts)
        {
            if (counts[n] != null)
            {
                zeroCount += counts[n].zeroCount;
                oneCount += counts[n].oneCount;

                return;
            }

            counts[n] = new Count(0, 0);

            Fibo(n - 1, ref counts[n].zeroCount, ref counts[n].oneCount, counts);
            Fibo(n - 2, ref counts[n].zeroCount, ref counts[n].oneCount, counts);

            zeroCount += counts[n].zeroCount;
            oneCount += counts[n].oneCount;   
        }
    }
}
