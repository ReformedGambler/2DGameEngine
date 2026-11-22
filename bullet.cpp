#include "bullet.h"

Bullet::Bullet(
    Vector2 position,
    Vector2 hitboxSize,
    float maxSpeed,
    float damage)
    :
    position(position),
    hitboxSize(hitboxSize),
    maxSpeed(maxSpeed),
    damage(damage) {
    // Initialize brush to solid red brush
    renderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Red),
        brush.GetAddressOf()                // Gives the address of the pointer to write to
    );
}

bool Bullet::IsOffScreen() const {
    return position.x < 0 || position.x > systemWidth ||
           position.y < 0 || position.y > systemHeight;
}

void Bullet::DebugRender() {
    // Fill rectangle configurations
    D2D1_RECT_F rect = D2D1::RectF(
        position.x,
        position.y,
        position.x + hitboxSize.x,
        position.y + hitboxSize.y
    );

    // Draw rectangle
    renderTarget->DrawRectangle(
        rect,
        brush.Get(),                        // Gets the address of the pointer
        1.0f
    );
}