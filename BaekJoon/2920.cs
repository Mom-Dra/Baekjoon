using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    internal class _2920 : Solution
    {
        public override void Solve()
        {
            string readLine = Console.ReadLine();

            int[] arr = readLine.Split().Select(int.Parse).ToArray();

            int k = 0;

            for(int i = 1; i < arr.Length; ++i)
            {
                if (arr[i] > arr[i - 1])
                {
                    if(k == 2)
                    {
                        k = 3;
                        break;
                    }

                    k = 1;
                }
                else if (arr[i] < arr[i - 1])
                {
                    if(k == 1)
                    {
                        k = 3;
                        break;
                    }

                    k = 2;
                }
            }

            switch(k)
            {
                case 1:
                    Console.WriteLine("ascending");
                    break;
                case 2:
                    Console.WriteLine("descending");
                    break;
                case 3:
                    Console.WriteLine("mixed");
                    break;
            }
        }
    }
}
