#include <iostream>
using namespace std;

class clubhouse
{
    protected:
        int choice;
        string service;
        int pricing;
        float tax;
        string check_in;
        string check_out;
        string desc;
        string location;
        float tot_cost;

    public:
        float service_avail(); //used by user to avail clubhouse service
        void staff_clubhouse(); //used to trace clubhouse staff
        void clubhouse_display(); //used to display clubhouse charges
        void clubhouse_staff_display();
    
};

float clubhouse::service_avail()
{
    cout<<"\n\tSERVICES";
    cout<<"\n0. Exit";
    cout<<"\n1. Pool Table";
    cout<<"\n2. Air Hockey";
    cout<<"\n3. Carrom";
    cout<<"\n4. Swimming Pool";
    cout<<"\n5. Gym Center";
    cout<<"\nEnter Your Choice:";
    cin>>choice;
    switch(choice)
    {
        case 0:
        {
            cout<<"Exiting...";
            break;
        }
        case 1:
        {
            service="Pool Table";
            pricing=200;
            tax=0.07*pricing;
            break;
        }
        case 2:
        {
            service="Air Hockey";
            pricing=200;
            tax=0.07*pricing;
            break;
        }
        case 3:
        {
            service="Carrom";
            pricing=100;
            tax=0.07*pricing;
            break;
        }
        case 4:
        {
            service="Swimming Pool";
            pricing=500;
            tax=0.07*pricing;
            break;
        }
        case 5:
        {
            service="Gym Center";
            pricing=1000;
            tax=0.07*pricing;
            break;
        }
    }
    cout<<"\nChoice recorded successfully"<<endl;
    tot_cost=pricing+tax; //used to store clubhouse fee
   
    return tot_cost; //needs to be returned in total calculation
}

void clubhouse::clubhouse_display()
{
    cout<<"\nService: "<<service;
    cout<<"\nPrice: "<<pricing;
    cout<<"\nTaxes Applicable(7%): "<<tax;
    cout<<"\nTotal Cost: "<<tot_cost;
}

void clubhouse::staff_clubhouse()
{
    cout<<"\nLocation: ";
    cin.ignore();
    getline(cin,location);
    cout<<"Check In Time: ";
    getline(cin,check_in);
    cout<<"Check Out Time: ";
    getline(cin,check_out);
    cout<<"Description: ";
    getline(cin,desc);
}

void clubhouse::clubhouse_staff_display()
{
    cout<<"\nLocation: "<<location;
    cout<<"\nCheck In Time: "<<check_in;
    cout<<"\nCheck Out Time: "<<check_out;
    cout<<"\nDescription: "<<desc<<endl;
}
