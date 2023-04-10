#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
    Data(int v, int m): _v(v), _m(m){}
    int _v;
    int _m;
};

int main()
{
//    vector<int> v = {4, 5, 3};
//    vector<int> m = {2, 3, 4};

    using FUNC = function<bool(Data&, Data&)>;
    priority_queue<Data, vector<Data>, FUNC>
            pque([](Data& d1, Data& d2)->bool
            {
                return float(d1._v)/d1._m > float(d2._v)/d2._m;
            });
    pque.emplace(4, 2);
    pque.emplace(5, 3);
    pque.emplace(3, 4);

    while(!pque.empty())
    {
        cout << pque.top()._v << " " << pque.top()._m << endl;
        pque.pop();
    }



    return 0;
}
