#include <iostream>
#include <algorithm>
#include <vector>

void draw(int x, int y, int n, std::vector<std::vector<char> >& vec);

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;

    std::cin >> n;

    std::vector<std::vector<char> > vec(n, std::vector<char>(n, '*'));

    draw(0, 0, n, vec);

    for(std::vector<std::vector<char > >::iterator iter = vec.begin(); iter != vec.end(); ++iter){
        for(std::vector<char>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2){
            std::cout << *iter2;
        }

        std::cout << '\n';
    }

    return 0;
}

void draw(int x, int y, int n, std::vector<std::vector<char> >& vec){

    if(n == 1) return;

    for(int i = x; i < x + n; i += (n / 3)){
        for(int j = y; j < y + n; j += (n / 3)){
            draw(i, j, n / 3, vec);
        }
    }

    for(int i = x + (n / 3); i < x + (n / 3) * 2; ++i){
        for(int j = y + (n / 3); j < y + (n / 3) * 2; ++j){
            vec[i][j] = ' ';
        }
    }
}