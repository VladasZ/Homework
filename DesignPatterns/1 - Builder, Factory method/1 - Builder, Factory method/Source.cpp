#include <iostream>

using namespace std;

// Factory method

enum OS_ID {Linux, Windows, OS_X};


class Window {
public:
	static Window* createWindow(const OS_ID& os_id);
};

class LinuxWindow : public Window {
public:

	LinuxWindow() {
		cout << "Linux buttons created" << endl;
		cout << "Linux labels created" << endl;
		cout << "Linux etc. created" << endl;
	}
	
};


class WindowsWindow : public Window {
public:
	

	WindowsWindow() {
		cout << "Windows buttons created" << endl;
		cout << "Windows labels created" << endl;
		cout << "Windows etc. created" << endl;
	}

};


class OS_XWindow : public Window {
public:
	OS_XWindow() {
		cout << "OS_X buttons created" << endl;
		cout << "OS_X labels created" << endl;
		cout << "OS_X etc. created" << endl;
	}

};


Window* Window::createWindow(const OS_ID& os_id) {


	
	switch (os_id)
	{
	case Linux:
		return new LinuxWindow();
	case Windows:
		return new WindowsWindow();
	case OS_X:
		return new OS_XWindow();
	default:
		break;
	}


}

//////////////////
////////////////// Builder
//////////////////

class Car {
public:
	int engineVolume;
	int maxSpeed;
	char* model;

	void info() {
		cout << model << ": Engine volume - " << engineVolume << " Max speed - " << maxSpeed << endl;
	}
};




class OkaBuilder {
public:
	

	void mounthEngine(Car* newCar) {
		newCar->engineVolume = 1200;
		newCar->maxSpeed = 60;
		newCar->model = "Oka";
	}

	

	Car* buildCar() {
		Car* newCar = new Car;
		mounthEngine(newCar);
		return newCar;
	}


}okaBuilder;

class FerrariBuilder {
public:
	

	void mounthEngine(Car* newCar) {
		newCar->engineVolume = 6000;
		newCar->maxSpeed = 600;
		newCar->model = "Ferrari";
	}


	
	Car* buildCar() {
		Car* newCar = new Car;
		mounthEngine(newCar);
		return newCar;
	}


}ferrariBuilder;






int main() {

	Window* newLinuxWindow = Window::createWindow(Linux);
	Window* newOS_XWindow = Window::createWindow(OS_X);
	Window* newWindowsWindow = Window::createWindow(Windows);


	cout << endl;

	Car* newOka = okaBuilder.buildCar();
	Car* newFerrari = ferrariBuilder.buildCar();

	newOka->info();
	newFerrari->info();




	return 0;
}
