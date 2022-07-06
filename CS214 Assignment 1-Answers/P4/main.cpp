#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set <string> StringSet;

void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        StringSet.insert(soFar); // Insert the words into the unordered list
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
}
// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
    unordered_set<string>::iterator StringItr;
    // print the words
    for(StringItr= StringSet.begin(); StringItr!= StringSet.end(); StringItr++ ){
        cout<<*(StringItr)<<endl;
    }
}
int main() {
    string s;
    cin>>s;
    ListPermutations(s);
}
