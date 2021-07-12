#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

class Counter
{
private:
    int step, cnt;
public:
    Counter(): cnt(0), step(0)
    {

    }
    Counter(int c): cnt(c)
    {

    }
    Counter(int c, int s): cnt(c), step(s)
    {

    }
    void setIncrementStep(int step_val = 1)
    {
        step = step_val;
    }
    int getCount()
    {
        return cnt;
    }
    void increment()
    {
        cnt+=step;
    }
    void resetCount()
    {
        cnt = 0;
    }
    Counter operator ++()
    {
        return Counter(++cnt);
    }
    Counter operator ++(int)
    {
        return Counter(cnt++);
    }
    Counter operator + (Counter);
    Counter operator + (int);
    friend Counter operator + (int , Counter);
    void operator += (Counter);
};

Counter Counter::operator + (Counter c)
{
    int a = cnt+c.cnt;
    int b = min(step, c.step);
    return Counter(a, b);
}

Counter Counter::operator + (int var)
{
    int a = cnt+var;
    return Counter(a, step);
}
 Counter operator + (int var, Counter c)
 {
     int a = var+c.cnt;
     return Counter(a, c.step);
 }

void Counter::operator += (Counter c)
{
    cnt+=c.cnt;
}

int main()
{
    Counter c;
    cout<<c.getCount()<<"\n";
    c.setIncrementStep();
    c.increment();
    cout<<c.getCount()<<"\n";
    c.resetCount();
    cout<<c.getCount()<<"\n";
    Counter c1(1, 2), c2(3, 4), c3(5, 6);
    c1 = c2+c3;
    cout<<c1.getCount()<<"\n";
    c1.increment();
    cout<<c1.getCount()<<"\n";
    int var = 10;
    c1 = c2+var;
    cout<<c1.getCount()<<"\n";
    c1.increment();
    cout<<c1.getCount()<<"\n";
    c1 = var+c2;
    cout<<c1.getCount()<<"\n";
    c1.increment();
    cout<<c1.getCount()<<"\n";
    c1+=c2;
    cout<<c1.getCount()<<"\n";
}
