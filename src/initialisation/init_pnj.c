/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** init_pnj
*/

#include "prototype.h"

int init_pnj_phrase(obj_t *pnj)
{
    sfVector2f scale = {0.7, 0.7};
    int i = 0;

    pnj->text.texture = sfTexture_createFromFile(
        "assets/textures/bubble.png", NULL);
    pnj->text.sprite_bubble = sfSprite_create();
    sfSprite_setTexture(pnj->text.sprite_bubble, pnj->text.texture, sfTrue);
    sfSprite_setScale(pnj->text.sprite_bubble, scale);
    pnj->text.nb_dialog = 0;
    if (copy_into_hi(pnj) == 84)
        return (84);
    if (copy_into_sell(pnj) == 84)
        return (84);
    if (copy_into_by(pnj) == 84)
        return (84);
    pnj->text.font = sfFont_createFromFile("assets/texts/Timeless.ttf");
    pnj->text.phrase = sfText_create();
    pnj->talk = malloc(sizeof(musics));
    pnj->talk2 = malloc(sizeof(musics));
    pnj->talk3 = malloc(sizeof(musics));
    pnj->talk->sound = sfMusic_createFromFile("assets/sound/talk_pnj1.ogg");
    pnj->talk2->sound = sfMusic_createFromFile("assets/sound/talk_pnj2.ogg");
    pnj->talk3->sound = sfMusic_createFromFile("assets/sound/talk_pnj3.ogg");
}

void create_pnj(obj_t *pnj)
{
    pnj->texture = sfTexture_createFromFile("assets/textures/link.png", NULL);
    pnj->char_down = create_char_perso(0, 0, 16, 16);
    pnj->char_up = create_char_perso(0, 0 + 61, 16, 16);
    pnj->char_left = create_char_perso(0, 0 + 30, 16, 16);
    pnj->char_right = create_char_perso(0, 0 + 90, 16, 16);
    pnj->sprite = sfSprite_create();
    sfSprite_setTexture(pnj->sprite, pnj->texture, sfFalse);
    pnj->move.y = 3;
    pnj->move.x = 3;
    sfSprite_setTextureRect(pnj->sprite, pnj->char_down);
    sfSprite_setScale(pnj->sprite, pnj->move);
}

int init_pnj(scene_t *scene)
{
    obj_t *pnj = malloc(sizeof(obj_t));
    sfVector2f pos = {200, 200};

    if (pnj == NULL)
        return (84);
    memset(pnj, 0, sizeof(obj_t) * 1);
    create_pnj(pnj);
    if (init_pnj_phrase(pnj) == 84)
        return (84);
    sfSprite_setPosition(pnj->sprite, pos);
    create_zone_enn(pnj, 50);
    pnj->anim_clock = sfClock_create();
    pnj->next = scene->pnj;
    scene->pnj = pnj;
    return (0);
}
