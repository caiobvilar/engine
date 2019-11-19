#include "../include/Player.hpp"

Player::Player(const char* texturefile,SDL_Renderer* render, int x_start, int y_start)
{
	this->Obj_Rect.x = x_start;
	this->Obj_Rect.y = y_start;
	this->setTexture(texturefile,render);
}

Player::~Player()
{
	//
	std::cout << "\nPlayer destroyed" << std::endl;
}
void Player::update()
{
	this->state_cntr++;
	this->Obj_Rect.w=64;
	this->Obj_Rect.h=64;
	this->Obj_Rect.x = this->state_cntr%1024;
	if(this->Obj_Rect.x >= 1023)
	{
		this->Obj_Rect.y += 64;
		if(this->Obj_Rect.y > 767)
		{
			this->Obj_Rect.y=0;
		}
	}
}
void Player::draw(SDL_Renderer* render)
{
	//call SDL_RenderCopy() after changes are done...
	SDL_RenderCopy(render,this->player_sprsheet,NULL,&this->Obj_Rect);
}
void Player::setTexture(const char* filename, SDL_Renderer* render)
{
	this->player_sprsheet = TextureManager::LoadTexture(filename, render); 
}
