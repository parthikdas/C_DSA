let video = document.getElementById('video')
let canvas = document.getElementById('canvas')
let ctx = canvas.getContext('2d')
let height = 754, width = 1440
let model

const videoStream = () => {
    navigator.mediaDevices.getUserMedia({
        video: {height: height, width: width},
        audio: false
    })
    .then(stream => {
        video.srcObject = stream
    })
    .catch(err => {
        alert('Allow Camera Access')
    })
}

const detectHand = async () => {
    // Pass in a video stream (or an image, canvas, or 3D tensor) to obtain a
    // hand prediction from the MediaPipe graph.
    const predictions = await model.estimateHands(video)
    ctx.drawImage(video, 0, 0, width, height)
    if (predictions.length > 0) {
        /*
        `predictions` is an array of objects describing each detected hand, for example:
        [
          {
            handInViewConfidence: 1, // The probability of a hand being present.
            boundingBox: { // The bounding box surrounding the hand.
              topLeft: [162.91, -17.42],
              bottomRight: [548.56, 368.23],
            },
            landmarks: [ // The 3D coordinates of each hand landmark.
              [472.52, 298.59, 0.00],
              [412.80, 315.64, -6.18],
              ...
            ],
            annotations: { // Semantic groupings of the `landmarks` coordinates.
              thumb: [
                [412.80, 315.64, -6.18]
                [350.02, 298.38, -7.14],
                ...
              ],
              ...
            }
          }
        ]
        */
        for (let i = 0; i < predictions.length; i++) {
          const keypoints = predictions[i].landmarks;
    
          // Log hand keypoints.
          for (let i = 0; i < keypoints.length; i++) {
            const [x, y, z] = keypoints[i];
            console.log(`Keypoint ${i}: [${x}, ${y}, ${z}]`);
          }
        }
        predictions.forEach(pred => {
            ctx.fillStyle = 'red'
                pred.landmarks.forEach(landmark => {
                    ctx.fillRect(landmark[0], landmark[1], 5, 5)
                })
        })
    }
}

videoStream()
video.addEventListener('loadeddata', async () => {
    // Load the MediaPipe handpose model.
    model = await handpose.load()
    setInterval(detectHand, 40)
})