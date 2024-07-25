#include <iostream>
#include <stack>
#include <vector>

int main(){
    std::stack<int> st;
    std::vector<int> vec;
    std::vector<char> ans;

    int n;

    std::cin >> n;

    vec.reserve(n);

    for(int i = 0; i < n; i++){
        int tmp;
        std::cin >> tmp;
        vec.push_back(tmp);
    }

    int index = 0;
    int i = 1;

    while(index < n){
        if(st.empty() || i < vec[index]){
            st.push(i);
            ++i;

            ans.push_back('+');
        }
        else if(st.top() < vec[index]){
            st.push(i);
            ++i;

            ans.push_back('+');
        }
        else if(st.top() == vec[index]){
            st.pop();
            ++index;

            ans.push_back('-');
        }
        else{
            std::cout << "NO";
            return 0;
        }
    }

    for(std::vector<char>::iterator iter = ans.begin(); iter != ans.end(); ++iter){
        std::cout << *iter << '\n';
    }
    

    return 0;
}