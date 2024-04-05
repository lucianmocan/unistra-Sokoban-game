# Sokoban project (Course : Development techniques)

# To launch the game:
1. Clone this repository.
2. Compile SDL2 using `make install_dependencies` (I had some trouble back then and I had to install SDL2 globally).
3. Compile the program with `make`.
4. Launch the game, in the command line with : `./sokoban` or `./sokoban --console`; or with the SDL2 interface : `./sokoban --sdl2`.

You can also generate docs with doxygen if you may wish to do so :) `make doc`.

To archive the files inside the project: `make archive`.


### (Original, in French) Projet Sokoban (Techniques de dévéloppement L2S3)

### Pour lancer le programme:
1. Faire une clone de ce dépôt.
2. Compiler la bibliothèque SDL2 avec la commande "make install_dependencies" (il est possible qu'il
   sera nécéssaire d'installer la bibliothèque SDL2 globalement).
3. Compiler le programme avec "make".
4. Lancer le programme, soit dans le Terminal avec la commande "./sokoban" ou "./sokoban --console";
   soit avec l'interface SDL2 avec la commande "./sokoban --sdl2".


### Compilateur C utilisé:
Apple clang version 13.0.0 (clang-1300.0.27.3) pour la première partie du TP
gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) pour l'intégration avec SDL2

### Pour la documentation:
doxygen 1.9.5
