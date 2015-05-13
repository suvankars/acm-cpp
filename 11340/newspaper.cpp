#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>

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
  string nCases;
  string nPaid_chars;
  std::stringstream article;
  std::string line;
  std::cin >> nCases;
  char paid_char;
  int price;
  std::map<char, int> paid_chars;
  std::string nline;
  std::map<char, int> word_values;

  for (int i = 0; i < std::atoi( nCases.c_str() ); i++)
  {

    std::cin >> nPaid_chars;
    for (int n = 0; n < std::atoi( nPaid_chars.c_str()) ; n++)
      {
        std::cin >> paid_char >> price;
        paid_chars[paid_char] = price ;
      }  
      std::cin >> nline;
      for (int n = 0; n <= std::atoi( nline.c_str()) ; n++)
      {
        std::getline(std::cin, line);
        article << line;
      }  

  }

  word_values = article_value(article.str(), paid_chars);
  std::cout << compute_price(word_values) << "$" <<std::endl;
  
  return 0;
}
