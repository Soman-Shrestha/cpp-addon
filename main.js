const calculate = require('./build/Release/calculate');
console.time('c++')
calculate.calc();
console.timeEnd('c++')