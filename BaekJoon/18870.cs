using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _18870 : Solution
    {
        public override void Solve()
        {
            int N;

            string readLine = Console.ReadLine();

            N = int.Parse(readLine);

            int[] arr = new int[N];

            string line = Console.ReadLine();
            string[] splited = line.Split();

            for(int i = 0; i < N; ++i)
            {
                arr[i] = int.Parse(splited[i]);
            }

            int[] arr2 = arr.Distinct().OrderBy(x => x).ToArray();
            Dictionary<int, int> dic = new Dictionary<int, int>();
            
            for(int i = 0; i < arr2.Length; ++i)
            {
                dic.Add(arr2[i], i);
            }

            StringBuilder sb = new StringBuilder();

            for(int i = 0; i < arr.Length; ++i)
            {
                sb.Append($"{dic[arr[i]]} ");
            }

            Console.WriteLine(sb);
        }
    }
}
