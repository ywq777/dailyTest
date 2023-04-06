#include <bits/stdc++.h>
using namespace std;
// 容器里面元素的类型
class A
{
public:
    // 带左值引用参数的赋值函数
    A& operator=(const A &src)
    {
        cout << "operator=" << endl;
        return *this;
    }
    // 带右值引用参数的赋值函数
    A& operator=(A &&src) noexcept
    {
        cout << "operator=(A&&)" << endl;
        return *this;
    }
};

// 容器的类型
template<typename Ty>
class Vector
{
public:
    // 引用左值的push_back函数
    void push_back(const Ty &val)
    {
        cout << " 1" << endl;
        mvec[mcur++] = val;
    }
    // 引用右值的push_back函数
    void push_back(Ty &&val)
    {
        // 这里传递val时，要用move转换成右值引用类型，
        // 因为val本身是左值，有名字有地址，见前面引用折叠部分的说明
        cout << " 2" << endl;
        mvec[mcur++] = std::forward<Ty>(val);
    }
private:
    enum { VEC_SIZE = 10 };
    Ty mvec[VEC_SIZE];
    int mcur;

};

int main()
{
    Vector<A> vec{};
    A a;
    vec.push_back(a); // 调用A的左值引用的赋值函数
    vec.push_back(A()); // 理应调用A的右值引用参数的赋值函数，却调用了左值引用的赋值函数
    return 0;
}
