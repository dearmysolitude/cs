#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#define MAX 100
using namespace std;

//int Arr[MAX];
bool Flag[301];
const int a = 10;
int Arr[a] = {5, 3, 8, 4, 9, 1, 6, 2, 7, 10};


void Print()
{
	cout << "###############################################################################" << endl;
	//int Cnt = 0;
	for (int i = 0; i < a; i++)
	{
		printf("%3d ", Arr[i]);
		//Cnt++;
		//if (Cnt == 20)
		//{
		//	Cnt = 0;
		//	cout << endl;
		//}
	}
	cout << endl;
	cout << "###############################################################################" << endl;
	cout << endl;
}

void Interval_Sort(int Start, int End, int Gap)
{
	for (int i = Start + Gap; i <= End; i = i + Gap)
	{
		int Temp = Arr[i];
		int j;
		for (j = i - Gap; j >= Start; j = j - Gap)
		{
			if (Arr[j] > Temp)
			{
				Arr[j + Gap] = Arr[j];
				Arr[j] = Temp;
			}
			else break;
		}
	}
}

void Shell_Sort()
{
	for (int Interval = a / 2; Interval > 0; Interval = Interval / 2)
	{
		if ((Interval % 2) == 0)
			Interval++;
		for (int i = 0; i < Interval; i++)
		{
			Interval_Sort(i, a - 1, Interval);
		}
	}
}

int main(void)
{
	//srand((unsigned)time(NULL));
	for (int i = 0; i < a; i++)
	{
		//Arr[i] = (rand() % 300) + 1;
		if (Flag[Arr[i] == false])
		{
			Flag[Arr[i]] = true;
			i++;
		}
	}
	cout << "[Initialize Array State]" << endl;
	Print();
	Shell_Sort();
	cout << "[After Sort Array State]" << endl;
	Print();

	return 0;
}