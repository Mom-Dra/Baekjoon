using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2231 : Solution
    {
        public override void Solve()
        {
            int n;

            string readLine = Console.ReadLine();
            n = int.Parse(readLine);

            for(int i = 1; i <= n; i++)
            {
                int curr = i;
                int num = i;

                while(curr != 0)
                {
                    num += curr % 10;
                    curr /= 10;
                }

                if(num == n)
                {
                    Console.WriteLine(i);
                    return;
                }
            }

            Console.WriteLine(0);
        }
    }
}
