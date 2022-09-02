const https = require('https')
const data = new TextEncoder().encode(
    JSON.stringify({
      todo: 'Buy the milk 🍼'
    })
  )
let options = {
    host: 'crudcrud.com',
    path: '/api/d5cba75efdc44088b1b84e9106d97229/todos',
    method: 'POST',
    port: 443,
    headers: {
        'Content-Type': 'application/json',
        'Content-Length': data.length
    }
}
const req = https.request(options, res => {
  console.log(`statusCode: ${res.statusCode}`)

  res.on('data', d => {
    process.stdout.write(d)
  })
})

req.on('error', error => {
  console.error(error)
})
req.write(data)
req.end()