#include "Rest.h"

int counterr{ 0 };
unsigned blocks_x{ 10 }, blocks_y{ 4 }, block_width{ 75 }, block_height{ 30 };
unsigned blocksR_x{ 10 }, blocksR_y{ 4 }, blockR_width{ 75 }, blockR_height{ 30 };
unsigned blocksG_x{ 10 }, blocksG_y{ 4 }, blockG_width{ 75 }, blockG_height{ 30 };
unsigned blocksK_x{ 2 }, blocksK_y{ 1 }, blockK_width{ 75 }, blockK_height{ 30 };
unsigned map_x{ 1 }, map_y{ 1 }, map_width{ 800 }, map_height{ 600 };
float frame{ 100 };
float xxx{ 1000 };
float yyy{ 800 };
Buff buff(map_width + frame, map_height - (frame + (frame / 2)));
BuffP buffP(map_width + frame, map_height - (frame + (frame / 2)));
BuffB buffB(map_width + frame, map_height - (frame+ (frame / 2)));
RenderWindow window(VideoMode(static_cast<unsigned>(xxx), static_cast<unsigned>(yyy)), "Arkanoid");
Event event;

using namespace std;
using namespace sf;
bool paused(bool);
bool pause = false;
int buffspin{};
int timee{ 500 };
int seed_num{1};
int new_game{};
int k_block{};
bool hard;


unsigned frame_x{ 1 }, frame_y{ 1 }, frame_width{ 1200 }, frame_height{ 1000 };
Text text;
template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();

}
bool Rest::collisionTest(Paddle& paddle, Ball& ball)
{
    if (!isIntersecting(paddle, ball)) return false;
    {
        ball.move_up();
    }
    if (ball.getPosition().x < paddle.getPosition().x)
    {
        ball.move_left();
    }
    else if (ball.getPosition().x < paddle.getPosition().x)
    {
        ball.move_right();
    }
    //else if (ball.getPosition().x == paddle.getPosition().x)
    //{
    //    ball.move_up();
    //}
}


