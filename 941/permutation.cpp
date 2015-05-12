#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
using std::getline;


 
string nth_permutation(std::string str, int n){
    
   for(int i=0; i<3; i++){
    std::next_permutation(str.begin(), str.end());
     
  }
    return str;
}

int main() {
  string line_count;
  std::getline(std::cin, line_count);
  int count = std::atoi( line_count.c_str() );
  
  //
  // for (int n=0; n < count ; n ++){
    
  //   if(n%2==0){
  //     std::getline(std::cin, str);
  //     std::cout << str;
  //   }
  //   else{
  //      //get permutation count
  //   }
  // }
  // std::cout << line_count;
  std::cout << nth_permutation("abc", 2) << std::endl;
  return 0;
}




