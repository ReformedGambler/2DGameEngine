#include "bullet.h"

Bullet::Bullet(
    Vector2 position,
    Vector2 hitboxSize,
    float speed,
    float health,
    float damage)
    :
    Entity(position,
           hitboxSize,
           speed,
           health,
           damage) {

}

void Bullet::Update(double deltaTime) {

}

void Bullet::Render() {

}

void Bullet::DebugRender() {
    // Change brush to solid black brush
    renderTarget->CreateSolidColorBrush(
        D2D1::ColorF(D2D1::ColorF::Black),
        &brush
    );

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
        brush,
        1.0f
    );
}