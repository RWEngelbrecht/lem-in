# lem-in

The first group project for the algos elective branch at WeThinkCode. 

The objective of this project is to write a program that takes input from stdout, which then builds an "ant farm" map. By then applying an algorithm, n amount of ants must move from the starting "room" to the end as quickly as possible.
Each room may only hold one "ant" at a time, except for the start and end rooms. An ant may only move once per turn.

An example of the input:

3         (number of ants)

##start   (command specifying the next line as the start room)

A 1 0     (where A is room's name, 1 its x position, 0 its y position)

##end     (command specifying the next line as the end room)

B 5 0

C 9 0

D 13 0

A-C       (room A linked to room C)

C-D

D-B

The resulting "farm" will look like this:

[A]-[C]-[D]-[B]

An example of the output:

L1-C                (an ant moves from room 1 to room 2)

L1-3 L2-2           

L1-1 L2-3 L3-2

L2-1 L3-3

L3-1
