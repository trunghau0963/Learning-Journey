//using singleton to strictly one connection
require('dotenv').config();
'use strict'
const mongoose = require('mongoose');
const { countConnect } = require('../helpers/check.connect.js');
 
const connectionString = process.env.MONGODB_URI || 'mongodb://localhost:27017/mydatabase';

//singleton
class MongoDBConnection {
  constructor() {
    this.connect();
  }

  connect(type = "mongodb") {
    if (1 === 1) {
      // 1 === 1 means we are in debug mode, so we enable mongoose debug mode, debug mode is
      mongoose.set("debug", true);
      mongoose.set("debug", { color: true });
      //this scope meaning we are setting mongoose to debug mode
    }

    mongoose
      .connect(connectionString)
      .then(() => {
        console.log("MongoDB instance connected", countConnect());
      })
      .catch((err) => {
        console.error("MongoDB connection error:", err);
      });
  }

  static getInstance() {
    if (!MongoDBConnection.instance) {
      MongoDBConnection.instance = new MongoDBConnection();
    }
    return MongoDBConnection.instance;
  }
}

const instance = MongoDBConnection.getInstance();
module.exports = instance;
