/*
    cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns 
    the first and last element of that pair. For example, car(cons(3, 4)) 
    returns 3, and cdr(cons(3, 4)) returns 4.
*/

#include <iostream>
#include <utility>

std::pair<int, int> cons(int a, int b){
    std::pair<int, int> thisPair (a, b);
    return thisPair;
}

int car(std::pair<int,int> pair){
    return pair.first;
}

int cdr(std::pair<int,int> pair){
    return pair.second;
}

int main(){
    std::cout << "First: " << car(cons(3,4)) << "\n";
    std::cout << "Second: " << cdr(cons(3,4)) << "\n";
    return 0;
}