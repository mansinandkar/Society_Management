#include<iostream>
#include "oop_bill.cpp"
#include "oop_clubhouse.cpp"
#include "oop_hallbooking.cpp"
//including files to access class declarations given in other files
using namespace std;

class user:public BillGenerate,public clubhouse,public HallBooking //inheriting multiple classes
{
    protected:
        string user_name;
        int flat_no;
        int house_type;
        float rent;
        float maintenance_fee;
        float sinking_fund;
    public:
        void get_user_details();
        void display_user_details();
        float user_calculate();
        void display_user_calculate();
        int get_flat_no()
        {
            return flat_no;
        };
};

void user::get_user_details()
{
    cout<<"\nEnter your name: ";
    cin.ignore();
    getline(cin,user_name);
    cout<<"Enter Flat number: ";
    cin>>flat_no;
    cout<<"House type:";
    cout<<"\n1. 1 BHK";
    cout<<"\n2. 2 BHK";
    cout<<"\n3. 3 BHK";
    cout<<"\n4. 3.5 BHK";
    cout<<"\n5. Row house";
    cout<<"\nEnter choice: ";
    cin>>house_type;
    
}

float user::user_calculate()
{
    float house_fee;
    if (house_type==1)
    {
        rent=15000;
        maintenance_fee=3500;
        sinking_fund=2000;
    }
    else if(house_type==2)
    {
        rent=30000;
        maintenance_fee=5000;
        sinking_fund=4000;
    }
    else if (house_type==3)
    {
        rent=45000;
        maintenance_fee=7000;
        sinking_fund=6000;
    }
    else
    {
        rent=60000; 
        maintenance_fee=9000;
        sinking_fund=8000;
    }
    house_fee=rent+maintenance_fee+sinking_fund;
    return house_fee;
}

void user::display_user_calculate()
{
    cout<<"\nRent: "<<rent;
    cout<<"\nMaintenance fee: "<<maintenance_fee;
    cout<<"\nSinking fund: "<<sinking_fund;
}

void user::display_user_details()
{
    cout<<"\nName: "<<user_name;
    cout<<"\nFlat No. "<<flat_no;
    switch(house_type)
    {
        case 1:
            cout<<"\nHouse type is: 1 BHK";
            break;
        case 2:
            cout<<"\nHouse type is: 2 BHK";
            break;
        case 3:
            cout<<"\nHouse type is: 3 BHK";
            break;
        case 4:
            cout<<"\nHouse type is: 3.5 BHK";
            break;
        case 5:
            cout<<"\nHouse type is: Row House";
            break;
    }
}

class staff:public clubhouse
{
    protected:
        string staff_name;
        int staff_flat_no;
        int staff_code;
        string staff_job;
        string staff_phone_no;

    public:
        int get_staff_code()
        {
            return staff_code;
        }

        string get_staff_job()
        {
            return staff_job;
        }

        string get_staff_phone()
        {
            return staff_phone_no;
        }
        
        string get_staff_name()
        {
            return staff_name;
        }

        void get_staff_details()
        {
            cout<<"\nEnter staff name: ";
            cin.ignore();
            getline(cin,staff_name);
            cout<<"Enter Flat number: ";
            cin>>staff_flat_no;
            cout<<"Enter staff code: ";
            cin>>staff_code;
            cout<<"Enter staff job: ";
            cin.ignore();
            getline(cin,staff_job);
            cout<<"Enter staff contact number: ";
            cin>>staff_phone_no;
        }
        
        void display_staff_details()
        {
            cout<<"\nName: "<<staff_name;
            cout<<"\nFlat No. "<<staff_flat_no;
            cout<<"\nStaff code: "<<staff_code;
            cout<<"\nStaff job: "<<staff_job;
            cout<<"\nStaff Contact no: "<<staff_phone_no<<endl;
        }
};