# Advanced Programmings AT3

## Net code

Here are some things that you should probably need to know when writing net code (networking code), so that when you go
to view mine, you won't be overwhelmed. 

### File descriptions

A file descriptor is a number that points to a file table. If you find the process id for the code that is created when 
you build and execute this code, you can actually find the file in /proc/<proc id>/fd. This file is a random, unique 
number that is created by Linux or whatever OS that links said number to a file. In this case, we are creating a file 
which will store the retrieved request into /proc, that is why it returns an integer inside the socket() call. If you 
understand this, I recomend you read the man pages for `socket(2)`, `bind(2)`, `listen(2)`, `accept(2)`, and `close()`