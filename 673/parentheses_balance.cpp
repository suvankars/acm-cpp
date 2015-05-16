#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
      matcher.push(parentheses[i]);
    }
    else if ((parentheses[i] == closing_brace1) || (parentheses[i] == closing_brace2)){
      char top_elm;
      if(!matcher.empty()){
        top_elm = matcher.top();

        if(brace_pair[top_elm] == parentheses[i]){
          matcher.pop();
        }
        else{
          matcher.push(parentheses[i]);
        }
      }
      else{
        matcher.push(parentheses[i]);
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
  std::string nCases;
  std::string nCasesq;
  std::string line;
  
  std::getline(std::cin, nCases);
  for(int i = 0 ; i < std::atoi( nCases.c_str()) ; i++ ){
	std::getline(std::cin, line);
    std::cout << isBalanced(line) << std::endl;
  }
  return 0;
}
