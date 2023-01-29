#include<iostream>
#include<vector>
using namespace std;
// 调整 
void HeadAdjust(vector<int>& nums, int k, int n){
    int temp =nums[k];
    for(int i = 2 * k; i <= n; i *= 2){
        if(i < n && nums[i] < nums[i+1]){
            i++;
        }
        if(temp >= nums[i]) break;
        else{
            nums[k] = nums[i];
            k = i;
        }
    }
    nums[k] = temp;
}

// 建立大根堆 
void BuildMaxHeap(vector<int>& nums, int n){
    for(int i = n / 2; i >= 0; i--){
        HeadAdjust(nums, i, n);
    }
} 

void HeapSort(vector<int>& nums, int n){
    BuildMaxHeap(nums, n);
    for(int i = n; i >= 0; i--){
        swap(nums[i], nums[0]);
        HeadAdjust(nums, 0, i - 1);
    }
}
int main(){
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 9, 55, 4};
    int n = nums.size() - 1;
    cout << "排序前：" << endl;
    for(int i = 0; i <= n; i++){
        cout << nums[i] << ' ';
    }  
    cout << endl;
    HeapSort(nums, n);
    cout << "排序后：" << endl;
    for(int i = 0; i <= n; i++){
        cout << nums[i] << ' ';
    }
    cout << endl;
}
