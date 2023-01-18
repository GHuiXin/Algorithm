#include<iostream>
#include<vector> 

using namespace std;
void sort(vector<int>& nums, int& n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - 1 - i; j++){
			if(nums[j] > nums[j + 1]){
				swap(nums[j], nums[j + 1]);
			}
		}
	}	
}
int main(){
	vector<int> nums = {5, 10, 2, 3, 1, 4, 6, 11, 12, 9};
	int n = nums.size(); 
	sort(nums, n);
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
}
