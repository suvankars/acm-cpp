#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
using std::getline;


 
string nth_permutation(std::string str, int n){
    
   for(int i=0; i<n; i++){
    std::next_permutation(str.begin(), str.end());
     
  }
    return str;
}

int print_permutation(int count){
  for (int n=0; n < count ; n ++){
    string str;
    string per_count;
    for (int n=0; n < 2 ; n ++){
      
      if(n%2==0){
        std::getline(std::cin, str);
      }
      else{
          std::getline(std::cin, per_count);
      }

    }
    std::cout << nth_permutation(str, std::atoi( per_count.c_str() )) << std::endl;  
  }
}

int main() {
  string line_count;
  std::getline(std::cin, line_count);
  int count = std::atoi( line_count.c_str() );
  print_permutation(count);
  return 0;
}




