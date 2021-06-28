#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Rectangle
{
private:
    float length;
    float width;
public:
    Rectangle(): length(1), width(1)
    {

    }
    Rectangle(float l, float w): length(l), width(w)
    {

    }
    void setValue(float l=1, float w=1)
    {
        if(l>=1 && l<20 && w>=1 && w<20)
        {
            length=l;
            width=w;
        }
        else
        {
            cout<<"Range exceeded!\n";
            return;
        }
    }
    void getValue()
    {
        cout<<"Enter length: ";
        cin>>length;
        cout<<"Enter width: ";
        cin>>width;
    }
    float perimeter()
    {
        return length+width;
    }
    float area()
    {
        return length*width;
    }
};

int main()
{
    Rectangle r1, r2(11.5, 7.9), r3, r4;
    r1.setValue();
    r3.getValue();
    r4.setValue(20.5, 11.9);
    cout<<r1.perimeter()<<" "<<r1.area()<<"\n";
    cout<<r2.perimeter()<<" "<<r2.area()<<"\n";
    cout<<r3.perimeter()<<" "<<r3.area()<<"\n";
    cout<<r4.perimeter()<<" "<<r4.area()<<"\n";
}
