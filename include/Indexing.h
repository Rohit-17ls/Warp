#pragma once
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <vector>
#include "./Tensor.h"

namespace Warp{


float Tensor::item(){
	if(m_dimensions.size() == 1 && m_dimensions[0] == 1){
		return m_heap_memory[0];
	}	

	std::logic_error("item() cannot be applied on Tensors containing multiple dimensions or multiple elements in the 0th dimension\n");
	return -1;

}

void Tensor::x_copy_memory(const int& start_index, const int& end_index, float* src_data_address){
	memcpy(m_heap_memory+start_index, src_data_address, end_index-start_index);

}


Tensor& Tensor::operator[](const int& index){
	int block_size = 1;
	

	if(index >= m_dimensions.size()) std::out_of_range("Index is out of range\n");
	


	std::vector<int> v(m_dimensions.size()-1);;
	for(int i=1; i<m_dimensions.size(); i++){
		block_size *= m_dimensions[i];
		v[i-1] = m_dimensions[i];
		std::cout << block_size << " " << m_dimensions.size() << std::endl;
	}

	for(int& dim : v) std::cout << dim << " ";

	std::cout << "\n" << block_size << std::endl;
	
	
	//std::cout << std::vector<int>(m_dimensions.begin()+1, m_dimensions.end());
	//Tensor* new_tensor = new Tensor({1, 2});
	//Tensor new_tensor({1, 2});
	//new_tensor->x_copy_memory(index*block_size, block_size, m_heap_memory);
	//new_tensor->size();
	//return *new_tensor;
	
	return *this;
}

Tensor* Tensor::test(){

	Tensor* new_tensor = new Tensor({1, 2});
	return new_tensor;
}



}

