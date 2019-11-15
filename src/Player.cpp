#include "../include/Player.hpp"

Player::Player(const char* texturefile,SDL_Renderer* render)
{
	this->setTexture(texturefile,render);
}

Player::~Player()
{
	//
	std::cout << "Player destroyed" << std::endl;
}
void Player::update()
{
	this->state_cntr++;
	this->Obj_Rect.w=64;
	this->Obj_Rect.h=64;
	this->Obj_Rect.x=this->state_cntr%800;
	if(this->Obj_Rect.x <= 800)
	{
		this->Obj_Rect.y += 64;
		if(this->Obj_Rect.y > 640)
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
