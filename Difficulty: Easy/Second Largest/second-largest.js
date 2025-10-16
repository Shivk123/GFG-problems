class Solution {
    getSecondLargest(arr) {
        // code here
        let max = -Infinity;
        let secondMax = -Infinity;
        
        for (let num of arr) {
            if (num > max) {
                secondMax = max;
                max = num;
            } else if (num > secondMax && num < max) {
                secondMax = num;
            }
        }
        
        if (secondMax === -Infinity) {
            return -1;
        } else {
            return secondMax;
        }
    }
}