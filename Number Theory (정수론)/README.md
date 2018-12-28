## Number Theory 정수론
- [Euclidean algorithm 유클리드호제법](https://github.com/allwhite423/Algorithm/tree/master/Number%20Theory%20(%EC%A0%95%EC%88%98%EB%A1%A0)#euclidean-algorithm-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C%ED%98%B8%EC%A0%9C%EB%B2%95)
- [소수 관련 알고리즘](https://github.com/allwhite423/Algorithm/tree/master/Number%20Theory%20(%EC%A0%95%EC%88%98%EB%A1%A0)#%EC%86%8C%EC%88%98%EA%B4%80%EB%A0%A8-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)


### Euclidean algorithm 유클리드호제법
>[참조](http://lonpeach.com/2017/11/12/Euclidean-algorithm/)

**최대 공약수(GCD: Greatest Common Divisor**) 를 구하는 방법

- 개념
	- 2개의 수 a, b가 있을 때 (a > b)
	- ***a % b = r*** (a를 b로 나눈 나머지)라 할 때
	- **a & b의 최대공약수는 b & r의 최대공약수와 같음**을 이용
	- a % b = r 하고, **b-> a, r->b**에 넣고 계속 반복하여 나머지가 0일 때까지 반복
	- 나머지가 0이 될 때, 그때의 b가 최대공약수

- 구현
	- Java
	- C++
```c++
int gcd(int a, int b) {
    int r = a % b;
    
    while(r != 0) {
        a = b;
        b = r;
        
        r = a % b;
    }
    
    return b;
}

int gcd2(int a, int b) {
	while(b > 0) {
		int temp = a;
		a = b;
		b = temp % b;
	}
	
	return a;
}

int recursiveGCD(int a, int b) {

	/* 
     * eqaul logic
     * if (b==0) return a;
     * gcd(b, a%b)
    */

    return b? recursiveGCD(b, a % b) : a;
}
```
> 0 : false, 1: true
**최소 공배수(LCM: Lowest Common Multiple)*** 구하는 방법
- 최대 공약수(GCD) 사용해서 도출 가능
- a = gcd * x , b = gcd * y 라고 할 때, x & y는 서로소 
- 최소공배수 = x * y * gcd = (a/gcd) * (b/gcd) * gcd = a*b/gcd

```c++
int lcm(int a, int b){
	return a * b / gcd(a, b);
}
```
### 소수관련 알고리즘
> [참조](https://ratsgo.github.io/data%20structure&algorithm/2017/10/07/prime/)

- 소수 판별
	- 소수 = 1과 자기자신으로만 나누어 떨어지는 수
	- 2~해당 수 까지 돌면서 나누어 떨어지면 소수 아님 
	- 혹은 범위를 더 작게 - 1~ √n에 약수 범위의 반이 존재하는 성질을 이용
	- [참조](http://marobiana.tistory.com/89)
	```c++
	#include <cmath> //sqrt()함수 사용 위해
	int isPrime(int n) {
		int flag = true;
		int sn = sqrt(n);
		for(int i = 2; i <= sn; i++ ) {
			if(n % i == 0 ) {
				flag = false;
				break;
			}
		} 
		return flag;
	}
	int main() {
		int n;
		cin >> n;
		if(isPrime(n)) {
			cout<< "prime" << endl;
		} else {
			cout<< "not prime" << endl;
		}
		
		return 0;
	}
	
	```
- 소인수분해
	- 어떤 숫자를 소수들의 곱으로만 나타낸 것
	- [참조코드](https://aossuper8.tistory.com/7)
- 특정 범위 내 소수 찾기
	- ***에라토스테네스의 체 알고리즘(Sieve of Eratosthenes)***





