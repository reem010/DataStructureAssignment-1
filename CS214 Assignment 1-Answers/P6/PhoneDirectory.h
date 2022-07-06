#ifndef P_6_PHONEDIRECTORY_H
#define P_6_PHONEDIRECTORY_H
#include <bits/stdc++.h>
using namespace std;
struct person{
    string first_name;
    string last_name;
    string phone_number;
};
class PhoneDirectory{
private:
    vector<person>p;
public:
    void addNewEntry(person person_info);
    void lookUpByPhone(string pn);
    void lookUpByFirstName(string fn);
    void deleteEntry(string fn);
    void listEntries();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
};



#endif //P_6_PHONEDIRECTORY_H
