#include "game.h"
#include <iostream>

Game::Game(int id,string name,int year, string developers,string genre){
	this-> id=id;
	this-> name = name;
	this-> year = year;
	this-> developers = developers;
	this-> genre = genre;
}

int Game::getId(){
	return id;
}

string Game::toString(){
	stringstream ss;
	ss << id <<"	"<<name<<"	"<<year<<"	"<<developers<<"	"<<genre<<endl; 
	return ss.str(); 
}
