const http = require('http')
const fs = require('fs')
let data = []
http.createServer((req, res) => {
    console.log(req.url)
    if(req.url === '/data') {
        // if(req.method==='POST') {
        //     let body = ''
        //     req.on('data', (chunk) => {
        //         body += chunk
        //     })
        //     req.on('end', function() {
        //         try {
        //             body = JSON.parse(body);
        //             console.log(body)
        //             res.end()
        //         } catch (er) {
        //             res.statusCode = 400
        //             return res.end(`error: ${er.message}`)
        //         }
        //     })
        // }
        // res.end()
    } else {
        let fileName = '.' + (req.url === '/' ? '/index.html' : req.url)
        const stream = fs.createReadStream(fileName)
        stream.pipe(res)
    }
})
.listen(3000, console.log('server running at http://localhost:3000'))