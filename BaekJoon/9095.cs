using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _9095 : Solution
    {
        public override void Solve()
        {
            int T;

            string readLine = Console.ReadLine();

            T = int.Parse(readLine);

            int[] dp = new int[12];

            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 4;

            for(int i = 0; i < T; ++i)
            {
                int n;
                string line = Console.ReadLine();
                n = int.Parse(line);

                if(n <= 3)
                {
                    Console.WriteLine(dp[n]);
                }
                else
                {
                    for(int j = 4; j <= n; ++j)
                    {
                        dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
                    }
                    Console.WriteLine(dp[n]);
                }
            }
        }
    }
}
