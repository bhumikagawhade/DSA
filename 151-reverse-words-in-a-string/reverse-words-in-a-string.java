class Solution {
    public String reverseWords(String s) {
        int i=s.length()-1;
        StringBuilder st = new StringBuilder();

        while(i>=0){
            while(i>=0 && s.charAt(i)==' '){
                i--;
            }
            int j=i;
            while(j>=0 && s.charAt(j)!= ' '){
                j--;
            }

            st.append(s.substring(j+1,i+1));

            while(j>=0 && s.charAt(j) ==' '){
                j--;
            }
            if(j>=0) st.append(" ");

            i=j;

        }

        return new String(st);


    }
}