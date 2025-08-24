const os = require('os');

console.log(`CPU Architecture: ${os.arch()}`);
console.log(`CPU Count:`, os.cpus().length);
console.log(`(List threadpool size:`, os.cpus());
console.log(`Free Memory: ${os.freemem() / 1024 / 1024} MB`);
