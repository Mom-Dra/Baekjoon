#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class MyStack
{
private:
    T* data;
    int _top;
    int capacity;

public:
    MyStack(int capacity){
        data = new T[capacity];
        this->capacity = capacity;
        _top = -1;
    }

    MyStack(){
        data = nullptr;
        capacity = 0;
        _top = -1;
    }

    ~MyStack(){
        if(data) delete[] data;
    }

    void push(const T item){
        if(!data) {
            data  = new T[10];
            capacity = 10;
        }

        if(_top + 1 == capacity){

            T* newData = new T[capacity * 2];

            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            capacity *= 2;
        }

        data[_top + 1] = item;
        _top++;
    }

    void pop(){
        if(_top >= 0)
            --_top;
    }
    int size(){return _top + 1;}
    bool empty(){return (_top + 1) == 0;}
    int top(){
        if(_top == -1) return -1;

        return data[_top];
    }
};


int main(){

    MyStack<int> st;

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::string tmp;
        std::cin >> tmp;

        if(tmp == ("push")){
            int tmp;
            std::cin >> tmp;
            st.push(tmp);
        }
        else if(tmp == ("pop")){
            int tmp;
            tmp = st.top();
            st.pop();

            std::cout << tmp << '\n';
        }
        else if(tmp == ("size")){
            std::cout << st.size() << '\n';
        }
        else if(tmp == ("empty")){
            std::cout << st.empty() << '\n';
        }
        else if(tmp == ("top")){
            std::cout << st.top() << '\n';
        }
    }


    return 0;
}