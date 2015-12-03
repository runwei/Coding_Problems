#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
	ifstream fin;
	fin.open ("input.txt");
    fin>>T;
    while (T--){
        int N;
        fin>>N;
        vector<string> vec(N,"");
        for (int i=0;i<N;i++) {
            fin>>vec[i];
            sort(vec[i].begin(),vec[i].end());
			cout<<vec[i]<<endl;
        }
        for (int i=0;i<N-1;i++)
            for (int j=0;j<N;j++) 
            if (vec[i][j]>vec[i+1][j]) {cout<<"NO";return 0;}
        
        cout<<"YES";
            
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}




import java.io.*;
public class Solution {
    public static void main(String args[] ) throws Exception {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        Scanner sc = new Scanner(System.in);
        int N=sc.nextInt();
        int K=sc.nextInt();
        int arr[]=new int[N];
        Hashtable table=new Hashtable();
        for (int i=0;i<N;i++) {
            arr[i]=sc.nextInt();
            table.put(arr[i],map.get(arr[i]) + 1);
        }
        int totalnum=0;
        Set<int> keys = table.keySet();
        for(int key: keys){
            totalnum+=table.get(key+K)*table.get(key);
        }
        cout<<totalnum;
    }
}


select dept.deptId,
   deptName,
   count(emp.empid) as numb_of_emps
   from department dept inner join employee emp
   on dept.deptid = emp.deptid
   group by dept.deptid

// int main() {
//     int m,n;
// 	ifstream fin;
// 	  fin.open ("input.txt");
//     fin>>n>>m;
//     vector<vector<int> > neighbor(n, vector<int>());
//     while (m--){
//         int left,right;
//         fin>>left>>right;
//         neighbor[left-1].push_back(right-1);
//         neighbor[right-1].push_back(left-1);
//     }
//     unordered_map<int,bool> m_map;
//     for (int i=0;i<n;++i) m_map[i]=true;
//     int num2remove=0;
//     dfs(1,neighbor,num2remove,m_map);
//     cout<<num2remove;
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }