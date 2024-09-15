import java.util.HashMap;
class Solution {
    public int findTheLongestSubstring(String s) {
         int n=s.length();
        HashMap<Integer,Integer>mp=new HashMap<>();
        int mask=0,mx=0;
        mp.put(0,-1);
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            if(ch=='a'){
                mask^=(1<<0);
            }else if(ch=='e'){
                mask^=(1<<1);
            }else if(ch=='i'){
                mask^=(1<<2);
            }else if(ch=='o'){
                mask^=(1<<3);
            }else if(ch=='u'){
                mask^=(1<<4);
            }
            if(mp.containsKey(mask)){
                mx=Math.max(mx,i-mp.get(mask));
            }else{
                mp.put(mask,i);
            }
        }
        return mx;
    }
}