#pragma once
#include "./Tensor.h"


namespace Warp{


Tensor& Tensor::operator+(const Tensor& operand_tensor){
	Tensor* new_tensor = new Tensor(operand_tensor);

	for(int i = 0; i < new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] += this->m_heap_memory[i];
	}

	return *new_tensor;

}


Tensor& Tensor::operator-(const Tensor& operand_tensor){
	Tensor* new_tensor = new Tensor(operand_tensor);

	for(int i = 0; i < new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] *= -1;
		new_tensor->m_heap_memory[i] += this->m_heap_memory[i];
	}

	return *new_tensor;
}


Tensor& Tensor::operator*(const Tensor& operand_tensor){
	Tensor* new_tensor = new Tensor(operand_tensor);

	for(int i = 0; i < new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] *= this->m_heap_memory[i];
	}

	return *new_tensor;
}


Tensor& Tensor::operator/(const Tensor& operand_tensor){
	Tensor* new_tensor = new Tensor(operand_tensor);

	for(int i = 0; i < new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] = this->m_heap_memory[i]/(new_tensor->m_heap_memory[i]);
	}

	return *new_tensor;
}

}
