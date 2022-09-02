const EventEmitter = require('events')

const eventEmitter = new EventEmitter()

eventEmitter.on('start', () => {
    console.log('started')
})
eventEmitter.emit('start')

// we can make them respond once also, normally listener is invoked every time the named event is emitted.
eventEmitter.once('oneTime', () => {
    console.log('once for all')
})
eventEmitter.emit('oneTime') // prints -> once for all
eventEmitter.emit('oneTime') // ignored

// For error purpose
let a = 2, b = 0
eventEmitter.on('error', err => {
    console.log(err)
})
if(!b) eventEmitter.emit('error', new Error("Denominator can't be zero")) // after this error throw node js crashes


console.log('Final')