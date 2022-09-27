#include "Phone.h"

#include <iostream>

#include<string>

#include<fstream>

using namespace std;

Phone::Phone() {
  //creating dummy head
  createDummyHead();
  // use to read existing data from the file
  read_from_file();

}
void Phone::addcontact(string name, string number, string email) {
  ptr curr = head -> next;
  ptr Newnode = new Node;
  Newnode -> name = name;
  Newnode -> number = number;
  Newnode -> email = email;
  Newnode -> next = curr;
  Newnode -> prev = curr -> prev;
  curr -> prev = Newnode;
  (Newnode -> prev) -> next = Newnode;
}
//it is used to change upper case to lowercase
void Phone::changeCase(string & a, string & b) {
  for (int i = 0; i < a.length(); i++) {
    char ch;

    ch = tolower(a[i]); //converting string to lowercase and store in char
    b[i] = ch; //update string by passing char at each cycle
  }
}
void Phone::read_from_file() {
  fstream Data;
  ptr traversal = head -> next;
  Data.open("phonedirectory.txt", ios:: in ); //'in' mode used to read from file
  if (Data.is_open()) //check wheather file is open or not
  {
    string name;
    string number;
    string email;

    while (getline(Data, name)) //read name line from file
    {
      getline(Data, number); //read number line from file
      getline(Data, email);
      addcontact(name, number, email); //passing name and number to addcontact function
    }
  }

  Data.close(); // to close file
}

void Phone::delete_by_name(string name) {

  ptr curr = head -> next;
  while (curr != head) {
    if (curr -> name == name) {
      (curr -> next) -> prev = curr -> prev;
      (curr -> prev) -> next = curr -> next;
      delete curr;
      break;
    }
    curr = curr -> next;
  }
}
void Phone::search_by_name(string name) {

  ptr travers = head -> next;
  while (travers != head) {
    if (travers -> name == name) {
      cout << "Contact found!" << endl;
      cout << "NAME    : " << travers -> name << endl;
      cout << "CONTACT : " << travers -> number << endl;
      break;
    }
    travers = travers -> next;
  }

}
void Phone::update_contact(string Up_name) {
  string up_name, up_number, up_mail;
  int check;
  ptr travers = head -> next;
  while (travers != head) {
    if (travers -> name == Up_name) {
      int n, n1;
      cout << "Contact found !" << endl;
      cout << "1.Update Name \n 2.Update Number \n 3. Update Email" << endl;
      cin >> n;
      switch (n) {
      case 1:
        cout << "Update  Name" << endl;
        cin >> up_name;
        travers -> name = up_name;
        cout << "Do you want to update number , email or both ?" << endl;
        cout << "Enter 1 . Update Number 2. Update Email 3. Both" << endl;
        cin >> n1;
        switch (n1) {
        case 1:
          cout << "Update  Number" << endl;
          cin >> up_number;
          travers -> number = up_number;
          break;
        case 2:
          cout << "Update  Email" << endl;
          cin >> up_mail;
          travers -> email = up_mail;
          break;
        case 3:
          cout << "Update  Number" << endl;
          cin >> up_number;
          travers -> number = up_number;
          cout << "Update  Email" << endl;
          cin >> up_mail;
          travers -> email = up_mail;
          break;
        }
        case 2:
          for (;;) {
            cout << "Update  number" << endl;
            cin >> up_number;
            if (up_number.length() == 11) {
              break;
            } else
              cout << "Invalid Number ! " << endl;
          }
          travers -> number = up_number;
          break;
        case 3:
          for (;;) {
            cout << "Enter email :" << endl;
            cin >> up_mail;
            if (valid_mail(up_mail) == true) {
              break;
            } else
              cout << "Invalid mail ! " << endl;
          }
          travers -> email = up_mail;
          break;
      }
    }
    travers = travers -> next;
  }
}
bool Phone::valid_mail(string email) {
  if (!((email.front() >= 'a' && email.front() <= 'z') ||
      (email.front() >= 'A' && email.front() <= 'Z'))) {

    // If it's not an alphabet
    // email id is not valid
    return 0;
  }
  // Variable to store position
  // of At and Dot
  int At = -1, Dot = -1;

  // Traverse over the email id
  // string to find position of
  // Dot and At
  for (int i = 0; i < email.length(); i++) {

    // If the character is '@'
    if (email[i] == '@') {

      At = i;
    }

    // If character is '.'
    else if (email[i] == '.') {

      Dot = i;
    }
  }

  // If At or Dot is not present
  if (At == -1 || Dot == -1)
    return 0;

  // If Dot is present before At
  if (At > Dot)
    return 0;

  // If Dot is present at the end
  return !(Dot >= (email.length() - 1));
}
void Phone::delHead() {

  if (empty())
    return;
  else {
    ptr curr = head -> next;
    (curr -> next) -> prev = curr -> prev;
    (curr -> prev) -> next = curr -> next;
    delete curr;
  }

}
void Phone::createDummyHead() {
  head = new Node;
  head -> next = head;
  head -> prev = head;
}
bool Phone::empty() {
  if (head -> next == head && head -> prev == head)
    return true;
  else
    return false;
}
void Phone::delete_all_contact() {
  while (!empty())
    delHead();
}

void Phone::display_all_contacts() {
  cout << "\t\t\tDisplaying all contacts " << endl;
  for (int i = 0; i < 26; i++) {
    ptr curr = head -> next;
    while (curr != head) {
      if (curr -> name[0] == (97 + i) || curr -> name[0] == (65 + i)) {
        cout << "Name : " << curr -> name << endl;
        cout << "Contact :" << curr -> number << endl;
        cout << "E-Mail :" << curr -> email << endl << endl;
      }
      curr = curr -> next;
    }
  }
}
void Phone::save_contacts() //use to save contacts
{
  fstream Data; //making object of fsrteam
  ptr traversal = head -> next; //passing address of first node
  Data.open("phonedirectory.txt", ios::trunc | ios::out); //trunc is used to delete existing file
  if (Data.is_open()) // check to create either file created
  {
    while (traversal != head) //traverse untill each to head pointer
    {
      Data << traversal -> name << endl;
      Data << traversal -> number << endl;
      traversal = traversal -> next;
    }
  }
  Data.close(); //to close file
}

Phone::~Phone() //destructor
{
  save_contacts(); // use to auto save contact after the program end
}
