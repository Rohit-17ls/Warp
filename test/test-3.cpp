#include <iostream>
#include <vector>
#include "../include/Warp.h"

int main(){


	std::vector<int> vec = {1, 2};
	Warp::Tensor* t = new Warp::Tensor(vec);
	t->print();

	Warp::Tensor t1({2, 3, 4});
       	t1 = Warp::Tensor::arange(t1, 0, 50, 2);
	Warp::Tensor t2 = t1.log();
	Warp::Tensor t3 = t1.sqrt();

	std::cout << t1 << std::endl;
	std::cout << t2 << std::endl;
	std::cout << t3 << std::endl;
		
	return 0;
}
