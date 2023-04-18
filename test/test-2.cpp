#include <iostream>
#include "../include/Tensor.h"

int main(){

        int test_block = 2;

        if(test_block == 1){


        Warp::Tensor* t = new Warp::Tensor({2, 3, 4});

        Warp::Tensor* t2 = new Warp::Tensor(*t);

        t->view({3, 4, 2});
        t2->flatten();

        Warp::Tensor* t3 = Warp::Tensor::flatten(t);

        std::cout << t->size();
        std::cout << t2->size();
        std::cout << t3->size();

        t3 = t3->unsqueeze();

        t->print();

        t2->print();
        t3->print();

        }else{


        Warp::Tensor* t1 = new Warp::Tensor({2, 3, 4});

        // Allows for chaining
        t1 = t1->flatten()->unsqueeze()->reshape({2, -1, 2});


        // Overloaded Printing
        std::cout << t1 << std::endl;

        t1 = t1->reshape({6, -1});
        t1->print();

        Warp::Tensor* t2 = Warp::Tensor::arange(0, 10, 2);
        t2->print();
//      t1->print();
//      t2->print();


        }

        return 0;
}
