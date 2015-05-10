#include <iostream>

using std::string;

int cycle_length(int n){
  if (n == 1) {
    return 1;
  } else if(n%2==0) {
    return 1 + cycle_length(n/2);
  } else{
    return 1 + cycle_length(3*n + 1);
  }
}

int max_cycle_length(int begin, int end) {

  int max = 0;
  for(int i = begin; i <= end; i++){
    int current = cycle_length(i);
    
    if(current > max) {
      max = current;
    }
  }
  return max;
}

int main() {
	int begining;
	int end;
	std::cout << "Please enter input pair, seperated by space: ";
	std::cin >> begining >> end ;

	std::cout << begining << " " << end << " " <<max_cycle_length(begining, end) << std::endl;
	return 0;
}