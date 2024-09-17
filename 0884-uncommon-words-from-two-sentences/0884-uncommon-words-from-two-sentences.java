class Solution {
     
    void stringMap(String[] word,HashMap<String,Integer>mp){
       for(String w:word){
           mp.put(w,mp.getOrDefault(w,0)+1);
       }
    }
    public String[] uncommonFromSentences(String s1, String s2) {
         ArrayList<String>res=new ArrayList<>();
        String[] word1=s1.split(" ");
        String[] word2=s2.split(" ");
         HashMap<String,Integer>mp=new HashMap<>();
       stringMap(word1,mp);
        stringMap(word2,mp);
        for(String s:mp.keySet()){
            if(mp.get(s)==1){
               res.add(s); 
            }
        }
        return res.toArray(new String[res.size()]);
    }
}