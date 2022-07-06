
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
using namespace std::chrono;

#define boom ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
#define endl "\n";



class Sorter
{
public:
    virtual void sort(vector<ll>& data, ll size)
    {

    }
};



class SelectionSort : public Sorter
{
public :
    void sort(vector <ll>& data, ll size)
    {
        for (ll i = 0; i < size - 1; i++)
        {
            ll minidx = i;
            for (ll j = i + 1; j < size; j++)
            {
                if (data[j] < data[minidx])
                {
                    minidx = j;
                }
            }
            swap(data[minidx], data[i]);
        }
    }

};


class QuickSort : public Sorter
{
public :


    void sort(vector<ll>& data, ll size)
    {
        quickSort(data, 0, size - 1);
    }

    void quickSort(vector<ll>&data, ll left, ll right)
    {
        ll i = left, j = right;
        ll pivot = data[(left + right) / 2];

        while (i <= j) {
            while (data[i] < pivot)
                i++;
            while (data[j] > pivot)
                j--;
            if (i <= j)
            {
                swap(data[i], data[j]);
                i++;
                j--;
            }
        }

        if (left < j) {

            quickSort(data, left, j);
        }
        if (i < right) {

            quickSort(data, i, right);
        }

    }



};


class Testbed
{
private:
    vector <ll> data;
public:

    void GenerateRandomList(ll min, ll max, ll size)
    {
        for (ll i = 0; i < size; i++)
        {
            data.push_back(rand() % (max - min + 1) + min);
        }
    }


    void GenerateReverseOrderedList(ll min, ll  max, ll size)
    {
        GenerateRandomList(min, max, size);
        sort(data.begin(), data.end(), greater <ll>());
    }


    ll RunOnce(Sorter* a, vector<ll>& data, ll size)
    {
        auto start = chrono::high_resolution_clock::now();
        a->sort(data, size);
        auto end = chrono::high_resolution_clock::now();

        return chrono::duration_cast<chrono::microseconds>(end - start).count();

    }


    long long RunAndAverage(Sorter* a, int type, ll min, ll max, ll size, ll sets_num)
    {
        ll duration = 0;
        if (type == 0)
        {
            for (ll i = 0; i < sets_num; i++)
            {
                GenerateRandomList(min, max, size);
                duration += RunOnce(a, data, size);

            }
        }
        else if (type == 1)
        {

            for (ll i = 0; i < sets_num; i++)
            {
                GenerateReverseOrderedList(min, max, size);
                duration += RunOnce(a, data, size);
            }
        }
        return (duration / sets_num);
    }


    void RunExperient(Sorter* a, int type, ll  min, ll max, ll min_val, ll max_val, ll sets_num, ll step)
    {
        cout<<"Set Size"<<setw(30)<<"Time Average\n";
        for (ll i = min_val; i <= max_val; i += step)
        {
            long long average = RunAndAverage(a, type, min, max, i, sets_num);
            cout << i << setw(28)<< average << endl;

        }
    }
};



int main()
{
    int type;
    cout << "Enter the type of list : " << endl;
    cin >> type;


    ll min;
    cout << "Enter the mimimum number of list : " << endl;
    cin >> min;


    ll max;
    cout << "Enter the maximum number of list : " << endl;
    cin >> max;

    ll min_val;
    cout << "Enter the minimum size : " << endl;
    cin >> min_val;

    ll max_val;
    cout << "Enter the maximum size : " << endl;
    cin >> max_val;


    ll sets_num;
    cout << "Enter the number of sets : " << endl;
    cin >> sets_num;

    ll step;
    cout << "Enter the step value : " << endl;
    cin >> step;




    cout << endl;
    cout << endl;
    Testbed X;
    Sorter* Q = new QuickSort();
    cout << "Using Quick sort ::->  " << endl;
    cout << "**********************" << endl;

    X.RunExperient(Q, type, min, max, min_val, max_val, sets_num, step);
    cout << endl;
    cout << endl;

    cout << "*********************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    Testbed Y;
    Sorter* S = new SelectionSort();
    cout << "Using Selection sort ::->  " << endl;
    cout << "**************************" << endl;

    Y.RunExperient(S, type, min, max, min_val, max_val, sets_num, step);

    return 0;
}
