/*  
  
  Stupid exercise from someone on /r/learnprogramming's CS homework:
  
    Without using any selection constructs (if/else, switch, 
    ternary operator, conditional expressions), logical and 
    relation operators (&&, ||, <, <=, etc), and no boolean 
    expressions, solve the following problem:
    
    "Given two non-negative integers as input, square the 
    smaller of the two values and multiply the larger by 2. 
    Make no changes when the values are the same."
    
  Considering ! reversals to be boolean, which is not allowed, 
  my solution involves arrays, function pointers and a lot of 
  bitwise operation.
  
*/
#include <stdio.h>

typedef void(*function)(int, int);

void different(int larger, int smaller){
  printf("%u > %u\n", larger, smaller);
  smaller *= smaller;
  larger <<= 1;
  printf("Larger x2 = %u\nSmaller^2 = %u\n", larger, smaller);
}

void same(int x, int y){
  printf("%u == %u\n", x, y);
}

int main(){

  unsigned int 
    x = 4, y = 5, // the input
    ordered[2];
    
  // ordered[0] will be lesser, 
  // ordered[1] will be greater OR undefined
  ordered[(0xf0000000&(x-y))>>31] = y;  
  ordered[(0xf0000000&(y-x))>>31] = x;  

  function funcs[2] = {different, same};
  function f = funcs[1^(((0xf0000000&(x-y))>>31)+((0xf0000000&(y-x))>>31))];
  
  (*f)(ordered[1], ordered[0]); 
  
}
