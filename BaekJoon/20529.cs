using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _20529 : Solution
    {
        public override void Solve()
        {
            // 세 사람 사이의 심리적인 거리를 정의한다
            // A와 B 사이의 심리적인 거리 + B와 C 사이의 심리적인 거리
            // + A와 C 사이의 심리적인 거리

            // 두사람의 심리적인 거리를 구하는 함수를 만든다
            // NC3 3명을 뽑을 수 있는 모든 경우의 수를 구한다
            // 거기서 점수가 가장 적은 사람을 구한다

            int T;

            T = int.Parse(Console.ReadLine());

            for (int i = 0; i < T; ++i)
            {
                int N = default;
                N = int.Parse(Console.ReadLine());

                string line = Console.ReadLine();
                string[] mbties = line.Split(' ');
                int length = mbties.Length;

                if (N > 32)
                {
                    Console.WriteLine(0);
                    continue;
                }

                int min = int.MaxValue;

                for (int j = 0; j < length - 2; ++j)
                {
                    for (int k = j + 1; k < length - 1; ++k)
                    {
                        for (int l = k + 1; l < length; ++l)
                        {
                            int sum = default;
                            sum += Calculate(mbties[j], mbties[k]);
                            sum += Calculate(mbties[k], mbties[l]);
                            sum += Calculate(mbties[l], mbties[j]);

                            if (sum < min) min = sum;
                        }
                    }
                }

                Console.WriteLine(min);
            }
        }

        private int Calculate(string s1, string s2)
        {
            int score = default;

            for (int i = 0; i < 4; ++i)
            {
                if (s1[i] != s2[i])
                    ++score;
            }
            
            return score;
        }
    }
}
