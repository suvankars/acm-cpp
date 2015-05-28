#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

std::map<char, char> mapper(std::string substitution, std::string plaintext){
  std::map<char, char> cypher_map;

  for(std::size_t i= 0 ; i < plaintext.length(); i++ ){
    char key = plaintext[i];
    char value = substitution[i];
    cypher_map[key] = value;
  }
  return cypher_map;
}

std::string cypher(std::map<char, char> cypher_map, std::string article){
  std::map<char,char>::iterator it;
   for(size_t i = 0; i < article.length(); i++){
     it = cypher_map.find(article[i]);
     char value = it->second;
     if((value)){
       article[i] = value;
     }
   }

  std::string cyphered_text = article;
  return cyphered_text;
}

int main() {

  std::string nCases;
  std::string line;
  std::string plaintext;
  std::string substitution;
  std::stringstream article;
  std::string cyphered_text;
  std::map<char, char> cypher_map;

  std::cin >> nCases;
  for(int i = 0; i < std::atoi(nCases.c_str()); i++	){
	  std::getline(std::cin, line);
	  std::getline(std::cin, line);
	  if(line != ""){
		  std::cout << "exiting ...";
		  exit;
	  }
	  std::getline(std::cin, plaintext);
	  std::getline(std::cin, substitution);

	  while (getline(std::cin, line))
	  {
		if (line == "") continue; // Skip blank line
		article << line;
	  }
  }

  cypher_map = mapper(substitution, plaintext);
  cyphered_text = cypher(cypher_map, article.str());
  std::cout << substitution << std::endl;
  std::cout << plaintext << std::endl;
  std::cout << cyphered_text << std::endl;
  return 0;
}
