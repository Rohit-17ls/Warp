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

	Tensor* view(const std::vector<int>& new_dimensions){
		int dim_product = 1;
		for(int dim : new_dimensions) dim_product *= dim;

		if(dim_product != m_memory_items){
			throw std::invalid_argument("Incompatible dimensions\n");
			return this;
		}

		m_dimensions.assign(new_dimensions.begin(), new_dimensions.end());
		return this;
	}

	Tensor* reshape(const std::vector<int>& new_dimensions){
		if(new_dimensions.size() == 0){
			m_dimensions.clear();
			return this;
		}

		int dim_product = 1;
		bool is_inferred = 0;
		int inference_index = 0;
		
		for(int dim : new_dimensions){
			if(dim != -1){
			       	dim_product *= dim;
			}else if(dim == -1){
				if(is_inferred) throw std::invalid_argument("Cannot infer multiple dimensions\n");       
				is_inferred = 1; 
				inference_index *= -1;
				continue;
			}
			if(!is_inferred) inference_index--;
		}

		


		if(inference_index >= 0){
			if(m_memory_items % dim_product != 0) throw std::invalid_argument("Incompatible Dimensions\n");
			int inferred_dimension = m_memory_items / dim_product;
			
			m_dimensions.resize(new_dimensions.size());
			int i = 0;
			for(int dim : new_dimensions){
				if(dim == -1) m_dimensions[i++] = inferred_dimension;
				else m_dimensions[i++] = dim;
			}


		}else if(dim_product != m_memory_items){
			throw std::invalid_argument("Incompatible Dimensions");
		}else{
			m_dimensions.assign(new_dimensions.begin(), new_dimensions.end());
		}

		return this;
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

	Tensor* flatten(){
		m_dimensions.resize(1);
		m_dimensions[0] = m_memory_items;
		return this;

	}
	
	
	Tensor*  unsqueeze(){
		m_dimensions.insert(m_dimensions.begin(), 1);
		return this;
	}


	Tensor(const Tensor& other) : m_dimensions(other.m_dimensions), m_memory_items(other.m_memory_items) {
		// Allocate memoy for heap allocated members
		std::cout << "Copy Constructor Called\n";
		m_heap_memory = new float[other.m_memory_items];
	}




	std::vector<int> size() const{
		return std::vector<int>(m_dimensions);
	}

	friend std::ostream& operator<<(std::ostream& os, Tensor* tensor);
	
	float min(Tensor* tensor, int dim);
	
	
};

float Tensor::min(Tensor* tensor, int dim){
	return 1.0;

}


std::ostream& operator<<(std::ostream& os, Tensor* tensor){
	tensor->print();
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


