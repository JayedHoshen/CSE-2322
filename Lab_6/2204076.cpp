#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn]) mn = j;
        }
        swap(a[i], a[mn]);
    }
}

void merge(int arr[], int l, int m, int r) {
    int a = m - l + 1, b = r - m, L[100], R[100];
    for (int i = 0; i < a; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < b; i++)
        R[i] = arr[m + l + i];
    int i = 0, j = 0, k = l;
    while (i < a && j < b) {
        if (L[i] <= R[j]) arr[k] = L[i];
        else arr[k] = R[j];
        k++;  i++; j++;
    }
    while (i < a) arr[k++] = L[i++];
    while (j < b) arr[k++] = R[j++];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n = 7;
    int a[] = {38, 27, 43, 3, 9, 38, 10};
    
    int choice;
    cout << "1.Selection Sort  2.Merge Sort\nChoice a type: ";
    cin >> choice;

    if (choice == 1) selectionSort(a, n);
    else mergeSort(a, 0, n - 1);
    
    cout << "Sorted: ";
    print(a, n);

    return 0;
}