#include <iostream>
#include "Phone.h" //header of phone class
#include<string> //including string library
using namespace std;
int menu(); //declaring menu function
int main()
{
     cout << "\t\t\t**************************************************" << endl;
    cout << "\t\t\t|             Phone Book Application             |"<< endl;
    cout << "\t\t\t*************************************************" << endl;
    Phone a; //making object of funtion
    int n;
    string name,number,mail;
    int option = menu();
    do{
    switch(option)
    {
        //adding contact
    case 1:
        cout << "Enter  Name"<<endl;
        cin >> name;
        for(;;)
        {
            cout << "Enter  number"<<endl;
            cin >> number;
            if(number.length()==11)
            {
                 break;
            }
            else
        cout << "Invalid Number ! " << endl;
        }
        for(;;)
        {
            cout << "Enter email :" << endl;
            cin >> mail;
            if(a.valid_mail(mail)==true)
            {
                 break;
            }
            else
        cout << "Invalid mail ! " << endl;
        }

        a.addcontact(name,number,mail);
        break;
        //displaying all contacts
    case 2:
        a.display_all_contacts();
        break;
        //deleting name
    case 3:
        cout << "Enter  name";
        cin >> name;
        a.delete_by_name(name);
        break;
        //updating contact
    case 4:
        cout << "Enter  name";
        cin >> name;
        a.update_contact(name);
        break;
        //searching name
    case 5:
        cout << "Enter  name";
        cin >> name;
        a.search_by_name(name);
        break;
        //deleting all contacts
    case 6:
        cout << "Do you really want to delete all contacts?"<<endl;
        cout << "1.yes 2. no" << endl;
        cin >> n;
        switch(n)
        {
        case 1:
           a.delete_all_contact();
           break;
        case 2:
            break;
        }
//saving contacts
    case 7:
        a.save_contacts();
    case 8:
        //exit program
        exit(0);
    }
    option = menu();
    }while(option!=9);
}
int menu()
{

    cout << "\t\t\t*************************************************" << endl;
    cout << "\t\t\t|                                                |"<< endl;
    cout << "\t\t\t|             [1] Add Contacts                   |"<< endl;
    cout << "\t\t\t|             [2] Display all Contacts           |"<< endl;
    cout << "\t\t\t|             [3] delete contact                 |"<< endl;
    cout << "\t\t\t|             [4] Update Contact                 |"<< endl;
    cout << "\t\t\t|             [5] Search Contact                 |"<< endl;
    cout << "\t\t\t|             [6] Delete all Contact             |"<< endl;
    cout << "\t\t\t|             [7] save contact                   |"<< endl;
    cout << "\t\t\t|             [8] Exit                           |"<< endl;
    cout << "\t\t\t*************************************************" << endl;
    int num;
    cout << "Enter option from the given menu"<<endl;
    cin >> num;

    return num;
}
