#include <iostream>
#include <sstream>
#include <vector>
#include <map>

#include <stack>

using namespace std;

std::string isBalanced(std::string parentheses_str){
  vector<char> parentheses(parentheses_str.begin(), parentheses_str.end());
  std::stack<char> matcher;
  std::map<char, char> brace_pair;
  brace_pair['('] = ')';
  brace_pair['['] = ']';

  char opening_brace1 = '(';
  char opening_brace2 = '[';

  char closing_brace1 = ')';
  char closing_brace2 = ']';


  for(std::vector<char>::size_type i = 0; i != parentheses.size(); i++  ){
    if ((parentheses[i] == opening_brace1) || (parentheses[i] == opening_brace2) ){
      std::cout << " going to push " << parentheses[i] << std::endl;
      matcher.push(parentheses[i]);
    }
    else if ((parentheses[i] == closing_brace1) || (parentheses[i] == closing_brace2)){
       std::cout << " going to pop " << parentheses[i] << std::endl;
      char top_elm;
      if(!matcher.empty()){
        top_elm = matcher.top();
      }
        if(brace_pair[top_elm] == parentheses[i]){
          std::cout << " going to remove " << parentheses[i] << std::endl;
          if(!matcher.empty()){
            matcher.pop();
          }
        else{
          std::cout << "push remaining elements " << parentheses[i] << std::endl;
          matcher.push(parentheses[i]);
        }

      }


    }

  }

  std::string balanced = "No";

  if (matcher.empty()) {
   balanced = "Yes";
  }

  return balanced;
}

int main() {
  std::string parentheses_str = "(([()])))";
  std::cout << isBalanced(parentheses_str) << std::endl;
  std::string parentheses_str2 = "([()[]()])()";
  std::cout << isBalanced(parentheses_str2) << std::endl;
  return 0;
}
