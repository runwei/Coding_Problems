
void knuthshuffle(vector<int> &arr) {
	int n=arr.size();
	for (int k=n-1;k>=0;--k){
		swap(arr[k],arr[rand()%(k+1)]);
	}
}	