<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>

## Recursion 재귀

### 귀납적 계산법
구하는 값을 $f(x)$ 라고 할 때, 
$f(x)$ 를 구하기 위해 또 다시 $f(x)$ 를 사용하는 것

예제) $n^{m}$을 귀납적으로 계산하기
$n^{m} = n^{m-1} \times n$ , $n^{0} = 1$
$5^{4} = 5^{3} \times 5$
$5^{3} = 5^{2} \times 5$
...
$5^{0} = 1$

### 수학적 귀납법
- 명제 : $P(n)$이 모든 자연수 n에 대해 성립함을 보여라
- 증명순서
	1. $P(1)$ 이 참임을 보이고
	2. $P(k)$가 참이라고 가정한 후, $P(k+1)$이 성립함을 보인다
	3. 따라서 모든 자연수 n에 대하여 $P(n)$이 성립한다.
- 예제) 모든 자연수 n에 대하여 다음이 성립함을 보여라
$$1 + 2 + \cdots + n = \frac{n(n+1)}{2}$$ 
1. n = 1일때, 성립함
	$\frac{n(n+1)}{2} = \frac{1 \times 2}{2} = 1$
2.  k일 때, 다음 식이 성립한다고 가정하고 k+1일 때 성립함
	$1 + 2 + \cdots + k = \frac{k(k+1)}{2}$ 
	양변에 k+1을 더한다
	$1 + 2 + \cdots + k + (k+1) = \frac{k(k+1)}{2} + (k+1) = \frac{k(k+1) + 2(k+1)}{2} = \frac{(k+1)(k+2)}{2}$ => 성립함

	$\therefore$ 위 식은 성립함


### 재귀함수
- 재귀함수는 수학적 귀납법을 적용하여, 귀납적으로 문제를 계산하는 방법
- 함수 코드 자체가 증명 과정과 같다
- 예시) ***getFactorial(n)*** 함수 : **n!** 값을 반환
	1. n = 0 : 1을 반환
	2. n = k-1일 때, 제대로 동작한다고 가정하면, n = k일 때 ***getFactorial(k) * (k-1)*** 을 반환

```c++
int getFactorial(int n) {
	if(n == 0) 
		return 1;
	else 
		return getFactorial(n-1) * n;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", getFactorial(n));
}
```

### 재귀함수 디자인 (중요)
1. 함수의 역할을 **말로 정확하게** 정의한다
2. **기저조건(Base condition)** 에서 함수가 제대로 동작함을 보인다
3. 함수가 (작은 input 에 대하여) **제대로 동작한다고 가정하고** 함수를 완성한다.

- 예제 1) $n^{m}$을 재귀함수를 이용하여 계산하기
	- ***getPower(n, m)*** : $n^{m}$을 반환하는 함수
$$getPower(n, m) 
=\begin{cases} 1,  
& \text{if $m$ equal 0 (기저조건)} \\
getPower(n, m-1) \times n, & \text{if $n^{m-1}$ is true(ok)}
\end{cases} $$

```c++
int getPower(int n, int m) {
	if(m == 0) 
		return 1;
	else 
		return getPower(n, m-1) * n;
}
```

- 예제 1) n to m : _n_ 부터 _m_ 까지 숫자의 합을 구하는 함수
	- ***getSum(n, m)*** : _n_ 부터 _m_ 까지 숫자의 합을 구하는 함수
	- 3+ 4+ 5 = (3+4) + 5
$$
getSum(n, m) 
=\begin{cases} n,  
& \text{if $n$ = $m$ (=getSum(n, n) } \\
getPower(n, m-1) + m , & \text{if else}
\end{cases} 
$$

```c++
int getSum(int n, int m) {
	if(n == m) 
		return n;
	else 
		return getSum(n, m-1) + m;
}
```

- 예제 3) 각 자릿수의 합 : 십진수 n을 입력받아 각 자릿수의 합을 구하기
	- 10 -> 1 / 12321 -> 9
	- (1232 합) + 1
	- ***getDigitSum(x)*** : x의 각 자릿수의 합을 반환
$$
getDigitSum(x) 
=\begin{cases} x,  
& \text{if x가 한자릿수 } \\
getDigitSum(x/10) + getDigitSum( x m 10 ), 
& \text {if else (m : 나머지)}
\end{cases} 
$$

```c++
int getDigitSum(int x) {
	if(x < 10 && x >= 0) 
		return x;
	else 
		return getDigitSum(x/10) + getDigitSum(x%10);
}
```

- 예제 4) 이진수 출력하기 : 십진수 n을 입력받아 이진수로 변환하여 반환
	- n을 2로 나눠서 나머지는 놓고, 몫을 계속 2로 나눈다
	- 몫이 1이 될 때까지 나눈 뒤, 나머지를 거꾸로 읽으면 이진수임
	- 10 = 5 * 2 ... 0
	- 5의 이진수(101) + 뒤에 0붙이면 10의 이진수(1010)가 됨
	- ***printBinary(x)*** : x를 이진수로 바꾼 결과를 출력함
	- 기저조건 : x 가 1, 0이면 그대로 반환
	- 그 외의 값이면 x/2를 다시 printBinary에 넘기고 나머지를 뒤에 출력
$$
printBinary(x) 
=\begin{cases} x,  
& \text{if x = 0 or 1 } \\
printBinary(x/2),  print x m 2, 
& \text {if else (m : 나머지)}
\end{cases} 
$$

```c++
int printBinary(int x) {
	if(x == 0 || x == 1) 
		printf("%d", &x);
	else {
		printBinary(x / 2);
		printf("%d", x % 2);
	}
}
```

- 예제 5) 팰린드롬 판별 : 입력받은 문자열이 팰린드롬인지 판별하라
	- 팰린드롬 : 뒤집어도 똑같은 문자열
	- abcba -> yes / aabb -> no
	- ***isPalindrome(myString, start, end)*** : myString의 start ~ end가 팰린드롬이면 true, 아니면 false를 반환
	- 기저조건 
		- 문자열 길이가 짝수 : start + 1 == end -> 같으면 true, 아니면 false
		- 문자열 길이가 홀수 : start == end이면 return true;
	- 그 외엔 isPalindrome(myString, start+1, end-1) && myString[start] == myString[end]
```c++
#include <stdio.h>
#include <string.h>

int isPalindrome(char myString[], int start, int end) {
	if(start == end) 
		return true;
	else if(start + 1 == end ) {
		return myString[start] == myString[end];
	} else {
		return isPalindrome(myString, start + 1, end - 1) 
				&& myString[start] == myString[end];
	}
	
}

int main() {
	char myString[100];
	scanf("%s", myString");
	
	int len = strlen(myString);
	
	if( isPalindrom(myString, 0, len-1) )
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
```
