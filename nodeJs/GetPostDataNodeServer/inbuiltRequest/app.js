const http = require('http')
const fs = require('fs') // for reading file
const qs = require('querystring') // to make url into json

let data = []
http.createServer(function(req, res) {
    // all of them are get response
    console.log(req.url)
    if(req.url === '/') {
        fs.readFile("./index.html", "UTF-8", function(err, html){
            res.writeHeader(200, {"Content-Type": "text/html"})
            res.write(html)
            res.end()
        })
    } else if(req.url === '/thanks') {
        fs.readFile("./thanks.html", "UTF-8", function(err, html){
            res.writeHeader(200, {"Content-Type": "text/html"})
            res.write(html)
            res.end()
        })
    } else {
        let data = qs.parse(req.url.substring(2))
        data = JSON.parse(JSON.stringify(data)) // to remove [Object: null prototype]
        console.log(data) // we got our data
        res.writeHead(301,{Location: '/thanks'}) // redirecting to thanks.html
        res.end()
    }
}).listen(3000, console.log('http://localhost:3000'))