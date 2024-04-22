using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2609 : Solution
    {
        public override void Solve()
        {
            int a, b;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            a = int.Parse(splited[0]);
            b = int.Parse(splited[1]);

            if(a > b)
            {
                int tmp = b;
                b = a;
                a = tmp;
            }

            int min = 1;
            int max = 1;

            for(int i = 2; i <= a; ++i)
            {
                if(a % i == 0 && b % i == 0)
                {
                    max = i;
                }
            }

            min = a * b / max;

            Console.WriteLine(max);
            Console.WriteLine(min);
        }
    }
}
