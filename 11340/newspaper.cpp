#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> article_value(std::string article, std::map<char, int> paid_chars ){
  for(std::map<char, int>::iterator it=paid_chars.begin(); it!=paid_chars.end(); ++it){
    char paid_char = it->first ;
    int value = it->second;
    
    int occurrence = std::count(article.begin(), article.end(), paid_char);
     it->second = value*occurrence; //Update map with occurrence count of that paid character
  }

  return paid_chars;
}

//Functer 
int map_acc(int lhs, const std::pair<char, int> & rhs) {
    return lhs + rhs.second;
}

double compute_price(std::map<char, int> word_values){
  const double total_cent = std::accumulate(word_values.begin(), word_values.end(), 0, map_acc);
  const double dollar = total_cent/100;
  return dollar;
}
  
int main() {
  std::string article = "ACM ICMnternationalAAAAAA";
  std::map<char, int> paid_chars;
  std::map<char, int> word_values;
  paid_chars['A'] =  1;
  paid_chars['C'] =  0;
  paid_chars['M'] =  100;
  
  word_values = article_value(article, paid_chars);
  std::cout << compute_price(word_values) << "$" <<std::endl;
  
//   for (const auto &p : word_values) {
//    std::cout << "m[" << p.first << "] = " << p.second << '\n';
//  }
  return 0;
}
