import random
import time

weapon=[]


def print_pause(word):
	print(word)
	time.sleep(2)
	
def start():
	print_pause("Hello!Adventurer")
	print_pause("Get ready to dive into this thrilling adventure game.")
	print_pause("All your decisions count and it will determine the final outcome of the game.")
	print_pause("So,play carefully.")
	while True:
	    print_pause("Are you ready to go on an adventure?")
	    ready=input("yes/no \n").lower()
	    if "yes" in ready:
	    	print_pause("Great!Let's start.")
	    	break
	    elif "no" in ready:
	    	print_pause("So sad.")
	    	print_pause("You can play if you change your mind.")
	    else:
	    	print_pause("Sorry,I don't understand you.")
	    	
	    	
def character():
	    	characters= ["Pirate", "Bandit" , "Thug"]
	    	character= random.choice(characters)
	    	print_pause("Welcome adventurer.In this game you will play as a " + character + ".")
	    	print_pause("Your every decison counts.")
	    	print_pause("You are in the middle of a jungle")
	    	print_pause("This jungle has a lot to offer than you think.")
	    	print_pause("There is a grave silence in the jungle.\n\n")
	    	
def sword_selection(weapon):
	    	print_pause("As you move forward ,you found a bag. ")
	    	print_pause("The bag seems to be heavy.Oh there are many weapons.")
	    	print_pause("Unfortunately,you can only take one with you. ")
	    	while True:
	    		print_pause("Which one you'll pick?")
	    		selection=input("1.Sword \n 2.Knife\n 3.Stick \n").lower()
	    		if "1" in selection:
	    			print_pause("Great Selection.This magical sword can cut through the hardest steel in the world.")
	    			weapon.append("sword")
	    			break
	    		elif "2" in selection:
	    		   	print_pause("This tiny knife is comfortable to carry.Great choice.")
	    		   	weapon.append("knife")
	    		   	break
	    		elif "3" in selection:
	    		   	print_pause("You seem to be tired.It will help you explore the forest.")
	    		   	weapon.append("stick")
	    		   	break
	    		else:
	    			print_pause("I don't understand.Please try again.")
	    			
def crosswords(weapon):
	    	print_pause("You continue your journey with the weapon you just got.")
	    	print_pause("You've reached the crosswords.")
	    	while True:
	    		print_pause("There are 3 directions.")
	    		print_pause("where do you want to go next.")
	    		direction=input("1.Forward\n 2.Left\n 3.Right\n").lower()
	    		if "1" in direction:
	    			print_pause("You decided to go ahead.")
	    			print_pause("You reached a blind end.")
	    			print_pause("So,you had to return.")
	    			print_pause("You have reached the same crossroads.")
	    		elif "2" in direction:
	    			print_pause("You decided to go left")
	    			print_pause("You reached a huge cliff.")
	    			cliff=input("Do you want to \n1.return or 2.jump off the cliff?\n").lower()
	    			if "2" in cliff:
	    				print_pause("That was a wrong decison.The cliff was too high.You died.")
	    				result= "lost"
	    				break
	    			elif "1" in cliff:
	    				print_pause("You returned to the same crossroads.")
	    		elif "3" in direction:
	    			print("You decided to go right.")
	    			print("You've encountered with a tiger.")
	    			print_pause("You have no option but to fight.")
	    			print_pause("Use your weapon to fight.")
	    			if "sword" in weapon:
	    				print_pause("Your magical sword cut through the entire body of the tiger.")
	    				print_pause("You won")
	    				break
	    			elif "knife" in weapon:
	    				print_pause("Your little knife is of no match for the tiger.")
	    				print_pause("You are killed miserably.")
	    				break
	    			elif "stick" in weapon:
	    				print_pause("Did you think this stick will help you?")
	    				print_pause("You are killed.")
	    				print_pause("You lost.")
	    				break 

def play_again():
	    	print_pause("Do you want to play again.")
	    	print_pause("Maybe other outcomes are waiting for you.")
	    	again= input("yes/no\n").lower()
	    	if "yes" in again:
	    			print_pause("Great!We will start right away.")
	    			start_game()
	    	elif "no" in again:
	    			print_pause("Thank you for playing.")
	    	else:
	    			print_pause("I don't understand you.")
	    			
	    			
def start_game():
	weapon = []
	start()
	character()
	sword_selection(weapon)
	crosswords(weapon)
	play_again()

start_game()