#include <iostream>
#include <vector>
#include "../include/Warp.h"
#define print(x) { std::cout << x << std::endl;}

void sub(const Warp::Tensor& tensor){
	Warp::Tensor temp = Warp::Tensor::subtract(tensor, 2);
	print(temp);
}


int main(){


	Warp::Tensor t({2, 3});


	print(t);

	//t+1;

	Warp::Tensor t1 = t + 1;
	t = t+7;
	Warp::Tensor t2 = Warp::Tensor::add(t, 3);

//	sub(t2);


	print(t);
	print(t1);
	print(t2);

//	temp.discard();
	return 0;
}
