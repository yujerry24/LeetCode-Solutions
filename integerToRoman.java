class Solution {
    public String intToRoman(int num) {
        int thousands = num/1000;
        int hundreds = (num/100)%10;
        int tens = (num/10)%10;
        int ones = num%10;
        
        String returnValue="";
        for(int i=1; i<=thousands; i++) {
            returnValue+="M";
        }
        
        switch(hundreds) {
            case 1: returnValue+="C";
                break;
            case 2: returnValue+=("CC");
                break;
            case 3: returnValue+=("CCC");
                break;
            case 4: returnValue+=("CD");
                break;
            case 5: returnValue+=("D");
                break;
            case 6: returnValue+=("DC");
                break;
            case 7:returnValue+=("DCC");
                break;
            case 8: returnValue+=("DCCC");
                break;
            case 9: returnValue+=("CM");
                break;
        }
        
          switch(tens) {
            case 1: returnValue+=("X");
                break;
            case 2:  returnValue+=("XX");
                break;
            case 3:  returnValue+=("XXX");
                break;
            case 4:  returnValue+=("XL");
                break;
            case 5:  returnValue+=("L");
                break;
            case 6:  returnValue+=("LX");
                break;
            case 7:  returnValue+=("LXX");
                break;
            case 8:  returnValue+=("LXXX");
                break;
            case 9: returnValue+=("XC");
                break;
        }
        
          switch(ones) {
            case 1:  returnValue+=("I");
                break;
            case 2:  returnValue+=("II");
                break;
            case 3: returnValue+=("III");
                break;
            case 4:  returnValue+=("IV");
                break;
            case 5:  returnValue+=("V");
                break;
            case 6:  returnValue+=("VI");
                break;
            case 7: returnValue+=("VII");
                break;
            case 8:  returnValue+=("VIII");
                break;
            case 9:  returnValue+=("IX");
                break;
        }
        
        return returnValue;
        
    }
}