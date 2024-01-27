# Projet : Minitalk

## 🏁 Objectif 🏁

Développer un programme de communication client-serveur utilisant les signaux UNIX, en se concentrant sur la gestion de multiples requêtes clients et la transmission efficace des messages par communication bit par bit (opérations binaires).

## 🚀 Utilisation 🚀

```shell
git clone git@github.com:nfauconn/minitalk.git
cd minitalk/Project
make
```

Démarrer le serveur :
```shell
./server
```

Dans un autre terminal, utilisez le client :
```shell
./client <PID_serveur> <message>
```

## 💡 Compétences 💡

- **Communication Binaire et Opérations Bit à Bit :** Communication bits par bits entre le client et le serveur, encodage et décodage des messages par des opérations binaires

- **Gestion des Signaux et Communication Inter-Processus :** Signaux UNIX pour la CIP, gestion des signaux personnalisés pour une transmission de données efficace

- **Gestion des Erreurs :** Vérification et réponse aux erreurs, assurant un comportement prévisible du programme dans divers scénarios

- **Synchronisation et Timing :** Synchronisation entre les processus client et serveur, gestion du timing de l'envoi et de la manipulation des signaux

- **Gestion des Ressources :** Aucune fuite de ressources et performance optimale pendant la communication

- **Compétences en Programmation de Bas Niveau :** Gestion de la mémoire, pointeurs et appels système à bas niveau


## 📋 Sujet 📋

### Instructions Communes

- **Langue** : Le projet doit être écrit en C.
- **Conformité à la Norme** : Le code doit adhérer à la Norme de l'école.
- **Gestion des Erreurs** : Les programmes ne doivent pas se terminer de manière inattendue (par exemple, segmentation fault, bus error, double free). De tels incidents rendront le projet non fonctionnel et entraîneront une note de 0.
- **Gestion de la Mémoire** : Toute mémoire allouée sur le tas doit être correctement libérée. Les fuites de mémoire ne sont pas tolérées.
- **Exigences du Makefile** :
   - Doit compiler les fichiers sources pour produire le résultat requis avec les flags `-Wall`, `-Wextra` et `-Werror`.
   - Ne doit pas relinker.
   - Doit contenir les règles `$(NAME)`, `all`, `clean`, `fclean`, et `re`.

### Partie Obligatoire

- Une variable globale autorisée
- Fonctions autorisées : `write` - `signal` - `sigemptyset` - `sigaddset` - `sigaction` - `kill` - `getpid` - `malloc` - `free` - `pause` - `sleep` - `usleep` - `exit`
- Signaux autorisés: `SIGUSR1` - `SIGUSR2`

Créer un programme de communication sous la forme d'un client et d'un serveur.

- Le serveur doit être lancé en premier. Après son lancement, il doit afficher son PID.
- Le client prend deux paramètres :
  - Le PID du serveur.
  - La chaîne à envoyer.
- Le client doit envoyer la chaîne passée en paramètre au serveur. Une fois la chaîne reçue, le serveur doit l'imprimer.
- Le serveur doit afficher la chaîne assez rapidement. 1 seconde pour afficher 100 caractères est bien trop long.
- Le serveur doit être capable de recevoir des chaînes de plusieurs clients à la suite sans avoir besoin de redémarrer.
- La communication entre le client et le serveur doit se faire uniquement à l'aide de signaux UNIX.

### Partie Bonus 

- Le serveur reconnaît chaque message reçu en renvoyant un signal au client.
- Support des caractères