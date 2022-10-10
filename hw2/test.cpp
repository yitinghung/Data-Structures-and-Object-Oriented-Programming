#include <iostream>
#include <cmath>
#include <string>
/*The header files above are those you might use.
You can include other header files if you need to use them.
But make sure those header files can be used in the test environment. */
using namespace std;


class Machine {  /* DO NOT add any code in this parent class and its virtual function*/
    protected:
        string type;
    public:
        virtual void welcome_message(){}
        virtual void problem_solver(int x){}
		virtual void problem_solver(string str){}
};


class Math_machine:public Machine{
    public:
        Math_machine(string type){this->type=type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}

        void problem_solver(int x) {
            int a, b;
            for(int i=sqrt(x); i>0; i++){
                if(x % i == 0){
                    a=i;
                    b=x/a;
                    break;
                }
            }
            int c, d;
            for(int i=sqrt(x+1); i>0; i++){
                if((x+1) % i == 0){
                    c=i;
                    d=(x+1)/c;
                    break;
                }
            }
            if (a-b < c-d)
                cout << b << " " << a << endl;
            else
                cout << d << " " << c << endl;
        }
};

class String_machine:public Machine{
    public:
        String_machine(string type){this->type=type;}
        void welcome_message(){cout<<"Solving the "<<type<<" problem."<<endl;}

        void problem_solver(string str) {
            int n=str.length();
            int ans=0, i=0;
            while(i<n){
                int cnt0=0, cnt1=0;
                if(str[i] == '0'){
                    while(i<n && str[i] == '0'){
                        cnt0++;
                        i++;
                    }
                    int j=i;
                    while(j<n && str[j] == '1'){
                        cnt1++;
                        j++;
                    }
                }
                else{
                    while(i<n && str[i] == '1'){
                        cnt1++;
                        i++;
                    }
                    int j=i;
                    while(j<n && str[j] == '0'){
                        cnt0++;
                        j++;
                    }
                }
                ans += min(cnt0, cnt1);
            }
            cout << ans << endl;
        }
};

int main(){
    string question_type;
    while(cin >> question_type){
        Machine machine;
        machine.welcome_message();
        if(question_type == "math"){
            Math_machine Math(question_type);
            //Math.welcome_message();
            int x;
            cin >> x;
            Math.problem_solver(x);
        }
        else{
            String_machine String(question_type);
            //String.welcome_message();
            string a;
            cin >> a;
            String.problem_solver(a);
        }
    }
}
