#include <iostream>
#include "../include/Tensor.h"

int main(){


	Warp::Tensor* t = new Warp::Tensor({2, 3, 4});
	std::cout << t << std::endl;


	return 0;
}
