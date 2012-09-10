#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::stringstream;

unsigned int denom(unsigned int* change, unsigned int penny_value){  
  return (*change-(*change%=penny_value))/penny_value;  
}

string pluralize(unsigned int a, string word){
  stringstream ss;
  ss << a << " " << word;
  string plural;
  if(ss.str()[ss.str().length()-1]=='y') plural = ss.str().substr(0, ss.str().length()-1)+"ies"; else plural = ss.str()+'s';
  return (a==1?ss.str():plural);
  
}
template<class T> string serialize(vector<T> v){
  if(!v.size()) return "nothing";
  stringstream ss;
  for(int i=0; i<v.size(); i++) 
    if(v.size()>1&&i==v.size()-1) ss << " and " << v[i];
    else if(i)                    ss << ", " << v[i]; 
    else                          ss << v[i];
    
  return ss.str();
}

int main(int argc, char* argv[] ){

  if(argc < 2){
    cout << "Invalid input.\nUsage: " << argv[0] << " [dollar][.cents]"; 
    return 1; 
  }
  
  unsigned int change = 0;
  char dot = 0, error = 0;
  for(int i=0, c=argv[1][0]; c!='\0'; c=argv[1][++i]){
    if(dot) if(++dot > 3) error = 1;
    if(isdigit(c)) change = change*10+c-'0';
    else if(!dot&&c=='.') dot = 1;
    else error = 1;
  }
  if(error){ 
    cout << "Invalid input.\n"; 
    return 1; 
  }
  if(dot < 2) change *= 100;
  else if(dot==2) change *= 10;
  
  unsigned int bill100, bill50, bill20, bill10, bill5, toonie, dollar, quarter, nickel, dime, penny;
  
  bill100  = denom(&change, 10000);
  bill50   = denom(&change, 5000);
  bill20   = denom(&change, 2000);
  bill10   = denom(&change, 1000);
  bill5    = denom(&change, 500);
  toonie   = denom(&change, 200);
  dollar   = denom(&change, 100);
  quarter  = denom(&change, 25);
  dime     = denom(&change, 10);
  nickel   = denom(&change, 5);
  penny    = change;
  
  vector<string> received;
  
  if(bill100) received.push_back(pluralize(bill100, "$100 bill"));
  if(bill50)  received.push_back(pluralize(bill50, "$50 bill"));
  if(bill20)  received.push_back(pluralize(bill20, "$20 bill"));
  if(bill10)  received.push_back(pluralize(bill10, "$10 bill"));
  if(bill5)   received.push_back(pluralize(bill5, "$5 bill"));
  if(toonie)  received.push_back(pluralize(toonie, "toonie"));
  if(dollar)  received.push_back(pluralize(dollar, "loonie"));
  if(quarter) received.push_back(pluralize(quarter, "quarter"));
  if(dime)    received.push_back(pluralize(dime, "dime"));
  if(nickel)  received.push_back(pluralize(nickel, "nickel"));
  if(penny)   received.push_back(pluralize(penny, "penny"));
    
  cout << "You receive " << serialize(received) << ".\n";
    
  received.clear();
  return 0;

}
