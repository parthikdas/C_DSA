const http = require('http')
const fs = require('fs')
let data = []
http.createServer(function(req, res) {
  console.log(req.url)
  console.log(req.method)
  if(req.url === '/') { // basic first page will be the html
    fs.readFile("./index.html", "UTF-8", function(err, html){
      res.writeHeader(200, {"Content-Type": "text/html"})
      res.write(html)
      res.end()
    })
  } else if(req.url === '/data') { // if the url contains data then post or get request have come
    if(req.method == 'POST') { // POST
      let body = ''
      // Readable streams emit 'data' events once a listener is added.
      req.on('data', (chunk) => {
          body += chunk
          //console.log('Partial body: ' + body)
      })
      // The 'end' event indicates that the entire body has been received.
      req.on('end', function() {
          try {
            body = JSON.parse(body);
            // Write back something interesting to the user:
            res.write(typeof body);
            data.push(body)
            console.log(body)
            res.end()
          } catch (er) {
            // uh oh! bad json!
            res.statusCode = 400
            return res.end(`error: ${er.message}`)
          }
      })
    } else if(req.method == 'GET') { // GET
      res.writeHead(200, {"Content-Type": "text/plain"})
      res.write(JSON.stringify(data))
      res.end()
    }
  }
}).listen(3000, console.log('http://localhost:3000'))

// Here we are not only serving html but also handling get, post requests.
// Go to http://localhost:3000 for the website
// Go to http://localhost:3000/data for the data in json format