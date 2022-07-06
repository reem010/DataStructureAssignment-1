#include <bits/stdc++.h>

using namespace std;

//create function to swap two variables
void swap(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
}

//create function to check if the vector has an untitled songs
bool checkVector(const vector<string>& v) {
    int val = 0;
    for (auto &i: v) {
        if (i == "untitled")
            val++;
    }
    return val > 0;
}

//create function to sort list of songs
void BiasedSort(vector<string>&v) {
    int count = 0, idx;

    //sort the untitled songs if its exist
    if(checkVector(v)){
        for(int i=0;i<v.size()-1;i++){
            if(v.at(0)=="untitled")
                continue;

            idx=i;
            for(int j=i+1;j<v.size();j++){
                if(v.at(j)=="untitled"){
                    swap(v.at(idx),v.at(j));
                    idx++;
                    count++;
                }
            }
        }
    }

    //sort the rest of songs alphabetically
    for (int i = count; i < v.size()-1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) > v.at(j))
                swap(v.at(i), v.at(j));
        }
    }
}


int main() {

    vector<string> v = {"safari", "firework", "untitled", "cet la vie", "untitled", "imagine dragons", "blinding lights"};

    BiasedSort(v);

    for (auto const &i: v)
        cout << i << endl;

    return 0;
}
