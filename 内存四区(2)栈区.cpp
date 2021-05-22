#include<iostream>
using namespace std;

void func()
{
	int* p = new int(10);
	return p;
}
int main()
{
	int* p = func();
	cout << *p << endl;

	system("pause");
	return 0;
}