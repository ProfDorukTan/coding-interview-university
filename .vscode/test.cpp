#include <iostream>
#include "vector.h"
#include <random>

// Function to generate a random integer within a specified range [-100, 100]
int getRandomNumber() {
    std::random_device rd; // Obtain a random seed from the OS entropy device
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(-100, 100); // Uniform distribution between min and max
    return dis(gen);
}


int main() {
    // Test the constructor
    vector<int> v2;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v2 capacity: " << v2.capacity() << std::endl;

    // Test the push function
    v2.push(10);
    v2.push(20);
    v2.push(30);
    v2.print_vector();
    std::cout << "v2 size after push: " << v2.size() << std::endl;
    std::cout << "v2 capacity after push: " << v2.capacity() << std::endl;
    

    // Test the push function for resize
    for(int i = 0; i < 20; i++){
        v2.push(getRandomNumber());
    }
    v2.print_vector();
    std::cout << "v2 size after push: " << v2.size() << std::endl;
    std::cout << "v2 capacity after push: " << v2.capacity() << std::endl;
    for(int i = 0; i < 200; i++){
        v2.push(getRandomNumber());
    }
    v2.print_vector();
    std::cout << "v2 size after push: " << v2.size() << std::endl;
    std::cout << "v2 capacity after push: " << v2.capacity() << std::endl;


    // Test the pop function
    std::cout <<  "Popped: " << v2.pop() << std::endl;
    v2.print_vector();
    std::cout << "v2 size after pop: " << v2.size() << std::endl;
    std::cout << "v2 capacity after pop: " << v2.capacity() << std::endl;

    // Test the pop function for resize
    for(int i = 0; i < 200; i++){
        v2.pop();
        std::cout << "v2 size after pop: " << v2.size() << std::endl;
        std::cout << "v2 capacity after pop: " << v2.capacity() << std::endl;
    }
    v2.print_vector();

    
    // Test the at function
    v2.print_vector();
    for(int i = 0; i < v2.size(); i++){
        std::cout << v2.at(i) << " ";
    }
    std::cout << std::endl;

    // Test the insert function
    v2.insert(0, 9999);
    v2.print_vector();  
    for(int i = -5; i < 40; i = i + 4){
        v2.insert(i, 9999);
        v2.print_vector();
    }    
     
    // Test the remove function
    v2.remove(0);
    v2.print_vector();  
    for(int i = v2.size() - 1; i > -5; i = i - 2){
        v2.remove(i);
        v2.print_vector();
    }  

    // Test the find function
    for(int i = -2; i < 7; i = i + 1){
        std::cout << v2.find(v2.at(i)) << std::endl;
    }
    return 0;
}