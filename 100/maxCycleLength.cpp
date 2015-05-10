#include <iostream>
#include <stdlib.h> 

using std::string;

const int upper_limit = 10000;
const int lower_limit = 0;

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

void usages(){
	std::cout << "ERROR: Invalid Inputs" << std::endl;
	std::cout << "Input must be in between " << upper_limit << " and " << lower_limit << std::endl; 
		
	exit (EXIT_FAILURE);
}

int main() {
	int begining;
	int end;
	

	std::cout << "Please enter input pair, seperated by space: ";
	std::cin >> begining >> end ;
	if (begining - lower_limit <= upper_limit - lower_limit){
		usages();
	}

	std::cout << begining << " " << end << " " <<max_cycle_length(begining, end) << std::endl;
	return 0;
}