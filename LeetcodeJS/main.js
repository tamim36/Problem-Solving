
// 77
var combine = function(n, k) {
    let ans = []

    function recur_combine(cur, sofar){
        if (sofar.length == k){
            ans.push([...sofar])
            return
        }

        for (let i = cur; i <= n; i++){
            sofar.push(i)
            recur_combine(i+1, sofar)
            sofar.pop()
        }
    }

    recur_combine(1, [])
    return ans
};

// 2704
var expect = function(val) {
    return {
        toBe : (anotherVal) => {
            if (val === anotherVal){
                return true
            }
            throw new Error('Not Equal')
        },
    
        notToBe : (anotherVal) => {
            if (val !== anotherVal){
                return true
            }
            throw new Error('Equal')
        }
    }
};

// 47
var permuteUnique = function(nums) {
    let data = []
    function _permute(curr, remaining){
        if (!remaining.length){
            data.push([...curr])
            return
        }

        let uniques = new Set()
        for (let i = 0; i < remaining.length; i++){
            if (uniques.has(remaining[i])){
                continue
            }
            else {
                uniques.add(remaining[i])
                curr.push(remaining[i])
                _permute(curr, [...remaining.slice(0, i), ...remaining.slice(i+1)])
                curr.pop()
            }
        }
    }

    _permute([], nums)
    return data
};

// 2620
var createCounter = function(n) {
    return function() {
        return n++
    };
};

// 2667
var createHelloWorld = () => {
    return () => {
        return 'Hello World'
    }
}

// 2389
var answerQueries = function(nums, queries) {
    nums.sort((a, b) => a - b);

    const prefixSum = [nums[0]];
    for (let i = 1; i < nums.length; i++){
        prefixSum.push(prefixSum[i - 1] + nums[i]);
    }

    const binarySearch = (arr, left, right, val) => {
        if (right >= left){
            let mid = left + Math.floor((right - left) / 2);

            if (arr[mid] == val){
                return mid;
            } 
            else if (val < arr[mid]){
                return binarySearch(arr, left, mid - 1, val);
            }
            else {
                return binarySearch(arr, mid+1, right, val);
            }
        }
        else {
            return right;
        }
    }

    const answer = [];
    for (let j = 0; j < queries.length; j++){
        answer.push(binarySearch(prefixSum, 0, prefixSum.length - 1, queries[j]) + 1);
    }

    return answer;
};

// 1658
var minOperations = function(nums, x) {
    let target = -x;
    target = nums.reduce((tot, cur) => tot+cur, target);
    if (target == 0) return nums.length;
    if (target < 0) return -1;

    let map = new Map();
    map.set(0, -1);
    let sum = 0, res = Number.MIN_SAFE_INTEGER;
    
    for (let i = 0; i < nums.length; i++){
        sum += nums[i];
        if (map.has(sum - target)){
            res = Math.max(res, i - map.get(sum - target));
        }

        map.set(sum, i);
    }

    return res === Number.MIN_SAFE_INTEGER ? -1 : nums.length - res;
};

// 417
var pacificAtlantic = function(heights) {
    const m = heights.length, n = heights[0].length;
    const ans = [];
    const pacific = new Array(m).fill(null).map(() => new Array(n).fill(false));
    const atlantic = new Array(m).fill(null).map(() => new Array(n).fill(false));
    const dir = [[0,1], [0, -1], [1,0], [-1, 0]];

    function dfs_PacificAtlantic(heights, visited, x, y){
        if (visited[x][y]) return;
        visited[x][y] = true;

        for (let i = 0; i < 4; i++){
            const xx = x + dir[i][0];
            const yy = y + dir[i][1];

            if (xx >= 0 && xx < m && yy >= 0 && yy < n 
                && heights[x][y] <= heights[xx][yy] && !visited[xx][yy])
                dfs_PacificAtlantic(heights, visited, xx, yy);
        }
    }

    for (let i = 0; i < m; i++){
        dfs_PacificAtlantic(heights, pacific, i, 0);
        dfs_PacificAtlantic(heights, atlantic, i, n-1);
    }
    for (let i = 0; i < n; i++){
        dfs_PacificAtlantic(heights, pacific, 0, i);
        dfs_PacificAtlantic(heights, atlantic, m-1, i);
    }

    for (let i = 0; i < m; i++){
        for (let j = 0; j < n; j++){
            if (pacific[i][j] && atlantic[i][j]){
                ans.push([i, j]);
            }
        }
    }

    return ans;
};


class Adder {
    constructor(a){
        this.aVal = a 
    }

    add(b) {
        const sum = this.aVal + b
        return sum
    }
}

// Reigion Main


const addto2 = new Adder(2)
addto2.aVal = 3
console.log(addto2.add(5))

// endregion