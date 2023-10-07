import turtle


wn = turtle.Screen()
wn.title("Bouncing Ball Animation")
wn.bgcolor("white")
wn.setup(width=600, height=400)


ball = turtle.Turtle()
ball.shape("circle")
ball.color("red")
ball.penup()
ball.speed(0)
ball.goto(0, 0)


ball_dx = 6  
ball_dy = -6  


def move():
    global ball_dx, ball_dy
    ball.setx(ball.xcor() + ball_dx)
    ball.sety(ball.ycor() + ball_dy)


    if ball.xcor() > 290:
        ball.setx(290)
        ball_dx *= -1

    if ball.xcor() < -290:
        ball.setx(-290)
        ball_dx *= -1

    if ball.ycor() > 190:
        ball.sety(190)
        ball_dy *= -1

    if ball.ycor() < -190:
        ball.sety(-190)
        ball_dy *= -1

   
    wn.update()  
    wn.ontimer(move, 10) 


wn.tracer(0)


move()


wn.exitonclick()
