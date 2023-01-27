#include<iostream>
#include<vector>

using namespace std;
void merge(vector<int>& nums, int low, int mid, int high){
	vector<int> temp(nums.size());
	for(int l = low; l <= high; l++){
		temp[l] = nums[l];  
	}
	int i, j, k = 0;
	for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++){
		if(temp[i] <= temp[j]){
			nums[k] = temp[i++];
		} 
		else{
			nums[k] = temp[j++];
		}
	}
	while(i <= mid) nums[k++] = temp[i++];
	while(j <= high) nums[k++] = temp[j++];
}
void mergeSort(vector<int>& nums, int low, int high){
	if(low < high){
		int mid = low + (high - low) / 2;
		mergeSort(nums, low, mid); //��� 
		mergeSort(nums, mid + 1, high); //�Ҳ� 
		merge(nums, low, mid, high); //�ϲ� 
	}
	
}
int main(){
	vector<int> nums = {2, 4, 5, 1, 3, 10, 8, 6, 22, 25, 23, 15};
	mergeSort(nums, 0, nums.size() - 1);
	for(int i = 0; i < nums.size(); i++){
		cout << nums[i] << ' ';
	} 
	cout << endl;
} 
