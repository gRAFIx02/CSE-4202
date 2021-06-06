#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    RationalNumber(): numerator(0), denominator(0)
    {

    }
    void asign(int n, int d)
    {
        numerator = n;
        denominator = d;
        if(denominator==0)
        {
            cout<<"Invalid Entry!\n";
            exit(1);
        }
    }
    double convert()
    {
        return double(numerator)/double(denominator);
    }
    void invert()
    {
        swap(numerator, denominator);
        if(denominator==0)
        {
            cout<<"Invalid Entry!\n";
            exit(1);
        }
    }
    void print()
    {
        cout<<"The Rational Number is: "<<numerator<<"/"<<denominator<<"\n";
    }
};

int main()
{
    RationalNumber r;
    int n, d;
    cin>>n>>d;
    r.asign(n, d);
    r.print();
    cout<<r.convert()<<"\n";
    r.invert();
    r.print();
    cout<<r.convert()<<"\n";
}
