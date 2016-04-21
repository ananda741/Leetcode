#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

    int partition(vector<Interval> &arr,int begin,int finish){
        int pindex = begin,i;
        int pivot = arr[finish].start;
        
        for(i=begin;i<finish;i++){
            if(arr[i].start<pivot){
                swap(arr[i].start,arr[pindex].start);
                swap(arr[i].end,arr[pindex].end);
                pindex++;
            }
        }
        swap(arr[finish].start,arr[pindex].start);
        swap(arr[finish].end,arr[pindex].end);
        return pindex;
    }

    
    void Quick_sort(vector<Interval> &arr,int begin,int finish){
        if(begin>=finish)
            return;
            
        int index = partition(arr,begin,finish);
        
        Quick_sort(arr,begin,index-1);
        Quick_sort(arr,index+1,finish);
    }
    

    vector<Interval> merge(vector<Interval>& intervals) {
        int i,len = intervals.size();
        if(len == 0)
            return intervals;
        Quick_sort(intervals,0,len-1);
        
	for(i=0;i<len;i++){
		cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<",";	
	}
	cout<<endl;
        vector<Interval> res;
        
        res.push_back(intervals[0]);
        
        for(i=1;i<len;i++){
            if(intervals[i].start > res.back().end)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end , intervals[i].end);
        }
        
        return res;
    }


int main(){
	vector<Interval> intervals;
	Interval maser(1,4);
	intervals.push_back(maser);
	Interval laser(2,5);
	intervals.push_back(laser);
	/*Interval razor(8,10);
	intervals.push_back(razor);          
	Interval phaser(15,18);
	intervals.push_back(phaser);                           */
	
	intervals = merge(intervals);

	int i,len = intervals.size();

	for(i=0;i<len;i++){
		cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<",";	
	}
	cout<<endl;
}

