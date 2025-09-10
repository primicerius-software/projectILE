#include <iostream>
#include <cmath>
#include <iomanip>
//projectILE Alpha V1.0
//projectILE MADE BY TUX BUX FOR PRIMIÇERIUS (SOFTWARE)
//2025
//GENERAL PUBLIC LICENSE V3

double air_pressure = 101325;
double temp_celcius = 15.0;
double error_tolerance = 0.5;

int artifical_shot() {
	//USER INPUT VARIABLES
	double velocity, angle_deg, diameter, mass;
	//LAUNCH ANGLE AND IT'S CORRECTION
	std::cout << " \n";
	std::cout << "Enter the launch degree (between 1° and 89° degrees)";
	std::cin >> angle_deg;
	if (angle_deg == 90) {
        std::cout << "This shot will go straight to the air.\n";
        std::cout << "It'll land on just some milimeters away where it's launched.\n";
        return 0;
    } 	
    if (angle_deg >= 91 && angle_deg <= 180) {
        std::cout << "This shot will go to backwards.\n";
        return 0;
    } 
    if (angle_deg >= 181 && angle_deg <= 359) {
        std::cout << "This shot will go to underground.\n";
        return 0;
    } 
    if (angle_deg == 0 || angle_deg == 360) {
        std::cout << "This shot will go to paralel to ground.\n";
        return 0;
    }	
    if (angle_deg > 360) {
        std::cout << "Please enter a value between 1° and 89°\n";
        return 0;
    }
    
    //OTHER USER INPUT
	std::cout << "Enter muzzle velocity of the projectile (m/s)";
	std::cin >> velocity;
	std::cout << "Enter diameter of the projectile (mm)";
	std::cin >> diameter;
	std::cout << "Enter weight of the projectile (kg)";
	std::cin >> mass;
	
	//UNIT ARRANGEMENTS
	double temp_kelvin = temp_celcius + 273.15;
	
    //ENVIRONMENTAL EFFECTS
	const double R = 287.05; // gas constant for dry air
	double air_density = air_pressure / (R * temp_kelvin);
    const double gravity = 9.81; //generic earth gravity

   //PROJECTILE CALCULATION
    const double radius = diameter / 2.0 / 1000.0;
    const double area = M_PI * radius * radius;
    const double drag_coefficient = 0.295; //generic for bullet-like shapes

    //LAST CALC.
    const double angle_rad = angle_deg * M_PI / 180.0;
    double vx = velocity * std::cos(angle_rad);
    double vy = velocity * std::sin(angle_rad);

    //STARTING POS.
    double x = 0.0;
    double y = 0.0;

    //TIME (SECONDS)
    const double dt = 0.01;
    
    //END USER INFO.
    double max_height = y;
    double total_time = 0.0;

     //SIM LOOP
    while (y >= 0.0) {
        double speed = std::sqrt(vx * vx + vy * vy);
        double drag_force = 0.5 * air_density * drag_coefficient * area * speed * speed;
        
        if (y > max_height) {
			max_height = y;
		}

        //DRAG EFFECT ON PROJECTILE
        double ax = -drag_force * (vx / speed) / mass;
        double ay = -drag_force * (vy / speed) / mass - gravity;

        //VELOCITY UPDATE
        vx += ax * dt;
        vy += ay * dt;

        //POSITION UPDATE
        x += vx * dt;
        y += vy * dt;
        
        total_time += dt;
    }
    
	//END USER INFO
	std::cout << " \n";
    std::cout << "Projectile landed " << x << " meters away from it's launch point.\n";
    std::cout << "Projectile reached maximum altitude of " << max_height << " meters.\n";
    std::cout << "Projectile spend " << total_time << " seconds from launch to landing.\n";
    return 0;
}

