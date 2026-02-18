class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int temp;
        temp = n >> 1;
        temp = temp ^ n;
        unsigned int result = temp + 1;
        return (temp & result) == 0;
    }
};