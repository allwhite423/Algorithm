//
// Insertion Sort O(n^2)
//
// Input
// n - size of list
// list...
// output : sorted list(ascending)

#include <iostream>
using namespace std;

void swap(int*, int*);

void printResult(int list[], int n);

int main() {
    //input
    int n;
    cin >> n;
    
    int *list = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    // Sorting
    for (int i = 1; i < n; i++) { // 1 ~ n-1
        
        for(int j = i; j > 0; j--) { // i ~ 0
            if(list[j-1] > list[j])
                swap(list[j-1], list[j]);
        }
        
        
    }
    
    printResult(list, n);
    
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printResult(int list[], int n) {
    // print sorted list output
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}
