# Advanced Programmings AT3

## Net code

Here are some things that you should probably need to know when writing net code (networking code), so that when you go
to view mine, you won't be overwhelmed. 

### File descriptions

- A file descriptor is a number that points to a file. 
- If you find the process id for the code that is created when 
you build and execute this code, you can actually find the file in /proc/<proc id>/<id returned from `bind(2)` or 
equivalent net functions>. 
- This file is a random, unique  number that is created by Linux or whatever OS that links said 
number to a file. 
- In this case, we are creating a file which will store the retrieved request into /proc, that is why it 
returns an integer inside the socket() call. 
- If you understand this, I recomend you read the man pages for `socket(2)`, 
`bind(2)`, `listen(2)`, `accept(2)`, and `close()`. This is relevant to `Server::Serve(1)` in `Server.cpp`

### TCP Linger / Time-Wait

- When you open a server, it opens up a port as you know
- When the application closes, and thus the socket is closed too, the socket "can go into a TIME-WAIT state on the end 
that initiated the close" - [Lewis Van Winkle](https://handsonnetworkprogramming.com/articles/bind-error-98-eaddrinuse-10048-wsaeaddrinuse-address-already-in-use/)
- When you use `SO_REUSEADDR` (socket, reuse address), you can pretty much override the old one
- Example in `Server::Serve(1)`:
```c++
int res = 1;
if (setsockopt(serverFileDescriptor, SOL_SOCKET, SO_REUSEADDR,
               (void*)&res, sizeof(res)) < 0) { }
```