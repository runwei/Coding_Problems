#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int> > threesum(vector<int> &nums, int target) {
	sort(nums.begin(),nums.end());
	vector<int> m_vec;
	vector<vector<int> > m_ret;
	for (int first=0;first<nums.size()-2;first++) {
		if (first!=0 && nums[first]==nums[first-1])  continue;
		int middle=first+1,last=nums.size()-1;
		while (middle<last) {
			if (middle!=first+1 && nums[middle]==nums[middle-1]) ++middle;
			else if (last!=nums.size()-1 && nums[last]==nums[last+1]) --last;
			else if (nums[first]+nums[middle]+nums[last]==target) {
				m_vec.clear();
				m_vec.push_back(nums[first]);
				m_vec.push_back(nums[middle]);
				m_vec.push_back(nums[last]);
				m_ret.push_back(m_vec);
				break;
			} else if (nums[first]+nums[middle]+nums[last]<target) ++middle;
			else --last;
		}
	}
	return m_ret;
}


int main() {
	int A[]={3,3,4,2,1,4,5,3,2,3,42};
	vector<int> m_num(A,A+sizeof(A)/sizeof(int));
	vector<vector<int> > m_ret=threesum(m_num,9);
	for (int i=0;i<m_ret.size();i++) 
		for (auto& j:m_ret[i]) cout<<j<<" ";
	return 0;
}