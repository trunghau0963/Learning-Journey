require('dotenv').config();
'use strict'
const mongoose = require('mongoose');

const connectString = process.env.MONGODB_URI;

mongoose.connect(connectString)
    .then(() => {
        console.log('MongoDB connected');
    })
    .catch(err => {
        console.error('MongoDB connection error:', err);
    });

//dev
if(1 === 0){
    mongoose.set('debug', true);
    mongoose.set('debug', { color: true });
}

// this scope meaning we are in the development environment, and if(1===0) is false, that means we are not in the development environment

module.exports = mongoose; // this means we are exporting the mongoose instance

// in nodejs, the require register to the library just call one time and use it
// but another such as JAVA or PHP, after we declare the require, it still multiple times call to the library, it mean
// when we export the library, we have multiple connections to the 1 database