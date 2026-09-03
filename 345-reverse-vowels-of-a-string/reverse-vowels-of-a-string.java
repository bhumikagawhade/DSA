class Solution {
    public String reverseVowels(String s) {
        char arr[] = s.toCharArray();
        String vowels = "aeiouAEIOU";
        int i=0;
        int j=arr.length-1;
        while(i<=j){
            while(i<=j && vowels.indexOf(arr[i])==-1){
                i++;
            }
            while(j>=i && vowels.indexOf(arr[j])==-1){
                j--;
            }

            if(i<=j){

            
            char temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;

            i++;
            j--;
            }

        }

        return new String(arr);
    }
}