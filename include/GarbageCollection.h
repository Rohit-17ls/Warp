#pragma once
#include "./Tensor.h"


namespace Warp{

// Beta
void Tensor::discard(){
	delete[] m_heap_memory;
}

}
