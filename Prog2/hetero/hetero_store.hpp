/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template <typename T, size_t bemeret, class kivetel>
class HeteroStore {
protected:
    T tomb[bemeret];
public:
    HeteroStore(){

    }
};


#endif // HETEROSTORE_HPP
