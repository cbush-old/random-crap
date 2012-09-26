// fibonat: find fibonacci sequence value at given position
//   using matrix product
#include <iostream>
#include <cstdlib>

using std::cout;

struct colvect {
  long long int x,y;
  colvect(long long int _x, long long int _y): x(_x),y(_y){}
  colvect operator=(colvect B){
    x = B.x;
    y = B.y;
  }
};

struct sqmat {
  long long int a,b,c,d;
  sqmat(long long int _a, long long int _b, long long int _c, long long int _d):a(_a),b(_b),c(_c),d(_d){}
  sqmat operator=(sqmat B){
    a = B.a;    b = B.b;    
    c = B.c;    d = B.d;
    return *this;
  }
  sqmat operator*(sqmat B){
    return sqmat(
      a * B.a + b * B.c, a * B.b + b * B.d,
      c * B.a + d * B.c, c * B.b + d * B.d
    );
  }
  sqmat operator*=(sqmat B){
    return *this = *this * B;
  }
  colvect operator*(colvect B){
    return colvect(
      a * B.x + b * B.y,
      c * B.x + d * B.y
    );
  }
  sqmat pow(unsigned long long int n){
    sqmat R (a,b,c,d), S (a,b,c,d);
    for(long long int i=0; i<n; ++i)
      R *= S;
    return R;
  }
};

unsigned long long int fibonat(unsigned long long int n){
  
  if(n < 1) return 0;
  sqmat A(1,1,1,0);
  colvect B = A.pow(n-1)*colvect(1,0);
  return B.x;

}

int main(int argc, char* argv[]){

  if(argc < 2){ 
    cout << "Usage: " << argv[0] << " [number]\n";
    return 1;
  }
  
  unsigned long long int n = atoi(argv[1]);
  
  if(!n){
    cout << "Enter a number greater than 0.\n";
    return 1;
  }
  
  cout << fibonat(n);
  return 0;
}
