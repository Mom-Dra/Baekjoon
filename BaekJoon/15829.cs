using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _15829 : Solution
    {
        public override void Solve()
        {
            long r = 1;
            int m = 1234567891;

            int l;

            string readline = Console.ReadLine();
            l = int.Parse(readline);

            string str = Console.ReadLine();

            long hash = 0;

            for(int i = 0; i < l; i++)
            {
                int num = str[i] - 'a' + 1;

                hash = hash + ((num * r)) % m;
                r = (r * 31) % m;
            }

            Console.WriteLine(hash % m);
        }
    }
}
