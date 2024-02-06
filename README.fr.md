[![en](https://img.shields.io/badge/lang-en-pink.svg)](https://github.com/nfauconn/minitalk/blob/master/README.md)
[![fr](https://img.shields.io/badge/lang-fr-purple.svg)](https://github.com/nfauconn/minitalk/blob/master/README.fr.md)

*Langage de programmation C* •*Communication binaire et opérations bit à bit* • *Gestion des signaux et communication inter-processus* • *Gestion des erreurs* • *Synchronisation et temporisation* • *Gestion des ressources* • *Programmation de bas niveau*

# Minitalk

## Description

Un programme de communication client-serveur utilisant les signaux UNIX, se concentrant sur la gestion de multiples requêtes clients et la transmission efficace de messages par communication bit par bit (opérations binaires).

| Clé | Valeur |
| -- | -- |
| Nom du programme | `server` et `client` |
**Langue** | C
**Fonctions autorisées** | `write`, `signal`, `sigemptyset`, `sigaddset`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`
**Signaux UNIX autorisés** | `SIGUSR1` et `SIGUSR2`
**Variables globales autorisées** | 1

- Le serveur est capable de recevoir des chaînes de plusieurs clients à la suite sans avoir besoin de redémarrer.
- Le serveur accuse réception de chaque message reçu en renvoyant un signal au client.
- Support des caractères Unicode

## Utilisation

```shell
git clone git@github.com:nfauconn/minitalk.git
cd minitalk/Project
make
```

#### Démarrer le serveur :
```shell
./server
```

#### Dans un autre terminal, utiliser le client :
```shell
./client <server_PID> <message>
```