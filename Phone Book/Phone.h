#ifndef PHONE_H
#define PHONE_H
#include<string>
using namespace std;
struct Node
{
    string name;
    string number;
    string email;
    Node* next;
    Node* prev;
};
typedef Node* ptr;
class Phone
{
    public:
        Phone();
        void createDummyHead();
        void addcontact(string name,string number,string email);
        void search_by_name(string name);
        void delete_by_name(string name);
        void update_contact(string Up_name);
        bool valid_mail(string email);
        void display_all_contacts();
        void display_all_contact();
        bool empty();
        void delHead();
        void save_contacts();
        void delete_all_contact();
        void read_from_file();
        virtual ~Phone();
        void changeCase(string &a, string &b);

        ptr head;
};

#endif // PHONE_H
