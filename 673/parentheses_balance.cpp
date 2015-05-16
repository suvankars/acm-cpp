#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// To execute C++, please define "int main()"

// std::vector<std::string> &split(std::string str, char delim, std::vector<std::string> &elements){
//   std::stringstream ss(str);
//   std::string item;

//   while(std::getline(ss, item, delim)){
//     elements.push_back(item);
//   }
//   return elements;
// }

// std::vector<std::string> split(std::string str, char delim){
//   std::vector<std::string> elements ;
//   split(str, delim, elements);
//   return elements;
// }


std::string isBalanced(std::string parentheses){
  vector<char> elements(parentheses.begin(), parentheses.end());
  std::map <char, char> matches;
  matches['('] = ')';
  matches['['] = ']';


  std::string balanced = "Yes";
  for(std::map<char, char>::iterator it = matches.begin(); it != matches.end(); it++) {
    char opening_brace = it->first;
    char closing_brace = it->second ;


    int l = elements.size();
    std::string found = "Yes";
   // std::string individual_match = "No";
    for(std::vector<char>::size_type i = 0; i != elements.size() ; i++) {

        if(elements[i] == opening_brace){
         std::cout << " going to found match for" << elements[i] <<std::endl;
          std::string i_match = "No";
          for(std::vector<char>::size_type j = l-1; j != i ; j--){
            if(elements[j] == closing_brace){
               i_match = "Yes";
               std::cout << " found match for " << elements[i] << " with " << elements[j] <<std::endl;
               l = j;
               break;
            }
           }

          if(  i_match == "Yes"){
            found = "Yes";
          }else{
            found = "No";
            std::cout << " NOT found match for " << i_match  <<std::endl;
          }
         }
      }


    if(found=="No"){
      balanced = "No";
      break;
    }
  }

  return balanced;
}

int main() {
  std::string parentheses = "(([]))";
  std::cout << isBalanced(parentheses) << std::endl;
  return 0;
}
