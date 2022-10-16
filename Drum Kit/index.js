//Detecting button press

for (var i = 0; i < document.getElementsByClassName("drum").length; i++) {
  document.querySelectorAll(".drum")[i].addEventListener("click", handleClick);

  function handleClick() {
    var buttonInnerHTML = this.innerHTML;   //this is to change innerhtml of the button with class drum
    
    makeSound(buttonInnerHTML);
    buttonAnimation(buttonInnerHTML);
  
  }
}

//Detecting keyboard press

document.addEventListener("keydown", function(event){
    makeSound(event.key);
    buttonAnimation(event.key);
});


function makeSound(key){
     
     switch (key) {    //switch case to add audio to the buttons 
          case "w":
            var tom1 = new Audio("tom-1.mp3");
            tom1.play();
    
            break;
    
          case "a":
            var tom2 = new Audio("tom-2.mp3");
            tom2.play();
    
            break;
    
          case "s":
            var tom3 = new Audio("tom-3.mp3");
            tom3.play();
    
            break;
    
          case "d":
            var tom4 = new Audio("tom-4.mp3");
            tom4.play();
    
            break;
    
          case "j":
            var crash = new Audio("crash.mp3");
            crash.play();
    
            break;
    
          case "k":
            var kickBass = new Audio("kick-bass.mp3");
            kickBass.play();
    
            break;
    
          case "l":
            var snare = new Audio("snare.mp3");
            snare.play();
    
            break;
    
            default: console.log(buttonInnerHTML);
        }

}

function buttonAnimation(currentKey){
   var activeButton = document.querySelector("." + currentKey);
   activeButton.classList.add("pressed");

   setTimeout(function(){
        activeButton.classList.remove("pressed");
   }, 100);
}