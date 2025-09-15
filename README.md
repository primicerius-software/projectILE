# projectILE
![projectILE Logo](https://i.imgur.com/nw7fnqm.png)

**projectILE is a C++ program created to realistically calculate environmental effects on projectiles and their trajectory.**

projectILE originally created as a personal project of [*dev.as4*](https://www.youtube.com/@dev.as4), now moved under [*Primiçerus Software*](https://www.youtube.com/@primicerius-software
) and will recieve new updates.

## THIS PROGRAM REQUIRES SDL LIBRARY!
This program works with SDL Library and the following extensions (only Beta V1.0 and newer versions need SDL):

SDL_Image

SDL_ttf

SDL_mixer

**See "Technical Details" section for more information about the program.**

## CURRENT VERSION = Beta V1.0
Previous versions:

Alpha V1.0

### THIS VERSION OFFERS
**Finally graphic interface!**

*(We're aware some texts are not aligned and button graphics are cripsy, but Primiçerius Software was on it's way to step in bigger project, the graphic interface update for projectILE made in rush. Just make it enough to work.)*

- dev.as4

Error tolerance, air temperature and air density can be changed in program.

Have two *"simulations"*:

**1-** Calculates launch angle needed for send the projectile *x* meters away.

**2-** Making an *"artifical shot"*, it returns these information:

  How far projectile landed away from it's launch point (meteres),
	
  Maximum altitude the projectile reached during flight (meters),
	
  Amount of time that projectile spend from launch to landing (seconds),

### USER NEED GIVE THESE INFORMATIONS ABOUT PROJECTILE
Muzzle velocity, (m/s)

Diameter, (mm)

Mass. (kg)

### PREDETERMINATED VARIABLES BY SYSTEM
How drag coefficent is the projectile = 0.295

Gas constant = 287.05 Joules/(Kilogram*Kelvin) 
> (Default gas constant for sea-level.)

*Accelaration of* Gravity = 9.807 m/s<sup>2</sup> 
> (Generic Earth gravity at sea-level.)

### ABOUT SIMULATION
The simulation are all same, in launch angle calculator, the program just keep make shoots from 1° to 89° to find the best angle. Angle degree start from 1.00 and adding 0.01 in each loop.

And of course updates the velocity, speed and position of the projectile, while doing this, it squezes all effects into a single variable called drag_force.

It calculates how air density effects on projectile, based on the information about projectile. Such as how drag coefficent is it, how large it's area and how fast it's going.

### KNOWN BUGS/PROBLEMS
Some texts aren't aligned well and button graphics look crispy.

No memory leaks reported, contact us if you had *(most of them caused from text.)*

### PLANNED FEATURES
More unit support, (Fahrenheit, foot etc.)

Allowing user change more of the variables in the program,

Air temperature and density based on altitude,

Rocket-like objects, (Objects that accelerate over time towards to air, store fuel etc.)

A document explain the *"mathematics"* of this program.

### TECHNICAL DETAILS

Code written, built and compiled in Geany IDE. Using G++ compiler.

Uses SDL library (SDL2.30.0) and the extensions: SDL_image, SDL_ttf, SDL_mixer.

Also string, cmath, iomanip and iostream libraries used in the program, which your compiler probably have them.

Compile command: g++ -Wall -c "%f" "sdl2-config --cflags"
> When compiling, i had a error about system can't find SDL.image.h, i believe it's a Geany (IDE) based problem, program still runs as expected.

Build command: g++ -Wall -o "%e" "%f" $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf -lSDL2_mixer

Execute command: "./%e"

The program tested in Linux Mint 22.1 'Xia' Cinnamon, Wine and Proton environments.





