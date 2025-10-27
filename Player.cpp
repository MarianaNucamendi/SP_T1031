#include "Player.h"

Player::Player(): username(""), ac(0), hp(0){}

Player::Player(std::string username, int ac, int hp): username(username), ac(ac), hp(hp) {}

Player::~Player(){}