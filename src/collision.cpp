#include "../include/engine.h"
# include "../include/player.h"

Sprite Platform::getSpritePlat()
{
    return sprite;
}

// void Platform::groundScreenCheck(Player *player)
// {
// 	if (hitbox.position.x < 0)
//         player.position.x = -hitbox.offX;
//     else if (position.x + hitbox.width + hitbox.offX > WIN_W)
//         position.x = WIN_W - (hitbox.width + hitbox.offX);
//     if (hitbox.position.y < 0)
//         position.y = -hitbox.offY;
//     else if (position.y + hitbox.height + hitbox.offY > WIN_H - ground.hitbox.height)
//         position.y = WIN_H - (hitbox.height + hitbox.offY + ground.hitbox.height);

// }