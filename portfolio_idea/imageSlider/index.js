var images = [
    "https://images.sadhguru.org/sites/default/files/inline-images/sadhguru-pics.jpg",
    "https://images.sadhguru.org/sites/default/files/inline-images/isha-images.jpg",
    "https://images.sadhguru.org/sites/default/files/inline-images/photo-of-sadhguru.jpg"
];
var rightBtn = document.getElementById('right');
var leftBtn = document.getElementById('left');
var i=0;
var time=5000;

function setImage() { //This function changes the images
    document.slide.src = images[i];
}
function slideImg() { // This function will load when window is loaded and will automatically change images every 5sec
    if(i<images.length-1) {
        i++;
    } else {
        i=0;
    }
    setImage();
    setTimeout('slideImg()',time);
}
window.onload = slideImg; // when window is loaded call slideImg()
rightBtn.addEventListener('click', function () {
    if(i<images.length-1) {
        i++;
    } else {
        i=0;
    }
    setImage();
})
leftBtn.addEventListener('click', function () {
    if(i>0) {
        i--;
    } else {
        i=images.length-1;
    }
    setImage();
})