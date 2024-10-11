#include "ISpriteSheet.hpp"

namespace MoonEngine 
{
    class SpriteSheet : public ISpriteSheet
    {   
        protected:
            SpriteSheet(const std::string &path);
            virtual void createSprites() = 0;

        public:
            void createSprite(unsigned int id, int top, int left, int width, int height) override;
            sf::Sprite &getSprite(unsigned int id) override;
            virtual ~SpriteSheet();
    };
}
