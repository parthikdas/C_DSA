
var nosDisplay = document.querySelector('#nosDisplay');
var opDisplay = document.querySelector('#operatorDisplay');
var first_number, second_number, result='= ';
var first_number_found = false, calc_done = false, dot_used=false, negetive_used=false;
//For the numbers
function check_default_display() { //This function checks whether default value is displayed 
    if(nosDisplay.innerHTML=='0') {
        return 1;
    } else {
        return 0;
    }
}
function first() { //This function checks whether the first number is found if yes then second number will start from empty screen
    if(first_number_found) {
        nosDisplay.innerHTML = '';
    }
    first_number_found = false; //this have to be done as again when a number is clicked the screen becomes blank
}
function one_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '1';
    } else { //else append it
        nosDisplay.innerHTML += '1';
    }
}
function two_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '2';
    } else { //else append it
        nosDisplay.innerHTML += '2';
    }
}
function three_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '3';
    } else { //else append it
        nosDisplay.innerHTML += '3';
    }
}
function four_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '4';
    } else { //else append it
        nosDisplay.innerHTML += '4';
    }
}
function five_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '5';
    } else { //else append it
        nosDisplay.innerHTML += '5';
    }
}
function six_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '6';
    } else { //else append it
        nosDisplay.innerHTML += '6';
    }
}
function seven_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '7';
    } else { //else append it
        nosDisplay.innerHTML += '7';
    }
}
function eight_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '8';
    } else { //else append it
        nosDisplay.innerHTML += '8';
    }
}
function nine_clicked() {
    first();
    if(check_default_display()) { //if defualt display is there then make this as new
        nosDisplay.innerHTML = '9';
    } else { //else append it
        nosDisplay.innerHTML += '9';
    }
}
function zero_clicked() {
    first();
    if(!(check_default_display())) { //if already zero is present as defualt then don't add else add
        nosDisplay.innerHTML += '0';
    }
}
//For pie
function pie_clicked() {
    first();
    if(check_default_display()) {
        nosDisplay.innerHTML = '3.14';
    } else {
        nosDisplay.innerHTML += '3.14';
    }
}
//For the negetive
function negetive_clicked() {
    first();
    if(!negetive_used && !(nosDisplay.innerHTML.includes('-'))) { //if negetive is not used and the existing value doesnot contain negetive then only you can enter( this condition is when result becomes the first number (it may contain dot bcz of previous calculation))
        nosDisplay.innerHTML = '-'; //as it will be in the front so just '=' not '+='
        negetive_used = true;
    }
}
//For the dot
function dot_clicked() {
    first();
    if(!dot_used && !(nosDisplay.innerHTML.includes('.'))) { //if dot is not used and the existing value doesnot contain dot then only you can enter( this condition is when result becomes the first number (it may contain dot bcz of previous calculation))
        nosDisplay.innerHTML += '.';
        dot_used = true;
    }
}

//For the prev_char_remove
function prev_char_remove_clicked() { //removes the last character
    let string = nosDisplay.innerHTML;
    string = string.slice(0,-1);
    nosDisplay.innerHTML = string;
    if(!(string.includes('.'))){ //if user removed the decimal then make it false so that it can be entered later
        dot_used = false;
    }
    if(!(string.includes('-'))){ //if user removed the negetive then make it false so that it can be entered later
        negetive_used = false;
    }
}

//For the operators
function divide_clicked() {
    if(nosDisplay.innerHTML!='') { //so that input won't be done until some number input
        opDisplay.innerHTML = '/';
    }
    getFirstNumber();
}
function multi_clicked() {
    if(nosDisplay.innerHTML!='') {
        opDisplay.innerHTML = 'X';
    }
    getFirstNumber();
}
function add_clicked() {
    if(nosDisplay.innerHTML!='') {
        opDisplay.innerHTML = '+';
    }
    getFirstNumber();
}
function subs_clicked() {
    if(nosDisplay.innerHTML!='') {
        opDisplay.innerHTML = '-';
    }
    getFirstNumber();
}
function check_float_number() { //Function to check whether number is float or int
     if(parseFloat(nosDisplay.innerHTML)==parseInt(nosDisplay.innerHTML)) { //parseFloat('2.2')=2.2, parseInt('2.2')=2, parseFloat('2')=2, parseInt('2')=2
         return 0;
     } else {
         return 1;
     }
}
function getFirstNumber() {
    if(calc_done) {
        let string = nosDisplay.innerHTML;
        string = string.slice(2,string.length); //as i have '= ' in result need to take care of it so string will have the whole and updated string will have '= ' after this
        if(check_float_number()) {
            first_number = parseFloat(string);
            dot_used = false;
        } else {
            first_number = parseInt(string);
        }
        first_number_found = true;
        negetive_used = false; //First number is found so make it false
        return;
    }
    if(check_float_number()) {
        first_number = parseFloat(nosDisplay.innerHTML);
        dot_used = false;
    } else {
        first_number = parseInt(nosDisplay.innerHTML);
    }
    first_number_found=true;
    negetive_used = false; //First number is found so make it false
    return;
}
//For the cancel
function cancel_clicked() {
    nosDisplay.innerHTML='0';
    opDisplay.innerHTML='';
    first_number = null;
    second_number = null;
    result='= ';
    dot_used = false;
    negetive_used = false;
    calc_done = false;
    return;
}
//For the equal
function equal_clicked() {
    if(check_float_number()) {
        second_number = parseFloat(nosDisplay.innerHTML);
        dot_used = false;
    } else {
        second_number = parseInt(nosDisplay.innerHTML);
    }
    negetive_used = false; //Second number is found so make it false
    calculation();
    opDisplay.innerHTML='';
    nosDisplay.innerHTML=result;
    return;
}
//For the calculation
function calculation() {
    if(calc_done) { //this is for the second time if we want to repeat with current ans again
        result='= '; //if previous calculation is done and cancel not pressed then make it null to store next ans
    }
    if(opDisplay.innerHTML=='/'){
        if(second_number == '0') {
            result += 'undefined';
        } else {
            let ans = first_number / second_number;
            if(isInt(ans)) { //if ans is int make it as a single digit
                result += ans.toFixed(0); //if ans is 2.0 then we want it as 2
            } else {
                result += ans.toFixed(2); //for 4 digit precision
            }
        }
        calc_done=true;
        return;
    } else if(opDisplay.innerHTML=='X'){
        let ans = first_number * second_number;
        if(isInt(ans)) {
            result += ans.toFixed(0); //this toFixed is used to round off
        } else {
            result += ans.toFixed(2);
        }
        calc_done=true;
        return;
    } else if(opDisplay.innerHTML=='+'){
        let ans = first_number + second_number;
        if(isInt(ans)) {
            result += ans.toFixed(0);
        } else {
            result += ans.toFixed(2);
        }
        calc_done=true;
        return;
    } else if(opDisplay.innerHTML=='-'){
        let ans = first_number - second_number;
        if(isInt(ans)) {
            result += ans.toFixed(0);
        } else {
            result += ans.toFixed(2);
        }
        calc_done=true;
        return;
    }
}
function isInt(n) { //Function to check if ans is int or float
    return n % 1 === 0;
 }

