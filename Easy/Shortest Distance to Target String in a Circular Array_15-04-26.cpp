/**
 * @param {string[]} words
 * @param {string} target
 * @param {number} startIndex
 * @return {number}
 */
var closestTarget = function(words, target, startIndex) {
    let n = words.length;
    let minDistance = Infinity;

    for (let i = 0; i < n; i++) {
        if (words[i] === target) {
            let diff = Math.abs(i - startIndex);

            let currentBest = Math.min(diff, n - diff);
            
            minDistance = Math.min(minDistance, currentBest);
        }
    }

    return minDistance === Infinity ? -1 : minDistance;
};