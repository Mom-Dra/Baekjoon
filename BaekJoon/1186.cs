using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Channels;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1186 : Solution
    {
        public override void Solve()
        {
            int N, K;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split(' ');

            N = int.Parse(splited[0]);
            K = int.Parse(splited[1]);

            int[,] rectangles = new int[N, 4];
            int[] areas = new int[N];

            // Input
            for(int i = 0; i < N; ++i)
            {
                string line = Console.ReadLine();
                string[] splitedLine = line.Split();

                for(int j = 0; j < 4; ++j)
                {
                    rectangles[i, j] = int.Parse(splitedLine[j]);
                }
            }

            for(int i = 0; i < N; ++i)
            {
                areas[i] = CalculateArea(i, rectangles);

                for(int j = i + 1; j < N; ++j)
                {
                    areas[i] -= OverlappedArea(i, j, rectangles);
                }
            }

            //for(int i = 0; i < N; ++i)
            //{
            //    Console.WriteLine($"areas[{i}]: {areas[i]}");
            //}

            bool[] answerVisited = new bool[N];
            int maxArea = 0;

            for(int j = 0; j < N; ++j)
            {
                if(N - j >= K)
                {
                    bool[] visited = new bool[N];
                    visited[j] = true;
                    foo(j, areas, visited, K, 0, ref maxArea, answerVisited, N, 1);
                }
            }

            for(int i = 0; i < N; ++i)
            {
                //Console.WriteLine($"answerVisited[{i}]: {answerVisited[i]}");

                if (answerVisited[i])
                    Console.Write($"{i + 1} ");
            }
        }

        private int CalculateArea(int n, int[,] rectangles)
        {
            int width = rectangles[n, 2] - rectangles[n, 0];
            int height = rectangles[n, 3] - rectangles[n, 1];

            return width * height;
        }

        private int OverlappedArea(int i, int j, int[,] rectangles)
        {
            int rec1_x1 = rectangles[i, 0];
            int rec1_x2 = rectangles[i, 2];
            int rec1_y1 = rectangles[i, 1];
            int rec1_y2 = rectangles[i, 3];

            int rec2_x1 = rectangles[j, 0];
            int rec2_x2 = rectangles[j, 2];
            int rec2_y1 = rectangles[j, 1];
            int rec2_y2 = rectangles[j, 3];

            bool a = (rec2_x1 > rec1_x1 && rec2_x1 < rec1_x2);
            bool b = (rec2_x2 > rec1_x1 && rec2_x2 < rec1_x2);

            bool c = (rec2_y1 > rec1_y1 && rec2_y1 < rec1_y2);
            bool d = (rec2_y2 > rec1_y1 && rec2_y2 < rec1_y2);

            if ((a || b) && (c || d))
            {
                int width = 0;
                int height = 0;

                if(a && c)
                {
                    width = rec1_x2 - rec2_x1;
                    height = rec1_y2 - rec2_y1;
                }
                else if(a && d)
                {
                    width = rec1_x2 - rec2_x1;
                    height = rec2_y2 - rec1_y1;
                }
                else if (b && c)
                {
                    width = rec2_x2 - rec1_x1;
                    height = rec1_y2 - rec2_y1;
                }
                else if (b && d)
                {
                    width = rec2_x2 - rec1_x1;
                    height = rec2_y2 - rec2_y1;
                }

                return width * height;
            }

            return 0;
        }

        private void foo(int n, int[] areas, bool[] visited, int k, int area, ref int maxArea, bool[] answerVisited, int N, int count)
        {
            area += areas[n];

            //for (int i = 0; i < N; ++i)
            //{
            //    Console.WriteLine($"n: {n}, count: {count}, visited[{i}]: {visited[i]}");
            //}

            if (count == k)
            {
                //Console.WriteLine($"area: {area}, maxArea: {maxArea}");

                if (area > maxArea)
                { 
                    maxArea = area;
                    Array.Copy(visited, answerVisited, N);
                    //Console.WriteLine($"MaxArea: {maxArea}");
                }

                return;
            }

            for (int i = n + 1; i < N; ++i)
            {
                visited[i] = true;
                foo(i, areas, visited, k, area, ref maxArea, answerVisited, N, count + 1);
                visited[i] = false;
            }
        }
    }
}
