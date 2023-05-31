#include "../include/TileMap.h"
#include "../include/Camera.h"
void TileMap::Start() {

}
TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated)
{
    this->parallax = 0;
    SetTileSet(tileSet);
    Load(file);
}

void TileMap::SetTileSet(TileSet *tileSet)
{
    //set tilemap
    this->tileSet = tileSet;
}
void TileMap::Load(std::string file)
{
    // load file
    ifstream arquivo;
    int tile;
    arquivo.open(file.c_str());
    if (arquivo) // garante q o arquivo foi aberto corretamente.
    {
        // get three first values and passing to mapWidth, mapHeight and mapDepth, using a comma as separator
        char virgula;
        arquivo >> mapWidth >> virgula >> mapHeight >> virgula >> mapDepth;

        // imprime os valores
        cout << "mapWidth: " << mapWidth << endl;
        cout << "mapHeight: " << mapHeight << endl;
        cout << "mapDepth: " << mapDepth << endl;

        // push all tiles to vector

        for (int i = 0; i < (mapWidth * mapHeight * mapDepth); i++)
        {
            arquivo >> tile >> virgula;
            // std::cout << i << ": " << tile << std::endl;
            tileMatrix.push_back(tile - 1);
        }

        arquivo.close(); // fecha o arquivo
    }
}

void TileMap::Render()
{
    // Renderiza as camadas do mapa. Dica: utilize o RenderLayer e o box do
    //  GameObject que o cont�m.
    for (int i = 0;i < mapDepth; i++)
    {
        RenderLayer(i, Camera::pos.x + (int)Camera::pos.x * parallax * i, Camera::pos.y + (int)Camera::pos.y * parallax * i);

    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
    for (int x = 0; x < mapWidth; x++)
    {
        for (int y = 0; y < mapHeight; y++)
        {
            tileSet->RenderTile(At(x, y, layer),
                (float)(x * tileSet->GetTileWidth()),
                (float)(y * tileSet->GetTileHeight()));
        }
    }
}
void TileMap::Update(float dt)
{
}

bool TileMap::Is(string type)
{
    if (type == "TileMap")
        return true;
    return false;
}

int TileMap::GetWidth()
{
    return this->mapWidth;
}

int TileMap::GetHeight()
{
    return this->mapHeight;
}

int TileMap::GetDepth()
{
    return this->mapDepth;
}
/*At é um método acessor. Ele retorna uma referência ao elemento
[x][y][z] de tileMatrix. */
int& TileMap::At(int x, int y, int z)
{   
    // indice = x + largura*y + (z*largura*altura) 
    int index = x + (y * mapWidth) + (z * mapWidth * mapHeight);
    int& reference = tileMatrix[index];

    return reference;
}
void TileMap::SetParallax(float parallax) {
    this->parallax = parallax;
}
