class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;

        for (int i = 1; i <= n; ++i) {
            // Check divisibility by both 3 and 5 first (or simply 15)
            if (i % 3 == 0 && i % 5 == 0) {
                answer.push_back("FizzBuzz");
            }
            // Check divisibility by 3
            else if (i % 3 == 0) {
                answer.push_back("Fizz");
            }
            // Check divisibility by 5
            else if (i % 5 == 0) {
                answer.push_back("Buzz");
            }
            // Otherwise, convert the number to string
            else {
                answer.push_back(to_string(i));
            }
        }

        return answer;
    }
};