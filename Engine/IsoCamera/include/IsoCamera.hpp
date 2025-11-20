#ifndef ISO_CAMERA_HPP
#define ISO_CAMERA_HPP

#include <SDL3/SDL.h>
class IsoCamera
{
  public:
    IsoCamera(int screenWidth,
              int screenHeight,
              float tileWidth,
              float tileHeight);
    ~IsoCamera();

    void
    WorldToScreen(float worldX, float worldY, float& screenX, float& screenY);
    void
    ScreenToWorld(float screenX, float screenY, float& worldX, float& worldY);
    void SetPosition(float x, float y);
    void GetPosition(float& x, float& y);
    void SetZoom(float zoom);
    float GetZoom() const;

  private:
    float posX;
    float posY;
    float zoom;
    int screenWidth;
    int screenHeight;
    float tileWidth;
    float tileHeight;
};

#endif // ISO_CAMERA_HPP