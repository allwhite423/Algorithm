# Sorting
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Bubble Sort](#bubble-sort)

## Selection Sort 
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
