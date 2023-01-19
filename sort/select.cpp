#include<iostream>
#include<vector>

using namespace std;
void select(vector<int>& nums, int n){
	for(int i = 0; i < n; i++){
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(nums[min] > nums[j]){
				min = j;
			}
		}
		swap(nums[i], nums[min]);
	}
}
int main(){
	vector<int> nums = {11, 1, 24, 2, 4, 3, 9, 20, 21, 30, 15, 18, 12, 44};
	int n = nums.size();
	select(nums, n);
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
} 
