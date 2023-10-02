// javascript logic for calculator
// initaily we will declared variable that will store and use to display the string 
let string = "";

// now we will create variable that will store all the buttons 
let buttons = document.querySelectorAll('.button');
// create variable that will access the input box 
let inputbox = document.querySelector('input')
// now by using Array.from()method we will add onclick event on each button 
Array.from(buttons).forEach((button)=>{
  // we will add eventlistener to button that will perform action when user will click on button 
  button.addEventListener('click',(e)=>{
    // now will check and apply condition for calculation
    if(e.target.innerHTML == '='){
      string = eval(string);// eval() method is used for evaluating the numeric problems or expression 
      // after evaluating the expression we will display the result on inputbox by using innerHTML property
      inputbox.value = string;
    }else if(e.target.innerHTML == 'AC'){
      string = "";
      inputbox.value = string;
    }else if(e.target.innerHTML == '<i class="bi bi-backspace"></i>'){
      // for deleting the last number we will use slice() method 
      string = string.slice(0, -1);
      inputbox.value = string;
    }else{
      string = string + e.target.innerHTML;
      inputbox.value = string; 
    }
  })
})