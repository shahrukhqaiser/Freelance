#include <iostream>
using namespace std;

void swap(int* list1, int* list2, int n)
{
	if (n > 0)
	{
		swap(list1, list2,n-1);
		swap(list1[n - 1], list2[n - 1]);
	}
	else
		return;
	
}
//int main()
//{
//	bool flag = true;
//	int size = 0;
//
//	while (flag)
//	{
//		cout << "Enter an even integer in the range[2,100] for the size of the list:";
//		cin >> size;
//
//		if (size >= 2 && size <= 100 && size % 2 == 0)
//		{
//			flag = false;
//		}
//	}
//
//	int* arr = new int[size];
//
//	cout << "Enter " << size << " integers to insert into the list:\n";
//	for (int i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//	swap(arr, arr + size / 2, size / 2);
//	cout << endl;
//
//	cout << "The list after swapping its first half with its second half is:\n";
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i]<<"  ";
//	}
//
//
//}