class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Integer> st = new Stack<>();
         if(k >= num.length()){
            return "0";
        }

        for(char ch : num.toCharArray()){
            int n= ch-'0';
            System.out.println(n);
            while(!st.isEmpty() && k>0 && st.peek() > n  ){
                st.pop();
                k--;
            }
            st.push(n);
        }
        while(k>0 && !st.isEmpty()){
            st.pop();
            k--;
        }

        StringBuilder res = new StringBuilder();

        while(!st.isEmpty()){
            res.append((char)(st.peek()+'0'));
            st.pop();
        }
        while(res.length()!=0 && res.charAt(res.length()-1) == '0'){
            res.deleteCharAt(res.length()-1);
        }
        res.reverse();

        if(res.length() == 0) return "0";
        return res.toString();
    }
}