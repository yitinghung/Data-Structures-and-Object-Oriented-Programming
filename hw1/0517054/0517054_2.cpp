#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

class Polynomial{
private:
    int x;
    vector<int> coef;
public:
    Polynomial(){}
    Polynomial(int xData, vector<int> coefData){
        x = xData;
        coef = coefData;
    }
    int calculate(int xData, vector<int> coefData){
        int ans = 0;
        for(int i=0; i<coefData.size(); i++){
            ans += coefData[i]*pow(xData, coefData.size()-1-i);
        }
        return ans;
    }
    int firstDerivative(int xData, vector<int> coefData){
        int ans = 0;
        for(int i=0; i<coefData.size()-1; i++){
            ans += coefData[i]*((coefData.size()-1-i)*pow(xData, coefData.size()-i-2));
        }
        return ans;
    }
    int secDerivative(int xData, vector<int> coefData){
        int ans = 0;
        for(int i=0; i<coefData.size()-2; i++){
            int a = coefData[i]*(coefData.size()-1-i)*(coefData.size()-i-2);
            int b = pow(xData, coefData.size()-i-3);
            ans += a*b;
        }
        return ans;
    }
};

int main(){
    int x;
    
    while (cin >> x){
        string coef;
        vector<int> coef_v;
        getchar();
        getline(cin, coef);
        
        string result;
        stringstream input(coef);
        while(input >> result)
            coef_v.push_back(atoi(result.c_str()));
        Polynomial P(x, coef_v);
        cout << P.calculate(x, coef_v) << " " << P.firstDerivative(x, coef_v) << " " << P.secDerivative(x, coef_v) << endl;
    
    }
    return 0;
    }

