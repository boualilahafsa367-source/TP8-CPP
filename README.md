# Exercice 1 : Gestion de périphériques audio

Figure 1 : Résultat de la compilation et de l'exécution de l'exercice 1
<img width="1920" height="858" alt="Screenshot (1269)" src="https://github.com/user-attachments/assets/e0adb865-1d9d-4170-bfe8-86cfc7991e16" />

Dans cet exercice, nous avons créé une classe abstraite SortieAudio contenant trois méthodes virtuelles pures : ouvrir(), jouer() et fermer(). 
Nous avons ensuite développé trois classes dérivées : HautParleur, CasqueBT et SortieHDMI, chacune avec sa propre implémentation.
Une fonction tester() permet d'utiliser les périphériques de manière polymorphe à travers des pointeurs de la classe mère.
Un tableau dynamique stocke les différents objets.
Enfin, le destructeur virtuel et les instructions delete et delete[] assurent une libération correcte de la mémoire.

# Exercice 2 : Moteur de rendu 3D

Figure 2 : Résultat de la compilation et de l'exécution de l'exercice 2
<img width="1920" height="657" alt="Screenshot (1271)" src="https://github.com/user-attachments/assets/b27a6102-97bb-4063-b87c-30ae2ca6e992" />

Dans cet exercice, nous avons créé une structure Vec3 pour représenter les coordonnées dans l'espace 3D.
La classe abstraite Lumiere définit la méthode virtuelle pure intensite().
Trois classes dérivées représentent les lumières directionnelle, ponctuelle et spot, avec des calculs d'intensité adaptés à chacune.
Nous avons utilisé std::vector et std::unique_ptr pour stocker et gérer automatiquement les différentes sources lumineuses.
La fonction calculerEclairage() additionne les intensités des lumières pour plusieurs points de test.
Cet exercice met en pratique le polymorphisme et la gestion automatique de la mémoire.

# Exercice 3 : Système de plugins de traitement de texte

Figure 3 : Résultat de la compilation et de l'exécution de l'exercice 3
<img width="1920" height="925" alt="Screenshot (1273)" src="https://github.com/user-attachments/assets/0e9f9e74-8f01-4aac-8fa2-6e474985dbf3" />

Dans cet exercice, nous avons défini une classe abstraite Plugin contenant les méthodes virtuelles pures nom() et traiter().
Trois plugins dérivés ont été développés : CorrecteurOrthographique, TraducteurAnglais et AnalyseurStyle.
Chaque plugin réalise un traitement particulier sur le texte saisi par l'utilisateur.
Une factory statique creerPlugin() permet de créer les plugins selon le type demandé. 
Les objets sont stockés dans un std::vector de pointeurs intelligents std::unique_ptr. 
Le programme applique successivement les traitements et affiche le texte après chaque étape, illustrant ainsi le polymorphisme et l'extensibilité du système.
