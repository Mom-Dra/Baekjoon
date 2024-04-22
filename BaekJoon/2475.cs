using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2475 : Solution
    {
        public override void Solve()
        {
            // 컴퓨터마다 6자리의 고유번호를 매긴다
            // 00000 - 99999
            // 처음 5자리에 들어가는 5개의 숫자를 각각 제곱한 수의 합을 10으로 나눈 나머지

            string readLine = Console.ReadLine();

            string[] splited = readLine.Split();

            int[] arr = new int[splited.Length];

            for(int i = 0; i < arr.Length; i++)
            {
                arr[i] = int.Parse(splited[i]);
                //Console.WriteLine(arr[i]);
            }


            int sum = 0;
            for(int i = 0; i < arr.Length; ++i)
            {
                sum = sum + arr[i] * arr[i];
            }

            Console.WriteLine(sum % 10);
        }
    }
}
