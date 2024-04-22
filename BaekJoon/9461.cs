using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _9461 : Solution
    {
        public override void Solve()
        {
            int T;

            string readLine = Console.ReadLine();
            T = int.Parse(readLine);

            long[] dp = new long[101];

            dp[1] = 1;
            dp[2] = 1;
            dp[3] = 1;
            dp[4] = 2;
            dp[5] = 2;

            for(int i = 6; i <= 100; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 5];
            }

            for(int i = 0; i < T; ++i)
            {
                int n;
                string line = Console.ReadLine();
                n = int.Parse(line);

                Console.WriteLine(dp[n]);
            }
        }
    }
}
