

#include "space-invaders/assets/assets.h"


namespace SpaceInvaders {
    namespace Assets {

        //               ##
        //             ######
        //             ######
        //     ######################
        //   ##########################
        //   ##########################
        //   ##########################

        GLubyte player_1[1][5 * 13 * 7] {
            {
                0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 1, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,
                0, 0, 0, 0, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 1, 1, 1, 0,  0, 0, 0, 0, 0,
                0, 1, 1, 1, 0,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  0, 1, 1, 1, 0,
                1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,
                1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,
            }
        };

        GLubyte player_gun[2][6 * 13 * 13] {
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 0, 1, 1,  0, 1, 1, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 0, 1, 1,  0, 1, 1, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            }
        };


        GLubyte player_twix[3][6 * 13 * 13] {
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 0, 0, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 0, 0, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 0, 0, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            }
        };

        GLubyte player_laser[3][6 * 13 * 13] {
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 0, 0, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 1, 1, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            }
        };


        GLubyte player_lightning[2][6 * 13 * 13] {
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 1, 0, 0, 1, 0,  1, 0, 1, 1, 0, 1,  0, 1, 0, 0, 1, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            },
            {
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  1, 0, 0, 0, 0, 1,  0, 0, 0, 0, 0, 0,  1, 0, 1, 1, 0, 1,  0, 0, 0, 0, 0, 0,  1, 0, 0, 0, 0, 1,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 1, 1, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 1, 1, 1, 1, 0,  1, 0, 0, 0, 0, 1,  1, 0, 1, 1, 0, 1,  1, 0, 0, 0, 0, 1,  0, 1, 1, 1, 1, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 1, 1, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
                1, 1, 0, 0, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 1, 1, 1, 1, 1,  0, 1, 1, 1, 1, 0,  1, 0, 1, 1, 1, 1,  0, 1, 0, 0, 1, 0,  1, 1, 0, 0, 1, 1,
                0, 0, 0, 0, 0, 0,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  1, 1, 0, 0, 1, 1,  0, 0, 0, 0, 0, 0,
            }
        };

        GLubyte player_bullet_1[1][1 * 1 * 4] = { 1, 1, 1, 1 };
    }
}
