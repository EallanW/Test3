#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <ctime>

using namespace std;

#define maxn 110
#define datat int
#define ansdatat int

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        int n = num.size();
        vector<vector<int> > res;
        vector<int> item(4);
        set<vector<int> > hash;
        
        for (int i = 0;i<n-3;i++)
        for (int j = i+1;j<n-2;j++){
            int left = j+1, right = n-1;
            while(left<right){
                int tmp = num[i]+num[j]+num[left]+num[right];
                if(tmp == target){
                    item[0] = num[i];
                    item[1] = num[j];
                    item[2] = num[left];
                    item[3] = num[right];
                    if(hash.find(item) == hash.end()){
                        hash.insert(item);
                        res.push_back(item);
                    }
                    left++;
                }
                else if(tmp > target){//It's >, not < !!!
                    right--;
                }
                else{
                    left++;
                }
                    
            }
                
            
        }
        
        return res;
        
    }
};


void init_deal(){
}

int main(){
	
//	freopen(".in", "r", stdin);

	

	return 0;
};

