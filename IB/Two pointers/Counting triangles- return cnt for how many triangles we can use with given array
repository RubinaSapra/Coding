int Solution::nTriang(vector<int> &A) {
     int n=A.size(),ans=0,m=1e9+7;
    sort(A.begin(),A.end());
    for(int i=0;i<n-2;i++){
        if(A[i]==0) continue;
        for(int j=i+1;j<n-1;j++)
            ans=(ans+((lower_bound(A.begin(),A.end(),A[i]+A[j]))-(A.begin()+j+1)))%m;
    }
    return ans;
}
