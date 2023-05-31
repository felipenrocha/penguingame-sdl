#pragma once

#ifndef __TILE_MAP_H__
#define __TILE_MAP_H__
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <fstream> //using to manip files
#include <stdio.h>
#include "GameObject.h"
#include "TileSet.h"

class TileMap : public Component {
public:
    TileMap(GameObject& associated, string file, TileSet* tileSet);
    void Start() override;

    void Load(string file);

    void SetTileSet(TileSet* tileSet);
    int& At(int x, int y, int z);
    void Render() override;

    void Update(float dt) override;

    bool Is(string type) override;

    void RenderLayer(int layer, int cameraX, int cameraY);

    int GetWidth();

    int GetHeight();

    int GetDepth();

    void SetParallax(float);

private:
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
    float parallax;

};
#endif