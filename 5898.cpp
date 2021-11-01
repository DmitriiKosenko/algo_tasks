/*

5898. Kth Distinct String in an Array

A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for (int i = 0; i < arr.size(); i++) {
            int val = m[arr[i]];
            m[arr[i]] = val + 1;
        }
        
        int counter = 0;
        for (int i = 0; i < arr.size() && counter < k; i++) {
            if (m[arr[i]] == 1) {
                if (counter + 1 == k) {
                    return arr[i];
                }
                counter++;
            }
        }
        return "";
    }
};


int main() {

	Solution s;

	vector<string> v1 = {"d","b","c","b","c","a"};
	cout << s.kthDistinct(v1, 2) << endl;
	
	return 0;
}