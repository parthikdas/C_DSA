const https = require('https')
function getResourceList(requests) {
    ans = []
    const options = {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json' // Set the Content-Type to JSON
        },
      };
    requests.forEach(url => {
        let req = https.request(url, options, (response) => {
            let responseData = '';
            response.on('data', (chunk) => {
              responseData += chunk;
            });
            response.on('end', () => {
              ans.push(responseData)
            })
        });
        req.on('error', (error) => {
            // Handle errors here
            console.error('Request Error:', error);
          });
    })
    return ans
}

requests = ["https://api.example.com/resource6/resource21/", "https://api.example.com/resource951/id60/resource115", "https://api.example.com/resource535/id52/id57/id53"]
ans = getResourceList(requests)
ans.forEach(element => {
  console.log(element)  
});