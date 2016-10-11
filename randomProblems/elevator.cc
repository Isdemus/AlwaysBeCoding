#include <thread>
#include <vector>

/*
 *	First attempt is to design an elevator without elevating algorithm.
 *	It stops every requested floor with FIFO policy
 */
 using namespace std;

class Elevator {
  public:
  	typedef enum state {IDLE, UP, DOWN, STOP, BROKEN} State;
  	typedef vector<int> Request;
 	Elevator(int maxfloor);
 	~Elevator();
 	void Request(int floor);		// Request called when user presses a floor button
 	void GoingUp();					
 	void GoingDown();				
 	void Stop();					// Stop the elevator
 	void OpenDoor();				// Open the door
 	void CloseDoor();				// Close the door
 	void EmergencyActuator();		// Emergency call

  private:
  	State 			_state;
  	Request 		_station;
  	int				_currentfloor;
  	int				_targetfloor;
  	int				_minfloor;
  	int				_maxfloor;
};

Elevator::Elevator(int minfloor, int maxfloor) 
	: _state(IDEL), _station(Request()), _currentfloor(0), _minfloor(minfloor), _maxfloor(maxfloor)	{
	_station.reserve(maxfloor - minfloor + 1);
}
Elevator::~Elevator() : _state(BROKEN) {}

void Elevator::Request(int floor) {
	if (_currentfloor == floor)
		return;

	if (_state == IDEL && _station.empty()) {
		_station.push_back(floor);
		_targetfloor = floor;
		_state = _currentfloor > floor ? DOWN : UP;
		if (_state == UP)	GoingUp();
		else				GoingDown();
		return;
	}

	// If the floor has been requested before, cancel the request
	auto iter = _station.find(floor);
	if (iter != _station.end()) {
		if (_targetfloor == floor) {
			_targetfloor = maxfloor + 1;
			_state = IDEL;
		}
		_station.erase(iter);
	} else {
		_station.push_back(floor);

	}
}

void Elevator::GoingUp() {
	_currentfloor += 1;

	// Checking if it reached the target floor to stop
	if (_targetfloor == _currentfloor) {
		Stop();
		_station.erase(_station.find(_targetfloor));

		if (!_station.empty()) {
			_targetfloor = *_station.begin();
			_state = _currentfloor > floor ? DOWN : UP;
			
			// Deciding where to go
			if (_state == UP)	GoingUp();
			else				GoingDown();
		} else {
			_state = IDEL;
		}
	} else if (_state == UP) {
		GoingUp();
	}
}

void Elevator::GoingDown() {
	_currentfloor -= 1;

	// Checking if it reached the target floor to stop
	if (_targetfloor == _currentfloor) {
		Stop();

		if (!_station.empty()) {
			_targetfloor = *_station.begin();
			_state = _currentfloor > floor ? DOWN : UP;

			if (_state == UP)	GoingUp();
			else				GoingDown();
		} else {
			_state = IDEL;
		}
	} else if (_state == Down) {
		GoingDown();
	}
}

void Elevator::Stop() {
	_state = STOP;
	OpenDoor();
	std::this_thread::sleep_for(5s);
	CloseDoor();
}

void Elevator::OpenDoor() {
	if (_state != STOP) {
		// Potentially an error has occured
		_state = BROKEN;
		EmergencyActuator();
	}
	OpenDoor_API();
}

void Elevator::CloseDoor() {
	if (_state != STOP) {
		//Potential Error has been occured
		_state = BROKEN;
		EmergencyActuator();
	}
	CloseDoor_API();
}