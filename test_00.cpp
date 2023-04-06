#include <bits/stdc++.h>
using namespace std;

class B;

class A
{
public:
    A() {cout << "A()" << endl;}
    ~A() {cout << "~A()" << endl;}
//    shared_ptr<B> _ptrb; // 强智能指针交叉引用的问题
    void method()
    {
        cout << "A 的方法！" << endl;
    }
    weak_ptr<B> _ptrb;
};

class B
{
public:
    B() {cout << "B()" << endl;}
    ~B() { cout << "~B()" << endl;}
//    shared_ptr<A> _ptra;
    void method()
    {
        shared_ptr<A> ps = _ptra.lock();
        if(ps != nullptr)
        {
            ps->method();
        }
        else
        {
            cout << "A资源不存在" << endl;
        }
    }

    weak_ptr<A> _ptra;
};

int main()
{
    shared_ptr<B> pb(new B());
    {
        shared_ptr<A> pa(new A());
        pa->_ptrb = pb;
        pb->_ptra = pa;

        cout << pa.use_count() << endl;
        cout << pb.use_count() << endl;
    }
    pb->method();

    return  0;
}
