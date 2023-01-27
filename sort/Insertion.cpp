#include<iostream>
#include<vector> 

using namespace std;

/**
 * ��������������
 * 1��ֱ�Ӳ������� 
 	- ʱ�临�Ӷ�O(n^2)
	- �ռ临�Ӷ�O(1)
	- �ȶ�
	- ����˳��洢����ʽ�洢
 * 2���۰�������� 
 	- ʱ�临�Ӷ�O(n^2)
	- �ռ临�Ӷ�O(1)
	- �ȶ�
	- ������������
 * 3��ϣ������
 	- ʱ�临�Ӷ�O(n^2)
	- �ռ临�Ӷ�O(1)
	- ���ȶ�
	- ����˳��洢 
  
 
*/ 
void Insertion1(vector<int>& nums, int n){
	for(int i = 1; i < n; i++){
		if(nums[i] < nums[i - 1]){
			int temp = nums[i];
			int j = i - 1;
			while(j >= 0 && temp < nums[j]){
				nums[j + 1] = nums[j]; // ����ƶ� 
				j--;
			}
			nums[j + 1] = temp; // ���� 
		}
	} 
}//ֱ�Ӳ������� 

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
} // �۰��������
 
void Insertion3(vector<int>& nums, int& n){
	for(int stage = n / 2; stage >= 1; stage = stage / 2){// �����仯 
		for(int i = stage; i < n; i++){ // ֱ�Ӳ������� 
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
}// ϣ������
 
int main(){
	vector<int> nums = {2, 4, 3, 10, 22, 14, 30, 31, 20, 15, 44, 13};
	int n = nums.size();
	// 1 ֱ�Ӳ������� 
	Insertion1(nums, n);
	cout << "ֱ�Ӳ�������:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	Insertion2(nums, n);
	cout << "�۰��������:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
	Insertion3(nums, n);
	cout << "ϣ������:" << endl; 
	for(int i = 0; i < n; i++){
		cout << nums[i] << ' ';
	}
	cout << endl;
} 

