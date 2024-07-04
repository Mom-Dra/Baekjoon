#pragma once

#include "Solution.h"
#include <iostream>
#include <queue>
#include <string>

class _9019 : public Solution
{
	void Solve() override
	{
		std::ios_base::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);

		// D S L R �� �̿��ϴ� ������ ���Ⱑ �ִ�
		// �������Ϳ��� 0 �̻� 10,000 �̸��� �������� ������ �� �ִ�
		
		int T;
		std::cin >> T;

		for (int i = 0; i < T; ++i)
		{
			//std::cout << "�Է��̿�\n";
			int A, B;
			std::cin >> A >> B;

			// A���� B�� ��ȯ�ϱ� ���� �ʿ��� �ּ����� ��ɾ� ������ ����Ѵ�

			std::queue<std::pair<int, std::string>> q;
			q.push(std::make_pair(A, ""));
			
			bool visited[10000] = {};
			visited[A] = true;

			while (!q.empty())
			{
				//std::cout << "~ing\n";

				std::pair<int, std::string> front = q.front();
				q.pop();

				int currN = front.first;
				std::string op = front.second;

				if (currN == B)
				{
					//std::cout << "����̿�\n";
					std::cout << op << '\n';
					break;
				}

				// D
				int D, S, L, R;
				D = currN * 2 > 9999 ? currN * 2 % 10000 : currN * 2;
				if (!visited[D])
				{
					q.push(std::make_pair(D, op + "D"));
					visited[D] = true;
				}

				S = currN == 0 ? 9999 : currN - 1;
				if (!visited[S])
				{
					q.push(std::make_pair(S, op + "S"));
					visited[S] = true;
				}

				L = (currN % 1000) * 10 + (currN / 1000);
				if (!visited[L])
				{
					q.push(std::make_pair(L, op + "L"));
					visited[L] = true;
				}

				R = (currN % 10) * 1000 + (currN / 10);
				if (!visited[R])
				{
					q.push(std::make_pair(R, op + "R"));
					visited[R] = true;
				}

				//std::cout << "~end\n";
			}
		}
	}
};