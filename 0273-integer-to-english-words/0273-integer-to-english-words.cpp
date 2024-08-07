class Solution {
public:
    string unit[20]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    string tens[10]{"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        if(num<20){
            return unit[num];
        } 
        if(num<100){
            return tens[num/10]+((num%10!=0)?" "+numberToWords(num%10):"");
        }
        if(num<1000){
             return unit[num/100]+" Hundred"+((num%100!=0)?" "+numberToWords(num%100):"");
        }
        if(num<1000000){
            return numberToWords(num/1000)+" Thousand"+((num%1000!=0)?" "+numberToWords(num%1000):"");
        }
        if(num<1000000000){
              return numberToWords(num/1000000)+" Million"+((num%1000000!=0)?" "+numberToWords(num%1000000):"");
        }
           return numberToWords(num/1000000000)+" Billion"+((num%1000000000!=0)?" "+numberToWords(num%1000000000):"");
    }
};