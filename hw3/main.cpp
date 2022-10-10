#include"SimpleVector.h"
using namespace std;
#include<iostream>
#include<cmath>

int main()
{
	int input_type, command = -1;
    cin >> input_type;
    
    if (input_type == 1)
    {
        SimpleVector<int> sv1(5);
        int value, index;
        
        while(command != 0){
        	cin >> command >> value >> index; 
	    	switch (command){
			    case 1:
			    	sv1.my_push_back(value);
			    	break;
			
			    case 2:
			        sv1.my_insert(value, index);
			        break;
			        
			    case 3:
			        sv1.my_set(value, index);
			        break;
			        
			    case 4:
			    	sv1.my_reverse();
			    	break;
			
			    case 5:
			        sv1.my_pop_back();
			        break;
			        
			    case 6:
			        sv1.my_clear();
			        break;
			    		        
			    case 0:
			        sv1.print();
			        cout << endl;
			        for(int i=0; i<sv1.my_size(); i++){
			        	cout << sv1[i] << "_";
					}
					cout << endl;
					if(sv1.my_empty()){
						cout << "Is Empty";
					}else{
						cout << "Not Empty";
					}
					
			        break;
			        
			    default:
			        break;
			}
		}
        
    }
    else
    {
    	SimpleVector<double> sv2;
    	double value, index;
        
        while(command != 0){
        	cin >> command >> value >> index; 
	    	switch (command){
			    case 1:
			    	sv2.my_push_back(value);
			    	break;
			
			    case 2:
			        sv2.my_insert(value, index);
			        break;
			        
			    case 3:
			        sv2.my_set(value, index);
			        break;
			        
			    case 4:
			    	sv2.my_reverse();
			    	break;
			
			    case 5:
			        sv2.my_pop_back();
			        break;
			        
			    case 6:
			        sv2.my_clear();
			        break;
			    		        
			    case 0:
			        sv2.print();
			        cout << endl;
			        for(int i=0; i<sv2.my_size(); i++){
			        	cout << sv2[i] << "_";
					}
					cout << endl;
					if(sv2.my_empty()){
						cout << "Is Empty";
					}else{
						cout << "Not Empty";
					}
					
			        break;
			        
			    default:
			        break;
			}
		}
    }
}

