/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    let n=functions.length;
    if(n==0){
        return function(x) {
        return x;
      }
    }
    return function(x) {
        let res=functions[n-1](x);
        for(let i=n-2;i>=0;i--){
            res=functions[i](res);
        }
        return res;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */