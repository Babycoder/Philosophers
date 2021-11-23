# Philosophers
1337 (42Network) project about inter-process communication. A program that can monitor multiple instances of itself, either processes or threads, using mutexes.

Final grade : 100/100
Mandatory part : 100/100

Concept
Philosophers (represented by parts of a program) sit around a table, with a big plate of spaghetti at its center. They each have a fork, but they need two forks to eat ; so they need to borrow their neighbor's fork to eat.

Of course, if they borrow a neighbor's fork, the neighbor can't use the fork. The processes / threads must communicate, to know the state of the forks (and of the other philosophers) at all times. There must also be a parent process that monitors everything.

One, Two, Three...
./philo does this using threads as philosophers, and mutexes as forks.

<img src="https://camo.githubusercontent.com/f5535480b4f5213ea50ba8e09841e7ae5185785167a6eda22a1beae321af39b2/68747470733a2f2f692e696d6775722e636f6d2f4f4668716e71772e706e67">

<h1>How to use it :</h1>
Using make in the philodirectory will create the philo executable.

You run it specifying, in order :

The number of philosophers
The time in milliseconds until a philosopher dies from starvation
The time in milliseconds it takes for a philosopher to eat
The time in milliseconds it takes for a philosopher to sleep
(Optional) The number of meals before the program stops
./philo 6 400 200 100 5
Here, the program will create 6 philosophers, who will die if they go without eating for 400 milliseconds. It takes them 200 milliseconds to eat, and 100 milliseconds to sleep. The program will stop after each philosopher has had 5 meals (or if any one of them dies prematurely).