bool Rest:: collisionTest(Paddle& paddle, Buff& buff, Ball& ball)
{
    if (!isIntersecting(paddle, buff)) return false;
    {

        ball.ball_velocity -= 0.75;
        buff.move_up();
    }
    //if (buff.getPosition().x < paddle.getPosition().x)
    //{
    //    ball.ball_velocity -= 0.75;
    //    buff.move_up();
    //}
    //else if (buff.getPosition().x < paddle.getPosition().x)
    //{
    //    ball.ball_velocity -= 0.75;
    //    buff.move_up();
    //}
    //else if (buff.getPosition().x == paddle.getPosition().x)
    //{
    //    ball.ball_velocity -= 0.75;
    //    buff.move_up();
    //}

}
bool Rest::collisionTest(Paddle& paddle, BuffP& buffP)
{
    if (!isIntersecting(paddle, buffP)) return false;
    {    
        paddle.clocking = timee;
        buffP.move_up();
        paddle.paddle_width = 200;
        paddle.shape_1.setSize({ paddle.paddle_width - 4, paddle.paddle_height - 4 });
        paddle.shape_1.setOrigin((paddle.paddle_width - 4) / 2.f, (paddle.paddle_height - 4) / 2.f);
        paddle.shape_2.setRadius(paddle.paddle_radius);
        paddle.shape_2.setOrigin(paddle.paddle_radius + (paddle.paddle_width / 2) - 3, (paddle.paddle_radius / 2.f) + 5);
        paddle.shape_3.setRadius(paddle.paddle_radius);
        paddle.shape_3.setOrigin(paddle.paddle_radius - (paddle.paddle_width / 2) + 3, (paddle.paddle_radius / 2.f) + 5);
        paddle.shape_4.setSize({ paddle.paddle_width, paddle.paddle_height });
        paddle.shape_4.setOrigin(paddle.paddle_width / 2.f, paddle.paddle_height / 2.f);
            
    }


}
bool Rest::collisionTest(Paddle& paddle, BuffB& buffB, Ball& ball)
{
    if (!isIntersecting(paddle, buffB)) return false;
    {
        paddle.clocking = (timee*2)-200;
        buffB.move_up();

    }


}
int Rest::randomm_number()
{
    spin = 0;
    spin = (rand() % 10 );
    return spin;
}
int Rest::binary_num()
{
    buffspin = 0;
    buffspin = (rand() % 3);
    return buffspin;
}
bool Rest:: collisionTest(Block& block, Ball& ball, Paddle& paddle)
{
    if (!isIntersecting(block, ball)) return false;
    else {
        block.destroy();
        ++counterr;

        this->randomm_number();
        if (counterr % 30 == 0)
        {
            
            ball.ball_velocity += 1;
        }

        if (spin == 5)
        {
            buff_setup();
        }
        if (counterr % new_game == 0)
        {
            ball.ball_velocity -= 1;
            setting_blocks(blocks_x, blocks_y, block_width, block_height);
            for (auto& block : blocks) { window.draw(block); }
            setting_blocksR(blocksR_x, blocksR_y, blockR_width, blockR_height);
            for (auto& blockR : blocksR) { window.draw(blockR); }
            setting_blocksG(blocksG_x, blocksG_y, blockG_width, blockG_height);
            for (auto& blockG : blocksG) { window.draw(blockG); }
            setting_blocksK(blocksK_x, blocksK_y, blockK_width, blockK_height);
            for (auto& blockK : blocksK) { window.draw(blockK); }
        }
        if ( paddle.penetration == false)
        {
            //cout << "counterr" << counterr << endl;
            float overlapLeft{ ball.right() - block.left() };
            float overlapRight{ block.right() - ball.left() };
            float overlapTop{ ball.bottom() - block.top() };
            float overlapBottom{ block.bottom() - ball.top() };
            bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
            bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
            float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
            float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };
       
            if (abs(minOverlapX) < abs(minOverlapY))
            {
                ballFromLeft ? ball.move_left() : ball.move_right();
            }
            else
            {
                ballFromTop ? ball.move_up() : ball.move_down();
            }
        }
        return true;
    }
}



vector<Block> Rest:: setting_blocks(unsigned blocks_x, unsigned  blocks_y, unsigned  block_width, unsigned  block_height)
{
    blocks.clear();
    if (seed_num == 0)
    {
        
        for (float i = 0; i < 1; i++)
        {
            for (float j = 0; j < blocks_x; j++)
            {
                {

                    blocks.emplace_back((j + 1.75) * (static_cast<float>(block_width) + 5.0), (i + 8) * (static_cast<float>(block_height) + 5), block_width, block_height);
                }

            }
        }

        new_game = 110;
        //cout << new_game << endl;
    }
    else
    {
        for (float i = 0; i < (blocks_x / 2); i++)
        {
            for (float j = 0; j < 3; j++)
            {
                {

                    blocks.emplace_back((j+0.75) * ((static_cast<float>(block_width) + 5)*3), (i + 4) * (static_cast<float>(block_height) + 5), block_width, block_height);
                }

            }
        }
        new_game = 90;
        //cout << new_game << endl;
    }
    return blocks;
}

vector<BlockR> Rest::setting_blocksR(unsigned blocksR_x, unsigned  blocksR_y, unsigned  blockR_width, unsigned  blockR_height)
{
    blocksR.clear();
    if (seed_num == 0)
    {
        for (float i = 0; i < 2; i++)
        {
            for (float j = 0; j < (blocksR_x); j++)
            {
                {

                    blocksR.emplace_back((j +1.75) * (static_cast<float>(blockR_width) + 5), (i + 6) * (static_cast<float>(blockR_height) + 5), blockR_width, blockR_height);
                }

            }
        }
        
    }
    else
    {
        for (float i = 0; i < blocksR_x / 2; i++)
        {
            for (float j = 0; j <3 ; j++)
            {
                {

                    blocksR.emplace_back(((j + 0.75) * ((static_cast<float>(blockR_width) + 5)*3)+ blockR_width + 5), (i + 4) * (static_cast<float>(blockR_height) + 5), blockR_width, blockR_height);
                }

            }
        }
    }
    return blocksR;
}

