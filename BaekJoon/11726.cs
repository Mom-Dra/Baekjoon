using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11726 : Solution
    {
        public override void Solve()
        {
            int N;

            string readLine = Console.ReadLine();

            N = int.Parse(readLine);

            int[] dp = new int[1001];

            dp[1] = 1;
            dp[2] = 2;

            for(int i = 3; i <= N; ++i)
            {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
            }

            Console.WriteLine(dp[N]);
        }
    }
}
