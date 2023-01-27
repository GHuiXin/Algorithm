#include<iostream>
#include<vector> 

using namespace std;

/**
 * 方法：插入排序
 * 1：直接插入排序 
 	- 时间复杂度O(n^2)
	- 空间复杂度O(1)
	- 稳定
	- 适用顺序存储、链式存储
 * 2：折半插入排序 
 	- 时间复杂度O(n^2)
	- 空间复杂度O(1)
	- 稳定
	- 适用数据量少
 * 3：希尔排序
 	- 时间复杂度O(n^2)
	- 空间复杂度O(1)
	- 不稳定
	- 适用顺序存储 
  
 
*/ 
void Insertion1(vector<int>& nums, int n){
	for(int i = 1; i < n; i++){
		if(nums[i] < nums[i - 1]){
			int temp = nums[i];
			int j = i - 1;
			while(j >= 0 && temp < nums[j]){
				nums[j + 1] = nums[j]; // 向后移动 
				j--;
			}
			nums[j + 1] = temp; // 插入 
		}
	} 
}//直接插入排序 

void Insertion2(vector<int>& nums, int& n){
	for(int i = 1; i < n; i++){
		int temp = nums[i];
		int low = 0, high = i - 1, mid;
		while(low <= high){
			mid =low + (high - low) / 2;
			if(temp < nums[mid]) high = mid - 1;
			else low = mid + 1; 
		}
		for(int j = i - 1; j >= high + 1; j--){
			nums[j + 1] = nums[j];
		}
		nums[high + 1] = temp;
	}  
} // 折半插入排序
 
void Insertion3(vector<int>& nums, int& n){
	for(int stage = n / 2; stage >= 1; stage = stage / 2){// 步长变化 
		for(int i = stage; i < n; i++){ // 直接插入排序 
			if(nums[i] < nums[i - stage]){
				int temp = nums[i];
				int j = i - stage;
				while(j >= 0 && temp < nums[j]){
					nums[j + stage] = nums[j];
					j--;
				}
				nums[j + stage] = temp; 
			}
		}
	}
}// 希尔排序
 
int main(){
	vector<int> nums = {2, 4, 3, 10, 22, 14, 30, 31, 20, 15, 44, 13};
	int n = nums.size();
	// 1 直接插入排序 
	Insertion1(nums, n);
	cout << "直接插入排序:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	Insertion2(nums, n);
	cout << "折半插入排序:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	Insertion3(nums, n);
	cout << "希尔排序:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
} 

