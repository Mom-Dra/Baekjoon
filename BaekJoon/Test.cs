using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class Test : Solution
    {
        public override void Solve()
        {
            int[] arr = new int[] { 1, 2, 3 };

            ArrayTest(ref arr);

            foreach(int i in arr)
            {
                Console.WriteLine(i);
            }
        }

        private void StringBuilderTest()
        {
            StringBuilder sb = new StringBuilder();
            string[] data;

            int maxCase = int.Parse(Console.ReadLine());

            for (int i = 0; i < maxCase; ++i)
            {
                data = Console.ReadLine().Split();
                sb.Append(int.Parse(data[0] + int.Parse(data[1]) + '\n'));
            }

            Console.WriteLine(sb);
        }

        private void ArrayTest(ref int[] arr)
        {
            arr = arr.Reverse().ToArray();
        }
    }
}
