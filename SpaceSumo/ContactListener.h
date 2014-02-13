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
    void EndContact(b2Contact* contact);

private:
	void beginCase(void* userDataA, void* userDataB);
	void endCase(void* userDataA, void* userDataB);
};