bool Rest::collisionTest(BlockR& blockR, Ball& ball, Paddle& paddle)
{
    if (!isIntersecting(blockR, ball)) return false;
    else {
        blockR.destroy();
        ++counterr;

        this->randomm_number();
        if (spin == 5)
        {
            buff_setup();
        }
        if (counterr % new_game == 0)
        {
            ball.ball_velocity -= 1;
            setting_blocks(blocks_x, blocks_y, block_width, block_height);
            for (auto& block : blocks) { window.draw(block); }
            setting_blocksR(blocksR_x, blocksR_y, blockR_width, blockR_height);
            for (auto& blockR : blocksR) { window.draw(blockR); }
            setting_blocksG(blocksG_x, blocksG_y, blockG_width, blockG_height);
            for (auto& blockG : blocksG) { window.draw(blockG); }
            setting_blocksK(blocksK_x, blocksK_y, blockK_width, blockK_height);
            for (auto& blockK : blocksK) { window.draw(blockK); }
        }
        if (counterr % 30 == 0)
        {

            ball.ball_velocity += 1;
        }
        if (paddle.penetration == false)
        {
            //cout << "counterr" << counterr << endl;
            float overlapLeft{ ball.right() - blockR.left() };
            float overlapRight{ blockR.right() - ball.left() };
            float overlapTop{ ball.bottom() - blockR.top() };
            float overlapBottom{ blockR.bottom() - ball.top() };
            bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
            bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
            float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
            float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

            if (abs(minOverlapX) < abs(minOverlapY))
            {
                ballFromLeft ? ball.move_left() : ball.move_right();
            }
            else
            {
                ballFromTop ? ball.move_up() : ball.move_down();
            }
        }
    }
    return true;
}

vector<BlockG> Rest::setting_blocksG(unsigned blocksG_x, unsigned  blocksG_y, unsigned  blockG_width, unsigned  blockG_height)
{
    blocksG.clear();
    if (seed_num == 0)
    {
        
        for (float i = 0; i < 2; i++)
        {
            for (float j = 0; j < blocksG_x; j++)
            {
                {

                    blocksG.emplace_back((j + 1.75) * (static_cast<float>(blockG_width + 5)), (i + 4) * (static_cast<float>(blockG_height + 5)), blockG_width, blockG_height);
                }

            }
        }
        
    }
    else
    {
        for (float i = 0; i < blocksG_x/2; i++)
        {
            for (float j = 0; j < 3; j++)
            {
                {

                    blocksG.emplace_back(((j + 0.75) * (static_cast<float>((blockG_width + 5)*3))+ (static_cast<float>(blockG_width) + 5)*2), (i + 4) * (static_cast<float>(blockG_height) + 5), blockG_width, blockG_height);
                }

            }
        }
    }
    return blocksG;
}

bool Rest::collisionTest(BlockG& blockG, Ball& ball, Paddle& paddle)
{
    if (!isIntersecting(blockG, ball)) return false;
    else {
        blockG.destroy();
        ++counterr;

        this->randomm_number();
        if (spin == 5)
        {
            buff_setup();
        }

        if (counterr % 30 == 0)
        {

            ball.ball_velocity += 1;
        }

        if (counterr % new_game == 0)
        {
            ball.ball_velocity -= 1;
            setting_blocks(blocks_x, blocks_y, block_width, block_height);
            for (auto& block : blocks) { window.draw(block); }
            setting_blocksR(blocksR_x, blocksR_y, blockR_width, blockR_height);
            for (auto& blockR : blocksR) { window.draw(blockR); }
            setting_blocksG(blocksG_x, blocksG_y, blockG_width, blockG_height);
            for (auto& blockG : blocksG) { window.draw(blockG); }
            setting_blocksK(blocksK_x, blocksK_y, blockK_width, blockK_height);
            for (auto& blockK : blocksK) { window.draw(blockK); }
        }
        if (paddle.penetration == false)
        {
            //cout << "counterr" << counterr << endl;
            float overlapLeft{ ball.right() - blockG.left() };
            float overlapRight{ blockG.right() - ball.left() };
            float overlapTop{ ball.bottom() - blockG.top() };
            float overlapBottom{ blockG.bottom() - ball.top() };
            bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
            bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
            float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
            float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

            if (abs(minOverlapX) < abs(minOverlapY))
            {
                ballFromLeft ? ball.move_left() : ball.move_right();
            }
            else
            {
                ballFromTop ? ball.move_up() : ball.move_down();
            }
        }
    }
    return true;
}

