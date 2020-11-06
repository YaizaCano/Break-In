#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"

#define PLAYER_SIZE_X 34
#define PLAYER_SIZE_Y 46
Player::Player()
{
}


Player::~Player()
{
}

void Player::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram)
{
	spritesheet.loadFromFile("images/player.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(PLAYER_SIZE_X, PLAYER_SIZE_Y), glm::vec2(1, 1), &spritesheet, &shaderProgram);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(posPlayer.x), float(posPlayer.y)));
}


void Player::update(int deltaTime)
{

	if(Game::instance().getSpecialKey(GLUT_KEY_LEFT))
	{
		posPlayer.x -= 2;
		if (posPlayer.x < -4)
			posPlayer.x += 2;

	}
	else if(Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
	{
		posPlayer.x += 2;
		if (posPlayer.x > 13 * 28 - 10)
			posPlayer.x -= 2;
	}

	if (Game::instance().getSpecialKey(GLUT_KEY_UP))
	{
		posPlayer.y -= 2;
		if (posPlayer.y < 16 + 894)
			posPlayer.y += 2;

	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_DOWN))
	{
		posPlayer.y += 2;
		if (posPlayer.y > 27 * 16 - 14 + 894)
			posPlayer.y -= 2;
	}
		
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

void Player::render()
{
	sprite->render();
}

void Player::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Player::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

glm::ivec2 Player::getPosition()
{
	return posPlayer + tileMapDispl;
}

int Player::getPlayerXSize()
{
	return PLAYER_SIZE_X;
}




