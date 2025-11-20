#include "IsoCamera.hpp"
IsoCamera::IsoCamera(int screenWidth,
                     int screenHeight,
                     float tileWidth,
                     float tileHeight)
    : posX(0.0f), posY(0.0f), zoom(1.0f), screenWidth(screenWidth),
      screenHeight(screenHeight), tileWidth(tileWidth), tileHeight(tileHeight)
{
}
IsoCamera::~IsoCamera() {}
void IsoCamera::WorldToScreen(float worldX,
                              float worldY,
                              float& screenX,
                              float& screenY)
{
    screenX = (worldX - worldY) * (tileWidth / 2) * zoom + screenWidth / 2;
    screenY = (worldX + worldY) * (tileHeight / 2) * zoom + screenHeight / 4;
}
void IsoCamera::ScreenToWorld(float screenX,
                              float screenY,
                              float& worldX,
                              float& worldY)
{
    float adjustedX = (screenX - screenWidth / 2) / (zoom * (tileWidth / 2));
    float adjustedY = (screenY - screenHeight / 4) / (zoom * (tileHeight / 2));
    worldX = (adjustedX + adjustedY) / 2;
    worldY = (adjustedY - adjustedX) / 2;
}
void IsoCamera::SetPosition(float x, float y)
{
    posX = x;
    posY = y;
}
void IsoCamera::GetPosition(float& x, float& y)
{
    x = posX;
    y = posY;
}
void IsoCamera::SetZoom(float zoom) { this->zoom = zoom; }

float IsoCamera::GetZoom() const { return zoom; }
