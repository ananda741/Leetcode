#include<iostream>
#include<vector>
using namespace std;




    void move2end(vector<int> &nums1,int size,int n){
        int i,j = size-1;
        for(i = size-1;i>=0;i--){
            if(i<n){
                nums1[j] = nums1[i];
                j--;
            }
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n == 0)
            return;
        
        move2end(nums1,m+n,m);

	int l;
	for(l = 0;l<nums1.size();l++)
		cout<<nums1[l]<<" ";

	cout<<endl;
        
        int i = n;
        int j = 0;
        int k = 0;
        
        while(k<m+n){
            if((i<(m+n) && nums1[i]<=nums2[j])||j==n){
                nums1[k] = nums1[i];
                i++;
                k++;
            }
            else{
                nums1[k] = nums2[j];
                j++;
                k++;
            }
        }
    }





int main(){
	vector<int> nums1,nums2;
	nums1.push_back(4);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	nums2.push_back(5);

	int i;

	merge(nums1,1,nums2,1);

	for(i=0;i<nums1.size();i++)
		cout<<nums1[i]<<" ";

	cout<<endl;
}
