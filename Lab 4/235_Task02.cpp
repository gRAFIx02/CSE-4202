#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class Travel
{
private:
    int flightNumber;
    string destination;
    float distance;
    float MaxFuelCapacity;
    int calFuel(float distance)
    {
        if(distance<=1000)
            return 500;
        if(distance>1000 && distance<=2000)
            return 1100;
        if(distance>2000)
            return 2200;
    }
public:
    Travel():flightNumber(0), distance(0), MaxFuelCapacity(0)
    {

    }
    void FeedInfo()
    {
        cout<<"Flight Number: ";
        cin>>flightNumber;
        cout<<"Destination: ";
        cin>>destination;
        cout<<"Distance: ";
        cin>>distance;
        cout<<"Max Fuel Capacity: ";
        cin>>MaxFuelCapacity;
    }
    void ShowInfo()
    {
        cout<<"Flight Number: "<<flightNumber<<"\n";
        cout<<"Destination: "<<destination<<"\n";
        cout<<"Distance: "<<distance<<"\n";
        cout<<"Max Fuel Capacity: "<<MaxFuelCapacity<<"\n";
        if(calFuel(distance)<=MaxFuelCapacity)
            cout<<"Fuel Capacity is fit for this flight\n";
        else
            cout<<"Not sufficient fuel capacity for this flight\n";
    }
};

int main()
{
    Travel t1;
    t1.FeedInfo();
    t1.ShowInfo();
}
