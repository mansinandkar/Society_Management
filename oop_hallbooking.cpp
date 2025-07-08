#include<iostream>
using namespace std;

class HallBooking
{
    protected:
        float rent; 
    public:
        void rent_booking(); //to show the rent values
        float make_booking(int);

};

void HallBooking::rent_booking()
{
    cout<<"\nAvailable packages: ";
    cout<<"\n1. 2 hours - Rs3000";
    cout<<"\n2. 3 hours - Rs.5000";
    cout<<"\n3. 5 hours - Rs.7000";
    cout<<"\n4. 7 hours - Rs.9000";
    cout<<"\n5. 9 hours - Rs.11000";
    cout<<"\n6. 24 hours - Rs.13000";
}

float HallBooking::make_booking(int flag) //flag sees if the user wants to book the hall
{
    rent=0;
    if(flag==1)
    {
    int choice;
    cout<<"\nEnter the plan you want to pick: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            rent=3000;
            break;
        case 2:
            rent=5000;
            break;
        case 3:
            rent=7000;
            break;
        case 4:
            rent=9000;
            break;
        case 5:
            rent=11000;
            break;
        case 6:
            rent=13000;
            break;
        default:
            cout<<"\nInvalid package.";
    }
    cout<<"The hall is successfuly booked."<<endl;
    }
    return rent;
}
