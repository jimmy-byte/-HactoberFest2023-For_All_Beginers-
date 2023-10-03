// alert("hello");
var buttonColours = ["red","blue","green","yellow"];
var gamePattern = [];
var userClickedPattern = [];

// In the start choosing any key starts the game
var started = false;                   //to allow only the first keydown to start the game
var level = 0;
$(document).on("keydown",function(){
    if(!started){
        nextSequence();
        // $("#level-title").text("Level " + level);
        started = true;
    }
});
function nextSequence(){
    userClickedPattern = [];
    level++;
    $("#level-title").text("Level " + level);
    //A random colour is first selected
    var randomNumber = Math.floor(Math.random()*4);
    var randomChosenColour = buttonColours[randomNumber];
    gamePattern.push(randomChosenColour);
    
    // animate the random chosen colour with flash
    $("#" + randomChosenColour).fadeOut(100).fadeIn(100);
    
    //Adds audio to that colour
    playSound(randomChosenColour);
}

//To take user click pattern
$(".btn").on("click",function(){
    var userChosenColor = $(this).attr("id");
    userClickedPattern.push(userChosenColor);
    console.log(userClickedPattern);
    playSound(userChosenColor);
    animatePress(userChosenColor);
    checkAnswer(userClickedPattern.length - 1);
});

//function to play sound
function playSound(name){
    var audio = new Audio("./sounds/"+name+".mp3");
    audio.play();
}

//function to animate buttons
function animatePress(currentColor){
    $("#" + currentColor).addClass("pressed");
    setTimeout(function(){
        $("#" + currentColor).removeClass("pressed")
    },100);
}

//to check user's answer 
function checkAnswer(currentLevel){
    if(gamePattern[currentLevel] == userClickedPattern[currentLevel]){
        console.log("success");
        //Write an if statement inside checkAnswer() to check if the most recent user answer is the same as the game pattern. If so then log "success", otherwise log "wrong".
        if(gamePattern.length == userClickedPattern.length){
            setTimeout(function(){
                nextSequence();
            },1000);
        }
    }
    else{
        //wrong output
        $("body").addClass("game-over");
        playSound("wrong");
        setTimeout(function(){
            $("body").removeClass("game-over");
        },200);
        $("h1").text("Game Over!Press any key to start over")
        restart();
    }
}

// to restart the game if you got the wrong click
function restart(){
    gamePattern = [];
    level = 0;
    started = false;
}