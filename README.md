# projectILE
![projectILE Logo](https://i.imgur.com/3UAInCe.png)

**projectILE is a C++ program created to realistically calculate environmental effects on projectiles and their trajectory.**

projectILE originally created as a personal project of [*Tux Bux*](https://www.youtube.com/@tuxbux999), now moved under [*Primiçerus Software*](https://www.youtube.com/@primicerius-software
) and will recieve new updates.

## CURRENT VERSION = Alpha V1.0

### THIS VERSION OFFERS
Terminal Based (text) interface
Error tolerance, air temperature and air density can be changed in program.
Have two *"simulations"*:
**1-** Calculates launch angle needed for send the projectile *x* meters away.
**2-** Making an *"artifical shot"*, it returns these information:
  How far projectile landed away from it's launch point (meteres),
  Maximum altitude the projectile reached during flight (meters),
  Amount of time that projectile spend from launch to landing (seconds).

### USER NEED GIVE THESE INFORMATIONS ABOUT PROJECTILE
Muzzle velocity, (m/s)
Diaemter, (mm)
Mass. (kg)

### PREDETERMINATED VARIABLES BY SYSTEM
*(These variables still can be changed in the code, they mostly left there because they are needed to make calculations but changing them make very little difference at results.)*
How drag coefficent is the projectile = 0.295
Gas constant = 287.05 Joules/(Kilogram*Kelvin) (Default gas constant for sea-level.)
*Accelaration of* Gravity = 9.807 m/s<sup>2</sup> (Generic Earth gravity at sea-level.)

### THIS VERSION CALCULATES
Air density
Radius of the projectile
Area of the projectile

### ABOUT SIMULATION
The simulation are all same, in launch angle calculator, the program just keep make shoots from 1° to 89° to find the best angle.
Angle degree start from 1.00 and adding 0.01 in each loop,
and of course updates the velocity, speed and position of the projectile.
while doing this, it squuezes all effects into a single variable called drag_force, 
it calculates how air density effects on projectile, based on the information about projectile. Such as how drag coefficent is it, how large it's area and how fast it's going.

### KNOWN BUGS/PROBLEMS
The variable called "diameter" is first made as "caliber" as it's a shell or bullet, they are close things, but not same. It'll fixed in next updates.

### PLANNED FEATURES
2D Interface,
More unit support, (Fahrenheit, foot etc.)
Allowing user change more of the variables in the program,
Air temperature and density based on altitude,
Rocket-like objects, (Objects that accelerate over time towards to air, store fuel etc.)





