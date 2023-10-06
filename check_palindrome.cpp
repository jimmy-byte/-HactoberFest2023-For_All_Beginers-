#include<bits/stdc++.h>

using namespace std;

    bool isPalindrome(string&s) {
         int left = 0, right = s.length()-1;
        while(left<right)
        {
            if(!isalnum(s[left])) 
                left++;
            else if(!isalnum(s[right])) 
                right--;
            else if(tolower(s[left])!=tolower(s[right])) 
                return false;
            else {
                left++; 
                right--;
            }
        }
        return true;
    }

    int main(){
        string s1;
        cin>>s1;

        bool ans = isPalindrome(s1);

        if(ans){
            cout<<"your string is palindrome"<<endl;
        }
        else{
            cout<<"your string is not palindrome"<<endl;
        }
        return 0;
    }