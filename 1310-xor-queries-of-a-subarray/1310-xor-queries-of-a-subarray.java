class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
       int n=arr.length;
        int[] pre=new int[n];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i]^pre[i-1];
        }
        int k=queries.length;
        int[] ans=new int[k];
        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==0){
                ans[i]=pre[r];
            }else{
                ans[i]=pre[r]^pre[l-1];
            }
        }
        return ans;
    }
}