// Set thread pool size before any other imports
// require('./threadpool');
const os = require('os');
// Get the number of CPU cores and set thread pool size
// Using all available logical cores
// Set thread pool size before anything else
process.env.UV_THREADPOOL_SIZE = os.cpus().length; 
console.log(`Setting thread pool size to: ${process.env.UV_THREADPOOL_SIZE}`);
// Alternatively, use double the cores for more threads if operations are I/O heavy
// process.env.UV_THREADPOOL_SIZE = os.cpus().length * 2;

// require('dotenv').config();
const express = require("express");
const app = express();
const bcrypt = require('bcrypt');
const crypto = require('crypto');

console.log(`Setting thread pool size to: ${process.env.UV_THREADPOOL_SIZE}`);

app.get('/', async  (req, res) => {
    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash("myPlaintextPassword", salt);
    res.send(hashedPassword);
});

const start = Date.now();
for (let i = 0; i < 6; i++) {
    crypto.pbkdf2("myPlaintextPassword", "salt", 100000, 512, "sha512", () => {
        console.log(`Hashing ${i + 1} done in ${Date.now() - start} ms`);
    });
}

app.listen(3055, () => {
    console.log(`Server is running on port 3055`);
});