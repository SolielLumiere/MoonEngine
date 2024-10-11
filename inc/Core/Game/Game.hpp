#include "IGame.hpp"

namespace MoonEngine 
{

    class Game : protected IGame
    {
        
    public:
        Game(unsigned int width, unsigned int height, const std::string &title);
        ~Game();

        virtual void start() override;

    protected:

        virtual void update() override;
        void handleEvents() override;
        void render() override;
        void onResize() override;
        void onCreate() override;

        float deltaTime();

    private:
        sf::Clock mClock;

    };

}

