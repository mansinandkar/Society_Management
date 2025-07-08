#include <iostream>
#include<bits/stdc++.h> //standard library to convert string to upper character
#include "oop_users.cpp"
using namespace std;

class query
{
    private:
        char name[50];
        int flat_no;
        char title[30];
        char description[200];


    public:
        int choice;
        string temp;
        void get_contacts(staff s[], int);
        void raise_query();
        void display_query();  
};
//will take the data for raise query
void query::raise_query()
{
    cout<<"\nResident Name: ";
    cin.ignore();
    cin.getline(name,50);
    cout<<"Flat No: ";
    cin>>flat_no;
    cout<<"Title: ";
    cin.ignore();
    cin.getline(title,30);
    cout<<"State your complaint: ";
    cin.getline(description,200);

}

void query::display_query()
{
    cout<<"\nResident Name: "<<name;
    cout<<"\nFlat No: "<<flat_no;
    cout<<"\nTitle: "<<title;
    cout<<"\nState your complaint: "<<description;
}
//will take data from s[] , compare different staff jobs and will display the staff name,staff job and phone number
void query::get_contacts(staff s[], int staff_records)
{
    int flag=0;
    cout<<"\nHelp available:";
    cout<<"\n1. Maid"<<endl;
    cout<<"2. Plumber"<<endl;
    cout<<"3. Electrician"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        for(int a=0; a<staff_records; a++)
        {
            temp=s[a].get_staff_job();
            transform(temp.begin(), temp.end(),temp.begin(), ::toupper);//convert staff_job to upper string
            if(temp=="MAID")
            {
                flag=1;
                cout<<"\nStaff name: "<<s[a].get_staff_name();
                cout<<"\nStaff job: "<<temp;
                cout<<"\nPhone no: "<<s[a].get_staff_phone();
                cout<<endl;
            }  
        }
        break;
    case 2:
        for(int a=0; a<staff_records; a++)
        {
            temp=s[a].get_staff_job();
            transform(temp.begin(), temp.end(),temp.begin(), ::toupper);//convert staff_job to upper string
            if(temp=="PLUMBER")
            {
                flag=1;
                cout<<"staff name: "<<s[a].get_staff_name();
                cout<<"Staff job: "<<temp;
                cout<<"\nPhone no: "<<s[a].get_staff_phone();
            }  
        }
        break;
    case 3:
        for(int a=0; a<staff_records; a++)
        {
            temp=s[a].get_staff_job();
            transform(temp.begin(), temp.end(),temp.begin(), ::toupper);//convert staff_job to upper string
            if(temp=="ELECTRICIAN")
            {
                flag=1;
                cout<<"staff name: "<<s[a].get_staff_name();
                cout<<"Staff job: "<<temp;
                cout<<"\nPhone no: "<<s[a].get_staff_phone();
            }  
        }
        break;
    default:
        cout<<"\nInvalid option";
        break;
    }
     if(flag==0)
     {
        cout<<"\nSorry, this staff is not available."<<endl;
     }
}      



