using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11050 : Solution
    {
        public override void Solve()
        {
            int n;
            int k;

            string readline = Console.ReadLine();
            string[] splited = readline.Split();

            n = int.Parse(splited[0]);
            k = int.Parse(splited[1]);

            Console.WriteLine(Factorial(n) / (Factorial(n - k) * (Factorial(k))));
        }

        private int Factorial(int n)
        {
            if (n == 0) return 1;

            return n * Factorial(n - 1);
        }
    }
}
