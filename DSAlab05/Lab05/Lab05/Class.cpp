#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;
int Sum(int n);
int SumWith2Diff(int n);
double SumWithPower(int n);
double SumWithPower3(int n);
double TSum(int n);
double TSum2(int n);
int DToB(int a);
int GCD(int a,int b);
string IntToString(int a);
bool SearchFirstEntry(int a[],int size, int num);
bool SearchLastEntry(int a[], int size, int num);
bool BinarySearch(int a[],int start, int size, int num);
int Power(int a, int b);
double PowerWithLessTime(int a, int b);
double Add(int a, int b);
double FastAdd(int a, int b);
double FAdd(int a, int b);
double FibItrative(int a);
int FibRecursive(int a);
long long FibHelper(vector<double>& FS, int a);
long long FibMemoization(int a);
int TriSumRecursive(int a);
double TrisumHelper(vector<double>& FS, int a);
double TriSumMemoization(int a);
double TrisumItrative(int a);
long long Sub(int a, int b);
long long FSub(int a, int b);
long long FibBottomUp(int a);
long long TriSumBottomUp(int a);
void SubArrays(vector<int> arr,int start,int end);
void sortStack(stack<int>& s);
int c = 0;
string s;

int main() 
{
	stack<int> s;

	s.push(34);
	s.push(3);
	s.push(31);
	s.push(98);
	s.push(92);
	s.push(23);

	sortStack(s);

	cout << "Sorted numbers are: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
int Sum(int n)
{
	if (n == 0) {
		return 0;
	}
	return n + Sum(n - 1);
}
int SumWith2Diff(int n)
{
	if (n == 1) {
		return 1;
	}
	return n + SumWith2Diff(n - 2);
}
double SumWithPower(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return pow(2, n) + SumWithPower(n - 1);
}
double SumWithPower3(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return pow(3, n) + SumWithPower3(n - 1);
}
double TSum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + TSum(n / 3);
}
double TSum2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + TSum2(n / 2);
}
int GCD(int a,int b)
{
	if (a % b==0)
	{
		return b;
	}
	return GCD(b, a % b);
}
string IntToString(int a)
{
	if (a/10==0)
	{
		return to_string(a %10);
	}
	return s+IntToString(a/10)+to_string(a%10);
}
int DToB(int a)
{
	if (a == 0)
	{
		return 0;
	}
	return DToB(a / 2) * 10 + a % 2;
}
bool SearchFirstEntry(int a[],int size,int num)
{
	if ( *a == num)
	{
		return true;
	}
	c++;
	if(c!=size)
	{ 
		return SearchFirstEntry(a + 1, size, num);
	}
	else
	{
		return false;
	}
}
bool SearchLastEntry(int a[], int size, int num)
{
	if (a[size] == num)
	{
		return true;
	}
	if (!(size<=0))
	{
		return SearchFirstEntry(a, size-1, num);
	}
	else
	{
		return false;
	}
}
bool BinarySearch(int a[],int start, int size, int num)
{
	
	if (start > size)
	{
		return false;
	}
	int mid = (start+ size) / 2;

	if (a[mid] == num) {
		return true;
	}
	else if (a[mid] > num) {
		return BinarySearch(a, start,mid-1,num);
	}
	else {
		return BinarySearch(a, mid+1, size, num);
	}
}
int Power(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	return a * Power(a, b - 1);
}
double PowerWithLessTime(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	double Power = PowerWithLessTime(a, b / 2);
	if (b % 2 == 0)
	{
		return  a * a;
	}
	else if(b%2==1)
	{
		return a * Power * Power;
	}
}
double Add(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	return a + Add(a, b - 1);
}
double FastAdd(int a, int b)       //it is also witn log n time complexity problem.
{
	if (b == 0)
	{
		return 0;
	}
	else if (b % 2 == 0)
	{
		return FastAdd(a+a, b / 2);
	}
	else
	{
		return FastAdd(a+a, b / 2) + a;
	}
}
double FAdd(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	int T = a, c = 1;
	while (c + c <= b)
	{
		T += T;
		c += c;
	}
	return T + FAdd(a, b - c);
}
double FibItrative(int a)
{
	int fib=0;
	for (int i = a; i > 0; i-=2)
	{
		fib = i + (i - 1);
	}
	return fib;
}
int FibRecursive(int a)
{
	if (a==1||a==0)
	{
		return a;
	}
	else
	return FibRecursive(a - 1) + FibRecursive(a - 2);
}
long long FibHelper(vector<double> &FS, int a)
{
	if (FS[a]!=-1)
	{
		return FS[a];
	}
	if (a == 1 || a == 0)
	{
		return a;
	}
	FS[a] = FibHelper(FS,a - 1)+FibHelper(FS,a-2);
	return FS[a];
}
long long FibMemoization(int a)
{
	vector<double> FS(a + 1, { -1 });
	FS[1] = 1;
	return FibHelper(FS, a);
}
long long FibBottomUp(int a)
{
	vector<long long> vector(a + 1, { -1 });
	vector[0] = 0, vector[1] = 1;
	for (int fib = 2; fib <= a; fib++)
	{
		vector[fib] = vector[fib - 1] + vector[fib - 2];
	}
	return vector[a];
}
double TrisumItrative(int a)
{
	int fib = 0;
	for (int i = a; i > 0; i -= 3)
	{
		fib += i + (i - 1)+(i-2);
	}
	return fib;
}
int TriSumRecursive(int a)
{
	if (a == 1 || a == 0||a==2)
	{
		return a;
	}
		return TriSumRecursive(a - 1) + TriSumRecursive(a - 2)+TriSumRecursive(a-3);
}
double TrisumHelper(vector<double>& FS, int a)
{
	if (FS[a] != -1)
	{
		return FS[a];
	}
	if (a == 1 || a == 0||a==2)
	{
		return a;
	}
	FS[a] = TrisumHelper(FS, a - 1) + TrisumHelper(FS, a - 2)+TrisumHelper(FS,a-3);
	return FS[a];
}
double TriSumMemoization(int a)
{
	vector<double> FS(a + 1, { -1 });
	FS[1] = 1;
	return TrisumHelper(FS, a);
}
long long TriSumBottomUp(int a)
{
	vector<long long> vector(a + 1, { -1 });
	vector[0] = 0, vector[1] = 1;
	for (int fib = 3; fib <= a; fib++)
	{
		vector[fib] = vector[fib - 1] + vector[fib - 2]+vector[fib-3];
	}
	return vector[a];
}
long long Sub(int a, int b)
{
	if (a == 0)
	{
		return c;
	}
	c++;
	return Sub(a - b, b);
}
long long FSub(int a, int b)
{
	if (a < b)
	{
		return 0;
	}
	int T = b, c = 1;
	while (T+T<= a)
	{
		T +=T;
		c += c;
	}
	return c + FSub(a - T, b);
}
////////////////////////Challenge01/////////////////////
void SubArrays(vector<int>arr,int start,int end)
{
		if (end == arr.size())
			return;
		else if (start > end)
			SubArrays(arr, 0, end + 1);
		else {
			cout << "[";
			for (int i = start; i < end; i++)
				cout << arr[i] << ", ";
			cout << arr[end] << "]" << endl;
			SubArrays(arr, start + 1, end);
		}
		return;
}
///////////////////////Chalange02//////////////
void sortStack(stack<int>& s) 
{
	if (s.empty())
		return;

	int x = s.top();
	s.pop();

	sortStack(s);

	stack<int> tempStack;

	while (!s.empty() && s.top() > x) {
		tempStack.push(s.top());
		s.pop();
	}
	s.push(x);
	while (!tempStack.empty()) {
		s.push(tempStack.top());
		tempStack.pop();
	}
}



 