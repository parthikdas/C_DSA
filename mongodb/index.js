const { MongoClient } = require('mongodb')
const url = 'mongodb://localhost:27017'
const client = new MongoClient(url)


async function getData() {
    let res = await client.connect()
    let db = res.db('e-comm')
    let collection = await collection.find({}).toArray()
    console.log(response)
}

getData()