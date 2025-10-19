# Projet TP2 - Manipulation d'Entiers Longs

## Description

Ce projet implémente un système de manipulation d'entiers longs (nombres entiers de grande taille) en C++. Il permet d'effectuer des opérations arithmétiques (addition, soustraction, multiplication) sur des nombres pouvant contenir jusqu'à 20 chiffres.

## Auteurs

- Simon l'Hinguerat
- Jean-Marc KERVIL

## Structure du Projet

### Fichiers Sources

#### 📄 [entierlong.h](entierlong.h)
Définit la structure de base `t_EntierLong` qui représente un entier long avec :
- Un booléen pour le signe (`negatif`)
- Un tableau de 20 chiffres (`chiffres[MAXCHIFFRES]`)

#### 📄 [lit_ecrit.h](lit_ecrit.h) / [lit_ecrit.cpp](lit_ecrit.cpp)
Contient les fonctions d'entrée/sortie :
- [`afficheEntierLong()`](lit_ecrit.cpp) : Affiche un entier long à l'écran
- [`litEntierLong()`](lit_ecrit.cpp) : Lit un entier long depuis le clavier

#### 📄 [utilitaires.h](utilitaires.h) / [utilitaires.cpp](utilitaires.cpp)
Fonctions utilitaires de conversion et comparaison :
- [`inttolong()`](utilitaires.cpp) : Convertit un `int` en `t_EntierLong`
- [`longtoint()`](utilitaires.cpp) : Convertit un `t_EntierLong` en `int`
- [`Egalite()`](utilitaires.cpp) : Test d'égalité avec signe
- [`EgaliteAbs()`](utilitaires.cpp) : Test d'égalité en valeur absolue

#### 📄 [operations.h](operations.h) / [operations.cpp](operations.cpp)
Implémente les opérations arithmétiques :
- [`addition_ms()`](operations.cpp) : Addition sans gestion du signe
- [`soustraction_ms()`](operations.cpp) : Soustraction sans gestion du signe
- [`add()`](operations.cpp) : Addition avec gestion des signes
- [`sous()`](operations.cpp) : Soustraction avec gestion des signes
- [`mult()`](operations.cpp) : Multiplication avec gestion des signes
- [`suiteadd()`](operations.cpp) : Fonction auxiliaire pour la multiplication

#### 📄 [main.cpp](main.cpp)
Programme principal qui teste toutes les fonctionnalités du projet.

### Fichiers de Configuration

#### 📄 [makefile](makefile)
Fichier de compilation du projet. Compile tous les fichiers sources et génère l'exécutable `prog`.

#### 📁 `.vscode/`
Configuration pour Visual Studio Code :
- [settings.json](.vscode/settings.json) : Paramètres de l'éditeur
- [tasks.json](.vscode/tasks.json) : Tâche de compilation
- [launch.json](.vscode/launch.json) : Configuration de débogage

## Compilation et Exécution

### Compilation
```bash
make
```

### Exécution
```bash
./prog
```

## Utilisation

Le programme vous demande de saisir deux nombres entiers (positifs ou négatifs) et effectue automatiquement les opérations suivantes :

1. Test d'égalité avec signe
2. Test d'égalité en valeur absolue
3. Addition sans signe
4. Addition avec signe
5. Soustraction sans signe
6. Soustraction avec signe
7. Multiplication avec signe

### Exemple d'utilisation

```
Bonjour à vous
Entrez un entier positif ou négatif
-1234
Vous avez entré -1234
Entrez un entier positif ou négatif
567
Vous avez entré 567
...
```

## Limitations

- Les nombres sont limités à 20 chiffres (défini par `MAXCHIFFRES`)
- La multiplication utilise une conversion vers `int`, ce qui peut limiter les valeurs très grandes

## License

Copyright (c) 2025