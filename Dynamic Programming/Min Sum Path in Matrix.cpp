int Solution::minPathSum(vector<vector<int> > &A) {
    int n=A.size();             // rows
    int m=A[0].size();          // columns

    if(n==0)
    return 0;

    vector<vector<int>> ans(n,vector<int> (m,0));  // DP 2-D array 

    ans[0][0]=A[0][0];  
    for(int i=1 ; i<m ; i++){
        ans[0][i]=ans[0][i-1]+A[0][i];      // Filling the values for first row values as no other possible path

    for(int j=1; j<n ; j++){
        ans[j][0]=ans[j-1][0]+A[j][0];      // Filling the values for first column values as no other possible path
    }
    
    for(int i=1; i<n ; i++){
        for(int j=1 ; j<m ; j++){
            ans[i][j]= A[i][j]+min(ans[i-1][j],ans[i][j-1]);   // Adding the minimum possible value from both the possible paths
        }
    }

    // for(int i=0 ; i<n ; i++){
    //     for(int j=0 ; j<m ; j++){
    //       cout << ans[i][j]<< " ";    // Helps in debugging
    //     }
    //     cout <<endl;
    // }

    return ans[n-1][m-1];
}
