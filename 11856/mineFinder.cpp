#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



typedef std::pair<int, int> MineCoordinate;



void display(char **mine, int hint[][20], int m, int n){
  for(int i = 0; i< m ; i++){
     for(int j = 0; j< n ; j++){
        if(mine[i][j] == '*'){
          std::cout << mine[i][j];
        }else {
          std::cout << hint[i][j];
        }
     }  
     std::cout << "" << std::endl;
   }
}


 void findMinePosition(char **mine, int m, int n){
   std::vector <MineCoordinate> minePositions;
   int hint[20][20] = {0};

   for(int i = 0; i< m ; i++){
     for(int j = 0; j< n ; j++){
        if(mine[i][j] == '*'){
          for(int dx = -1; dx <= 1 ; ++dx){
            for(int dy = -1; dy <= 1; ++dy){
              if((dx != 0 ) | (dy != 0) ){
                if((i+dx >= 0) && (j+dy >= 0) && (j+dy <= n) && (i+dx <= m)) {
                     hint[i + dx][j + dy] += 1;
                }
              }
            }
          }

        }
     }  
   }

   display(mine, hint, m, n);
   
 }

 

int main() {
  int x = -1;
  int y = -1;
  std::string line;

  std::getline(std::cin, line);
  
  while(!line.empty()){
    std::string start = line.substr(0, 1);
    std::string end = line.substr(1);  

    x = std::atoi( start.c_str() );
    y = std::atoi( end.c_str());
  
    char **mineAry = new char*[y];
    for(int i = 0; i < y; ++i) {
        mineAry[i] = new char[x];
    }


     char c; 
    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++){
        std::cin >> mineAry[i][j];
      }
      std::cin.ignore();
    }

    for(int i = 0; i< x ; i++){
       for(int j = 0; j< y ; j++){
            std::cout << mineAry[i][j];
       }  
       std::cout << "" << std::endl;
     }
     findMinePosition(mineAry, x, y);
    for(int i = 0; i < y; ++i) {
      delete [] mineAry[i];
    }
    delete [] mineAry;
  } //end while
  int m = 4;
  int n = 4;
  char mine[20][20]  = {{'*', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'.', '.', '.', '.'},
                        {'*', '.', '.', '.'}};
  
  //findMinePosition(mine, m, n);
  return 0;
}
  