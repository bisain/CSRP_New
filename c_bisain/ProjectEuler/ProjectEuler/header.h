//
//  header.h
//  ProjectEuler
//
//  Created by Park, Sabin - 0559 - MITLL on 5/20/15.
//  Copyright (c) 2015 Park, Sabin - 0559 - MITLL. All rights reserved.
//

#ifndef ProjectEuler_header_h
#define ProjectEuler_header_h

#include <stdio.h>          // input/output
#include <stdbool.h>        // includes bool
#include <string.h>         // string handling functions
#include <math.h>           // math functions
#include <stdlib.h>



// PE 001
int sumOfMultiples(int a, int b, int max);
// PE 002
long fibonacci(long n);
long evenFibonacci(long max);
// PE 003
bool checkPrime(long long n);
long long getLargestPrimeFactor(long long n);
// PE 004
int largestPalindromeProduct(void);
bool isPalindrome(int num);
// PE 005
int smallestMultiple(int max);
// PE 006
long sumOfSquares(int max);
long squareOfSums(int max);
long differenceBetween(int square, int sum);
// PE 007
long getPrime(int n);
bool isPrime(long n);
// PE 008
long long largestProductFromSequence(int numDigits);
// PE 009
int pythagoreanProduct(int targetSum);
// PE 010
long sumOfPrimes(long max);
// PE 011
long largestProductGrid(void);
// PE 012
int triangleNumber(int divisors);
// PE 013
long long sumOf100_50digitNums(void);
// PE 014
int numChains(long num);
long getLongestChain(long max);
// PE 015
long long getNumPaths(int x, int y);
long long sumPascalsTriangle(int n);
// PE 016
void twoPower(int n);
int sumString(char myStringp[]);
// PE 017
// PE 018




#endif