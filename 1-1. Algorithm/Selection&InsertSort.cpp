#include <iostream>

using namespace std;

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
void selection_sort(int list[], int n) {
    int i, j, least, tmp;
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], tmp);
        //print
        cout << "step " << i+1 << " = ";
        for (int k = 0; k < 9; k++)
        {
            cout << list[k] << " ";
        }
        cout << endl;
       //printstep(list, n, i + 1);
    }
}

void printArray(int list[], int size, string msg)
{
    cout << "[" << msg << "] = ";
    for (int i = 0; i <  size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
/*void printstep(int list[], int n, int k)
{
    cout << "step " << k << " = ";
    for (int i = 0; i < n; i++)
        cout << list[i];
    for (int i = k; i < 9; i++)
        cout << list[i];
    cout << endl;
}*/

//삽입정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; //레코드의 오른쪽 이동
        list[j + 1] = key;
        //printstep(list, n, i); //중간 출력과정-함수
        cout << "step " << i + 1 << " = ";
        for (int k = 0; k < 9; k++)
        {
            cout << list[k] << " ";
        }
        cout << endl;
    }
}

void main() {
    int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
    printArray(list, 9, "original");
    //selection_sort(list, 9);//선택정렬
    //printArray(list, 9, "selection");
    insertion_sort(list, 9);//삽입정렬
    printArray(list, 9, "insertion");
}