class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
         for (char c : s) {
            int val = c - 'a' + 1; // Convert character to its position in the alphabet (1-26)
            while (val > 0) {
                sum += val % 10; // Add each digit
                val /= 10;       // Process next digit
            }
        }
        while(k-->1){
           int currentSum = 0;
            while (sum != 0) {
                currentSum += sum % 10; 
                sum /= 10; 
            }
            sum = currentSum;
        
        }
        return sum;
    }
};
