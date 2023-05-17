
#ifndef __STATE_H__
#define __STATE_H__



#define MAP_TILEMAP_PATH "assets/map/tileMap.txt"
#define MAP_TILESET_PATH "assets/img/tileset.png"



#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "GameObject.h"
#include "TileMap.h"
#include "TileSet.h"
#include "CameraFollower.h"

class State
{
public:
	State();
	~State();
	bool QuitRequested();
	void LoadAssets();
	void Update(float dt);
	void Render();

private:
	Music music;
	bool quitRequested;
	void Input();
	void AddObject(int mouseX, int mouseY);
	std::vector<std::shared_ptr<GameObject>> objectArray;
};

#endif //SRC_STATE_H
