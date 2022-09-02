class Solution {
public:
    int countVowelPermutation(int n) {
        int arr[] = {1,1,1,1,1};
        int i=0, sum=0;
        while(--n) {
            int newArr[] = {0, 0, 0, 0, 0};
            for(i = 0;i<5;++i){
                sum = arr[i];
                if(i==0){
                    newArr[i+1]=(newArr[i+1]+sum)%1000000007;
                }else if(i==1) {
                    newArr[i-1]=(newArr[i-1]+sum)%1000000007;
                    newArr[i+1]=(newArr[i+1]+sum)%1000000007;
                }else if(i==2) {
                    newArr[i-2]=(newArr[i-2]+sum)%1000000007;
                    newArr[i-1]=(newArr[i-1]+sum)%1000000007;
                    newArr[i+1]=(newArr[i+1]+sum)%1000000007;
                    newArr[i+2]=(newArr[i+2]+sum)%1000000007;
                }else if(i==3) {
                    newArr[i-1]=(newArr[i-1]+sum)%1000000007;
                    newArr[i+1]=(newArr[i+1]+sum)%1000000007;
                }else if(i==4) {
                    newArr[i-4]=(newArr[i-4]+sum)%1000000007;
                }
            }
            for(i=0;i<5;++i)arr[i] = newArr[i];
        }
        sum=0;
        for(i=0;i<5;++i){
            sum = (sum + arr[i])%1000000007;
        }
        return sum;
    }
};