vector<BlockK> Rest::setting_blocksK(unsigned blocksK_x, unsigned  blocksK_y, unsigned  blockK_width, unsigned  blockK_height)
{
    blocksK.clear();
    if (k_block == 1)
    {
        for (float i = 0; i < blocksK_y; i++)
        {
            for (float j = 0; j < blocksK_x; j++)
            {
                {

                    blocksK.emplace_back((j + 1.75) * (static_cast<float>(blockK_width * 3)), (i + 10) * (static_cast<float>(blockK_height + 5)), blockK_width, blockK_height);
                }

            }
        }
    }

    return blocksK;
}

bool Rest::collisionTest(BlockK& blockK, Ball& ball, Paddle& paddle)
{
    if (!isIntersecting(blockK, ball)) return false;
    else 
    {
            float overlapLeft{ ball.right() - blockK.left() };
            float overlapRight{ blockK.right() - ball.left() };
            float overlapTop{ ball.bottom() - blockK.top() };
            float overlapBottom{ blockK.bottom() - ball.top() };
            bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
            bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
            float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
            float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

            if (abs(minOverlapX) < abs(minOverlapY))
            {
                ballFromLeft ? ball.move_left() : ball.move_right();
            }
            else
            {
                ballFromTop ? ball.move_up() : ball.move_down();
            }       
    }
}

void Rest:: buff_setup()
{
    binary_num();
    //cout << "spin"<<buffspin << endl; Do sprawdzania dropu buffów
    int cords = spin = rand() % map_width + frame + 1;
    if (buffspin ==0)
    {
        buff.move_down();
        buff.setPosition(static_cast<float>(cords), frame * 2);
        buff.set_fill_color();
    }
    else if (buffspin == 1)
    {
        buffP.move_down();
        buffP.setPosition(static_cast<float>(cords), frame * 2);
        buffP.set_fill_color();
    }
    else
    {
        buffB.move_down();
        buffB.setPosition(static_cast<float>(cords), frame * 2);
        buffB.set_fill_color();
    }

}




void starting_set();
void buff_setup();
void text_to_set();
void score();
Rest rest;

void Rest::setter()
{

    rest.setting_blocks(blocks_x, blocks_y, block_width, block_height);
    rest.setting_blocksR(blocksR_x, blocksR_y, blockR_width, blockR_height);
    rest.setting_blocksR(blocksR_x, blocksR_y, blockG_width, blockG_height);
    rest.setting_blocksR(blocksR_x, blocksR_y, blockK_width, blockK_height);
    window.setFramerateLimit(60);
    while (true)
    {

        //window.clear(Color::Black);
        window.pollEvent(event);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
           

        }
        if (event.type == Event::Closed)
        {
            window.close();
        }
        text_to_set();
        window.display();

        if (sf::Keyboard::isKeyPressed(Keyboard::Enter))
        {
            starting_set();

        }

        if (sf::Keyboard::isKeyPressed(Keyboard::H))
        {
            hard = true;
            starting_set();
            

        }
 }
}

