#include <iostream>
#include <vector>

using namespace std;

typedef std::pair<int, int> MinePosition;
// To execute C++, please define "int main()"
 std::vector<MinePosition> countMine(char mine[][4]){
   typedef std::pair<int, int> MinePosition;
   std::vector <MinePosition> minePositions;
   
   //std::map<int, int> minePosition;
   for(int i = 0; i< 4 ; i++){
     for(int j = 0; j< 4 ; j++){
        if(mine[i][j] == '*'){
          minePositions.push_back(std::make_pair( i, j ));
        }
     }  
   }
   return minePositions;
 }

 void findMine(char mine[][4]){
    int hint[4][4] = {0};
    std::vector<MinePosition> minePosition = countMine(mine);
   std::vector<MinePosition>::iterator it;
   for(it = minePosition.begin(); it != minePosition.end(); ++it){
     int x = it->first ;
     int y = it->second ;
     
      for(int dx = -1; dx <= 1 ; ++dx){
          for(int dy = -1; dy <= 1; ++dy){
              if((dx != 0 ) | (dy != 0) ){
                if((x+dx >= 0) && (y+dy >= 0) && (y+dy <= 3) && (x+dx <= 3)) {
                     hint[x + dx][y + dy] += 1;
                }
              }
          }
      }
     
   }
    
   for(int i = 0; i<= 3 ; i++){
     for(int j = 0; j<= 3 ; j++){
        std::cout << hint[i][j];
     }  
     std::cout << "" << std::endl;
   }
   
  }

int main() {
  
 
  
  char mine[4][4]  = {{'*', '.', '.', '*'},
                      {'.', '.', '.', '.'},
                      {'.', '.', '*', '.'},
                      {'*', '.', '.', '*'}};
  
  findMine(mine);
  return 0;
}
