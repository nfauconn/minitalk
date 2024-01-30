[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/minitalk/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/minitalk/blob/master/README.fr.md)

# Minitalk

*Binary Communication and Bitwise Operations* • *Signal Handling and Inter-Process Communication* • *Error Handling* • *Synchronization and Timing* • *Resource Management* • *Low-Level Programming Proficiency*

## Description

A client and server communication program using UNIX signals, focusing on handling multiple client requests and efficient message transmission through bit-by-bit communication (binary operations).


| Program name | `server` and `client` |
| -- | -- |
**Language** | C
**Authorized functions** | `write` `signal` `sigemptyset` `sigaddset` `sigaction` `kill` `getpid` `malloc` `free` `pause` `sleep` `usleep` `exit`
**Authorized UNIX signals** |`SIGUSR1` and `SIGUSR2`

- The server is able to receive strings from several clients in a row without needing to restart.
- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support


## Usage

```shell
git clone git@github.com:nfauconn/minitalk.git
cd minitalk/Project
make
```

#### Start the server:
```shell
./server
```

#### In another terminal, use the client:
```shell
./client <server_PID> <message>
```

