#include <iostream>
#include "../include/Warp.h"

int main(){


	Warp::Tensor* t = new Warp::Tensor({1});
	std::cout << t->item() << std::endl;


	Warp::Tensor t2({2, 3, 4});

	std::cout << t2.size() << std::endl;
	t2 = Warp::Tensor::arange(t2, 1, 100, 2);
//	t2 = t2.arange;
	std::cout << t2 << std::endl;

	t2[1];


	return 0;
}
