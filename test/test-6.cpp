#include <iostream>
#include "../include/Warp.h"
#define log(x) { std::cout << x << std::endl;}

int main(){

//	Warp::Tensor t({3, 3});

	Warp::Tensor t = Warp::Tensor::randn({3, 3});


	log(t);


	return 0;
}
