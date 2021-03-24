const addon = require('./build/Release/addon');

console.log("Output from encrypt.cc: ",addon.encrypt(2,3,4))
console.log("Output from decrypt.cc: ",addon.decrypt(2,4))
