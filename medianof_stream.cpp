#include<iostream>
#include<vector>
using namespace std;

    
    vector<int> stream;
    
    int find_pos(vector<int> &arr,int start,int end,int target){
        int mid;
        while(start <= end){
            mid = (start+end)/2;
            if(arr[mid] == target)
                return mid;
            else if(arr[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        if(arr[mid] > target)
            return mid;
        else
            return mid+1;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if(stream.empty())
            stream.push_back(num);
        else{
            int len = stream.size();
            int val = find_pos(stream,0,len-1,num);
            stream.insert(stream.begin()+val,num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int len = stream.size();
        if(len%2 == 1)
            return  stream[len/2];
        else{
		//cout<<stream[len/2-1]<<" "<<stream[len/2]<<endl;
            return (double)(stream[len/2-1]+stream[len/2])/2;
        }
    }

    void printstream(){
	int len = stream.size();
	for(int i=0;i<len;i++)
		cout<<stream[i]<<" ";
	cout<<endl;
    }

int main(){
	addNum(2);
	cout<<findMedian()<<endl;
	addNum(3);
	printstream();
	cout<<findMedian()<<endl;
}


