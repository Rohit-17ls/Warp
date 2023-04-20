#pragma once
#include "./Tensor.h"
#include <iostream>
#include <cmath>
#include <functional>

namespace Warp{

void Tensor::m_logarithm(const float& base){
	
	auto aggregate_function = [&](float argument, float base){
		return std::log(argument)/std::log(base);
	};

	for(int i=0; i<m_memory_items; i++){
		m_heap_memory[i] = aggregate_function(m_heap_memory[i], base);
	}
}

void Tensor::m_sqrt(){
	for(int i=0; i<m_memory_items; i++){
		m_heap_memory[i] = std::sqrt(m_heap_memory[i]);
	}

}


Tensor& Tensor::log(const float& base = 2.71828){
	Tensor* new_tensor = new Tensor(*this);
	
	new_tensor->m_logarithm(base);

	return *new_tensor;
	
}


Tensor& Tensor::sqrt(){
	Tensor* new_tensor = new Tensor(*this);

	new_tensor->m_sqrt();

	return *new_tensor;
}

}
