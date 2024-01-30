[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/minitalk/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/minitalk/blob/master/README.fr.md)

# Minitalk

A client and server communication program using UNIX signals, focusing on handling multiple client requests and efficient message transmission through bit-by-bit communication (binary operations).

## Usage

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


## Description

| Programs' names | `server` and `client` |
| -- | -- |
**Language** | C
**Norm Compliance** | Code must adhere to the Norm of the school.
**Authorized functions** | `write` `signal` `sigemptyset` `sigaddset` `sigaction` `kill` `getpid` `malloc` `free` `pause` `sleep` `usleep` `exit`
**Authorized UNIX signals** |`SIGUSR1` and `SIGUSR2`

- The server is be able to receive strings from several clients in a row without needing to restart.
- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support

## Skills

- **Binary Communication and Bitwise Operations:** Bit-level communication between client and server, message encoding and decoding through bitwise operations

- **Signal Handling and Inter-Process Communication:** UNIX signals for IPC, managing custom signal handlers for efficient data transmission

- **Error Handling:** Comprehensive error checking and response mechanisms, ensuring the program behaves predictably under various scenarios

- **Synchronization and Timing:** Proper synchronization between client and server processes, managing the timing of signal sending and handling

- **Resource Management:** No resource leaks and optimal performance during communication

- **Low-Level Programming Proficiency:** Memory, pointers, and system calls at a low level.
