#ifndef __TILE_SET_H__
#define __TILE_SET_H__

#include <string>
#include "Sprite.h"
#include "GameObject.h"

using namespace std;



class TileSet
{
public:
	TileSet(GameObject& associated, int tileWidth, int tileHeight, string file);
	void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

};
#endif

