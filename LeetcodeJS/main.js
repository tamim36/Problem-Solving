
// 2723
var addTwoPromises = async function(promise1, promise2) {
    let ans = 0;
    await promise1
        .then((val1) => promise2.then((val2) => {
            ans = val1 + val2;
            return ans;
        }))
    return ans
};

// 2621
async function sleep2(millis) {
    return new Promise((resolve) => setTimeout(() => resolve(), millis))
}

// Using async/await
async function exampleAsync() {
    console.log('Start');
    await sleep(3000);
    console.log('End');
 }
 
 // Using plain promises
 function examplePromise() {
    console.log('Start');
    sleep(3000).then(function() {
        console.log('End');
    });
 }
 
 // Helper function used by both exampleAsync and examplePromise
 function sleep(millis) {
    return new Promise(function(resolve) {
        resolve()
    });
 }

 // 2715
 var cancellable = function(fn, args, t) {
    this.cancelTimeoutId = setTimeout(() => {
        fn(...args)
    }, t);
    
    const cancelTimeout = () => {
        //console.log("it is called: " + this.cancelTimeoutId)
        clearTimeout(this.cancelTimeoutId)
    }
    return cancelTimeout
 };

 // 2725
 var cancellable = function(fn, args, t) {
    fn(...args)
    timeoutId = setInterval(fn, t, ...args);

    const cancelInterval = () => {
        clearInterval(timeoutId)
    }

    return cancelInterval
 };

// 2637
var timeLimit = function(fn, t) {
   
   return async function(...args) {
       return new Promise((resolve, reject) => {
        const timeoutId = setTimeout(() => {
            clearTimeout(timeoutId)
            reject('Time Limit Exceeded')
        }, t);

        fn(...args)
            .then((result) => {
                clearTimeout(timeoutId)
                resolve(result)
            })
            .catch((e) => {
                clearTimeout(timeoutId)
                reject(e)
            })
       })
   }
};

//#region 2622
var TimeLimitedCache = function() {
    this.cacheMap = new Map()
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    let retVal = false
    if (this.cacheMap.has(key)){
        retVal = true;
        clearTimeout(this.cacheMap.get(key).timeoutId)
    }
    const timeoutId = setTimeout(() => {
        this.cacheMap.delete(key)
        clearTimeout(timeoutId)
    }, duration);

    this.cacheMap.set(key, {"val": value, "timeoutId": timeoutId})
    return retVal
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cacheMap.has(key))
        return this.cacheMap.get(key).val
    else 
        return -1
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.cacheMap.size;
};
//#endregion

// 2627
var debounce = function(fn, t) {
    let timeoutId;
    return function(...args) {
        if (timeoutId)
            clearTimeout(timeoutId)

        timeoutId = setTimeout(() => {
            fn(...args)
        }, t);
    }
};

// 2721
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        let results = new Array(functions.length)
        let count = 0
        functions.forEach((fn, i) => {
            fn()
                .then(val => {
                    results[i] = val
                    count++
                    if (count == functions.length) resolve(results)
                })
                .catch(err => reject(err))
        })
    })
}

var isEmpty = function(obj) {
    if (Object.keys(obj).length || obj.length)
        return false;
    else 
        return true;
};

// 2677
var chunk = function(arr, size) {
    let results = []
    let count = 0
    let chunk = []

    arr.forEach((elem) => {
        chunk.push(elem)
        count++;

        if (count === size){
            count = 0
            results.push(chunk)
            chunk = []
        }
    })

    if (chunk.length)
        results.push(chunk)
    return results
};

// 2619
Array.prototype.last = function() {
    if (this.length === 0)
        return -1
    else 
        return this[this.length - 1]
};

// 2631
Array.prototype.groupBy = function(fn) {
    let results = {}

    this.forEach((elem) => {
        let key = fn(elem)
        if (!results[key])
            results[key] = [elem]
        else
            results[key].push(elem)
    })
    return results
};

// 2724
var sortBy = function(arr, fn) {
    arr.sort(function(a, b) {
        return fn(a) - fn(b)
    })

    return arr
};

// 2722
var join = function(arr1, arr2) {
    let results = []
    arr1 = sortBy(arr1, (obj) => obj.id)
    arr2 = sortBy(arr2, (obj) => obj.id)
    let i = 0, j = 0;
    while ( i < arr1.length && j < arr2.length ){
        if (arr1[i].id < arr2[j].id)
            results.push(arr1[i++])
        else if (arr1[i].id === arr2[j].id){
            results.push({...arr1, ...arr2})
            i++
            j++
        }
        else
            results.push(arr2[j++])
    }

    while(i < arr1.length)
        results.push(arr1[i++])

    while(j < arr2.length)
        results.push(arr2[j++])

    return results
};

// 2625
var flat = function (arr, n) {
    let results = []

  const recursiveTraverse = (arr, depth) => {
    arr.forEach((elem) => {
        if (Array.isArray(elem) && depth + 1 <= n){
            recursiveTraverse(elem, depth + 1)
        }

        results.push(elem)
    })
  }
  
  recursiveTraverse(results, 0)
  return results
};

