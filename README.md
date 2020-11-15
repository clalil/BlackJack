# Black Jack

## Built with  
**Programming language:** C++  
**Testing framework:** N/A

## Authors  
[Clarissa Liljander](https://github.com/clalil)  

## The code  
This program represents a simplified Black Jack game where the rules are as follows:  
* The dealer is dealt two cards in the beginning.
* The dealer wins if she has > 17 and the same current total as the player, if the player goes bust (> 21) or if the dealer has a higher total than the player but less than 22. 
* The player wins if he/she doesn't go bust (> 21 total score), the dealer goes bust or if the player has a higher score than the dealer but less than 22. 

#### Randomization of cards  
In this application, I've create a random number generator with a seed value, using the clock (chrono) to get a different sequence each time as opposed to the solution using the C-style ‘std::time’ method. I also use “mt19937” (a “Mersenne Twister” generator) in combination with the  “uniform_int_distribution” which handles the process of mapping random numbers to the distribution of interest.  

## Dependencies  
* Xcode  
 
## Setup  
To test this application you need to fork it to your own GitHub account and clone it to your local workspace. Once you have cloned the repository, you will be able to run the build inside of Xcode.  
  
If you do not have Xcode, you may also want to attempt to run the application directly in your CLI by entering the following command:  
```
$ g++ -std=c++11 main.cpp game_info.cpp game_play.cpp
$ ./a.out
```

## Instructions  
The game instructions are provided with the game itself.  

## Updates/Improvements  
Due to time constraints the current version of this application does not support the user choosing to convert the 'Ace' card to 1 or 11, thus it is by default 1.

## Acknowledgement  
Thank you to Paradox Interactive's [GamesByHer](https://gamedevcourse.paradoxinteractive.com/) initiative for creating this challenge for me.