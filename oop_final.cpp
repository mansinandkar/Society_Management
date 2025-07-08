#include <iostream>
#include "oop_frontgate.cpp"
#include "oop_query.cpp"

#include<fstream> //for file handling
using namespace std;
fstream file; //file object for frontgate
fstream file2; //file object for query

int main()
{
    file.open("frontgate.dat", ios::out|ios::binary); // file for front gate
    file.close();
    file2.open("query.dat", ios::out|ios::binary); // file for query
    file2.close();

    user u[300]; //assuming that the society has 300 flats/row houses in total
    staff s[50]; //assumming that the society has 50 staff memebers
    HallBooking h[25]; //assumming that the society can have 25 hall bookings for external users
    Front_gate f,temp;
    query q,temp1;

    int j=1;//used in printing of query/front gate
    int user_register,staff_register; //sees if the society resident is an already registered user
    int choice,main_menu_choice,query_choice; //used to store various choices
    int club_flag=0; //keeps track if the staff is from the clubhouse 
    int user_count=0,staff_count=0,hallbooking_count=0; //keeps record of the number of users,staff,hallbookings registered till date respctively

    ch: //label for main menu
    cout<<"\n\n\tMENU:"<<endl;
    cout<<"\n1. Front gate Security";
    cout<<"\n2. Society resident";
    cout<<"\n3. Society staff";
    cout<<"\n4. Hall booking(for externals)";
    cout<<"\n5. Query management";
    cout<<"\n6. Exit the system"<<endl;
    cout<<"\nEnter choice: ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1:
            int f_choice;
            cout<<"\nWelcome to the front gate"<<endl;
            file.open("frontgate.dat",ios::app|ios::binary); //opening file for writing
            if(file)
            {
                f.detail_gate();
                file.write((char *)&f,sizeof(f)); // write the object to a file
            }
            file.close();
            file.open("frontgate.dat", ios::in|ios::binary); //open file for reading
            cout<<"\n\nDo you want to see the front gate records till date?";
            cout<<"\n1. YES \n2. NO\nEnter choice: ";
            cin>>f_choice;
            if(f_choice==1)
            {
                j=1;
                while(!file.eof())
                {
                    file.read((char*)&temp,sizeof(temp)); //reads from the file
                    if(file)
                    {
                        cout<<endl<<"Delivery person "<<j;
                        temp.display_gate();
                        cout<<endl;
                        j++;
                    }
                }
            }
            file.close(); // close the file
            break;
        case 2:
            int society_choice,society_cont; //keeps track of society menu option, if they want to see the society menu again
            int flat_num,user_record; //used to store flat no of existing user to compare in the records, keeps track of the fact that the user at present is a new user or an existing user
            float club_fee; //used to store the club fee
            float hall_fee;
            float user_fee;
            cout<<"\n\tSOCIETY RESIDENT VIEW\n";
            cout<<"\nHave you already registered on the society app?\n1. NO\n2. YES";
            cout<<"\nEnter your choice: ";
            cin>>user_register;
            user_record=user_count; //initially, user_record is set to point to the next society user
            if(user_register==1) //new user is there-take their info
            {
                cout<<"\nInput your record for the system";
                u[user_count].get_user_details();
            }
            else //existing user found, check for flat number
            {
                cout<<"\nEnter your flat number: ";
                cin>>flat_num;
                for(int i=0;i<user_count;i++)
                {
                    if(flat_num==u[i].get_flat_no())
                    user_record=i; //this now points to the record of the existing user
                }
            }
            cout<<"\nYour record is: "<<endl;
            u[user_record].display_user_details(); //displays user details
            do //society menu
            {
                cout<<"\n\n SOCIETY MENU";
                cout<<"\n1. Clubhouse";
                cout<<"\n2. Hall Booking";
                cout<<"\n3. Bill Generation";
                cout<<"\n4. Exit";
                cout<<"\nEnter choice: ";
                cin>>society_choice;
                if(society_choice==1) //clubhouse
                {
                    cout<<"\nIf you are an existing user and wish to retain your earlier choice, please select 0"<<endl;
                    club_fee=u[user_record].service_avail();
                }
                else if(society_choice==2) //hall booking
                {
                    int flag; //used to check if hall booking is requested by the user or not
                    u[user_record].rent_booking();
                    cout<<"\n\nDo you want to book the hall?\n1. YES\n2. NO";
                    cout<<"\nEnter choice: ";
                    cin>>flag;
                    hall_fee=u[user_record].make_booking(flag);
                }
                else if(society_choice==3)//bill generate
                {
                    miscellaneous misc;
                    misc.Get_misc_details();
                    u[user_record].calculate_security();
                    u[user_record].calculate_miscellaneous(misc);
                    user_fee=u[user_record].user_calculate();
                    u[user_record].BillCalculation(user_fee,club_fee,hall_fee);
                    cout<<"\n\nBILL";
                    u[user_record].display_user_calculate();
                    u[user_record].BillDisplay(misc);
                }
                else
                {
                    ; //user doesn't want to do anything after his record creation
                }
                if(user_register==1) //if new record is added to the system, the user count should increase by 1
                {
                    user_count+=1;
                }
                cout<<"\nDo you want to see the society menu again?\n1. YES\n2. NO";
                cout<<"\nEnter choice: ";
                cin>>society_cont;
            }while(society_cont==1); //to see if the user wants to see the society menu
            break;
        case 3:
            int staff_c; //stores code of registered staff
            int club_choice;  //sees if the staff is part of the clubhouse
            int staff_record; //keeps track of the fact that the staff at present is a new staff or an existing staff
            cout<<"\n\tSTAFF VIEW"<<endl;
            cout<<"\nAre you a registered staff?";
            cout<<"\n1. No \n2. YES";
            cout<<"\nEnter choice: ";
            cin>>staff_register;

            staff_record=staff_count; //initially, staff_record is set to point to the next society staff
            if(staff_register==1)
            {
                s[staff_count].get_staff_details();
            }
            else //existing staff found, check for staff code
            {
                cout<<"\nEnter your staff code: ";
                cin>>staff_c;
                for(int i=0;i<staff_count;i++)
                {
                    if(staff_c==s[i].get_staff_code())
                    staff_record=i; //this now points to the record of the existing staff
                }
            }
            cout<<"\n\nAre you a part of the club house staff?\n1. YES \n2. NO";
            cout<<"\nEnter your choice: ";
            cin>>club_choice;
            club_flag=0;
            if(club_choice==1) //staff is part of the clubhouse
            {
                s[staff_record].staff_clubhouse();
                club_flag=1; //sets flag to 1-staff is part of clubhouse
            }

            if(club_flag==1)
            {
                s[staff_record].display_staff_details();
                s[staff_record].clubhouse_staff_display();
            }
            else
            {
                s[staff_record].display_staff_details();
            }

            if(staff_register==1) //if new record is added to the system, the staff count should increase by 1
            {
                staff_count+=1;
            }
            break;
        case 4: // hall booking for external users
            int hall_flag; //to see if they want to book the hall
            float booking_fee;

            h[hallbooking_count].rent_booking(); //shows hall charges
            cout<<"\n\nDo you want to book the hall?\n1. YES\n2. NO";
            cout<<"\nEnter choice: ";
            cin>>hall_flag;
            if(hall_flag==1) //user books the hall
            {
                booking_fee=h[hallbooking_count].make_booking(hall_flag);
                cout<<"\nHall charges are: "<<booking_fee<<endl;
            }
            break;
        case 5:
            cout<<"\n\tQUERY MANAGEMENT\n";
            cout<<"\n1. Generate number of help";
            cout<<"\n2. Raise a query";
            cout<<"\nEnter choice: ";
            cin>>query_choice;
            if(query_choice==1)
            {
                q.get_contacts(s,staff_count);
            }
            else
            {
                int q_choice;
                cout<<"\nWelcome to the Query portal";
                file2.open("query.dat",ios::app|ios::binary); //open file for writing
                if(file2)
                {
                    q.raise_query();
                    file2.write((char *)&q,sizeof(q));// write the object to a file
                }
                file2.close();
                file2.open("query.dat", ios::in|ios::binary); //open file for reading
                cout<<"\n\nDo you want to see all the queries? ";
                cout<<"\n1. YES \n2. NO\nEnter choice: ";
                cin>>q_choice;
                if(q_choice==1)
                {
                    j=1;
                    while(!file2.eof())
                    {
                        file2.read((char*)&temp1,sizeof(temp1)); //reads from the file
                        if(file2)
                        {
                            cout<<endl<<"Query "<<j;
                            temp1.display_query();
                            cout<<endl;
                            j++;
                        }
                    }
                }
                file2.close(); // close the file
            }
            break;
        case 6:
            exit(0);
            break;
        default: //user enters invalid choice
            {
                cout<<"\nInvalid choice.Enter choice again.";
                goto ch;
            }
    }
    cout<<"\nDo you want to see the main menu?\n1.YES\n2.NO";
    cout<<"\nEnter choice: ";
    cin>>main_menu_choice;
    if(main_menu_choice==1) //to see if the user wants to go back to the main menu
    {
        goto ch;
    }
    return 0;
}