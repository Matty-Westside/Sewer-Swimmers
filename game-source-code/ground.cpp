#include "ground.h"

Ground::Ground():
	MovingEntity{EntityList::Player, Vector2f(0, 0), Vector2f(_playerSpeed, _playerSpeed)}
	{};
	
float Ground::positionGeneration(float positionBounds) const
{
	auto tmp = static_cast<int>(positionBounds - _playerHeight);
	auto rand_num = rand()%tmp;
	return static_cast<float>(rand_num);
}

void Ground::setPosition(float x, float y)
{
	Entity::setPosition(x,y);
}

void Ground::move(float changeInTime)
{

}

list<Vector2f> Ground::hitboxPoints()
{
	list<Vector2f> hitbox_coords;
	Vector2f top_left = getPosition();
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y));
	hitbox_coords.push_back(Vector2f(top_left._x + _playerWidth, top_left._y - _playerHeight));
	hitbox_coords.push_back(Vector2f(top_left._x, top_left._y - _playerHeight));
	return hitbox_coords;
}

void Ground::collide(const shared_ptr<Entity>& collider)
{
	switch(collider->getEntityKey())
	{
		case EntityList::Player:
			destroy();
			break;
		case EntityList::Enemy:
			break;
		default:
			break;
	}
}