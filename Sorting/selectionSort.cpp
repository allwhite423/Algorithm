// 
// Selection Sort O(n^2)
//
// Input
// n - size of list
// list...
// output : sorted list(ascending)

#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    //input
    int n;
    cin >> n;
    
    int *list = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    // Sorting
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        
        for (int j = i; j < n; j++) {
            if(list[minIndex] > list[j]) // update minimum element
                minIndex = j;
        }
        
        swap(list[minIndex], list[i]);
        
    }
    
    // print sorted list output
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    
    return 0;
}
