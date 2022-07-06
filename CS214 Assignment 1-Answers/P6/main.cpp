#include <bits/stdc++.h>
#include "PhoneDirectory.h"
using namespace std;

int main() {
    person person_info;
    PhoneDirectory pd;
    while(true){
        cout<<"Choose a number from 1 to 6: "<<endl;
        cout<<"1. Add an entry to the directory\n"
              "2. Look up by phone number\n"
              "3. Look up by first name\n"
              "4. Delete an entry from the directory\n"
              "5. List All entries in phone directory\n"
              "6. Exit form this program\n";
        int num;
        cin>>num;
        switch (num) {
            case 1:
                cout<<"---Enter your Entry Info---"<<endl;
                cout<<"First name: ";
                cin>>person_info.first_name;
                cout<<"Last name: ";
                cin>>person_info.last_name;
                cout<<"Phone number: ";
                cin>>person_info.phone_number;
                pd.addNewEntry(person_info);
                break;
            case 2:
                cout<<"Enter the number you want to find: ";
                cin>>person_info.phone_number;
                pd.lookUpByPhone(person_info.phone_number);
                break;
            case 3:
                cout<<"Enter the name you want to find: ";
                cin>>person_info.first_name;
                pd.lookUpByFirstName(person_info.first_name);
                break;
            case 4:
                cout<<"Enter the name you want to delete: ";
                cin>>person_info.first_name;
                pd.deleteEntry(person_info.first_name);
                break;
            case 5:
                pd.insertionSort();
                //pd.selectionSort();
                //pd.bubbleSort();
                pd.listEntries();
                break;
            case 6:
                exit(0);
            default:
                cout<<"Invalid number.\n";
                exit(1);
        }
    }
}
