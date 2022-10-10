#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

template<class T>
class SimpleVector{
public:
    SimpleVector(int capacityValue){
        capacity = capacityValue;
        v = new T[capacity];
        for(int i=0; i<capacity; i++)
            v[i] = '\0';
    }
    SimpleVector(){
        capacity = 5;
        v = new T[capacity];
        for(int i=0; i<capacity; i++)
            v[i] = '\0';
    }
    ~SimpleVector(){
        delete [] v;
    }
    
    int my_empty(){
        for(int i=0; i<capacity; i++){
            if(v[i] != '\0')
                return 0;
        }
        return 1;
    }
    
    int my_size(){
        int count = 0;
        for(int i=0; i<capacity; i++){
            if(v[i] != '\0')
                count++;
        }
        return count;
    }
    
    void my_reverse(){
        for(int i=0; i<my_size()/2; i++){
            T temp = v[i];
            v[i] = v[my_size()-i-1];
            v[my_size()-i-1] = temp;
        }
    }
    
    void my_clear(){
        int i=0;
        while(v[i] != '\0'){
            v[i] = '\0';
            i++;
        }
    }
    
    void my_extend(){
        int new_capacity = capacity*2;
        T *new_v = new T[new_capacity];
        for(int i=0; i<new_capacity; i++)
            new_v[i] = '\0';
        for(int i=0; i<capacity; i++){
            new_v[i] = v[i];
        }
        delete v;
        v = new_v;
        capacity = new_capacity;
    }
    
    void my_push_back(T value){
        if(my_size() == capacity)
            my_extend();
        v[my_size()] = value;
    }
    
    void my_pop_back(){
        v[my_size()-1] = '\0';
    }
    
    void my_insert(T value, T index){
        if(index<my_size()){
            if(my_size() == capacity)
                my_extend();
            for(int i=my_size()-1; i>=(int)index; i--){
                v[i+1] = v[i];
            }
            v[(int)index] = value;
        }
    }
    
    void my_set(T value, T index){
        if((int)index < my_size())
            v[(int)index] = value;
    }
    
    void print(){
        for(int i=0; i<my_size(); i++){
            cout << v[i] << "_";
        }
    }
    
    T operator [](T index){
        if((int)index >= my_size())
            return v[my_size()-1];
        else
            return v[(int)index];
    }

private:
    int capacity;
    T *v;
};




