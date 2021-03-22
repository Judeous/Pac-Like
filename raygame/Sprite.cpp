#include "Sprite.h"
#include "raylib.h"
#include <Vector2.h>
#include <cmath>

Sprite::Sprite(Texture2D* texture)
{
    m_texture = texture;
}

Sprite::Sprite(const char* path)
{
    m_texture = new Texture2D(LoadTexture(path));
}

int Sprite::getWidth()
{
    return m_texture->width;
}

void Sprite::setWidth(int value)
{
    m_texture->width = value;
}

int Sprite::getHeight()
{
    return m_texture->height;
}

void Sprite::setHeight(int value)
{
    m_texture->height = value;
}

void Sprite::draw(MathLibrary::Matrix3 transform)
{
    //Finds the scale of the sprite
    float spriteWidth = round(MathLibrary::Vector2(transform.m11, transform.m21).getMagnitude());
    float spriteHeight = round(MathLibrary::Vector2(transform.m12, transform.m22).getMagnitude());
    setWidth((int)spriteWidth);
    setHeight((int)spriteHeight);

    //Sets the sprite center to the transform origin
    MathLibrary::Vector2 position = MathLibrary::Vector2(transform.m13, transform.m23);
    MathLibrary::Vector2 forward = MathLibrary::Vector2(transform.m11, transform.m21);
    MathLibrary::Vector2 up = MathLibrary::Vector2(transform.m12, transform.m22);
    position = position - (forward.getNormalized() * spriteWidth / 2.0f);
    position = position - (up.getNormalized() * spriteHeight / 2.0f);

    //Find the transform rotation in radians 
    float rotation = atan2(transform.m21, transform.m11);

    //Draw the sprite
    DrawTextureEx(
        *m_texture,
        { position.x, position.y },
        rotation * 180.0f / PI,
        1,
        WHITE);
    DrawRectangleLines((int)position.x, (int)position.y, (int)spriteWidth, (int)spriteHeight, RED);
}

