#ifndef __INDY_CAT_GAME_HPP__
#define __INDY_CAT_GAME_HPP__

#include <string>

namespace ilrd
{
    class BoardSquare
    {   
        public:

        BoardSquare();
        ~BoardSquare() = default;
        BoardSquare(const BoardSquare& other) = default;
        BoardSquare& operator=(const BoardSquare& other) = default;

        enum SquereColor
        {
            RED = 0,
            GREEN = 1,
            YELLOW = 2,
            BLUE = 3,
            PURPLE = 4,
            ORANGE = 5
        };

        bool IsOccupied() const;
        SquereColor GetSquereColor() const;
        void SetRandomColor();
        void SetColor(SquereColor color);

        private:

        SquereColor m_color;
        bool m_is_occupied = false;
    };

    class Board
    {
        public:

        Board();
        ~Board() = default;
        
        void ShuffleBoard(); /*Mix Board*/
        void PrintBoard() const;
        void GetBoardToRightPosition(); /*Check if board is shuffled well*/
        void Swap(int x, int y, char direction);
        void RemoveSameSquares();
        bool IsThereSwapAvailable() const;

        private:

        Board(const Board& other) = delete;
        Board& operator=(const Board& other) = delete;

        BoardSquare m_board[10][10];
    };

    class Game
    {
        public:

        Game();
        ~Game() = default;

        void Run();
        void Exit();
        void GetUserDataInput();
        void PreapareForNewRound();
        void MoveSquare(std::string user_input);

        private:

        Game(const Game& other) = delete;
        Game& operator=(const Game& other) = delete;

        Board m_board;
        bool m_is_running = false;
        std::string m_command;
    };
}

#endif /*__INDY_CAT_GAME_HPP__*/