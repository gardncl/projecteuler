#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* 
Project Euler: Problem 4
December 19th, 2015
Clay Gardner

https://projecteuler.net/problem=4
Find the largest palindrome made from the product of two 3-digit numbers.
Solved the above problem.
NOTE: 998001 = 999*999
Input: 1 998001 
Output: 906609
Time: sys  0m0.003s

https://www.hackerrank.com/contests/projecteuler/challenges/euler004
Solved for full points.
*/

//Finds the first palindrome under or including 
//the given six digit number.
int generatePalindromeUnder(int num) {
  
    char str[7];
    int i;
   
    while(num > 101101) {
        intToString(&str,num);
        if(isPalindrome(str,6)&&multipleThreeDigits(num)){
          return num;
        }
        num--;
    }
    return 101101;
}

//Backwards, but this is for testing palindromes
//so that doesn't change our answer.
int intToString(char* str, int num) {
  int i,x;
  for(i = 0; num !=0; i++){
    x=num%10;
    if(num>=10){
      num = (int)num/10;
    } else {
      num=0;
    }
    if (x>=0 && x <=9) {
      str[i]=x+'0';
    }
  }
  str[i]=NULL;
  return i;
}

//Checks if a string is a palindrome
int isPalindrome(char* str,int length) {
  int i;
  for(i=0;i<6;i++) {
    if(str[i]!=str[length-1-i]) {
      return 0;
    }
  }
  return 1;
}

//Okay efficiency algorithm for seeing if two numbers
//are multiples of three digit numbers
int multipleThreeDigits(int n) {
  int i,r;
  for(i=999; i > 99 ; i-- ) {
    r=n/i;
    if (r>999) {
      break;
    } else if(n%i==0&&r>=100){
      return 1;
    }
  }
  return 0;
}


int main() {
	int count, i,n,m;
	scanf("%d\n", &count);
	for (i = 0; i < count; i++){
		int lpu;
		scanf("%i", &n);
   	lpu = generatePalindromeUnder(n);
		printf("%i\n", lpu);
    }
	return 0;
}