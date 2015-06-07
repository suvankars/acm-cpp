#include<iostream>
#include<vector>
#include <sstream>

using namespace std;

class Field {
  int m;
  int n;
  int fNum;
  std::vector <std::string> rows;

public:
  Field(int fNum){
    this->m = 0;
    this->n = 0;
    this->fNum = fNum;
  }
  
  void readHeader(std::istream &is){
    std::string line;
    std::getline(is, line);
    std::istringstream iss(line);

    iss >> this->m >> this->n;
  }

  bool terminating(){
    if( (this->m == 0) | (this->n == 0)){
      return true;
    }else{
      return false;
    }
  }

  void read( std::istream &is ){
    readHeader( is );
    if( terminating() ){
      return;
    }
    //readreast   
    for(int i =0 ; i < this->m ; i++){
      std::string row;
      std::getline(is, row);
      rows.push_back(row);
    }
  }

  bool valid() {
    if(this->rows.size() != this->m)
      return false;

    for (size_t i = 0; i < this->rows.size(); i++) {
      std::string row = this->rows[i];
      if(row.length() != this->n)
        return false;
    }

    return true;
  }

  void printField() {
    for(int i = 0; i < this->m; i++) {
      for(int j = 0; j < this->n; j++) {
        if(hasMine(i, j))
          std::cout << "*";
        else
          std::cout << adjacentMines(i, j);
      }
      std::cout << std::endl;
    }
  }

  int adjacentMines(int m, int n) {
    int count = 0;

    for(int i = -1; i <= 1; i++) {
      for(int j = -1; j <= 1; j++) {
        if( hasMine(m+i, n+j) )
          count++;
      }

    }
    return count;
  }

  bool hasMine(int m, int n) {
    if((m < 0) || (n < 0))
      return false;

    if((m >= this->m) || (n >= this->n))
      return false;

    std::string row = this->rows[m];
    return row[n] == '*';
  }

  void print(){
    std::cout << "Field #" << this->fNum << ":" << std::endl;

    if(valid()) {
      printField();
    } else {
      std::cout << "Invalid field." << std::endl;
    }
  }

};

int main( int argc, char *argv[] ){
  int field_number = 1;
  while(true){
    Field f( field_number++ ) ;
    f.read( std::cin );                 
    if(f.terminating()){
      break;
    }

    f.print();
    std::cout << std::endl;
  }
  
  return 0;  
}
