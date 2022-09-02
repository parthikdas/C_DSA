const axios = require('axios')

axios
  .post('https://crudcrud.com/api/d5cba75efdc44088b1b84e9106d97229/todos', {
    todo: 'Buy the milk'
  })
  .then(res => {
    console.log(`statusCode: ${res.status}`)
    console.log(res)
  })
  .catch(error => {
    console.error(error)
  })

// So, axios is 3rd party use cdn in html or use npm to install it.