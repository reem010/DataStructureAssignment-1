
#include <iostream>
#include<algorithm>
#include <bitset> 
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <chrono> 
using namespace std;


#define boom ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define endl "\n";


void normal_insertion_sort(ll arr[], ll n)
{
    ll temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
ll binary_search(ll arr[], ll val, ll low, ll high)
{
    if (high <= low)
        return (val > arr[low]) ?
        (low + 1) : low;

    ll m = (low + high) / 2;

    if (val == arr[m])
        return m + 1;

    if (val > arr[m])
        return binary_search(arr, val, m + 1, high);
    return binary_search(arr, val, low, m - 1);
}


void binary_insertion_sort(ll arr[], ll n)
{
    ll i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = arr[i];


        loc = binary_search(arr, selected, 0, j);


        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}


void print(ll arr[], ll size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
}


int main()
{
    ll n;
    cout << "Enter the size of the array that will be filled with random numbers " << endl;
    cin >> n;
    ll* arr1 = new ll[n];


    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Using Binary insertion sort :  " << endl;
    cout << "******************************" << endl;
    cout << endl;
    for (ll i = 0; i < n; i++)
    {
        arr1[i] = rand() +1;
    }
    auto start = chrono::steady_clock::now();
    binary_insertion_sort(arr1, n);
    auto end = chrono::steady_clock::now();


    //print(arr1, n);

   
    
    cout << "Duration : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " in microseconds" << endl;
    cout << "Duration : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " in milliseconds" << endl;



    cout << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << endl;
    cout << endl;
    ll* arr2 = new ll[n];

    cout << "Using Normal Insertion sort : " << endl;
    cout << "***********************" << endl;
;
    cout << endl;
    for (ll i = 0; i < n; i++)
    {
        arr2[i] = rand() +1;
    }
    start = chrono::steady_clock::now();
    normal_insertion_sort(arr2, n);
    end = chrono::steady_clock::now();
    //print(arr2, n);
  ;
   
    cout << "Duration : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " in microseconds" << endl;
    cout << "Duration : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " in milliseconds" << endl;

    return 0;
}