# Black Jack

## Built with  
**Programming language:** C++  
**Testing framework:** N/A

## Authors  
[Clarissa Liljander](https://github.com/clalil)  

## The code  
### Gameplay
This program represents a simplified Black Jack game where the rules are as follows:  
* The dealer is dealt two cards in the beginning.
* The dealer wins if she has > 17 and the same current total as the player, if the player goes bust (> 21) or if the dealer has a higher total than the player but less than 22. 
* The player wins if he/she doesn't go bust (> 21 total score), the dealer goes bust or if the player has a higher score than the dealer but less than 22. 

### Primitive AI
For added fun this game has a primitive version of an AI where the computer has the advantage of knowing the player's current total while making decisions on how to proceed with the gameplay during each turn.

### Randomization of cards  
In this application, I've create a random number generator with a seed value, using the clock (chrono) to get a different sequence each time as opposed to the solution using the C-style ‘std::time’ method. I also use “mt19937” (a “Mersenne Twister” generator) in combination with the  “uniform_int_distribution” which handles the process of mapping random numbers to the distribution of interest.  

## Dependencies  
* Xcode  

## Setup  
To test this application you need to fork it to your own GitHub account and clone it to your local workspace. Once you have cloned the repository, you will be able to run the build inside of Xcode or through the CLI once you are inside of the root folder DiceJack.  
  
If you do not have Xcode, you may want to run the application directly in your CLI by entering the following command:  
```
$ g++ -std=c++11 main.cpp game_info.cpp game_play.cpp
$ ./a.out
```

## Instructions  
The game instructions are provided with the game itself.  

## Acknowledgement  
Thank you to Paradox Interactive's [GamesByHer](https://gamedevcourse.paradoxinteractive.com/) initiative for creating this challenge for me.
