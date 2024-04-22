using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class Program2
    {
        static long[] memo = new long[501];

        public static void Main()
        {
            int num;
            num = Convert.ToInt32(Console.ReadLine());

            int twoCount = 0;
            int fiveCount = 0;

            for(int i = 1; i <= num; ++i)
            {
                int div = i;

                while(div != 0)
                {
                    if (div % 5 == 0)
                    {
                        ++fiveCount;
                        div /= 5;
                    }
                    else break;
                }
            }

            Console.WriteLine("fac: " + Factorial(num));
            Console.WriteLine(fiveCount);
        }

        public static long Factorial(int num)
        {
            if(num == 0) return 1;
            else if(num == 1) return 1;

            //if (memo[num] != 0) return memo[num];


            return memo[num] = num * Factorial(num - 1);
        }
    }
}
