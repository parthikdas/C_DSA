let api = 'https://crudcrud.com/api/4a796b37d4d54f25b513d9649aea25f7/users'
let loginSection = document.getElementById('loginSection')
let showDetails = document.getElementById('showDetails')
let showlogin = document.getElementById('showlogin'), showsignup = document.getElementById('showsignup')
let loginbutton = document.getElementById('login'), signupbutton = document.getElementById('signup')

// Show login section
showlogin.addEventListener('click', () => {
    if(showlogin.classList.contains('disable')) {
        showlogin.classList.remove('disable')
        showsignup.classList.add('disable')
        loginbutton.style.display = 'block'
        signupbutton.style.display = 'none'
        document.getElementById('write-name').style.display = 'none'
        document.getElementById('write-password2').style.display = 'none'
    }
})
// Show sign up section
showsignup.addEventListener('click', () => {
    if(showsignup.classList.contains('disable')) {
        showlogin.classList.add('disable')
        showsignup.classList.remove('disable')
        loginbutton.style.display = 'none'
        signupbutton.style.display = 'block'
        document.getElementById('write-name').style.display = 'block'
        document.getElementById('write-password2').style.display = 'block'
    }
})

// Function to store data in api
function storeData(data) {
    fetch(api, {
        headers: { "Content-Type": "application/json; charset=utf-8" },
        method: "POST",
        body: JSON.stringify(data),
        headers: {
            "Content-type": "application/json; charset=UTF-8"
        }
    })
}
// Function to delete user
function deleteUser(_id) {
    fetch(api + '/' + _id, {
        method: 'DELETE'
    })
    .then(response => console.log(response))
    .catch(err => console.log(err))
    alert('User removed')
    showUserDetails(0)
}
// Function to update user
function showUpdateSection(id) {
    document.getElementById(id).innerHTML = `<input type="text" id="${id + 'input'}">`
    document.getElementById(`${id+'but'}`).style.display = 'none'
    document.getElementById(`${id+'but1'}`).style.display = 'block'
}
function updateUser(_id, currentUserId, name, email, password, fieldId){
    if(fieldId === 'one') {
        name = document.getElementById('oneinput').value
    } else if(fieldId === 'two') {
        email = document.getElementById('twoinput').value
    } else if(fieldId === 'three') {
        password = document.getElementById('threeinput').value
    }
    fetch(api + '/' + _id, {
        headers: { "Content-Type": "application/json; charset=utf-8" },
        method: 'PUT',
        body: JSON.stringify({
            id: currentUserId,
            name: name,
            email: email,
            password: password
        })
    })
    .then(response => console.log(response))
    .catch(err => console.log(err))
    showUserDetails(currentUserId)
}
// To show user details
function showUserDetails(currentUserId) {
    fetch(api)
    .then(response => response.json())
    .then(data => {
        while(showDetails.firstChild) { // remove all child before adding table
            showDetails.removeChild(showDetails.lastChild)
        }
        let table = document.createElement('table'), tab
        if(currentUserId === 0) { // admin, show all users
            tab = ` <tr>
                        <th colspan="5">All user details</th>
                    </tr>
                    <tr>
                        <th>Id</th>
                        <th>Name</th>
                        <th>Email</th>
                        <th>Password</th>
                        <th>Operations</th>
                    </tr>`
            for (let i = 1 ; i < data.length ; i++) {
                tab += `<tr> 
                            <td>${data[i].id} </td>
                            <td>${data[i].name}</td>
                            <td>${data[i].email}</td> 
                            <td>${data[i].password}</td>
                            <td><button id=${data[i]._id} style="background:red;color:#fff;border:none;padding:.3rem;" onclick="deleteUser(this.id)">DELETE</button></td>       
                        </tr>`
            }
        } else {
            tab =  `<tr>
                        <th colspan="3">Your details</th>
                    </tr>
                    <tr>
                        <th>Id</th>
                        <td>${currentUserId}</td>
                        <td><button disabled>Update</button></td>
                    </tr>
                    <tr>
                        <th>Name</th>
                        <td id="one">${data[currentUserId].name}</td>
                        <td>
                            <button id="onebut" style="background:skyblue;border:none;padding:.3rem;" onclick="showUpdateSection('one')">Update</button>
                            <button id="onebut1" style="display:none;background:skyblue;border:none;padding:.3rem;" onclick="updateUser('${data[currentUserId]._id}', '${currentUserId}', '${data[currentUserId].name}', '${data[currentUserId].email}', '${data[currentUserId].password}', 'one')">Save</button>
                        </td>
                    </tr>
                    <tr>
                        <th>Email</th>
                        <td id="two">${data[currentUserId].email}</td>
                        <td>
                            <button id="twobut" style="background:skyblue;border:none;padding:.3rem;" onclick="showUpdateSection('two')">Update</button>
                            <button id="twobut1" style="display:none;background:skyblue;border:none;padding:.3rem;" onclick="updateUser('${data[currentUserId]._id}', '${currentUserId}', '${data[currentUserId].name}', '${data[currentUserId].email}', '${data[currentUserId].password}', 'two')">Save</button>
                        </td>
                    </tr>
                    <tr>
                        <th>Password</th>
                        <td id="three">${data[currentUserId].password}</td>
                        <td>
                            <button id="threebut" style="background:skyblue;border:none;padding:.3rem;" onclick="showUpdateSection('three')">Update</button>
                            <button id="threebut1" style="display:none;background:skyblue;border:none;padding:.3rem;" onclick="updateUser('${data[currentUserId]._id}', '${currentUserId}', '${data[currentUserId].name}', '${data[currentUserId].email}', '${data[currentUserId].password}', 'three')">Save</button>
                        </td>
                    </tr>`
        }
        table.innerHTML = tab
        showDetails.appendChild(table)
        // logout button
        let logoutBut = document.createElement('button')
        logoutBut.style = 'height:fit-content;width:fit-content;font-size:1.2rem;background:crimson;color:#fff;border:none;padding:.3rem;border-radius:.5rem;'
        logoutBut.innerHTML = 'Logout'
        logoutBut.onclick = function() {
            logout()
        }
        showDetails.appendChild(logoutBut)
    })
}
// Auto login feature
document.addEventListener('DOMContentLoaded', () => {
    let userLoginData = [] // 0th index will store email, 1st index will store password
    try{
        userLoginData = localStorage.getItem('userLoginData')
        if(userLoginData === 'null') throw 'Data not found new made'
        else {
            userLoginData = JSON.parse(userLoginData)
            tryLogin(userLoginData[0], userLoginData[1]) // sending email and password
        }
    }
    catch(err) {
        console.log(err)
        localStorage.setItem('userLoginData', userLoginData)
    }
})
// Function to try login
function tryLogin(email, password) {
    fetch(api)
    .then(response => response.json())
    .then(data => {
        let currentUserId = -1
        for(let i = 0; i < data.length; i++) { // checking for old user
            if(data[i].email == email) {
                currentUserId = i
                break
            }
        }
        if(currentUserId !== -1) {
            if(data[currentUserId].password === password) { // Successful login
                if(currentUserId !== 0) { // if not admin store the user details
                    localStorage.setItem('userLoginData', JSON.stringify([data[currentUserId].email, data[currentUserId].password]))
                }
                document.getElementById('userName').innerHTML = 'Hi, ' + data[currentUserId].name
                email = password = ''
                loginSection.style.display = 'none'
                showUserDetails(currentUserId) // to show details
            }
            else {
                alert('Wrong Password')
                password = ''
            }
        } else { // new User
            alert('Account not found. Please Sign up.')
            email = password = ''
        }
    })
}
// Login event
document.getElementById('login').addEventListener('click', () => {
    let email = document.getElementById('email'), password = document.getElementById('password')
    if(email.value && password.value) {
        tryLogin(email.value, password.value)
    } else alert('Enter credentials')
})
//Signup event
document.getElementById('signup').addEventListener('click', () => {
    let name = document.getElementById('name'),email = document.getElementById('email'), password = document.getElementById('password'), password2 = document.getElementById('password2')
    if(name.value && email.value && password.value && password2.value) {
        fetch(api)
        .then(response => response.json())
        .then(data => {
            let currentUserId = -1
            for(let i = 0; i < data.length; i++) { // checking for old user
                if(data[i].email == email.value) {
                    currentUserId = i
                    break
                }
            }
            if(currentUserId !== -1) {
                alert('Existing user')
            } else { // new User
                if(password.value == password2.value) {
                    storeData({ // Store new user's data
                                "id": data.length === 0 ? 0 : data[data.length-1].id+1, // last user's id+1
                                "name": name.value,
                                "email": email.value,
                                "password": password.value
                            })
                    alert('Registration successful. Please login.')
                } else {
                    alert('Passwords not matching')
                    password.value = password2.value = ''
                }
            }
            name.value = email.value = password.value = password2.value = '' // empty the fields
        })
    } else alert('Enter credentials')
})
// Logout
function logout() {
    document.getElementById('userName').innerHTML = 'Hi, User'
    while(showDetails.firstChild) { // remove all child before adding table
        showDetails.removeChild(showDetails.lastChild)
    }
    loginSection.style.display = 'flex'
    localStorage.removeItem('userLoginData') // if log out done then remove the details
}