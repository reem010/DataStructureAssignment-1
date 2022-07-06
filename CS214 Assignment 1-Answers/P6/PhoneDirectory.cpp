#include "PhoneDirectory.h"

void PhoneDirectory::addNewEntry(person person_info) {
    p.push_back(person_info);
}
void PhoneDirectory::lookUpByPhone(string pn) {
    int position=-1;
    for(int i=0; i<p.size();i++){
        if(p[i].phone_number==pn){
            position=i;
            cout << "Found Entry at position: " << position + 1 << endl;
            cout << "First name: " << p[position].first_name << " ";
            cout << ",Last name: " << p[position].last_name << " ";
            cout << ",Phone number: " << p[position].phone_number << endl;
        }
    }
    if(position==-1){
        cout<<"Entry does not exist."<<endl;
    }
}
void PhoneDirectory::lookUpByFirstName(string fn) {
    int position=-1;
    for(int i=0; i<p.size();i++){
        if(p[i].first_name==fn){
            position=i;
            cout << "Found Entry at position: " << position + 1 << endl;
            cout << "First name: " << p[position].first_name << " ";
            cout << ",Last name: " << p[position].last_name << " ";
            cout << ",Phone number: " << p[position].phone_number << endl;
        }
    }
    if(position==-1){
        cout<<"Entry does not exist."<<endl;
    }
}
void PhoneDirectory::deleteEntry(string fn) {
    int position=-1;
    for(int i=0; i<p.size();i++){
        if(p[i].first_name==fn) {
            position = i;
            p.erase(p.begin()+position);
        }
    }
    if(position==-1){
        cout<<"Entry does not exist."<<endl;
    }
}

void PhoneDirectory::listEntries() {
    for(int i=0; i<p.size();i++){
        cout<<"Entry number "<<i+1<<endl;
        cout<<"First name: "<<p[i].first_name<<" ";
        cout<<",Last name: "<<p[i].last_name<<" ";
        cout<<",Phone number: "<<p[i].phone_number<<endl;
    }
}

void PhoneDirectory::insertionSort() {
    person temp;
    for(int j, i=1; i<p.size();i++){
        temp=p[i];
        for(j=i; j>0 && temp.first_name<p[j-1].first_name;j--){
            p[j]=p[j-1];
        }
        p[j]=temp;
    }
}

void PhoneDirectory::selectionSort() {
    for(int i=0,least=i; i<p.size()-1;i++){
        for(int j=i+1;j<p.size();j++){
            if(p[j].first_name<p[least].first_name){
                least=j;
            }
            swap(p[i],p[least]);
        }
    }
}

void PhoneDirectory::bubbleSort() {
    for(int i=0;i<p.size()-1;i++){
        for(int j=p.size()-1;j>i;j--) {
            if(p[j].first_name<p[j-1].first_name){
                swap(p[j],p[j-1]);
            }
        }
    }
}

