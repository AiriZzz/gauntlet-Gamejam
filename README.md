# GAUNTLET GAME JAM

## GAME TITLE: Will it parade?

### A puzzle game about ordering and sorting the marching unit before the parade. You play as a Marching Coordinator new to the job. Every day or level, in this case, you will get a request from your boss to sort the marching order. Figure out the order from the request,confirm your guesses and move on to the next day. Happy sorting :D

#### Throughout Merdeka day until Malaysia day, there are almost countless parades happening everywhere. And when I thought about the theme, I kept going back to the parades and thought, why not a puzzle game where you guess and sort the units in a parade?

## HOW TO RUN THE GAME.

### in the interminal, type; make re && ./game

## LIBRARY USED.

### I used the Raylib library as it is the safest route and there is a lot of documentation for reference. It is useful for game development projects. With suggestion from peers, I committed to using the library as a tool. I do not think I did anything that the library has not given. But if I say I was proud of something, it would be figuring out the zone. The idea to snap the unit was not mine and was a peer's idea. But implementing it and making it work was probably my proudest moment, until I introduced another zone and practically butchered the code.

## WEEK 1 shows up in...

### Mostly in my unorganised, super unoptimised OOP architecture. I used unique pointers for level manager to handle the levels and units. Const on read only method, like Level.Draw() and GetIsPuzzledSolved(). Class designs from Week 1 also present when creating Units. Planned on using design patterns and algorithm but I had to cut corners due to time constraints.

## What I cut

### Originally, the idea was that each level would be random, so that every play through is not the same. The player would go through seven days planning the parade with different requests from the text. Then on the seventh day or the day of the parade. You'll get the result of how you interpret the request each day and how much it was right. I scrapped that idea when I was looking into how to make a big data struct that would have all the planned text, and random with unit names. I got overwhelmed and decided to maybe go for a smaller, much more manageable architecture.

### I also wanted to try tweening for better UI but implementing it was hard for me to make sense of it. So I went with what we have now