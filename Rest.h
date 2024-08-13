#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include "Ball.h"
#include "Map.h"
#include "Paddle.h"
#include "Block.h"
#include "Buff.h"
#include "BuffP.h"
#include "BuffB.h"
#include "Frame.h"
#include "BlockR.h"
#include "BlockG.h"
#include "BlockK.h"
class Rest
{
public:

    bool collisionTest(Paddle&, Buff&, Ball&);
    bool collisionTest(Block&, Ball&,Paddle&);
    bool collisionTest(BlockR& blockR, Ball& ball, Paddle& paddle);
    bool collisionTest(BlockG& blockG, Ball& ball, Paddle& paddle);
    bool collisionTest(BlockK& blockK, Ball& ball, Paddle& paddle);
    bool collisionTest(Paddle&, Ball&);
    bool collisionTest(Paddle&, BuffP&);
    bool collisionTest(Paddle&, BuffB&, Ball&);
    vector<Block> setting_blocks(unsigned, unsigned, unsigned, unsigned);
    vector<Block> blocks;
    vector<BlockR> setting_blocksR(unsigned, unsigned, unsigned, unsigned);
    vector<BlockR> blocksR;
    vector<BlockG> setting_blocksG(unsigned, unsigned, unsigned, unsigned);
    vector<BlockG> blocksG;
    vector<BlockK> setting_blocksK(unsigned, unsigned, unsigned, unsigned);
    vector<BlockK> blocksK;
    void setter();


private:
    void buff_setup();
    int spin{};
    int randomm_number();
    int binary_num();
};

