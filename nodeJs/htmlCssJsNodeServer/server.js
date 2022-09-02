const http = require('http')
const fs = require('fs')
http.createServer((req, res) => {
    /* Here for every file u have to explicitly use if else so i found a sol and used streams in that sol:
        let fileName = '.' + (req.url === '/' ? '/index.html' : req.url)
        const stream = fs.createReadStream(fileName)
        stream.pipe(res)
        // if the address is / then index.html else that file name and serve that through streams
    */
    if(req.url == '/') {
        fs.readFile("./index.html", "UTF-8", function(err, html){
            res.writeHeader(200, {"Content-Type": "text/html"})
            res.write(html)
            res.end()
        })
    }
    else if(req.url.match("\.css$")) { // using regex to find css extension
        fs.readFile("./style.css", "UTF-8", function(err, css){
            res.writeHeader(200, {"Content-Type": "text/css"})
            res.write(css)
            res.end()
        })
    } else if(req.url.match("\.js$")) {
        fs.readFile("./index.js", "UTF-8", function(err, js){
            res.writeHeader(200, {"Content-Type": "text/js"})
            res.write(js)
            res.end()
        })
    } 
}).listen(3000)

/*
    If u don't use fs then u have to write the whole html in res.write
    Eg: if(req.url == '/') {
            res.writeHeader(200, {"Content-Type": "text/html"})
            res.write('<!DOCTYPE html>
                        <html lang="en">
                        <head>
                            <meta charset="UTF-8">
                            <meta http-equiv="X-UA-Compatible" content="IE=edge">
                            <meta name="viewport" content="width=device-width, initial-scale=1.0">
                            <title>Document</title>
                        </head>
                        <body>
                            
                        </body>
                        </html>')
            res.end()
        }
*/