void text_to_set()
{
    Font font;
    font.loadFromFile("times.ttf");
    Text textdoustawienia;
    Text textdoustawienia_1;
    Text textdoustawienia_2;
    FloatRect textRect;
    textdoustawienia.setFont(font);
    textdoustawienia.setString("Press ENTER to start");
    textdoustawienia.setCharacterSize(36);
    textdoustawienia.setFillColor(sf::Color::White);
    textRect = textdoustawienia.getLocalBounds();
    textdoustawienia.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textdoustawienia.setPosition(xxx / 2.0f, yyy / 2.0f);
    textdoustawienia_2.setFont(font);
    textdoustawienia_2.setString("Press H to enable hard mode");
    textdoustawienia_2.setCharacterSize(20);
    textdoustawienia_2.setFillColor(sf::Color::Red);
    textRect = textdoustawienia_2.getLocalBounds();
    textdoustawienia_2.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textdoustawienia_2.setPosition(xxx / 2.0f, yyy / 1.8f);
    textdoustawienia_1.setFont(font);
    textdoustawienia_1.setString("ARKANOID");
    textdoustawienia_1.setCharacterSize(72);
    textdoustawienia_1.setFillColor(sf::Color::White);
    textRect = textdoustawienia_1.getLocalBounds();
    textdoustawienia_1.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    textdoustawienia_1.setPosition(xxx / 2.0f, yyy / 2.f / 2.0f);
    window.draw(textdoustawienia);
    window.draw(textdoustawienia_1);
    window.draw(textdoustawienia_2);
}

void score()
{
    Font font;
    font.loadFromFile("times.ttf");
    Text score;
    FloatRect textRect;
    score.setFont(font);
    score.setString("SCOCRE :");
    score.setCharacterSize(24);
    score.setFillColor(Color::White);
    textRect = score.getLocalBounds();
    score.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    score.setPosition(500, 50);
    stringstream ss;
    ss << "SCORE : " << counterr;
    score.setString(ss.str());
    window.draw(score);

}

