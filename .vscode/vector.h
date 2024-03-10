//Written by Doruk Tan Atila
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
const int INITIAL_VECTOR_SIZE = 16;                 //Vector will be initially created with size 16
const int VECTOR_SIZE_GROW = 2;                     //If the vector size reaches vector capacity needs to increase it will be multiplied by this amount
const float VECTOR_SIZE_DECAY = 0.5;                    //If the vector size is below threshold, the size will be multiplied by this amount
const float VECTOR_SIZE_DECAY_THRESH = 0.25;        //If the vector sizde drops below vector capacity * this amount the size will be decreased

template<typename var_type> //This template will be used to make the class generic for all data types

class vector {
public:
    vector(){
        arr = new var_type[INITIAL_VECTOR_SIZE];
        vector_size = 0;
        vector_capacity = INITIAL_VECTOR_SIZE;
    }
    ~vector() {
        delete[] arr;           // Deallocate the dynamically allocated memory
    }   
    //Returns the size of the vector
    int size(void) const {
        return vector_size;
    }
    //Returns the number of spaces allocated in the vector
    int capacity(void) const{
        return vector_capacity;
    }
    //Returns 0 if the vector is empty
    bool is_empty(void){
        if(vector_size == 0){
            return true;
        }
        return false;
    }
    //Returns the data stored at index
    var_type at(int index){
        if(index < 0){
            std::cerr << "Error: Index can't be negative!" << std::endl;
            return 0;
        }
        if(index >= vector_size){
            std::cerr << "Error: Index out of vector size!" << std::endl;
            return 0;
        }
        return arr[index];
    }
    //Pushes the data at the end of the index
    void push(var_type item){
        if(vector_size < vector_capacity){
            arr[vector_size] = item;
            vector_size++;
        }else{
            resize(vector_capacity * VECTOR_SIZE_GROW);
            arr[vector_size] = item;
            vector_size++;
        }
    }
    //Inserts the data at given index. Shifts the data in index and data right of index to right. 
    void insert(int index, var_type item){
        if(index < 0){
            std::cerr << "Error: Index can't be negative!" << std::endl;
            return;
        }
        if(index >= vector_size){
            std::cerr << "Error: Index out of vector size!" << std::endl;
            return;
        }
        if(vector_size == vector_capacity){
            resize(vector_capacity * VECTOR_SIZE_GROW);
        }
        for(int i = vector_size; i >= index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = item;
        vector_size++;
    }
    void prepend(var_type item){
        insert(0, item);
    }
    var_type pop(void){
        if(is_empty()){
            std::cerr << "Error: Vector empty!" << std::endl;
            return 0;  
        }
        vector_size--;
        if(vector_size < (vector_capacity * VECTOR_SIZE_DECAY_THRESH)){
            resize(vector_capacity * VECTOR_SIZE_DECAY);
        }
        return arr[vector_size];
    }
    void remove(int index){
        if(is_empty()){
            std::cerr << "Error: Vector empty!" << std::endl;
            return;  
        }
        if(index < 0){
            std::cerr << "Error: Index can't be negative!" << std::endl;
            return;
        }
        if(index >= vector_size){
            std::cerr << "Error: Index out of vector size!" << std::endl;
            return;
        }
        for(int i = index; i < vector_size; i++){
            arr[i] = arr[i + 1];
        }
        vector_size--;
    }
    int find(var_type item){
        for(int i = 0; i < vector_size; i++){
            if(arr[i] == item){
                return i;
            }
        }
        return -1;
    }
    void print_vector(){
        for(int i = 0; i < vector_size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    void resize(int new_capacity){
            var_type *temp_arr = new var_type[new_capacity];
            for(int i = 0; i < vector_size; i++){
                temp_arr[i] = arr[i];
            }
            delete []arr;
            arr = temp_arr;
            vector_capacity = new_capacity;
    }

    var_type *arr;
    int vector_size, vector_capacity; 
};

#endif // VECTOR_H