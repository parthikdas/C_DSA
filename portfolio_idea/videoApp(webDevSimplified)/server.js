const express = require('express')
const app = express()
const server = require('http').Server(app)
const io = require('socket.io')(server)
const { v4: uuidV4} = require('uuid')

app.set('view engine', 'ejs')
app.use(express.static('public'))

app.get('/', (req, res) => {
    res.redirect(`${uuidV4()}`)
})

app.get('/:room', (req, res) => {
    res.render('room', { roomId: req.params.room })
})

io.on('connection', socket => {
    // event when someone joins a room, we will pass the roomId and userId
    // On the front end when Everything is set up we have a room and user we arw gonna call the code inside join-room (socket.on)
    socket.on('join-room', (roomId, userId) => {
        console.log(roomId, userId)
        socket.join(roomId) // we are joining the new room with this current user, so anytime something happens to this room we will send it to this socket or essentially this user
        // socket.to(roomId).broadcast.emit('user-connected', userId) was not working
        socket.broadcast.emit('user-connected', userId) // send a msg to room, we are currently in, broadcast msg is send it to everyone else in same room but don't send it back as we know, we dont need to send a msg to ourself that we connected
        socket.on('disconnect', () => {
            // same as above to(roomId) not working
            socket.broadcast.emit('user-disconnected', userId)
        })
    })
})

server.listen(3000, () => {
    console.log('http://localhost:3000')
})