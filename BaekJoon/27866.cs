using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    internal class _27866 : Solution
    {
        public override void Solve()
        {
            string readLine;
            int i;

            readLine = Console.ReadLine();
            i = int.Parse(Console.ReadLine());

            Console.WriteLine(readLine[i - 1]);
        }
    }
}
