#pragma once
#include <iostream>
#include <vector>
#include <cstring>
#include <stdexcept>
#include <cstdio>


namespace Warp{

class Tensor{
	
private:
	float* m_heap_memory;
	std::vector<int> m_dimensions;
	int m_memory_items = 1; // Total number of elements in the tensor
	int m_memory_item_size = sizeof(float);

	void m_log_start_brace(int padding_space){
		for(int i=0; i<padding_space; i++) std::cout << " "; 
		std::cout << "[";
	}

	void m_log_end_brace(int is_newline = 0){
		if(is_newline) std::cout << "],\n";
		else std::cout << "]";
	}


	void m_recursive_print(int dim_index, bool is_first_iteration,  bool is_last_iteration, int& index){
		int current_dim = m_dimensions[dim_index];
		
		if(dim_index == m_dimensions.size()-1){
			m_log_start_brace(!is_first_iteration*dim_index);
			for(int i = 0; i < m_dimensions[dim_index]; i++){
				std::cout << m_heap_memory[index++] << ", ";
				//std::cout << index++ << ", ";
			}
			if(is_last_iteration) m_log_end_brace(0);
			else m_log_end_brace(1);
			return;
		}


		m_log_start_brace(std::max(0, dim_index-1));
		for(int i = 0; i < current_dim; i++){
			m_recursive_print(dim_index+1, i == 0, i == current_dim-1, index);
		}

		if(dim_index == 0) std::cout << "]";
		else m_log_end_brace(1);
		std::cout << std::endl;
		
	}

	void m_arange_assign(int start, int end, int step){
		int ind = 0;
		for(int i=start; i<end; i+=step){
			m_heap_memory[ind++] = i;
		}
	}



public:
	// Constructors
	
	Tensor(const std::vector<int>& dimensions){
		m_dimensions.assign(dimensions.begin(), dimensions.end());
		for(int& dim : m_dimensions) m_memory_items *= dim;
	
		m_heap_memory = new float[m_memory_items];
		memset(m_heap_memory, 0., sizeof(float) * m_memory_items);
	}

	void print(){
		int start_index = 0;
		m_recursive_print(0, 1, 0, start_index);
	}



	static Tensor* flatten(Tensor* tensor){
		Tensor* new_tensor = new Tensor(*tensor);
		new_tensor->flatten();
		return new_tensor;

	}

	static Tensor* arange(int start, int end, int step){
		Tensor* new_tensor = new Tensor({(end-start)/step});
		new_tensor->m_arange_assign(start, end, step);
		return new_tensor;
	}


	static Tensor& arange(Tensor& tensor, int start, int end, int step){
		tensor.m_arange_assign(start, end, step);
		return tensor;
	}

	std::vector<int> size() const{
		return std::vector<int>(m_dimensions);
	}



	// Copy Constructor

	Tensor(const Tensor& other) : m_dimensions(other.m_dimensions), m_memory_items(other.m_memory_items) {
		// Allocate memoy for heap allocated members
		std::cout << "Copy Constructor Called\n";
		m_heap_memory = new float[other.m_memory_items];
	}



	// Destructor
	~Tensor(){
		std::cout << "Destructor Called\n";
		delete[] m_heap_memory;
	}
	

	// Friend functions

	friend std::ostream& operator<<(std::ostream& os, Tensor& tensor);
	
	
	// Externally defined members' protypal definitions
	
	// ------------------------------------------------

	// Indexing.h
	float item();
	//Tensor* operator[](const int& index);
	Tensor& operator[](const int& index);

	// Reshaping.h
	Tensor& view(const std::vector<int>& new_dimensions);
	Tensor& reshape(const std::vector<int>& new_dimensions);
	Tensor& flatten();
	Tensor&  unsqueeze();
	
	// ------------------------------------------------

	// x-methods
	void x_copy_memory(const int& start_index, const int& end_index, float* src_data_address);		
	
};



std::ostream& operator<<(std::ostream& os, Tensor& tensor){
	tensor.print();
	return os;
}

}

std::ostream& operator<<(std::ostream& os, std::vector<int> vec){
	for(int& ele : vec){
		os << ele << " ";
	}
	os << "\n";
	return os;
}


