# object to string and vice-versa
- In normal JS, to make a object into string, we use JSON.stringify() and to do the opposite, we use JSON.parse()
Eg:
let a = {'a': 12, 'b': 10}
a = JSON.stringify(a) // "{'a': 12, 'b': 10}"
// its a string now
a = JSON.parse(a) // {'a': 12, 'b': 10}
// again its a object

- To do the same in nodeJS req where the json maybe like ?name="kittu"&age="10" to make it {name: "kittu", age: "10"}, we have to use 'querystring' module which is a built in module in nodeJS. Used in inbuiltRequest folder
// https://nodejs.org/api/querystring.html docs link for it
Eg:
const querystring = require('querystring');
let a = 'name="kittu"&age="10"'
a = querystring.stringify(a) // {name: "kittu", age: "10"}
// its a object
a = querystring.stringify(a) // 'name="kittu"&age="10"'
// again its a string


#Why to use emmitter
So lets imagine u can achieve the same thing with normal functions when something happens u just call the function but but but if the function is not defined then there will be error but in case of emmitter u can make custom events and call them the benefit is it doesn't matter there is receiving is there or not. Imagine this as radio signal emitter and receiver doesnot matter somebody is receiving it or not we can send and receive events

# REPL
In node we have inbuilt editor like for python, normally editor like that is availble in inspect of browser but we also have it in node in terminal type node it will open, 
	it is called as REPL ( read eval print loop ) . Funfact to get the last data if u dont remember use _ For example : 10+2 ->12 now u forgot this last data and u wanna add 7 to it so do _ + 7 . Press tab twice to list all the methods available in node. Then if u wanna know what are the things there in particular method or module type that name and hit enter it will show everything.

# Synchronus vs Asynchronus , Buffer Data
----- Here below we are using synchronus way, i.e using sync that means till one dish is heard and told to chef and the user got his food till then 2nd user/process have to wait ----
While doing file handling readFile and write File func gives buffer data
* If no file encoding is specified then raw buffer is returned.
So buffer datatype is only available in node u can access by const buf = fs.readFileSync(‘lol.txt’); to make the buffer data into string do buf.toString()

So if u want to get data without getting the buffer data at first then u have to use encoding i.e. 'utf-8'. So when u use functions like readFile, writeFile then u can use this encoding Eg:
fs.readFile('.'+req.url, "UTF-8", function(err, js){ // used aysnc way here so callback is there and no need for buffer so used utf-8, if u want buffer remove utf-8 and in callback console.log(js)
            res.writeHeader(200, {"Content-Type": "text/js"})
            if(req.url !== '/server.js') // if its server file then skip this
                res.write(js)
            res.end()
        })
but if u dont want to use encoding then u can use streams like readStream and writeStream. So, u can't get buffer data in streams.

----- Asynchronus way i.e dont use any word as sync in the func that means when 1 user order is heard then 2 nd user is heard that is no user have to wait -----
Eg: fs.writeFile('lol.txt','sksks') // here we will get an error we have to give a callback func (which will be called when task is done)
So with callback fs.writeFile('lol.txt','sksks',(err)=>{console.log('done')}) // then no error will come
So why there is need for callback in async way??
Ans: in node after async completes it does not know what to do after it so we have to give a callback func so it can execute after the task

FINAL code eg: SYNCHRONUS (wait till the 1st process completes)
const data = fs.readFile('read.txt','utf-8')
console.log(data) 
console.log('after the task ')
Output:
Bla Blas
after the task

ASYNCHRONUS (don't wait till the 1st process completes)
fs.readFileSync('read.txt','utf-8', (err, data) => {
	console.log(data)
})
console.log('after the task ')
Output:
after the task
Bla Blas

# creating and exporting module
in 1 file
const add = (a,b) => {
	return a+b;
}
const sub = (a,b) => {
	return a-b;
}
module.exports = {add, sub}
in another file
const {add, sub} = require('./filename')

# module wrapper function
so after we import, export something or normal code node js puts the code in a wrapper function with help of grouping operator () for eg:
(function() {
	const lol = require('jj')
	int a = lol+1
	module.exports = {lol}
})
// due to this all the code have becomes private this happens due to iifi
now after the above code outside u do console.log(a) then it will throw error

# streams notes is in loginSytems/v2(fileHandling) notes.md file