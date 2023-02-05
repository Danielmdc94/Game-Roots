#include "../include/engine.h"
# include "../include/player.h"

Vector2f Obstacle::groundCheck(Player *player, Vector2f position)
{
	if (player->hitbox.position.x < 0)
        position.x = -player->hitbox.offX;
    else if (position.x + player->hitbox.width + player->hitbox.offX > WIN_W)
        position.x = WIN_W - (player->hitbox.width + player->hitbox.offX);
    if (player->hitbox.position.y < 0)
        position.y = -player->hitbox.offY;
    else if (position.y + player->hitbox.height + player->hitbox.offY > WIN_H - hitbox.height)
        position.y = WIN_H - (player->hitbox.height + player->hitbox.offY + hitbox.height);
    return(position);
}


Vector2f Obstacle::CollisionCheck(Player *player, Vector2f position)
{
    if(player->hitbox.box.getGlobalBounds().intersects(hitbox.box.getGlobalBounds()))
    {
        if(player->hitbox.position.y + player->hitbox.height <= hitbox.position.y + 2)
            position.y = hitbox.position.y - player->hitbox.height - player->hitbox.offY;
        // if(hitbox.position.x < shroom.hitbox.position.x - shroom.hitbox.width/2)
        //     position.x = shroom.hitbox.position.x - hitbox.offX - hitbox.width;
        // else
        //     position.x = shroom.hitbox.position.x + shroom.hitbox.width - hitbox.offX;
        hitbox.box.setFillColor(Color::Red);
    }
    else
        hitbox.box.setFillColor(Color::Green);
    return (position);
}