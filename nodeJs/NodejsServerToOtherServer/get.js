const https = require('https')
let options = {
    host: 'crudcrud.com',
    path: '/api/d5cba75efdc44088b1b84e9106d97229/todos',
    method: 'GET',
    port: 443 // can also give port number, Port 443 is a virtual port that computers use to divert network traffic. Port 443 is used explicitly for HTTPS services and hence is the standard port for HTTPS (encrypted) traffic. It is also called HTTPS port 443, so all the secured transactions are made using port 443. You might be surprised to know that almost 95% of the secured sites use port 443 for secure transfers
}
let ans = []
const req = https.request(options, res => {
  console.log(`statusCode: ${res.statusCode}`)
  res.on('data', d => {
    //process.stdout.write(d)
    //console.log(JSON.parse(d)) //A common use of JSON is to exchange data to/from a web server. When receiving data from a web server, the data is always a string. Parse the data with JSON.parse(), and the data becomes a JavaScript object.
    gotIt(JSON.parse(d))
  })
})
req.on('error', error => {
  console.error(error)
})

req.end()

function gotIt(data) { // trying to store the data but its not happening only it can be used in this function not outside so
  ans = data
  //https://stackoverflow.com/questions/45018338/javascript-fetch-api-how-to-save-output-to-variable-as-an-object-not-the-prom/61285073#61285073
  //see this for the info
}
console.log(ans)