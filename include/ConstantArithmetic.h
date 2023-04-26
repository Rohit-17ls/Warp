#pragma once
#include "./Tensor.h"

namespace Warp{



Tensor& Tensor::operator+(int summand){
	
	Tensor* new_tensor = new Tensor(*this);
	
	for(int i=0; i < new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] += summand;
	}

	return *new_tensor;

}

Tensor& Tensor::operator-(int subtrahend){

	Tensor* new_tensor = new Tensor(*this);
	
	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] -= subtrahend;
	}

	return *new_tensor;;
}



Tensor& Tensor::operator*(int multiplier){

	Tensor* new_tensor = new Tensor(*this);
	
	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] *= multiplier ;
	}

	return *new_tensor;
}

Tensor& Tensor::operator/(int divisor){

	Tensor* new_tensor = new Tensor(*this);
	
	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] /= divisor;
	}

	return *new_tensor;
}


// Static
Tensor&  Tensor::add(const Tensor& tensor, int summand){
	Tensor* new_tensor = new Tensor(tensor);
	
	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] += summand;
	}
	
	return *new_tensor;
}


// Static
Tensor& Tensor::subtract(const Tensor& tensor, int subtrahend){
	Tensor* new_tensor = new Tensor(tensor);

	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] -= subtrahend;
	}

	return *new_tensor;
}


// Static
Tensor& Tensor::multiply(const Tensor& tensor, int multiplier){
	Tensor* new_tensor = new Tensor(tensor);

	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] *= multiplier;
	}

	return *new_tensor;
}

// Static
Tensor& Tensor::divide(const Tensor& tensor, int divisor){
	Tensor* new_tensor = new Tensor(tensor);

	for(int i=0; i<new_tensor->m_memory_items; i++){
		new_tensor->m_heap_memory[i] /= divisor;
	}

	return *new_tensor;
}

}
