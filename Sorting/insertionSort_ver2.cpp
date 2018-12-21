//
// Insertion Sort O(n^2)
// ver2 : using key
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
    int key, j;
    for (int i = 1; i < n; i++) { // 1 ~ n-1
        key = list[i];
        
        // 위치 찾을 때 까지 오른쪽으로 이동
        for(j = i-1; j >= 0 && list[j] > key; j--) { // i ~ 0
            list[j+1] = list[j];
        }
        
        // for문에서 decrement 후에, 조건식 check 하므로 +1 해줘야 맞는 자리
        list[j+1] = key;
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
