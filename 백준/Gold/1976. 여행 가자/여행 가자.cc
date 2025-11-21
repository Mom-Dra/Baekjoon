#include <iostream>
#include <vector>

class UnionFind
{
private:
	std::vector<int> parent;

public:
	explicit UnionFind(int n) : parent(n + 1, -1)
	{

	}

	int find(int x)
	{
		if (parent[x] < 0)
			return x;

		return parent[x] = find(parent[x]);
	}

	bool merge(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (x == y)
			return false;

		if (parent[y] < parent[x])
			std::swap(x, y);
		else if (parent[x] == parent[y])
			--parent[x];

		parent[y] = x;

		return true;
	}

	bool isConnected(int x, int y)
	{
		return find(x) == find(y);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	int M;

	std::cin >> N >> M;

	UnionFind unionFind{ N };

	for (int i{ 0 }; i < N; ++i)
	{
		for (int j{ 0 }; j < N; ++j)
		{
			bool b;
			std::cin >> b;

			if (b) unionFind.merge(i + 1, j + 1);
		}
	}

	int n;
	int parent;
	bool isSuccess{ true };

	std::cin >> n;
	parent = unionFind.find(n);

	for (int i{ 0 }; i < M - 1; ++i)
	{
		std::cin >> n;

		if (parent != unionFind.find(n))
		{
			isSuccess = false;
			break;
		}
	}

	std::cout << (isSuccess ? "YES" : "NO");

	return 0;
}