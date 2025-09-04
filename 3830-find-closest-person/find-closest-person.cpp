class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)<=abs(y-z)?abs(x-z)<abs(y-z):2;
    }
};