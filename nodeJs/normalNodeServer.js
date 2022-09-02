const http = require('http')
http.createServer((req, res) => {
    // `req` is an http.IncomingMessage, which is a readable stream.
    // `res` is an http.ServerResponse, which is a writable stream.
    res.statusCode = 200
    res.setHeader('Content-Type', 'text/html')
    res.end('<h1> Henloo00 </h1>')
}).listen(3000, '127.0.0.1', () => { // u can give port number and hostname, if hostname not given then localhost:{port number} by default
    console.log('Server is live on http://127.0.0.1:3000')
})