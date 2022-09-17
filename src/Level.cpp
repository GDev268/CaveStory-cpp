#include <SDL2/SDL.h>
#include <sstream>
#include <algorithm>
#include <cmath>

#include "Level.h"
#include "Graphics.h"
#include "tinyxml2/tinyxml2.h"

using namespace tinyxml2;

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
		_mapName(mapName),
		_spawnPoint(spawnPoint),
		_size(Vector2(0,0))
{
	this->loadMap(mapName, graphics);
}

Level::~Level() {

}

void Level::loadMap(std::string mapName, Graphics &graphics) {
	//Parse xml file
	XMLDocument doc;
	std::stringstream ss;
	ss << "maps/" << mapName << ".tmx";
	doc.LoadFile(ss.str(),c_str());
	//Gets the element <map> on the xml document
	XMLElement* mapNode = doc.FirstChildElement("map");

	//Get and store map size in _size from the previous element
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);
	this->_size = Vector2(width,height);

	//Get and store tiles size in _tileSize from the previous element
	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	this->_size = Vector2(tileWidth,tileHeight);

	//Load Tilesets
	//Must do to prevent crashes
	XMLElement* curTileSet = mapNode->FirstAttribute("tileset");
	if(curTileSet != NULL){
		while(curTileSet){
			int firstGid;
			const char* source = curTileSet->FirstChildElement("image")->Attribute("source");
			char* path;
			std::stringstream ss;
			ss << "assets/tilesets/" << source;
			curTileSet = curTileSet->NextSiblingElement("tileset");
			SDL_Texture* texture = SDL_CreateTextureFromSurface(graphics.getRenderer(),graphics.loadImage(ss.str()));
			this->_tilesets.push_back(Tileset(texture,firstGid));

			curTileSet = curTileSet->NextSiblingElement("tileset");
		}
	}
	//Load all layers of the map
	XMLElement* curlayer =  mapNode->FirstChildElement("layer");
	if(curlayer != NULL){
		while(curlayer){
			//Load data element
			XMLElement* curData = mapNode->FirstChildElement("data");
			if(curData != NULL){
				//Load tile element
				XMLElement* curTile = mapNode->FirstChildElement("tile");

				curlayer = curlayer->NextSiblingElement("layer");
			}

		}
	}
}

void Level::update(int elapsedTime) {

}

void Level::draw(Graphics &graphics) {
	//Draw the background
	SDL_Rect sourceRect = { 0, 0, 64, 64 };
	SDL_Rect destRect;
	for (int x = 0; x < this->_size.x / 64; x++) {
		for (int y = 0; y < this->_size.y / 64; y++) {
			destRect.x = x * 64 * Global::PLAYER_SIZE;
			destRect.y = y * 64 * Global::PLAYER_SIZE;;
			destRect.w = 64 * Global::PLAYER_SIZE;;
			destRect.h = 64 * Global::PLAYER_SIZE;;
			graphics.blitSurface(this->_backgroundTexture, &sourceRect, &destRect);
		}
	}
}