# Ideas taken from :
https://livebook.manning.com/book/node-js-in-action/chapter-5/7\

# Mainly 3 types:
	1. Local Storage
		1. Browser Storage
		2. File Handling
	2. Online Backend
	3. Database
		1. Sql Database
		2. No-Sql Database

# Basic Features in All versions: 
	* Login
	* Sign up
	* Logout
	* Admin can all user data and can delete any user
		-> Issue: After deleting a user who is not last the id arrangements is inappropriate. Eg: deleting 3 in 5 users the ids : 0 1 2 4
			-> Possible Sol : 1. After deleting the user, all the users after him/her reduce the id by 1
							  2. While adding a new user, make the id of new user as previous user's id+1 then ids: 0 1 2 4 5.
			-> Used sol : 1st sol is used in V1 and V2, 2nd sol is used in V3.
	* User can only see his/her data and can update it.

# Doubt
In online backend(V3) there is nothing to do and in V1 there is no server but in filehandling(V2) there is a server and i am getting the whole data (all users data) from server and checking the valid details in frontend idk if its correct to do or i should send the data to backend and do all stuff there??

# why main data oriented operations should be on backend
Filter and limit on the back end. If you had a million records, and a hundred thousand users trying to access those records at the same time, would you really want to send a million records to EVERY user? It'd kill your server and user experience (waiting for a million records to propagate from the back end for every user AND then propagate on the front end would take ages when compared to just getting 20-100 records and then clicking a (pagination) button to retrieve the next 20-100). On top of that, then to filter a million records on the front-end would, again, take a very long time and ultimately not be very practical.

From a real world stand point, most websites have some sort of record limit: Ebay = 50-200 records, Amazon = ~20, Target = ~20... etc. This ensures quick server responses and a smooth user experience for every user.

This depends on the size of your data. For eg: If you are having a large amount of data, it is better to implement the filter logic on the backend and let the db perform the operations.

In case, you have less amount of data, you can do the filter logic on the front end after getting the data.

Let us understand this by an example. Suppose you have an entity having 1,00,000 records and you want to show it in a grid. In this case it is better to get 10 records on every call and show it in a grid. If you want to perform any filter operation on this, it is better to make a query for the db on the backend and get the results

In case it you have just 1000 records in your entity, it will be beneficial to get all the data and do all the filter operations on the frontend


# in the file handling section we have stored the data in .txt file u can also do it in .json file
Eg:	const jsonData = JSON.stringify({"lol":"1"}) // while reading do JSON.parse with file encoding
fs.writeFile("json.json", jsonData, (err) => { // json.json is the file
	console.log(err)
})