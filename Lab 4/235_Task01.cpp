#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Calculator
{
private:
    int value;
public:
    Calculator():value(0)
    {

    }
    Calculator(int n):value(n)
    {

    }
    ~Calculator()
    {

    }
    void getValue()
    {
        cin>>value;
    }
    void setValue(int n)
    {
        value = n;
    }
    void add(int n)
    {
        value+=n;
    }
    void subtract(int n)
    {
        value-=n;
    }
    void multiply(int n)
    {
        value*=n;
    }
    void divideBy(int n)
    {
        if(n==0)
        {
            cout<<"Error: Division by 0 is undefined\n";
            return;
        }
        value/=n;
    }
    void clr()
    {
        value=0;
    }
    void display()
    {
        cout<<"Calculator display: "<<value<<"\n";
    }
};

int main()
{
    Calculator c(10);
    string s;
    int n;
    while(1)
    {
        cin>>s;
        if(s=="add")
        {
            cin>>n;
            c.add(n);
            c.display();
        }
        else if(s=="subtract")
        {
            cin>>n;
            c.subtract(n);
            c.display();
        }
        else if(s=="multiply")
        {
            cin>>n;
            c.multiply(n);
            c.display();
        }
        else if(s=="divide")
        {
            cin>>n;
            c.divideBy(n);
            c.display();
        }
        else if(s=="clear")
        {
            c.clr();
            c.display();
        }
        else
            return 0;
    }
}
