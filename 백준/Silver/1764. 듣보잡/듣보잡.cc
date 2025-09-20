#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::unordered_set<std::string> uSet;

    for(int i{0}; i < N; ++i)
    {
        std::string s;
        std::cin >> s;

        uSet.insert(s);
    }

    std::vector<std::string> results;

    for(int i{0}; i < M; ++i)
    {
        std::string s;
        std::cin >> s;

        if(uSet.find(s) != uSet.end())
            results.emplace_back(s);
    }

    std::sort(results.begin(), results.end());

    
    std::cout << results.size() << '\n';
    for(const auto& s : results)
        std::cout << s << '\n';

    return 0;
}