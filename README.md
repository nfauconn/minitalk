[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/minitalk/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/minitalk/blob/master/README.fr.md)

# Project: Minitalk

## 🏁 Goal 🏁

Developing a client and server communication program using UNIX signals, focusing on handling multiple client requests and efficient message transmission through bit-by-bit communication (binary operations).

## 🚀 Usage 🚀

```shell
git clone git@github.com:nfauconn/minitalk.git
cd minitalk/Project
make
```

Start the server:
```shell
./server
```

In another terminal, use the client:
```shell
./client <server_PID> <message>
```

## 💡 Skills 💡

- **Binary Communication and Bitwise Operations:** Bit-level communication between client and server, message encoding and decoding through bitwise operations

- **Signal Handling and Inter-Process Communication:** UNIX signals for IPC, managing custom signal handlers for efficient data transmission

- **Error Handling:** Comprehensive error checking and response mechanisms, ensuring the program behaves predictably under various scenarios

- **Synchronization and Timing:** Proper synchronization between client and server processes, managing the timing of signal sending and handling

- **Resource Management:** No resource leaks and optimal performance during communication

- **Low-Level Programming Proficiency:** Memory, pointers, and system calls at a low level.


## 📋 Project Instructions 📋

### Common Instructions

- **Language**: The project must be written in C.
- **Norm Compliance**: Code must adhere to the Norm of the school.
- **Error Handling**: Programs should not exit unexpectedly (e.g., segmentation fault, bus error, double free). Such incidents will render the project non-functional and result in a score of 0.
- **Memory Management**: All heap allocated memory must be properly freed. Memory leaks are not tolerated.
- **Makefile Requirements**:
   - Must compile source files to the required output with flags `-Wall`, `-Wextra`, and `-Werror`.
   - Must not relink.
   - Must contain the rules `$(NAME)`, `all`, `clean`, `fclean`, and `re`.

### Mandatory Part

- One global variable authorized
- Authorized functions: `write` - `signal` - `sigemptyset` - `sigaddset` - `sigaction` - `kill` - `getpid` - `malloc` - `free` - `pause` - `sleep` - `usleep` - `exit`
- Authorized UNIX signals: `SIGUSR1` and `SIGUSR2`

Create a communication program in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
	- The server PID.
	- The string to send.
- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. 1 second for displaying 100 characters is way too much.
- The server should be able to receive strings from several clients in a row without needing to restart.
- The communication between the client and the server has to be done only using UNIX signals.

### Bonus Part 

- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support
