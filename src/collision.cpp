#include "../include/engine.h"
# include "../include/player.h"

Vector2f Obstacle::groundCheck(Player *player, Vector2f position)
{
	if (player->getHitbox().position.x < 0)
        position.x = -player->getHitbox().offX;
    else if (position.x + player->getHitbox().width + player->getHitbox().offX > WIN_W)
        position.x = WIN_W - (player->getHitbox().width + player->getHitbox().offX);
    if (player->getHitbox().position.y < 0)
        position.y = -player->getHitbox().offY;
    else if (position.y + player->getHitbox().height + player->getHitbox().offY > WIN_H - hitbox.height)
        position.y = WIN_H - (player->getHitbox().height + player->getHitbox().offY + hitbox.height);
    return(position);
}


Vector2f Obstacle::CollisionCheck(Player *player, Vector2f position)
{
    if(player->getHitbox().rectangle.getGlobalBounds().intersects(hitbox.rectangle.getGlobalBounds()))
    {
        if(player->getHitbox().position.y + player->getHitbox().height <= hitbox.position.y + 2)
            position.y = hitbox.position.y - player->getHitbox().height - player->getHitbox().offY;

        // if(hitbox.position.x < shroom.hitbox.position.x - shroom.hitbox.width/2)
        //     position.x = shroom.hitbox.position.x - hitbox.offX - hitbox.width;
        // else
        //     position.x = shroom.hitbox.position.x + shroom.hitbox.width - hitbox.offX;
        hitbox.rectangle.setFillColor(Color::Red);
    }
    else
        hitbox.rectangle.setFillColor(Color::Green);
    return (position);
}