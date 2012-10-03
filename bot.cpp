/*

  Command line C++ scratch pad.
  Calls g++ on generated code.
  Compiled as bot.exe and saved 
  to a directory in PATH, usage 
  would be
  
    bot 'cout << "Hello world!"; '

  Output will be any errors from
  GCC or the result of the executed
  program.
  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]){

  string cppname ("tmp90210.cpp");
  string exename ("tmp90210.exe");
  ofstream file (cppname.c_str());
  
  file 
    << "#include <iostream>\n"
    << "#include <sstream>\n"
    << "#include <string>\n"
    << "#include <vector>\n"
    << "#include <cctype>\n"
    << "#include <cstdlib>\n\n"
    << "using namespace std;\n\n"
    << "int main(){\n\n";

  for(int i=1; i < argc; ++i)
    file << argv[i];
 
  file 
    << "\n\n}\n";
    
  file.close();
  
  cout << '\n';
  if(system(string("g++ "+cppname+" -o "+exename).c_str())){
    return 1;
  }
  system(string("./"+exename).c_str());
  system(string("rm "+exename+" "+cppname).c_str());
  cout << '\n';
  return 0;
  
}
