#include <SFML/Graphics.hpp>

int main() {
    // Create a window with the specified size and title
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop to keep the window open
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw here (if needed)

        // End the current frame
        window.display();
    }

    return 0;
}