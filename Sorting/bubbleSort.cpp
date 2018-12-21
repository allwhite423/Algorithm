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
    for (int i = n-1; i >= 1; i--) { // 경계값 n-1 ~ 1
        
        for(int j = 0; j < i; j++) { // 0 ~ i-1 (0 ~ n-2)
            //인접한 요소 비교 (j & j+1)
            if(list[j] > list[j+1])
                swap(list[j], list[j+1]);
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
