const videoGrid = document.getElementById('video-grid')
const socket = io('/') // socket is gonna connect to our root path of our application
// so to make connections between user using webrtc, we will use peer.js
// to start a peer server in 3001 port, so this peer server allows us to do is to connect different users and it will give us an id of a user which we can use here instead hardcoded number 10
// socket.emit('join-room', ROOM_ID, 10)
// This peer server takes all the webRTC info of a user and turns it into id that we can pass b/w places to connect to other peers
const myPeer = new Peer(undefined, { // undefined cuz server will take care for generating id, second id i host
    host: '/',
    port: '3001'
})
const myVideo = document.createElement('video')
myVideo.muted = true // we dont want to listen to our own video, so this is not gonna be mute for other people just mute for us
const peers = {} // to take record who came

navigator.mediaDevices.getUserMedia({
    video: true,
    audio:true
}).then(stream => {
    addVideoStream(myVideo, stream)

    myPeer.on('call', call => {
        call.answer(stream) // we answered the call now we have to respond to it
        const video = document.createElement('video')
        call.on('stream', userVideoStream => {
            addVideoStream(video, userVideoStream)
        })
    })

    // now we need to allow ourself to be connected by other users, so again use socket.io
    socket.on('user-connected', userId => {
        console.log('User connected ' + userId)
        connectToNewUser(userId, stream)
    })
})

socket.on('user-disconnected', userId => {
    console.log('User disconnected ' + userId)
    if(peers[userId]) peers[userId].close()
})

myPeer.on('open', id => { // as soon as we connect to peer server and get back an ID run this code
    socket.emit('join-room', ROOM_ID, id) // this id is user-id of webrtc given by peer
})
// socket.on('user-connected', userId => { // listening to user-connected event
//     console.log('User connected ' + userId) // someone else joined with this id this msg will to everyone in the room
// })

function connectToNewUser(userId, stream) {
    const call = myPeer.call(userId, stream) // we are calling this user with this ID and sending them our video and audio stream
    const video = document.createElement('video')
    call.on('stream', userVideoStream => {
        addVideoStream(video, userVideoStream)
    }) // then we listen to event
    // so this event is saying when we call this user we are gonna send them our videostream and when they send us back their video, we are gonna call then event stream which will take their video stream and it will add to our list of video
    call.on('close', () => { // when someone closes the video call, so we remove the video
        video.remove()
    })
    peers[userId] = call // userId = call that we just created 
}

function addVideoStream(video, stream) {
    video.srcObject = stream
    video.addEventListener('loadedmetadata', () => { // once video is loaded on page play video
        video.play()
    })
    videoGrid.append(video)
}