int launch_angle_calc() {
	//USER INPUT VARIABLES
	double velocity, target, diameter, mass;
	std::cout << " \n";
	std::cout << "Enter how far target away (meters)";
	std::cin >> target;
	std::cout << "Enter muzzle velocity of the projectile (m/s)";
	std::cin >> velocity;
	std::cout << "Enter diameter of the projectile (mm)";
	std::cin >> diameter;
	std::cout << "Enter weight of the projectile (kg)";
	std::cin >> mass;
	
    //UNIT ARRANGEMENTS
    double temp_kelvin = temp_celcius + 273.15;
    
    //ENVIRONMENTAL EFFECTS
	const double R = 287.057; //DEAFULT GAS CONSTANT FOR DRY AIR
	double air_density = air_pressure / (R * temp_kelvin);
    const double gravity = 9.807; //GENERIC EARTH GRAVITY

    //PROJECTILE CALCULATION
    double radius = diameter / 2.0 / 1000.0;
    double area = M_PI * radius * radius;
    double drag_coefficient = 0.295; //generic for bullet-like shapes
    
    double best_error_low = 9e9;
    double best_error_high = 9e9;
    double best_angle_low = 0.0;
    double best_angle_high = 0.0;
    
    //TIME (SECONDS)
    double dt = 0.01;

    //SIMULATION
    for (double angle_deg = 1.0; angle_deg <= 89.0; angle_deg += 0.01) {
		//CONVERT ANGLE TO RADIANS
		double angle_rad = angle_deg * M_PI / 180.0;

		//START POSITION AND VELOCITY
		double x = 0.0;
		double y = 0.0;
		double vx = cos(angle_rad) * velocity;
		double vy = sin(angle_rad) * velocity;

		//SHELL SIM
		while (y >= 0.0) {
			//SPEED CALC.
			double speed = std::sqrt(vx * vx + vy * vy);

			//DRAG FORCE CALC.
			double drag_force = 0.5 * air_density * drag_coefficient * area * speed * speed;

			//CALC. ACCELERATION FROM DRAG
			double ax = -drag_force * (vx / speed) / mass;
			double ay = -gravity - (drag_force * (vy / speed) / mass);

			//VELOCITY UPDATE
			vx += ax * dt;
			vy += ay * dt;

			//POSITION UPDATE
			x += vx * dt;
			y += vy * dt;
		}
		
		double error = std::abs(x - target);
		
		if (error <= error_tolerance) {
			if (best_angle_low == 0.0) {
				best_angle_low = angle_deg;
				best_error_low = error;
			}
			best_angle_high = angle_deg;
			best_error_high = error;
		}
	}
	
	std::cout << std::fixed << std::setprecision(5) << "\n";
	if (best_error_high > 10 && best_error_low > 10) {
		std::cout << "! Your projectile can't reach to target without MAJOR errors.\n";
		std::cout << "Your projectile either too slow or too fast.\n";
	}
	else if (best_angle_high == best_angle_low) {
		std::cout << "For send your projectile to the target " << target << " meters away,\n";
		std::cout << "You have one launch angle:\n";
		std::cout << "\n";
		std::cout << best_angle_low << " degrees with " << best_error_low << " meters error.\n";0
	}
	else {
		std::cout << "For send your projectile to the target " << target << " meters away,\n";
		std::cout << "You have two launch angles:\n";
		std::cout << "\n";
		std::cout << "Lower trajectory, shorter air time:\n";
		std::cout << best_angle_low << " degrees with " << best_error_low << " meters error.\n";
		std::cout << "Higher trajectory, longer air time:\n";
		std::cout << best_angle_high << " degrees with " << best_error_high << " meters error.\n";
	}
	
	return 0;
}	

int change_e_variables() {
	std::cout << "\n";
	std::cout << "=== Change environment variables ===\n";
	std::cout << "Enter new air pressure:\n";
	std::cout << "ⓘ Default air pressure: 101325 Pascal\n";
    std::cin >> air_pressure;
    std::cout << "Enter new air temperature:\n";
    std::cout << "ⓘ Default air temperature: 15.0 Degrees celcius\n";
    std::cin >> temp_celcius;
    std::cout << "Enter new error tolerance:\n";
    std::cout << "ⓘ Default error tolerance: 0.5 Meters\n";
    std::cin >> error_tolerance;
    std::cout << "Environment variables changed!\n";
    std::cout << "Current air pressure: " << air_pressure << " Pascal\n";
    std::cout << "Current air temperature: " << temp_celcius << " Degrees celcius\n";
    std::cout << "Current error tolerance: " << error_tolerance << " Meters\n";
    return 0;
}

int main() {
    int choice;

    while (true) {
        std::cout << "=== projectILE Main Menu ===\n";
		std::cout << "1 == Launch angle calculator \n";
		std::cout << "2 == Make an artificial shot\n";
		std::cout << "3 == Change environment variables\n";
		std::cout << "0 == Exit the program\n";
		std::cout << "=== MADE BY TUX BUX FOR PRIMIÇERIUS ===\n";
		std::cout << "Enter your choice:";
        std::cin >> choice;

        switch (choice) {
            case 1:
                launch_angle_calc();
                break;
            case 2:
                artifical_shot();
                break;
            case 3:
				change_e_variables();
				break;
            case 0:
                std::cout << "Exiting projectILE...\n";
                return 0;
            default:
                std::cout << "Invalid option, please try again.\n";
        }

		std::cout << "\n";
        std::cout << "Program ended, returning to main menu...\n";
        std::cout << "\n";
    }

    return 0;
}