// 2705
var compactObject = function(obj) {
  const isArray = (x) => {
    return Array.isArray(x)
  }

  const isObject = (x) => {
    return typeof x === 'object' && !Array.isArray(x) && x !== null
  }

  const recurObj = (ob) => {
    let res = {}
    for (const[k, v] of Object.entries(ob)){
        if (isArray(v))
            res[k] = recurArr(v)
        else if (isObject(v))
            res[k] = recurObj(v)
        else if (v)
            res[k] = v
    }
    return res
  }
  
  const recurArr = (arr) => {
    let res = []
    arr.forEach((elem) => {
        if (isObject(elem))
            res.push(recurObj(elem))
        else if (isArray(elem))
            res.push(recurArr(elem))
        else if (elem)
            res.push(elem)
    })
    return res
  }

  if (isArray(obj))
    return recurArr(obj)
  else 
    return recurArr(obj)
};

class EventEmitter {
    
    constructor(){
        this.map = new Map();
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {
        let arr  = this.map.get(eventName)
        if (arr)
            arr.push(callback)
        else
            arr = [callback]

        this.map.set(eventName, arr)
        return {
            unsubscribe: () => {
                if (this.map.get(eventName).length == 0)
                    this.map.delete(eventName)
                else
                    this.map.set(eventName, this.map.get(eventName).filter(item => item !== callback))
            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        let results = []
        if (!this.map.has(eventName))
            return results

        this.map.get(eventName).forEach((fn) => {
            if (args.length)
                results.push(fn(...args))
            else
                results.push(fn())
        })
        return results
    }
}

// 2695
var ArrayWrapper = function(nums) {
    this.arr = nums
};

/**
 * @return {number}
 */
ArrayWrapper.prototype.valueOf = function() {
    return this.arr.reduce((acc, cur) => {
        return acc + cur
    }, 0)
}

/**
 * @return {string}
 */
ArrayWrapper.prototype.toString = function() {
    return JSON.stringify(this.arr)
}

// 2726
class Calculator {
    
    /** 
     * @param {number} value
     */
    constructor(value) {
        this.val1 = value
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.val1 += value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.val1 -= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.val1 *= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
        if (value === 0)
            throw(new Error("Division by zero is not allowed"))
        this.val1 /= value
        return this
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.val1 = Math.pow(this.val1, value)
        return this
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.val1
    }
}

//#region Main
// -----------------------------------------------------------
const emitter = new EventEmitter();
emitter.emit("firstEvent"); // [], no callback are subscribed yet
emitter.subscribe("firstEvent", function cb1() { return 5; });
emitter.subscribe("firstEvent", function cb2() { return 6; });
console.log(emitter.emit("firstEvent")); // [5, 6], returns the output of cb1 and cb2

   
//#endregion



/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

// 2624
function memoize(fn) {
    let cache = []
    return function(...args) {
        if (cache[args] != undefined)
            return cache[args];
        
        let val = fn(...args);
        cache[args] = val;
        return cache[args]
    }
}




//#region Archive
// 2666     // How bind works
class Once {
    hasBeenCalled = false;
    result;
  
    call(fn, ...args) {
      if (!this.hasBeenCalled) {
        this.result = fn(...args);
        this.hasBeenCalled = true;
        return this.result;
      } else {
        return undefined;
      }
    }
  }
  
  function once(fn) {
    const instance = new Once();
    return instance.call.bind(instance, fn);
  }
  

var once = function(fn) {
    var privateFn = fn;
    return function(...args){
        if (privateFn){
            var res = privateFn(...args);
            privateFn = undefined;
            return res;
        }
        else {
            return undefined;
        }
    }
};


// 2629 // important
var compose = function(functions) {
    return function(inp) {
        return functions.reduceRight((acc, func) => {
            acc = func(acc)
            return acc
        }, inp);
    }
};

var compose2 = function(functions) {
  return functions.reduceRight(function(prevFn, nextFn) {
    return function(x) {
      return nextFn(prevFn(x));
    };
  },  function(x) { return x; });

};

// 2634
var reduce = function(nums, fn, init) {
    var val = init
  nums.forEach(element => {
    val = fn(val, element)
  });
  return val;  
};



var filter = function(arr, fn) {
    return arr.reduce((newArr, x, i) => {
        if (fn(x, i)){
            newArr.push(x)
        }
        return newArr
    }, []);
  };

var filter = function(arr, fn) {
  var res = []
  for (let i = 0; i < arr.length; i++){
    if (fn(arr[i], i))
        res.push(arr[i]);
  }  
  return res;
};


// 2635


var map = function(arr, fn) {
    var res = []
    for (let i = 0; i < arr.length; i++){
        res.push(fn(arr[i], i))
    } 
    return res
};

// 2665
var createCounter = function(init) {
    let curVal = init;

    return {
        increment: () => {
            return ++curVal;
        },
        decrement: () => {
            return --curVal;
        },
        reset: () => {
            curVal = init;
            return curVal;
        }
    }
    
};

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

//#endregion

