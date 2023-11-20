#include <iostream>

using namespace std;

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) //

void printstep(int list[], int ctr)
{
    cout << "step " << ctr << " = ";
    for (int k = 0; k < 9; k++)
    {
        cout << list[k] << " ";
    }
    return;
}

void printArray(int list[], int size, string msg)
{
    cout << "[" << msg << "] = ";
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

//선택정렬
void selection_sort(int list[], int n) {
    int i, j, least, tmp;
    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], tmp);
        //print
       printstep(list, n-i);
    }
}

//삽입정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; //레코드의 오른쪽 이동
        list[j + 1] = key;
        printstep(list, n - i);
        cout << endl;
    }
}

//버블정렬
void bubble_sort(int list[], int n) {
    int i, j, bChanged, tmp;
    for (i = n - 1; i > 0; i--) {
        bChanged = 0;
        for(j = 0; j <i; j++)
            if (list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], tmp);
                bChanged = 1;
                //print
                printstep(list, n - i);
                cout << endl;
            }
        if (!bChanged) break;
    }
}

int main() {
    int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
    printArray(list, 9, "original");

    //선택 정렬
    //selection_sort(list, 9);
    //printArray(list, 9, "selection");
 
    // 삽입정렬
    //insertion_sort(list, 9);//
    //printArray(list, 9, "insertion");

    //버블 정렬
    bubble_sort(list, 9);
    printArray(list, 9, "bubble");

    return 0;
}