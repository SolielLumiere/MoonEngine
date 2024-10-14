#include "ISpriteSheet.hpp"

namespace MoonEngine 
{
    class SpriteSheet : public ISpriteSheet
    {   
        public:
            SpriteSheet(const std::string &path);
        public:
            void createSprite(unsigned int id, int top, int left, int width, int height) override;
            sf::Sprite &getSprite(unsigned int id) override;
            virtual ~SpriteSheet();
    };
}
