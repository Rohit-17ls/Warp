#pragma once
#include "../include/Tensor.h"
#include <vector>
#include <random>
#include <stdexcept>
#include <cmath>

namespace Warp{

// Default values : out = nullptr, requires_grad = false;
Tensor& Tensor::randn(const std::vector<int>& dimensions, Tensor* out, bool requires_grad){
	
	Tensor* output_tensor;

	if(out != nullptr){
		if(out->size() == dimensions){
			output_tensor = out;
		}else{
			throw std::invalid_argument("Incompatible dimensions for out tensor");
		}
	}else{
		output_tensor = new Tensor(dimensions);
	}

	std::random_device rd;
   	std::mt19937 gen(rd());
   	std::normal_distribution<float> dist(0.0, 1.0);
	
	float mean = 0.0;
	for(int i=0; i<output_tensor->m_memory_items; i++){
		float rand_value = dist(gen);
		output_tensor->m_heap_memory[i] = rand_value;
		mean += rand_value;
	}
/*
	output_tensor->print();

	int n = output_tensor->m_memory_items;
	mean = mean/n;

	float std_deviation = 0.0;
	for(int i=0; i<output_tensor->m_memory_items; i++){
		std_deviation += std::pow((output_tensor->m_heap_memory[i] - mean), 2);
	
	}

	std_deviation = std::sqrt(std_deviation / (n-1));

	for(int i = 0; i < output_tensor->m_memory_items; i++){
		int x = output_tensor->m_heap_memory[i];
		output_tensor->m_heap_memory[i] = (x - mean) / std_deviation;
	}
*/

	return *output_tensor;	


}






}
