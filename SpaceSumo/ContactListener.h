#pragma once
#include <Box2D\Dynamics\b2WorldCallbacks.h>
#include <Box2D\Dynamics\Contacts\b2Contact.h>
#include "PowerUp.h"

class ContactListener :
	public b2ContactListener
{
public:
	ContactListener();
	~ContactListener();

	void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact) 
	{
  /*
		//check if fixture A was a ball
		void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		if ( bodyUserData )
        static_cast<Ball*>( bodyUserData )->endContact();
  
		//check if fixture B was a ball
		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if ( bodyUserData )
        static_cast<Ball*>( bodyUserData )->endContact();
  */
    }
};

