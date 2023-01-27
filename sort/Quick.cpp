#include<iostream>
#include<vector>

using namespace std;
/* 快速排序：
 * 时间复杂度：O(logn) 
 * 空间复杂度： O(n^2)
 * 不稳定 
*/ 
int Partition(vector<int>& nums, int low, int high){
	int value = nums[low];
	while(low < high){
		while(low < high && nums[high] >= value) high--;
		nums[low] = nums[high];
		while(low < high && nums[low] <= value) low++;
		nums[high] = nums[low];
	}
	nums[low] = value;
	return low;
	
}
void Quick(vector<int>& nums, int low, int high){
	if(low < high){
		int index = Partition(nums, low, high);
		Quick(nums, low, index - 1);
		Quick(nums, index + 1, high);
	}
}
int main(){
	vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
	cout << "排序前：" << endl; 
	for(auto& num : nums){
		cout << num << " ";
	}
	cout << endl;
	Quick(nums, 0, nums.size() - 1);
	cout << "排序后：" << endl; 
	for(auto& num : nums){
		cout << num << " ";
	}
	cout << endl;
} 
