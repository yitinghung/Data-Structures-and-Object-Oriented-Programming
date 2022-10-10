#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Large{
private:
    string num;
public:
    Large(string numValue){
        num = numValue;
    }
    Large(){}
    friend istream& operator >> (istream& inputStream, Large& large);
    friend ostream& operator << (ostream& outputStream, const Large& large);
    
    int sign(string& num1, string& num2){
        if(num1[0] == '-' && num2[0] == '-') // --
            return 1;
        if(num1[0] == '-' && num2[0] != '-') // -+
            return 2;
        if(num1[0] != '-' && num1[0] == '-') // +-
            return 3;
        if(num1[0] != '-' && num2[0] != '-')// ++
            return 4;
        else return 0;
    }
    
    const Large operator +(const Large& number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string total;
        if(sign(num1, num2) == 4){
            total = Large_add(num1, num2);
        }
        else if(sign(num1, num2) == 3){
            num2.pop_back();
            total = Large_sub(num1, num2);
        }
        else if(sign(num1, num2) == 2){
            num1.pop_back();
            total = Large_sub(num2, num1);
        }
        else{
            num1.pop_back();
            num2.pop_back();
            total = Large_add(num1, num2);
            total.append("-");
        }
        reverse(total.begin(), total.end());
        return Large(total);
    }
    string Large_add(string& num1, string& num2){
        int len1 = num1.length();
        int len2 = num2.length();
        int sum = 0;
        int carry = 0;
        if (len1 < len2) return Large_add(num2, num1);
        else{
            //len1 > len2
            for(int i = 0; i < len2; i++){
                sum = num1[i] - '0' + num2[i] - '0' + carry;
                if (sum > 9){
                    carry = 1;
                    sum = sum - 10;
                }
                else{
                    carry = 0;
                }
                num1[i] = sum + '0';
            }
            for (int i = len2; i < len1; i++){
                sum = num1[i] - '0' + carry;
                if (sum > 9){
                    carry = 1;
                    sum = sum - 10;
                }
                else{
                    carry = 0;
                }
                num1[i] = sum + '0';
            }
            if(carry == 1)
                num1.append("1");
            return num1;
        }
    }
    
    const Large operator -(const Large& number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string total;
        if(sign(num1, num2) == 4){
            total = Large_sub(num1, num2);
        }
        if(sign(num1, num2) == 3){
            num2.pop_back();
            total = Large_add(num1, num2);
        }
        if(sign(num1, num2) == 2){
            num1.pop_back();
            total = Large_add(num2, num1);
            total.append("-");
        }
        if(sign(num1, num2) == 1){
            num1.pop_back();
            num2.pop_back();
            total = Large_sub(num2, num1);
        }
        reverse(total.begin(), total.end());
        return Large(total);
    }
    string Large_sub(string& num1, string& num2){
        int len1 = num1.length();
        int len2 = num2.length();
        int long_len = len1; //default
        bool negative = false; //default
        if (len1 < len2){
            long_len = len2;
            negative = true;
        }
        else if(len1 == len2){
            for(int i = len1 - 1; i >= 0; i--){
                if (num1[i] - '0' < num2[i] - '0'){
                    long_len = len2;
                    negative = true;
                    break;
                }
                else if (num1[i] - '0' > num2[i] - '0')
                    break;
            }
        }
        
        int big_arr[long_len];
        int small_arr[long_len];
        memset(big_arr, 0, long_len*sizeof(int));
        memset(small_arr, 0, long_len*sizeof(int));
        
        if (long_len == len1 && negative == false){
            for(int i = 0; i < len1; i++){
                big_arr[i] = num1[i] - '0';
            }
            for(int i = 0; i < len2; i++){
                small_arr[i] = num2[i] - '0';
            }
        }
        else{
            for(int i = 0; i < len1; i++){
                small_arr[i] = num1[i] - '0';
            }
            for(int i = 0; i < len2; i++){
                big_arr[i] = num2[i] - '0';
            }
        }
        
        for(int i = 0; i < long_len; i++){
            big_arr[i] -= small_arr[i];
            if(big_arr[i] < 0){
                big_arr[i] += 10;
                big_arr[i+1]--;
            }
        }
        
        int final_len = long_len - 1;
        while(final_len > 0){
            if(big_arr[final_len] == 0){
                final_len--;
            }
            else
                break;
        }
        
        string ans = "";
        for(int i = 0; i <= final_len; i++){
            ans.append(to_string(big_arr[i]));
        }
        if(negative == true){
            ans.append("-");
        }
        return ans;
    }
    
    const Large operator *(const Large& number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string total;
        if(sign(num1, num2) == 4){
            total = Large_mul(num1, num2);
        }
        else if(sign(num1, num2) == 3){
            num2.pop_back();
            total = Large_mul(num1, num2);
            total.append("-");
        }
        else if(sign(num1, num2) == 2){
            num1.pop_back();
            total = Large_mul(num2, num1);
            total.append("-");
        }
        else{
            num1.pop_back();
            num2.pop_back();
            total = Large_mul(num1, num2);
        }
        reverse(total.begin(), total.end());
        return Large(total);
    }
    string Large_mul(string& num1, string& num2){
        int len1 = num1.length();
        int len2 = num2.length();
        int a[len1];
        int b[len2];
        int c[len1 + len2 + 1];
        memset(a, 0, len1*sizeof(int));
        memset(b, 0, len2*sizeof(int));
        memset(c, 0, (len1 + len2 + 1)*sizeof(int));
        
        for(int i = 0; i < len1; i++){
            a[i] = num1[i] - '0';
        }
        
        for(int j = 0; j < len2; j++){
            b[j] = num2[j] - '0';
        }
        for(int j = 0; j < len2; j++){
            for(int i = 0; i < len1; i++){
                c[i+j] += a[i] * b[j];
            }
        }
        
        for(int i = 0; i < len1 + len2; i++){
            if(c[i] >= 10){
                c[i+1] += c[i] / 10;
                c[i] = c[i] % 10;
            }
        }
        
        int final_len = len1 + len2 - 1;
        while(final_len > 0){
            if(c[final_len] == 0){
                final_len--;
            }
            else{
                break;
            }
        }
        string ans = "";
        for(int i = 0; i <= final_len; i++){
            ans.append(to_string(c[i]));
        }
        return ans;
    }
    
    const Large operator /(const Large& number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string neg;
        if(num2 == "0")
            return Large("Undefined");
        if(sign(num1, num2) == 3){
            num2.pop_back();
            neg = "True";
        }
        if(sign(num1, num2) == 2){
            num1.pop_back();
            neg = "True";
        }
        if (sign(num1, num2) == 1){
            num1.pop_back();
            num2.pop_back();
        }
        string total = Large_div(num1, num2);
        string total_float = Large_div_float(num1, num2, total);
        total.insert(0, total_float);
        if (neg == "True")
            total.append("-");
        reverse(total.begin(), total.end());
        return Large(total);
    }
    
    string Large_div(string& num1, string& num2){
        string ans = "0";
        string divisor = num1;
        string dividend = num2;
        while(Large_cmp(divisor, dividend) == 1 || Large_cmp(divisor, dividend) == 3){
            int gap = divisor.length() - dividend.length();
            int count = 0;
            string expand_dividend = "";
            for (int i = 0; i < gap-1; i++){
                expand_dividend.append("0");
                count++;
            }
            if(divisor[divisor.length()-1] > dividend[dividend.length()-1] && divisor.length() > dividend.length()){
                expand_dividend.append("0");
                count++;
            }
            expand_dividend += dividend;
            divisor = Large_sub(divisor, expand_dividend);
            string temp = "";
            for(int i = 0; i < count; i++){
                temp.append("0");
            }
            temp.append("1");
            ans = Large_add(ans, temp);
        }
        return ans;
    }
    
    string Large_div_float(string& num1, string& num2, string ans_int){
        string ans = "";
        string remainder = Large_mul(ans_int, num2);
        remainder = Large_sub(num1, remainder);
        
        remainder.insert(0, "0");
        for (int i=0; i<3; i++){
            ans_int = Large_div(remainder, num2);
            ans.insert(0, ans_int);
            string remainder2 = Large_mul(ans_int, num2);
            remainder2 = Large_sub(remainder, remainder2);
            remainder = remainder2;
            remainder.insert(0, "0");
        }
        ans.append(".");
        
        string round = Large_div(remainder, num2);
        if(round == "5" || round == "6" || round == "7" || round == "8" || round == "9"){
            string add = "1";
            ans = Large_add(ans, add);
        }
        if (ans[0] == '0' && ans[1] == '0' && ans[2] == '0')
            ans = "";
        return ans;
    }
    
    Large operator-(){
        Large result;
        result.num = num;
        reverse(result.num.begin(), result.num.end());
        if(sign(num, num) == 4){
            result.num.append("-");
        }
        if(sign(num, num) == 1){
            result.num.pop_back();
        }
        reverse(result.num.begin(), result.num.end());
        return result;
    }
    
    const Large operator>(const Large number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(sign(num1, num2) == 1){
            num1.pop_back();
            num2.pop_back();
            if(Large_cmp(num1, num2) == 2) {
                string a =  "True";
                return Large(a);
            }
            else {
                string a =  "False";
                return Large(a);
            }
        }
        if(sign(num1, num2) == 2){
            string a = "False";
            return Large(a);
        }
        if(sign(num1, num2) == 3){
            string a = "True";
            return Large(a);
        }
        if(sign(num1, num2) == 4){
            if(Large_cmp(num1, num2) == 1) {
                string a =  "True";
                return Large(a);
            }
            else {
                string a =  "False";
                return Large(a);
            }
        }
        else
            return Large();
    }
    
    const Large operator<(const Large number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(sign(num1, num2) == 1){
            num1.pop_back();
            num2.pop_back();
            if(Large_cmp(num1, num2) == 1) {
                string a =  "True";
                return Large(a);
            }
            else {
                string a =  "False";
                return Large(a);
            }
        }
        if(sign(num1, num2) == 2){
            string a = "True";
            return Large(a);
        }
        if(sign(num1, num2) == 3){
            string a = "False";
            return Large(a);
        }
        if(sign(num1, num2) == 4){
            if(Large_cmp(num1, num2) == 2) {
                string a =  "True";
                return Large(a);
            }
            else {
                string a =  "False";
                return Large(a);
            }
        }
        else
            return Large();
    }
    
    const Large operator ==(const Large number2){
        string num1 = num;
        string num2 = number2.num;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if(Large_cmp(num1, num2) == 3){
            string a = "True";
            return Large(a);
        }
        else{
            string a = "False";
            return Large(a);
        }
    }
    
    //1: >, 2: <, 3: =
    int Large_cmp(string num1, string num2){
        if (num1.length() > num2.length())
            return 1;
        else if (num1.length() < num2.length())
            return 2;
        else{
            int i = num1.length() - 1;
            while(i >= 0){
                if(num1[i] < num2[i])
                    return 2;
                else if(num1[i] > num2[i])
                    return 1;
                i--;
            }
            return 3;
        }
    }
};

istream& operator >> (istream& inputStream, Large& large){
    inputStream >> large.num;
    return inputStream;
}

ostream& operator << (ostream& outputStream, const Large& large){
    outputStream << large.num;
    return outputStream;
}



