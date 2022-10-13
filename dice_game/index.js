var player1="Player 1";
var player2="Player 2";

function changeNames(){
    player1=prompt("Enter the name of Player 1");
    player2=prompt("Enter the name of player 2");
    document.querySelector("p.player1").innerHTML=player1;
    document.querySelector("p.player2").innerHTML=player2;
}

function rollDice(){
    setTimeout(function(){
        var random1=Math.floor(Math.random()*6)+1; //setting range from 1to 6
        var randomImg1="dice"+random1+".png";
        var randomSrc="images/"+ randomImg1;
        var img1Src=document.querySelectorAll("img")[0];
        img1Src.setAttribute("src",randomSrc);
        
        var random2=Math.floor(Math.random()*6)+1;
        var randomImg2="images/"+"dice"+random2+".png";
        var img2Src=document.querySelectorAll("img")[1];
        img2Src.setAttribute("src",randomImg2);
        
        if(random1>random2){
            document.querySelector("h1").innerHTML=player1+" Wins!";
        }
            else if(random1<random2){
              document.querySelector("h1").innerHTML=player2+" Wins!";;
            }
            else 
            document.querySelector("h1").innerHTML="Draw";
        
    },250)
}




