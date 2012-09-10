// Experimenting with function pointers
// std=c++11
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::vector;

template<class object> object array_rand(vector<object>*); // cut random entry out of array and return it

typedef void(*voidfunc)();

void laundry(){     cout << "Laundry\n";        }
void walkdog(){     cout << "Walk the dog\n";   }
void payrent(){     cout << "Pay rent\n";       }
void buyfood(){     cout << "Buy food\n";       }
void paintroom(){   cout << "Paint room\n";     }

void agenda(voidfunc f1,voidfunc f2,voidfunc f3){

  cout << "To-do:\n";
  cout << "------\n";  
  if(f1) f1();
  if(f2) f2();
  if(f3) f3();
  cout << "\n";
  
}

int main(){

  srand(time(0));
  
  vector<voidfunc> v { laundry, walkdog, payrent, buyfood, paintroom };
  for(int i=0; i<3; ++i) agenda(array_rand(&v),array_rand(&v),array_rand(&v));
  
  return 0;

}

template<class object> object array_rand(vector<object>* v){

  int n = v->size();
  if(!n) return 0;
  
  int i = rand()%n;
  
  object t = v->at(i);
  v->erase(v->begin()+i);
  return t;

}
