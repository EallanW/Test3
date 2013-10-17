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
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(num.begin(), num.end());
        
        int res = num[0]+num[1]+num[2];//Don't minus target!
        
        int n = num.size();
        for (int i = 0;i<n-2;i++){
            int st = i+1, en = n-1;
            while(st<en){
                int tmp = num[i]+num[st]+num[en];
                if(abs(res-target) > abs(tmp-target)){
                    res = tmp;
                }
                
                if(tmp<=target){
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

