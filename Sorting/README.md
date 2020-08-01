# Sorting
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Bubble Sort](#bubble-sort)
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)

## Time Complexity (수정 필요)
|$O(n^{2})$| **Selection, Bubble, Insertion** |
|--|--|
|$O(n)$  | **Merge, Quick**  |

## Selection Sort 
[problem in Hackerrank](https://www.hackerrank.com/challenges/insertionsort2/problem) / 
[C++](https://github.com/allwhite423/Algorithm/blob/master/Sorting/selectionSort.cpp)

<br>

자리를 선택한다
1. 자리를 선택한다
2. 정렬안된 list element 중 min/max 를 찾는다
3. 해당 자리 element <-> min/max
4. 다음 자리에서 2,3 반복

- ***i*** : 자리 선택 
	- ***0 ~ n-2*** (n-1은 자동으로 정렬됨. 요소 하나만 남아서)
- ***j*** : min/max를 찾을 대상 list 
	- ***i ~ n-1*** (자기 자신 포함 해야 함!!)

```swift
func insertionSortNoMoreSwaps(_ array: [Int]) -> [Int] {
    var a = array
    for i in 1..<array.count {
        let key = a[i]
        var j = i
        while (j > 0 && a[j-1] > key) {
            a[j] = a[j-1]
            j -= 1
        }
        a[j] = key
    }
    return a
}
```

```c++
#include <iostream>
using namespace std;

class SelectionSort{
    public:
        SelectionSort(int n, int l[]) {
	        //this는 object 자기 자신을 가리키는 pointer 변수
            this->n = n;
            this->list=l;
        }
        void execute();
        void printResult();
    private:
        int n;
        int *list;
};

void SelectionSort::execute() {
    for(int i=0;i < n-1; i++) {
        int minIdx = i;
        for(int j = i; j < n; j++) {
            if(list[j] < list[minIdx])
                minIdx = j;
        }
        int temp = list[minIdx];
        list[minIdx] = list[i];
        list[i] = temp;
    }
}

void SelectionSort::printResult() {
    for(int i =0; i < n; i++) {
        cout<< list[i] << " ";
    }
    cout << endl;
}

int main() {
    
    int n;
    cin >> n;
    
    int *list = new int[n];
    
    for(int i = 0 ; i < n; i++) {
        cin >> list[i];
    }
    
    SelectionSort sort(n, list);
    
    sort.execute();
    sort.printResult();
    
}
```

## Insertion Sort
[C++1](https://github.com/allwhite423/Algorithm/blob/master/Sorting/insertionSort.cpp)

[C++2](https://github.com/allwhite423/Algorithm/blob/master/Sorting/insertionSort_ver2.cpp)


앞쪽에 정렬된 list에 요소를 삽입(Insert)하는 정렬 방법
자리를 찾아가는 과정

- ***i*** : 정렬된 list 에 넣을 요소. 자리를 찾아줘야 함
	- ***1 ~ n-1*** (맨 앞의 요소는 이미 정렬되었음)
- ***j*** : 새로 넣을 값과 비교할 정렬된 list element를 가리키는 index
	- ***i ~ 0*** (거꾸로 비교해 나감) 

```c++
//execute 함수만 구현 
void InsertionSort::execute() {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) { //-- 주의!!
            if(list[j] < list[j-1]){
                int temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
            }
        }
    }
}
```

## Bubble Sort
[C++](https://github.com/allwhite423/Algorithm/blob/master/Sorting/bubbleSort.cpp)

<br>

인접한 두개 요소를 계속해서 비교하여 정렬
뒤쪽에서부터 정렬됨

- ***i*** : 범위 지정 경계
	- ***n-1 ~ 1*** (마지막 요소 하나는 자동으로 정렬되니까)
- ***j*** : 인접 요소 비교하는 인덱스
	- j & j+1 을 비교
	- ***0 ~ n-2***  (n-2, n-1을 비교)

```c++
void BubbleSort::execute() {
    for(int i = n-1; i > 0; i-- ) {
        for(int j = 0; j < i; j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
        printResult();
    }
}
```

## Merge Sort
주어진 list를 2개로 계속해서 나눈다.
나누어진 list가 충분히 작으면 merge 한다.
merge하면서 순서대로 함

- recursion으로 구현 가능
- base condition(기저조건) : list가 충분히 작을 때 
- == list 요소가 한개이거나 두개일 때
- 같은 크기의 leftList, rightList 로 나눈 후, 각 list에 대해 mergeSort를 호출
- 그 결과를 ***merge()*** 함수로 합친다.
- 합칠 때, 순서대로 정렬됨

- ***mergeSort(list, start, end)***
```c++
# include <stdio.h>
# define MAX_SIZE 8
int tempList[MAX_SIZE]; // 추가적인 공간이 필요

void merge(int list[], int start, int mid, int end) {

int x = start, y = mid+1; // left list index, right list index
int z = s; //index for tempList
int z = start;

while(x <= mid && y <= end) {
if(list[x] < list[y]) {
tempList[z++] = list[x++];
} else {
tempList[z++] = list[y++];
}
}

while(x <= mid) {
tempList[z++] = list[x++];
}

while(y <= end) {
tempList[z++] = list[y++];
}

for(int i = start; i <= end; i++) {
list[i] = tempList[i];
} 
}

void mergeSort(int list[], int start, int end) {
int mid;
if(start < end) {
mid = (end + start) / 2;
mergeSort(list, start, mid);
mergeSort(list, mid+1, end);
merge(list, start, mid, end);
}
}


int main() {
int i;
int n = MAX_SIZE;
int list[n] = {21, 10, 12, 20, 25, 13, 15, 22};

// 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
mergeSort(list, 0, n-1);

// 정렬 결과 출력
for(i=0; i<n; i++){
printf("%d ", list[i]);
}

return 0;

}

```
## Quick Sort
pivot의 위치를 반복해서 구하여 전체 list를 정렬하는 방법
pivot(기준 값)을 기준으로 왼쪽은 작은 값, 오른쪽은 큰 값이 되도록 이동.
왼쪽, 오른쪽 리스트 각각에 대해 다시 quick sort 수행.

- base condition : list의 요소가 1개일 때
- 

>[sort참조](https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html)
