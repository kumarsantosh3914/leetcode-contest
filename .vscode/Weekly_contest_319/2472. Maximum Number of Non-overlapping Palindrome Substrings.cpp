#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define p(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define s(x) scanf("%f", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define bitcount __builtin_popcountll
#define INF 1e18+9
// #define int long long
// #define l "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vv vector<vector<int> > 
#define um unordered_map<int, int>
#define m map<int,int>
class Solution {
private:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.size() - 1;
        while(left < right) {
            if(s[left++] !=s [right--]) return 0;
        }
        return true;
    }
    bool isC(char c){
        return (c>='a' && c<='z') || (c>='A' && c<='Z');
    }
    bool isPalindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        //1: first solution
        int ans = 0;
        string temp = "";
        int i=0, j = 0, t = 0;
        while(i <= s.size() - k) {
            j = i;
            temp = "";
            t=i+1;
            while(j < s.size()) {
                temp+=s[j];
                if(temp.length() >= k) {
                    if(isPalindrome(temp)){
                        ans++;
                        t=j+1;
                        temp = "";
                    }
                }
                j++;
            }
            i = t;
        }
        return ans;
        //2: second solution
        int res = 0, n=s.length();
        for(int i=0; i<n; i++){
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r] && isC(s[l]) && isC(s[r])){
                if(r-l+1 >= k){
                    res++; 
                    s[l] = '$';
                    s[r] = '$'; 
                    break;
                }
                l--;
                r++;
            }
            
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r] && isC(s[l]) && isC(s[r])){
                if(r-l+1 >= k){
                    res++; 
                    s[l] = '$';
                    s[r] = '$'; 
                    break;
                }
                l--;
                r++;
            }
        }
        return res;
        //3: third solution
        //*Main catch here was to avoid picking a palindromic substring with size greater than k+1 because 
        //if there exist a palindromic substring with size greater than k+1 then it would definitely contain a palindromic '
        //substring with size at least k ( It was just basic observation ) And we are trying to minimize the length of the 
        //palindromic string ( with size >= k ) to maximize our answer.

        /*
           Suppose:
            string =abaczbzccc & k = 3

            Without break condition, answer would have been 2 ( aba, czbzc )
            With break condition, answer would be 3 ( aba, zbz, ccc )
            Note::Now observe the difference, instead of picking 'czbzc' we pick 'zbz' which allowed us to further pick 'ccc' as well. I hope it clarifies your doubt.
        */
       int ans = 0;
       for(int i=0; i<s.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            int len = (j - i) + 1;
            //this is the key
            if(len > k + 1) break;
            if(len >= k && isPalindrome(s, i, j)) {
                ans++;
                i = j;
                break;
            }
        }
       }
       return ans;
    }
};
