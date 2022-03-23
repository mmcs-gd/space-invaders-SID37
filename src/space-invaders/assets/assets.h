#pragma once


#include <GLES3/gl3.h>



namespace SpaceInvaders {

    namespace Assets {
        extern GLubyte invader_1[2][6 * 8 * 8];
        extern GLubyte invader_2[2][5 * 11 * 8];
        extern GLubyte invader_3[2][6 * 14 * 8];

        extern GLubyte player_1[1][5 * 13 * 7];
        extern GLubyte player_gun[2][6 * 13 * 13];
        extern GLubyte player_twix[3][6 * 13 * 13];
        extern GLubyte player_laser[3][6 * 13 * 13];
        extern GLubyte player_lightning[2][6 * 13 * 13];
        extern GLubyte player_bullet_1[1][1 * 1 * 4];

        extern GLubyte gun_icon[3 * 16 * 16];
        extern GLubyte twix_icon[3 * 16 * 16];
        extern GLubyte laser_icon[3 * 16 * 16];
        extern GLubyte lightning_icon[3 * 16 * 16];

        extern GLubyte cloud_1[1][6 * 16 * 11];
    }
}
