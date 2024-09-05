#include "Sorting.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include <queue>
#include<fstream>
using namespace std;
class compare {
public:
	bool operator()(int& a, int& b)
	{
		return a >= b;
	}
};
void fileWriter(string fName, int size) {
	ofstream Writer(fName);
	srand(time(0));
	for (int i = 0; i < size * 1024 ; i++)
	{
		Writer << rand() % 10 << endl;
	}
}
vector<int> fileReader(const string& fName) {
	ifstream Reader(fName);
	vector<int> data;

	if (!Reader) {
		cerr << "Error opening file: " << fName << endl;
		return data;
	}

	int number;
	while (Reader >> number) {
		data.push_back(number);
	}

	Reader.close();
	return data;
}
template<class T>
void HeapSort(vector<T>& v)
{
	priority_queue<T, vector <T>, compare>PQ;
	for (int vi = 0; vi < v.size(); vi++)
	{
		PQ.push(v[vi]);
	}
	v.clear();
	while (!PQ.empty())
	{
		v.push_back(PQ.top());
		PQ.pop();
	}
}
void Randomized_init(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 100;
	}
}
void Vector_Print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl << endl<<endl;
}
bool SwappingallTheWay(vector<int>& v)
{
	bool ChangeHappen = false;
	for (int i = 0; i < v.size() - 1;i++)
	{
		if (v[i] > v[i + 1])
		{
			swap(v[i], v[i + 1]);
			ChangeHappen = true;
		}
	}
	return ChangeHappen;
}
void BubbleSort(vector<int> & v)
{
	while (SwappingallTheWay(v)){}
}
int FindMinRange(vector<int>& v, int si, int ei)
{
	int mi = si;
	for (int i = si + 1; i <= ei; i++)
	{
		if (v[mi] > v[i])
		{
			mi = i;
		}
	}
	return mi;
}

void SelectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int mi = FindMinRange(v, i, v.size() - 1);
		swap(v[i], v[mi]);
	}
}

int Partition(vector<int>&v, int left, int right, int pi)
{
	int pivot = v[pi];
	int i = left;
	int j = left;
	swap(v[pi], v[right]);
	pi = right;
	int range = right - left + 1;
	while (j <= range)
	{
		if (v[j] >= v[pi])
		{
			i = i + 1;
			swap(v[i], v[j]);
		}
		j++;
	}
	swap(v[i + 1], v[pi]);
	return i + 1;
}
void QuickSort(vector<int>& v, int si, int ei)
{
	if (si >= ei)
	{
		return;
	}
	int pi = (rand() % (ei - si + 1)) + si;
	pi = Partition(v, si, ei, pi);
	QuickSort(v, si, pi - 1);
	QuickSort(v, pi + 1, ei);
}
void mainQuickSort(vector<int>& v)
{
	QuickSort(v, 0, v.size() - 1);
}
int main() {
	int size = 1;
	string path = "File.txt";
	fileWriter(path, size);
	vector<int> values = fileReader(path);

	cout << "Before Sorting.........." << endl;
	Vector_Print(values);
	cout << time(0) << endl;

	int choice;
	cout << "Choose a sorting algorithm:" << endl;
	cout << "1. QuickSort" << endl;
	cout << "2. SelectionSort" << endl;
	cout << "3. BubbleSort" << endl;
	cout << "4. HeapSort" << endl;

	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Using QuickSort:" << endl;
		mainQuickSort(values);
		break;
	case 2:
		cout << "Using SelectionSort:" << endl;
		SelectionSort(values);
		break;
	case 3:
		cout << "Using BubbleSort:" << endl;
		BubbleSort(values);
		break;
	case 4:
		cout << "Using HeapSort:" << endl;
		HeapSort(values);
		break;
	default:
		cout << "Invalid choice." << endl;
		break;
	}

	cout << "After Sorting............" << endl;
	Vector_Print(values);
	cout << time(0) << endl;

	return 0;
}
