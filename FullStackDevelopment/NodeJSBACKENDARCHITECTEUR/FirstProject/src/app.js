const express = require('express');
const morgan = require('morgan');
const app = express(); // this mean we are creating an instance of express

// init middleware
app.use(morgan('dev'))
// init db
require('./database/init.mongodb.js'); // this mean we are importing the database connection
// init routes
app.get('/', (req, res) => {
    return res.status(200).json({ message: 'Hello World' });
});

// handling errors
app.use((err, req, res, next) => {
    console.error(err.stack);
    res.status(500).send('Something broke!');
});


module.exports = app; // this mean we are exporting the app instance