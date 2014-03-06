#pragma once
#include <SFML\Window\Event.hpp>
#include <vector>
namespace sf
{
	namespace Xbox 
	{
		enum Button
		{
			A, B, X, Y, LEFT_BUTTON, RIGHT_BUTTON, BACK, START, LEFT_STICK_BUTTON, RIGHT_STICK_BUTTON
		};
		enum Analog
		{
			NO_TRIGGER,

			LEFT_STICK_UP,
			LEFT_STICK_DOWN,
			LEFT_STICK_Y_IDLE,
			LEFT_STICK_LEFT,
			LEFT_STICK_RIGHT,
			LEFT_STICK_X_IDLE,

			RIGHT_STICK_UP,
			RIGHT_STICK_DOWN,
			RIGHT_STICK_Y_IDLE,
			RIGHT_STICK_LEFT,
			RIGHT_STICK_RIGHT,
			RIGHT_STICK_X_IDLE,

			LEFT_TRIGGER,
			RIGHT_TRIGGER
		};
		struct ControllerStatus
		{
		public:
			ControllerStatus();
			enum Status
			{
				// DOWN/RIGHT
				POSITIVE,
				// UP/LEFT
				NEGATIVE, 
				IDLE
			};
			struct AnalogStatus
			{
				AnalogStatus(sf::Joystick::Axis aliasX, sf::Joystick::Axis aliasY);
				const sf::Joystick::Axis aliasX;
				const sf::Joystick::Axis aliasY;
				Status statusX;
				Status statusY;
			};
			struct TriggerStatus
			{
				TriggerStatus(sf::Joystick::Axis alias);
				const sf::Joystick::Axis alias;
				Status status;
			};
			AnalogStatus leftStick, rightStick;
			TriggerStatus leftTrigger, rightTrigger;

		};
		void getAnalogEvent(const sf::Event::JoystickMoveEvent &evt, ControllerStatus &status);
		static const sf::Joystick::Axis LEFT_STICK_Y = sf::Joystick::Axis::Y;
		static const sf::Joystick::Axis LEFT_STICK_X = sf::Joystick::Axis::X;
		static const sf::Joystick::Axis RIGHT_STICK_X = sf::Joystick::Axis::U;
		static const sf::Joystick::Axis RIGHT_STICK_Y = sf::Joystick::Axis::R;
		// < 0 = Left Trigger, > 0 = Right Trigger
		static const sf::Joystick::Axis TRIGGERS = sf::Joystick::Axis::Z;
		
		/*struct Stick
		{
		public:
			int id;
			int limit;

			Stick& set(int nid, int nlimit)
			{
				id = nid;
				limit = nlimit;
			}
		private:
			Stick(int id, int limit) : id(id), limit(limit) {}
		};
		struct Dpad
		{
		public:
			int id;

		private:
		};
		static const Stick LEFT_STICK_UP = set(2, 1);
		static const Stick LEFT_STICK_DOWN = set(2, -1);
		static const Stick LEFT_STICK_LEFT = set(3, -1);
		static const Stick LEFT_STIC_RIGHT = set(3, 1);

		static const Stick RIGHT_STICK_UP = set(4, 1);
		static const Stick RIGHT_STICK_DOWN = set(4, -1);
		static const Stick RIGHT_STICK_LEFT = set(5, -1);
		static const Stick RIGHT_STIC_RIGHT = set(5, 1);*/


	}
}