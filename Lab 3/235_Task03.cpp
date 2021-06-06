#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

class BankAccount
{
private:
    string name;
    long long account_no;
    string account_type;
    long long balnce;
public:
    BankAccount(): account_no(0), balnce(0)
    {

    }
    void customerDetails()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter account no: ";
        cin>>account_no;
    }
    void accountType()
    {
        cout<<"Enter account type: ";
        cin>>account_type;
    }
    void deposit()
    {
        long long money;
        cout<<"Enter amount to deposit: ";
        cin>>money;
        balnce+=money;
        cout<<"Your Balance: "<<balnce<<"\n";
    }
    void balance()
    {
        cout<<"Your Balance: "<<balnce<<"\n";
    }
    void withdraw()
    {
        int money;
        cout<<"Your Balance: "<<balnce<<"\nEnter withdrawal amount: ";
        cin>>money;
        cout<<"Cash "<<money<<" has been withdrawn from your account.\n";
        balnce-=money;
    }
    void display()
    {
        if(name.empty())
            cout<<"No entry\n";
        else
        {
            cout<<"Name of customer: "<<name<<"\n";
            cout<<"Account no.: "<<account_no<<"\n";
            cout<<"Account type: "<<account_type<<"\n";
            cout<<"Main Balance: "<<balnce<<"\n";
        }
    }
};

int main()
{
    BankAccount b;
    int c;
    while(c!=6)
    {
        cout<<"1. New Entry\n2. View Balance\n3. Deposit\n4. Withdraw\n5. View All Entry\n6. Exit\n";
        cout<<"Enter choice: ";
        cin>>c;
        cout<<"\n";
        if(c==1)
        {
            b.customerDetails();
            b.accountType();
        }
        else if(c==2)
        {
            b.balance();
        }
        else if(c==3)
        {
            b.deposit();
        }
        else if(c==4)
        {
            b.withdraw();
        }
        else if(c==5)
        {
            b.display();
        }
        else
            return 0;
        cout<<"\n";
    }
}
