class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int arr[]=new int[26];
        for(char i:allowed.toCharArray()){
            arr[i-'a']=1;
        }
        int c=0;
        int n=words.length;
        
        for(String s:words){
            int flag=1;
            for(int i=0;i<s.length();i++){
                if(arr[s.charAt(i)-'a']==0){
                    flag=0;
                    break;
                }
            }
            c+=flag;
        }
        return c;
    }
}