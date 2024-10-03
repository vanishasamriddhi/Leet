class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.length();

        // Map Roman numeral characters to their integer values
        for (int i = 0; i < n; i++) {
            // Check the current and next Roman numerals to handle subtraction cases
            if (i < n - 1 && romanValue(s[i]) < romanValue(s[i + 1])) {
                // If the current numeral is smaller than the next one, subtract it
                sum -= romanValue(s[i]);
            } else {
                // Otherwise, add it
                sum += romanValue(s[i]);
            }
        }
        
        return sum;
    }

private:
    // Helper function to map Roman numerals to integer values
    int romanValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};
