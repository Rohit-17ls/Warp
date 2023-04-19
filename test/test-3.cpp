#include <iostream>
#include <vector>
#include "../include/Warp.h"

int main(){


	std::vector<int> vec = {1, 2};
	Warp::Tensor* t = new Warp::Tensor(vec);
	t->print();


	return 0;
}
