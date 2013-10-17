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

struct IndPair{
    int i1, i2;
};

struct Node{
    IndPair p;
    Node* next;
};

class Solution {
public:
    map<int, Node*> hash;
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        vector<vector<int> > res;
        set<vector<int> > hash_res;
        
        sort(num.begin(), num.end());
        hash.clear();
        
        vector<Node*> v_node;
        
        int n = num.size();

        for (int i = 0;i<n-1;i++)
        for (int j = i+1;j<n;j++){
            IndPair p;
            p.i1 = i;
            p.i2 = j;
            Node* new_node = new Node;
            new_node->p = p;
            new_node->next = hash[num[i]+num[j]];
            hash[num[i]+num[j]] = new_node;
            v_node.push_back(new_node);
        }
        
        for (int i = 0;i<v_node.size();i++){
            int left = target-(num[v_node[i]->p.i1]+num[v_node[i]->p.i2]);
            Node* now = hash[left];
            vector<int> item(4);
            while(now!=NULL){
				//cout<<now->p.i1<<" "<<now->p.i2<<endl;
                item[0] = v_node[i]->p.i1;
                item[1] = v_node[i]->p.i2;
                item[2] = now->p.i1;
                item[3] = now->p.i2;
                
                sort(item.begin(), item.end());
				//for(int j = 0;j<4;j++)cout<<item[j]<<" ";cout<<endl;
                if(item[0] != item[1] && item[1] != item[2] && item[2] != item[3]){
                    vector<int> ans_item(4);
                    for (int j = 0;j<4;j++){
                        ans_item[j] = num[item[j]];
                    }
                    sort(ans_item.begin(), ans_item.end());
                    if(hash_res.find(ans_item) == hash_res.end()){
                        hash_res.insert(ans_item);
                        res.push_back(ans_item);
                    }
                }
                
                now = now->next;
            }
        }

        return res;
        
    }
};


void init_deal(){
}

int main(){
	
//	freopen(".in", "r", stdin);

	int a[] = {0,0,0,0};	
	vector<int> v;
	for (int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
	{
		v.push_back(a[i]);
		//cout<<v[i]<<endl;
	}

	Solution sol;
	vector<vector<int> > ans = sol.fourSum(v,0);
	cout<<ans.size()<<endl;

	return 0;
};

