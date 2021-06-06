#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Counter
{
private:
    int cnt;
    int step_val;
public:
    Counter(): cnt(0), step_val(0)
    {

    }
    void setIncrementStep(int val)
    {
        step_val = val;
    }
    int getCount()
    {
        return cnt;
    }
    void increment()
    {
        cnt+=step_val;
    }
    void resetCount()
    {
        cnt = 0;
    }
};

int main()
{
    Counter c1;
    int val;
    cout<<"Enter step value: ";
    cin>>val;
    c1.setIncrementStep(val);
    c1.increment();
    cout<<c1.getCount()<<"\n";
    c1.resetCount();
    cout<<c1.getCount()<<"\n";
    cout<<"Enter step value: ";
    cin>>val;
    c1.setIncrementStep(val);
    c1.increment();
    cout<<c1.getCount()<<"\n";
    cout<<"Enter step value: ";
    cin>>val;
    c1.setIncrementStep(val);
    c1.increment();
    cout<<c1.getCount()<<"\n";
    c1.resetCount();
}
