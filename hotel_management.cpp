#include<iostream>
#include<fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class temp{
    string name,email,date_of_saty,arival_time,roompref;
    long int contact_number;
    int c_id;
    string searchname,searchemail;
    int searchc_id;
    fstream file;
    public:
    void book_room();
    void details_room();
}obj;

int main()
{
    char choice;
    while(true){
    cout<<"\n1-Book Rooms";
    cout<<"\n2-Details of Booking";
    cout<<"\n3-exit";
    cout<<"\n Enter your choice ::";
    cin>>choice;

    switch(choice){
        case '1':
        cin.ignore(); //skip character in the input buffer
        obj.book_room();
        break;
        case '2':
        cin.ignore();
        obj.details_room();
        break;
        case '3':
        return 0;
        break;
        default:
        cout<<"Invalid selection........";
    }
}
}
void temp :: book_room(){
    cout<<"Enter your Name ::";
    getline(cin,name);//to take input with space
    cout<<"Enter your Mobile Number ::";
    cin>>contact_number;
    cin.ignore();
    cout<<"Enter Your Email address ::";
    getline(cin,email);
    cout<<"Date of stay(format:12May2024) ::";
    getline(cin,date_of_saty);
    cout<<"Time of arival(format:12pm) ::";
    getline(cin,arival_time);

    char roomp;
    cout<<"----Room Preference----";
    cout<<"\n1-Standard Room";
    cout<<"\n2-Delux Room";
    cout<<"\n3-Suite";
    cout<<"\n4-Family Room";
    cout<<"\n5-Connecting Rooms";
    cout<<"\n ENTER YOUR CHOICE ::";
    cin>>roomp;

    switch(roomp){
        case '1':
        roompref="Standard Room";
        break;
        case '2':
        roompref="Delux Room";
        break;
        case '3':
        roompref="Suite";
        break;
        case '4':
        roompref="Family Room";
        break;
        case '5':
        roompref="Connecting Rooms";
        break;
        default:
        cout<<"Invalid selection........";
        return;
    }


    srand(static_cast<unsigned int>(time(0)));
    c_id = 10000 + rand() % 90000;
    cout << "Your customer ID is :: " << c_id << endl;

    file.open("HotelData.txt",ios :: out | ios :: app);
    file<<name<<"*"<<contact_number<<"*"<<email<<"*"<<date_of_saty<<"*"<<arival_time<<"*"<<c_id<<"*"<<roompref<<endl;
    file.close();
}

void temp::details_room() {
    cout << "-----DETAILS-----";
    cout << "\nEnter Name ::";
    getline(cin, searchname);
    cout << "Enter your Email ::";
    getline(cin, searchemail);
    cout << "Enter customer ID ::";
    cin >> searchc_id;
    cin.ignore(); // skip character in the input buffer

    file.open("HotelData.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    while (file) {
        getline(file, name, '*');
        file >> contact_number;
        file.ignore(); // skip the '*' character1
        getline(file, email, '*');
        getline(file, date_of_saty, '*');
        getline(file, arival_time, '*');
        file >> c_id;
        file.ignore(); // skip the '*' character
        getline(file, roompref);

        if (file && name == searchname && email == searchemail && c_id == searchc_id) {
            cout<<"\n\n--------Customer Details--------"<<endl;
            cout<<"Customer name ::"<<name<<endl;
            cout<<"Contact Number ::"<<contact_number<<endl;
            cout<<"customer Email ::"<<email<<endl;
            cout<<"Customer ID ::"<<c_id<<endl;
            cout<<"Date of Stay ::"<<date_of_saty<<endl;
            cout<<"Time of Arival ::"<<arival_time<<endl;
            cout<<"Room prefered ::"<<roompref<<endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid details......." << endl;
    }

    file.close();
}

