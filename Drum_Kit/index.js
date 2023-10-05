var number=document.querySelectorAll(".drum").length;





for(var i=0;i<number;i++)
{
  document.querySelectorAll(".drum")[i].addEventListener("click",clickOnHead);
}




function clickOnHead()
{
makeSound(this.innerHTML);
}




document.addEventListener("keypress",function(event){
  makeSound(event.key)
});




function makeSound(key)
{
  switch (key) {
    case "w":
    var tom1=new Audio("sounds/tom-1.mp3");
    tom1.play();
      break;
      case "a":
      var tom2=new Audio("sounds/tom-2.mp3");
      tom2.play();
      break;
      case "s":
      var tom3=new Audio("sounds/tom-3.mp3");
      tom3.play();
      break;
      case "d":
      var crash=new Audio("sounds/tom-4.mp3");
      crash.play();
      break;
      case "j":
      var kick=new Audio("sounds/crash.mp3");
      kick.play();
      break;
      case "k":
      var snare=new Audio("sounds/kick-bass.mp3");
      snare.play();
      break;
      case "l":
      var snare=new Audio("sounds/snare.mp3");
      snare.play();
      break;
      default:
      alert("wrong option");

}
}
