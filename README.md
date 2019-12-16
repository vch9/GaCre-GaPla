# GaCre GaPla - Project C++
# LOA Université de Paris

By Benjamin Viau and Valentin Chaboche, supervised by Jean-Baptiste Yunès

## Purpose
The purpose of this project is to develop two applications:
 * gc to either create .game or .board
 * gp to either play .game or .board

## Install

To compile the project, you must follow this instructions:
```sh
  $ git clone git@github.com:vch9/GaCre-GaPla.git
  $ cd GaCre-GaPla
  $ make
```

## Game Creator

To create a .board run 
```sh
    $ ./gc (name).board
```
The (name).board will be stored in root/boards/

To create a .game run
```sh
    $ ./gc (name).game (name').board ..
```

Game creator will search for (name').board in root/boards/ and build the (name).game in root/games/

## Game Player

To play .game run
```sh
    $ ./gp (name).game
```

To try a board run
```sh
    $ ./gp (name).board
```

Game player will search for boards in roots/boards/ and games in root/games/


## What is this game ?
```
XXXXXXXXXXXXXXXXXXXX
X          *X  s   X
XJ    u      X     X
X             X    X
X      $           X
XXXXXXXXXXXXXXXX-XXX
Stage 1
Teleports: 1
Diamonds: 0
Arrows: 2
```

Player representend by 'J', your goal is to reach the next door '-', but it's for now closed, you need to collect at least one diamond ('$') to open the door.


## List of objects
    * Arrow:
      - '~' ->
        It's an arrow shot by the player, that's apply 50 damages on monsters,
        it can also destroy traps
    * Diamond:
      - '$' ->
        Only the player can collect diamond, one diamond is required in each stage to open the next door
    * Door:
      - '+' or '-'
        Entering a door changes the current stage, if the door is '+' it's open, you need to collect one diamond to open a '-' door
    * Monster:
      - 's' ->
        A monster protecting it's stage, it will chase you, but you can kill him with traps, arrows (or you can just run away)
    * Quiver:
      - ':' ->
        The quiver will give you 5 more arrows when you collect it
    * Wall:
      - 'X' ->
        It's a wall
    * Charge:
      - '*' ->
        The charge will give you 1 more teleport when you collect it
    * Trap:
      - 'o' ->
        You should not step on the trap, but you can destroy it by shooting an arrow at it
        
## List of commands
    * z -> move up
    * q -> move left
    * d -> move right
    * s -> move down
    * a -> move top left
    * e -> move top right
    * w -> move bot left
    * c -> move bot right
    * space -> shoot arrow
    * t -> teleport
