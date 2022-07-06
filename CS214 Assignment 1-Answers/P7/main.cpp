#include<iostream>
#include<vector>
using namespace std;

void updatedInsertionSort(vector<string>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		string temp = vec[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (vec[j] == "Untitled")break;// don't sort the Untitled part of the vector

			if (temp < vec[j] || temp == "Untitled")
			{
				vec[j + 1] = vec[j];
			}
			else break;
		}
		vec[j + 1] = temp;
	}
}

int main()
{
	vector<string>vec={ "Runaway","Hello","Jungle","Untitled","Older","Blue","Awakening","Untitled","Close to me","Freaks","Alone","Untitled" };
	cout << "THE songs before sorting:" << endl;
	for (int i = 0; i < 12; i++)
		cout << vec[i] << endl;
	updatedInsertionSort(vec);
	cout << "THE songs after sorting:" << endl;
	for (int i = 0; i < 12; i++)
		cout << vec[i] << endl;
}
