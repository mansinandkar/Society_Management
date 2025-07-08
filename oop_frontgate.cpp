#include <iostream>
using namespace std;

class Front_gate
{
    private:
        char delivery_boy_name[50];
        int delivery_flat_no;
    public:
        void detail_gate(); //used to get details of delivery person
        void display_gate(); //display details of delivery person 
};

void Front_gate::detail_gate()
{
    cout<<"\nEnter delivery person's name: ";
    cin.ignore();
    cin.getline(delivery_boy_name,50);
    cout<<"Enter flat number: ";
    cin>>delivery_flat_no;
}

void Front_gate::display_gate()
{
    cout<<"\nDelivery person's name: "<<delivery_boy_name;
    cout<<"\nFlat number: "<<delivery_flat_no;
}
