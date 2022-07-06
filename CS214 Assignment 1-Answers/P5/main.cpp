#include <bits/stdc++.h>
using namespace std;
class StudentName{
private:
    string name;
public:
    StudentName(string n);
    void print();
    bool replace(int i,int j);
};
StudentName::StudentName(string n){
    name=n;
    string last;
    stringstream ss(name);
    int size=0;
    while(ss>>last){
        size++;
    }
    if(size==2){
        name+=' '+last;
    }else if(size==1){
        name+=' '+last+' '+last;
    }
}
void StudentName::print(){
    string s;
    stringstream ss(name);
    while(ss>>s){
        cout<<s<<endl;
    }
}
bool StudentName::replace(int i,int j){
    string s;
    stringstream ss(name);
    vector<string>vecOfNames;
    while(ss>>s){
        vecOfNames.push_back(s);
    }
    if(i <1 || j<1 || i>vecOfNames.size()|| j>vecOfNames.size()){
        return false;
    }else{
        swap(vecOfNames[i-1],vecOfNames[j-1]);
        name="";
        for(int r=0;r<vecOfNames.size();r++){
            name += vecOfNames[r]+' ';
        }
        return true;
    }
}
int main() {
    StudentName s1("Ahmed Ibrahim");
    StudentName s2("Samy Gerges Ibrahim");
    StudentName s3("Reem Ahmed Khalil taha");
    StudentName s4("Ahmed Shahin");
    StudentName s5("Mohamed Hassan Ali");
    s1.replace(1,2);
    s2.replace(2,3);
    s3.replace(2,4);
    s4.replace(1,7);
    s5.replace(1,3);
    cout<<"First name: \n";
    s1.print();
    cout<<"Second name: \n";
    s2.print();
    cout<<"Third name: \n";
    s3.print();
    cout<<"Fourth name: \n";
    s4.print();
    cout<<"Fifth name: \n";
    s5.print();
}
