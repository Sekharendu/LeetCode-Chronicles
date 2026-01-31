# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code

/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    let letterToAscii=[];
    for(let letter of letters){
        letterToAscii.push(letter.charCodeAt(0));
    }
    let targetToAscii=target.charCodeAt(0);
    const result = letters.find(letter => letter > target);
    return result ?? letters[0];
    return letters[0];
};
```