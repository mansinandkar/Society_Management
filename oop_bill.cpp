#include <iostream>
using namespace std;

class miscellaneous
{
    private:
        float water_bill;
        float electricity_bill;
        float road_repair;
        float building_repair;
        float gardening;
        float additional_staff;

    public:
        friend class BillGenerate; //BillGenerate can now access private members of miscellaneous class
        miscellaneous() //constructor to give intial values
        {
            water_bill=0;
            electricity_bill=0;
            road_repair=1000;
            building_repair=5000;
            gardening=1500;
            additional_staff=7000;
        }
        void Get_misc_details()
        {
            cout<<"\nEnter the water bill: ";
            cin>>water_bill;
            cout<<"Enter the electricity bill: ";
            cin>>electricity_bill;
        }
        void display_misc_details()
        {
            cout<<"\nWater bill: "<<water_bill;
            cout<<"\nElectricity bill: "<<electricity_bill;
            cout<<"\nRoad repair costs: "<<road_repair;
            cout<<"\nBuilding repair costs: "<<building_repair;
            cout<<"\nCost of gardening: "<<gardening;
            cout<<"\nPayment of additional staff: "<<additional_staff;
        }
    ~miscellaneous() //destructor
    {
        ;
    };
};

class BillGenerate //used to generate bill
{
    private:
        float security;
        float clubhouse_fee;
        float miscellaneous_calc;
        float hall_booking_fee;
        double total_bill;
    
    public:
        void calculate_security(); //used to calculate amt for security staff
        void calculate_miscellaneous(miscellaneous &);
        void BillCalculation(float,float,float);
        void BillDisplay(miscellaneous &);
};

void BillGenerate::calculate_security()
{
    int security_guards=10;
    security=security_guards*100*30; //salary of Rs. 100 per day. Assuming 30 days are there in a month.

}

void BillGenerate::calculate_miscellaneous(miscellaneous &misc)
{
    miscellaneous_calc=misc.water_bill+misc.electricity_bill+misc.building_repair+misc.gardening+misc.road_repair+misc.additional_staff;
    //Sums up all of miscellaneous costs
}

void BillGenerate::BillCalculation(float user_fee,float clubhouse,float hall_booking) //calculates total bill
{
    clubhouse_fee=clubhouse;
    hall_booking_fee=hall_booking;
    total_bill=security+miscellaneous_calc+user_fee+hall_booking_fee+clubhouse_fee;
}

void BillGenerate::BillDisplay(miscellaneous &misc) //displays bill
{
    cout<<"\nClubhouse fee: "<<clubhouse_fee;
    cout<<"\nSecurity fee: "<<security;
    misc.display_misc_details();
    if(hall_booking_fee!=0)
    {
        cout<<"\nHall booking charges: "<<hall_booking_fee;
    }
    cout<<"\nTotal bill is: "<<total_bill<<endl;
}
