# GaCre GaPla - Project C++
# LOA Université de Paris

By Benjamin Viau and Valentin Chaboche, supervised by Jean-Baptiste Yunès

## Client
To compile the client, you must follow this instruction:
```sh
    $ make
```

## List of commands
    * Send
        $ ./client -send -board name.board
        $ ./client -send -game name.game
    You will send either name.board or name.game to the server
    
    * List
        $ ./client -list -game
        $ ./client -list -board
    The server will send you the list of either games or boards that you can download
    
    * Request
        $ ./client -request -game name.game
        $ ./client -request -board name.board
    Ask the server to download name.game or name.board
