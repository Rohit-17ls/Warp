#include <iostream>
#include "../include/Warp.h"
#define log(x) { std::cout << x << std::endl;}

int main(){



	Warp::Tensor t1({1, 2});
	Warp::Tensor t2({1, 2});

	log("---------------");
	

	t1 = t1+1;
	t2 = t1+1;

	log(t1);
	log(t2);

	Warp::Tensor t3 = t1 + t2;
	log(t3);


	return 0;
}
