#pragma once
#include <vector>
#include <iostream>
#include "./Tensor.h"

namespace Warp{

        Tensor& Tensor::view(const std::vector<int>& new_dimensions){
                int dim_product = 1;
                for(int dim : new_dimensions) dim_product *= dim;

                if(dim_product != m_memory_items){
                        throw std::invalid_argument("Incompatible dimensions\n");
                        return *this;
                }

                m_dimensions.assign(new_dimensions.begin(), new_dimensions.end());
                return *this;
        }

        Tensor& Tensor::reshape(const std::vector<int>& new_dimensions){
                if(new_dimensions.size() == 0){
                        m_dimensions.clear();
                        return *this;
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

                return *this;
        }


        Tensor& Tensor::flatten(){
                m_dimensions.resize(1);
                m_dimensions[0] = m_memory_items;
                return *this;

        }


        Tensor&  Tensor::unsqueeze(){
                m_dimensions.insert(m_dimensions.begin(), 1);
                return *this;
        }

}
