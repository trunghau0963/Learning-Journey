// Set thread pool size before anything else
const os = require('os');
process.env.UV_THREADPOOL_SIZE = os.cpus().length; 
console.log(`Setting thread pool size to: ${process.env.UV_THREADPOOL_SIZE}`);