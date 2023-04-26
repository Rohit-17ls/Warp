#pragma once
#include "./Tensor.h"
#include <vector>

namespace Warp{

bool Tensor::is_same_dimensions(const Tensor& t1, const Tensor& t2) const{
	return t1.size() == t2.size();	

}


}
