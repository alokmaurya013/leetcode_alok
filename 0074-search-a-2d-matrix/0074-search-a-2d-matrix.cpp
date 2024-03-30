class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=m-1,row;
        if(target<matrix[0][0]||target>matrix[m-1][n-1]){
            return false;
        }
        if(target<=matrix[0][n-1]){
            row=0;
        }else{
            while(low<high){
               int mid=(low+high)/2;
               if(target==matrix[mid][n-1]){
                   return true;
               }else if(target>matrix[mid][n-1]&&target<=matrix[mid+1][n-1]){
                   row=mid+1;
                   break;
               } else if(target<matrix[mid][n-1]&&target>matrix[mid-1][n-1]){
                  row=mid;
                   break;
               }else if(target>matrix[mid][n-1]){
                   low=mid+1;
               }else if(target<matrix[mid][n-1]){
                   high=mid;
               }
            }
        }
            low=0;
            high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(target==matrix[row][mid]){
                    return true;
                }else if(target>matrix[row][mid]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            return false;
    }
};