#pragma once

#include "Object.h"
#include "Textures.h"
#include "HookSettings.h"
#include "ControllerSettings.h"
#include "BoardObject.h"
#include "PlayerSettings.h"
#include "Barrel.h"

class Hook :
	public Object
{
public:
	// public fumctions
	Hook() {};
	/*
	Constructor: get the position of the Barrel
	*/
	Hook(const sf::Vector2f &position);
	/*
	draw the hook to the window
	*/
	virtual void draw(sf::RenderWindow & window);
	/*
	reset all hooks variables
	*/
	void reset(const sf::Vector2f &position);
	/*
	rotate the hook
	*/
	void rotate(float deltaTime);
	/*
	returns if the hook is sent
	*/
	bool isSent();
	/*
	returns if the hook is back
	*/
	bool isBack();
	/*
	return if the hook have some attached object
	*/
	bool isAttached();
	/*
	returns if the hook is in throwing dynamite mode
	*/
	bool isThrowingDynamite()const;
	/*
	update the throwing mode
	*/
	void updateThrowingMode(bool status);
	/*
	set the sent indicator to true
	*/
	void setSent();
	/*
	set the back indicator to true
	*/
	void setBack();
	/*
	update the attached indicator
	*/
	void updateIsAttached(bool status);
	/*
	send the hook
	*/
	bool send(float deltaTime);
	/*
	restore all indicators to false
	*/
	void restoreIndicators();
	/*
	returns the grab time
	*/
	float getGrabTime();
	/*
	returns the current angle
	*/
	float getAngle()const;
	/*
	returns the global bounds of the hook
	used for check intersection
	*/
	sf::FloatRect  getGlobalBounds()const;
	/*
	sets the grabbed object
	*/
	bool setGrabbedObject(BoardObject * obj);
	/*
	returns the grabbed object
	*/
	BoardObject * getGrabbedObject();
	/*
	sets the texture of the hook
	*/
	void setTexture(sf::Texture & texture);
	
private:
	//private members
	float m_angle;// holds the current angle
	bool m_isSent;// sent indicator
	bool m_isBack;// back indicator
	bool m_isAttached;// attached object indicator
	bool m_throwingDynamite;// throwing dynamite indicator
	bool m_direction; // false for left means add positive to angle 
	float m_totalRotateTime;// holds the total rotate time
	float m_totalGrabTime;// holds the total grab time
	float m_grabTime;// holds the current grab time
	sf::RectangleShape m_rope;// holds the rope of the hook
	BoardObject * m_grabbedObject = nullptr;// holds the grabbed object

	//private functions
	/*
	sets the angle
	*/
	void setAngle();
	/*
	returns the ends of the rope
	*/
	sf::Vector2f getEndOfRope();
	/*
	grab the hook back
	*/
	void grab(sf::Vector2f & size);
	/*
	change the grab speed
	*/
	void changeGrabSpeed(const sf::Vector2f & size);
};

