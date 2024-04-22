using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1463 : Solution
    {
        public override void Solve()
        {
            int minCount = int.MaxValue;
            int val;

            string readLine = Console.ReadLine();
            val = int.Parse(readLine);

            int[] memo = new int[val + 1];
            for (int i = 0; i < memo.Length; ++i)
            {
                memo[i] = int.MaxValue;
            }

            Foo(val, memo, ref minCount, 0);
            Console.WriteLine(minCount);
        }

        private void Foo(int val, int[] memo , ref int minCount, int currCount)
        {
            if (memo[val] < currCount)
            {
                return;
            }

            memo[val] = currCount;

            if(val == 1)
            {
                minCount = currCount < minCount ? currCount : minCount;
                return;
            }

            // 3으로 나눈다
            if(val % 3 == 0)
            {
                Foo(val / 3, memo, ref minCount, currCount + 1);
            }

            // 2로 나눈다
            if(val % 2 == 0)
            {
                Foo(val / 2, memo, ref minCount, currCount + 1);
            }

            // 1을 뺀다
            Foo(val - 1, memo, ref minCount, currCount + 1);
        }
    }
}
