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
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<vector<int> > hash;
        
        sort(num.begin(), num.end());
        
        vector<int> res_item(3);
        
        vector<vector<int> > res(0);
        
        
        int n = num.size();
        for (int i = 0;i<n-2;i++){
            int st = i+1, en = n-1;
            while(st<en){
                int tmp = num[i]+num[st]+num[en];
                if(tmp == 0){
                    res_item[0] = num[i];
                    res_item[1] = num[st];
                    res_item[2] = num[en];
                    
                    if(hash.find(res_item) == hash.end()){
                        res.push_back(res_item);
                        hash.insert(res_item);
                    }
                    
                    st++;
                }
                else if(tmp < 0){
                    st++;
                }
                else{
                    en--;
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

