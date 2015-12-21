#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 5
December 20th, 2015
Clay Gardner

https://projecteuler.net/problem=5
Solved the above problem.
Input: 1 20
Output: 232792560
Time: sys	sys	0m0.003s

https://www.hackerrank.com/contests/projecteuler/challenges/euler005
Solved for full points.
*/

int gcd(int m, int n) {
	int r;
    while (n!=0){
    	r=m%n;
    	m=n;
    	n=r;
    }
    return m;
}
int lcm(int m, int n){
	return (m*n)/gcd(m,n);
}
//Iterative least common multiple from 1 to n
int smallestMultiple(int n) {
	long i, t=1;
	for(i = 2; i  <= n; i++){
		if(t%i!=0){
			t=lcm(t,i);
		}
	}
	return t;
}

int main() {
	int count, i;
	long n, sm;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		scanf("%lu\n", &n);
   	 	sm = smallestMultiple(n);
		printf("%lu\n", sm);
    }
	return 0;
}