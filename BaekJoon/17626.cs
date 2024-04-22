using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _17626 : Solution
    {
        public override void Solve()
        {
            int N;

            string readLine = Console.ReadLine();
            N = int.Parse(readLine);

            int[] dp = new int[N + 1];

            dp[1] = 1;

            for(int i = 1; i <= N; ++i)
            {
                int minVal = int.MaxValue;

                for(int j = 1; j * j <= i; ++j)
                {
                    int tmp = i - j * j;
                    minVal = Math.Min(minVal, dp[tmp]);
                }

                dp[i] = minVal + 1;
            }

            Console.WriteLine(dp[N]);
        }
    }
}