void starting_set()
{
    Ball ball((map_width / 2) + frame, frame + map_height - 75);
    Ball ball2((map_width / 2) + frame + 50, frame + map_height - 75);
    Paddle paddle((map_width / 2) + frame, frame + map_height - 50);
    bool start = false;
    rest.setting_blocks(10, 4, 75, 30);
    rest.setting_blocksR(10, 4, 75, 30);
    rest.setting_blocksG(10, 4, 75, 30);
    rest.setting_blocksK(2, 1, 75, 30);
    seed_num = rand() % 2;
    k_block = rand() % 2;
    vector<Map> map;
    //vector<Frame>frame;
    int i{}, j{};
    //frame.emplace_back((j * frame_width), (i * frame_height), frame_width, frame_height);
    map.emplace_back((frame + ((j) * (map_width))), (frame + ((i) * (map_height))), map_width, map_height);

    while (window.isOpen())
    {
        window.clear(Color::Black);
        window.pollEvent(event);

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            window.close();

        }
        if (event.type == Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::Resized)
            window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
       // for (auto& frame : frame) { window.draw(frame); }
        for (auto& map : map) { window.draw(map); }

        ball.update();
        if (hard == true)
        {
            ball2.update();
        }
        paddle.update();
        buff.update();
        buffP.update();
        buffB.update();
        score();
 
        /*window.draw(text);*/
        rest.collisionTest(paddle, ball);
        rest.collisionTest(paddle, ball);
        rest.collisionTest(paddle, buff, ball);
        rest.collisionTest(paddle, buffP);
        rest.collisionTest(paddle, buffB,ball);
        if (hard == true)
        {
            rest.collisionTest(paddle, ball2);
            rest.collisionTest(paddle, buff, ball2);
            rest.collisionTest(paddle, buffP);
            rest.collisionTest(paddle, buffB, ball2);
        }


        for (auto& block : rest.blocks) if (rest.collisionTest(block, ball, paddle)) break;
        auto iterator = remove_if(begin(rest.blocks), end(rest.blocks), [](Block& block) {return block.is_destroyed(); });
        rest.blocks.erase(iterator, end(rest.blocks));

        for (auto& blockR : rest.blocksR) if (rest.collisionTest(blockR, ball, paddle)) break;
        auto iteratorR = remove_if(begin(rest.blocksR), end(rest.blocksR), [](BlockR& blockR) {return blockR.is_destroyed(); });
        rest.blocksR.erase(iteratorR, end(rest.blocksR));

        for (auto& blockG : rest.blocksG) if (rest.collisionTest(blockG, ball, paddle)) break;
        auto iteratorG = remove_if(begin(rest.blocksG), end(rest.blocksG), [](BlockG& blockG) {return blockG.is_destroyed(); });
        rest.blocksG.erase(iteratorG, end(rest.blocksG));

        for (auto& blockK : rest.blocksK) if (rest.collisionTest(blockK, ball, paddle)) break;


        if (hard == true)
        {
            for (auto& block : rest.blocks) if (rest.collisionTest(block, ball2, paddle)) break;
            auto iterator2 = remove_if(begin(rest.blocks), end(rest.blocks), [](Block& block) {return block.is_destroyed(); });
            rest.blocks.erase(iterator, end(rest.blocks));

            for (auto& blockR : rest.blocksR) if (rest.collisionTest(blockR, ball2, paddle)) break;
            auto iterator2R = remove_if(begin(rest.blocksR), end(rest.blocksR), [](BlockR& blockR) {return blockR.is_destroyed(); });
            rest.blocksR.erase(iteratorR, end(rest.blocksR));

            for (auto& blockG : rest.blocksG) if (rest.collisionTest(blockG, ball2, paddle)) break;
            auto iterator2G = remove_if(begin(rest.blocksG), end(rest.blocksG), [](BlockG& blockG) {return blockG.is_destroyed(); });
            rest.blocksG.erase(iteratorG, end(rest.blocksG));

            for (auto& blockK : rest.blocksK) if (rest.collisionTest(blockK, ball2, paddle)) break;
        }



        window.draw(ball);
        if (hard == true) { window.draw(ball2); }
        window.draw(paddle);
        window.draw(buff);
        window.draw(buffP);
        window.draw(buffB);
        for (auto& block : rest.blocks) { window.draw(block); }
        for (auto& blockR : rest.blocksR) { window.draw(blockR); }
        for (auto& blockG : rest.blocksG) { window.draw(blockG); }
        for (auto& blockK : rest.blocksK) { window.draw(blockK); }
        //window.draw(text);
        window.display();
        if (ball.bottom() > map_height + frame)
        {

            counterr = 0;
            buff.setPosition(map_width + (frame * 2), frame + map_width + 1);
            buffP.setPosition(map_width + (frame * 2), frame + map_width + 1);
            buffB.setPosition(map_width + (frame* 2), frame + map_width + 1);
            starting_set();

        }

        if (ball2.bottom() > map_height + frame)
        {

            counterr = 0;
            buff.setPosition(map_width + (frame * 2), frame + map_width + 1);
            buffP.setPosition(map_width + (frame * 2), frame + map_width + 1);
            buffB.setPosition(map_width + (frame * 2), frame + map_width + 1);
            starting_set();

        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
        {
            counterr = 0;
            if (hard == true)
                hard = false;
            else
                hard = true;
            starting_set();

        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::N)
        {
            if (pause == true)
            {
                ball.paused(pause);
                if (hard == true) { ball2.paused(pause); }
                paddle.paused(pause);
                buff.paused(pause);
                buffP.paused(pause);
                buffB.paused(pause);
                pause = false;
            }
            else
            {
                paddle.paused(pause);
                ball.paused(pause);
                if (hard == true) { ball2.paused(pause); }
                buff.paused(pause);
                buffP.paused(pause);
                buffB.paused(pause);
                pause = true;
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        {
            ball.start(start);
            if (hard == true) { ball2.start(start); }
            start = true;
        }
        if (paddle.clocking > 0)
        {
            paddle.clocking--;
        }
        else
        {
            paddle.paddle_width = 100;

        }
        if (ball.clocking > 0 && ball2.clocking > 0)
        {
            ball.clocking--;
            ball2.clocking--;
           
        }
        else
        {
            ball.shape_1.setFillColor(Color::Green);
            ball.shape_2.setFillColor(Color::White);
            ball2.shape_1.setFillColor(Color::Green);
            ball2.shape_2.setFillColor(Color::White);
        }

    }
}