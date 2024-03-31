
#include "gameIndyCat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <random>


using namespace ilrd;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_PURPLE  "\x1b[35m"
#define ANSI_COLOR_ORANGE  "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


BoardSquare::BoardSquare()
{
    SetRandomColor();
    m_is_occupied = true;
}

bool BoardSquare::IsOccupied() const
{
    return m_is_occupied;
}
        
BoardSquare::SquereColor BoardSquare::GetSquereColor() const
{
    return m_color;
}
        
void BoardSquare::SetRandomColor()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 5);
    m_color = static_cast<SquereColor>(dist(gen));
}

void BoardSquare::SetColor(BoardSquare::SquereColor color)
{
    m_color = color;
}


Board::Board()
{
    GetBoardToRightPosition();
}

void Board::Swap(int x, int y, char direction)
{
    BoardSquare temp;

    if(direction == 'l')
    {
        temp = m_board[y][x];
        m_board[y][x] = m_board[y][x - 1];
        m_board[y][x - 1] = temp;
    }
    else if(direction == 'r')
    {
        temp = m_board[y][x];
        m_board[y][x] = m_board[y][x + 1];
        m_board[y][x + 1] = temp;
    }
    else if(direction == 'u')
    {
        temp = m_board[y][x];
        m_board[y][x] = m_board[y - 1][x];
        m_board[y - 1][x] = temp;
    }
    else
    {
        temp = m_board[y][x];
        m_board[y][x] = m_board[y + 1][x];
        m_board[y + 1][x] = temp;
    }
}

void Board::ShuffleBoard()
{
    std::cout<< "Shuffle Board" << std::endl;

    for(size_t i = 0 ; i < 10 ; ++i)
    {
        std::cout << "" << std::endl;

        for(size_t j = 0; j < 10 ; ++j)
        {
            m_board[i][j].SetRandomColor();
        }
    }
    GetBoardToRightPosition();
}

void Board::PrintBoard() const
{

    std::cout << "  ";
    for(int i = 0; i < 10 ; ++i)
    {
        std::cout << i << " ";
    }

    for(size_t i = 0 ; i < 10 ; ++i)
    {
        std::cout << "" << std::endl;

        for(size_t j = 0; j < 10 ; ++j)
        {
            if(j == 0)
            {
                std::cout << i << " ";
            }

            int squareColor = static_cast<int>(m_board[i][j].GetSquereColor());

            switch(squareColor)
            {
                case 0:
                std::cout << ANSI_COLOR_RED << "R " << ANSI_COLOR_RESET;
                break;

                case 1:
                std::cout << ANSI_COLOR_GREEN << "G " << ANSI_COLOR_RESET;
                break;

                case 2:
                std::cout << ANSI_COLOR_YELLOW <<  "Y " << ANSI_COLOR_RESET;
                break;

                case 3:
                std::cout << ANSI_COLOR_BLUE <<  "B " << ANSI_COLOR_RESET;
                break;

                case 4:
                std::cout << ANSI_COLOR_PURPLE << "P " << ANSI_COLOR_RESET;
                break;

                case 5:
                std::cout << ANSI_COLOR_ORANGE <<  "O " << ANSI_COLOR_RESET;
                break;

                default:
                std::cout << "Wrong color" << std::endl;
                break;
            };
        }
    }
    std::cout << "" << std::endl;
}

bool Board::IsThereSwapAvailable() const
{
    int ColorLUT[6] = {0};

    for(int y = 0 ; y < 10 ; ++y)
    {
        for(int x = 0; x < 10 ; ++x)
        {
            /*left*/
            if(x - 3 >= 0)
            {
                for(size_t i = 0; i < 6; ++i)
                {
                    ColorLUT[i] = 0;
                }

                ++ColorLUT[static_cast<int>(m_board[y][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x - 1].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x - 2].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x - 3].GetSquereColor())];

                for(size_t i = 0; i < 6; ++i)
                {
                    if(ColorLUT[i] == 3)
                    {
                        return true;
                    }
                }
            }

            /*right*/
            if(x + 3 <= 9)
            {
                for(size_t i = 0; i < 6; ++i)
                {
                    ColorLUT[i] = 0;
                }

                ++ColorLUT[static_cast<int>(m_board[y][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x + 1].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x + 2].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y][x + 3].GetSquereColor())];

                for(size_t i = 0; i < 6; ++i)
                {
                    if(ColorLUT[i] == 3)
                    {
                        return true;
                    }
                }
            }

            /*up*/
            if(y - 3 >= 0)
            {
                for(size_t i = 0; i < 6; ++i)
                {
                    ColorLUT[i] = 0;
                }

                ++ColorLUT[static_cast<int>(m_board[y][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y - 1][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y - 2][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y - 3][x].GetSquereColor())];

                for(size_t i = 0; i < 6; ++i)
                {
                    if(ColorLUT[i] == 3)
                    {
                        return true;
                    }
                }
            }

            /*down*/
            if(y + 3 <= 9)
            {
                for(size_t i = 0; i < 6; ++i)
                {
                    ColorLUT[i] = 0;
                }

                ++ColorLUT[static_cast<int>(m_board[y][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y + 1][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y + 2][x].GetSquereColor())];
                ++ColorLUT[static_cast<int>(m_board[y + 3][x].GetSquereColor())];

                for(size_t i = 0; i < 6; ++i)
                {
                    if(ColorLUT[i] == 3)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void Board::GetBoardToRightPosition()
{
    for(int y = 0 ; y < 10 ; ++y)
    {
        for(int x = 0; x < 10 ; ++x)
        {
            /*left*/
            if(x - 2 >= 0)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y][x - 1].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y][x - 2].GetSquereColor())
                   {
                        while(m_board[y][x].GetSquereColor() == m_board[y][x - 1].GetSquereColor())
                        {
                            m_board[y][x].SetRandomColor();
                        }
                   }
            }

            /*right*/
            if(x + 2 <= 9)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y][x + 1].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y][x + 2].GetSquereColor())
                   {
                        while(m_board[y][x].GetSquereColor() == m_board[y][x + 1].GetSquereColor())
                        {
                            m_board[y][x].SetRandomColor();
                        }
                   }
            }

            /*up*/
            if(y - 2 >= 0)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y - 1][x].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y - 2][x].GetSquereColor())
                   {
                        while(m_board[y][x].GetSquereColor() == m_board[y - 1][x].GetSquereColor())
                        {
                            m_board[y][x].SetRandomColor();
                        }
                   }
            }

            /*down*/
            if(y + 2 <= 9)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y + 1][x].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y + 2][x].GetSquereColor())
                   {
                        while(m_board[y][x].GetSquereColor() == m_board[y + 1][x].GetSquereColor())
                        {
                            m_board[y][x].SetRandomColor();
                        }
                   }
            }
        }
    }
    
}


void Board::RemoveSameSquares()
{
    for(int y = 0 ; y < 10 ; ++y)
    {
        for(int x = 0; x < 10 ; ++x)
        {
            /*left*/
            if(x - 2 >= 0)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y][x - 1].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y][x - 2].GetSquereColor())
                   {
                        for(size_t i = y; i > 0; --i)
                        {
                            for(size_t j = x - 2; j < x + 1; ++j)
                            {
                                m_board[i][j] = m_board[i - 1][j];
                            }
                        }
                        for(size_t j = x - 2; j < x + 1; ++j)
                        {
                            m_board[0][j].SetRandomColor();
                        }
                        std::cout << "After Remove and adding random color to the fields" << std::endl;
                   }
            }

            /*right*/
            if(x + 2 <= 9)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y][x + 1].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y][x + 2].GetSquereColor())
                   {
                        for(size_t i = y; i > 0; --i)
                        {
                            for(size_t j = x; j < x + 3; ++j)
                            {
                                m_board[i][j] = m_board[i - 1][j];
                            }
                        }
                        for(size_t j = x ; j < x + 3; ++j)
                        {
                            m_board[0][j].SetRandomColor();
                        }
                        std::cout << "After Remove and adding random color to the fields" << std::endl;
                   }
            }

            /*up*/
            if(y - 2 >= 0)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y - 1][x].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y - 2][x].GetSquereColor())
                   {
                        for(int j = y - 3; j >= 0; --j)
                        {
                            m_board[j + 3][x] = m_board[j][x];
                        }

                        for(size_t j = 0 ; j < 3; ++j)
                        {
                            m_board[j][x].SetRandomColor();
                        }
                        std::cout << "After Remove and adding random color to the fields" << std::endl;
                   }
            }

            /*down*/
            if(y + 2 <= 9)
            {
                if(m_board[y][x].GetSquereColor() == m_board[y + 1][x].GetSquereColor() 
                   && m_board[y][x].GetSquereColor() == m_board[y + 2][x].GetSquereColor())
                   {
                        for(int j = y - 1; j >= 0; --j)
                        {
                            m_board[j + 3][x] = m_board[j][x];
                        }

                        for(size_t j = 0 ; j < 3; ++j)
                        {
                            m_board[j][x].SetRandomColor();
                        }
                        std::cout << "After Remove and adding random color to the fields" << std::endl;
                   }
            }
        }
    }
}

Game::Game() : m_is_running(true)
{

}

void Game::Run()
{
    while(true)
    {
        GetUserDataInput();
        if(m_is_running == false)
        {
            break;
        }
        PreapareForNewRound();
        std::cout << "After prepare operation: " << std::endl;
        m_board.PrintBoard();
    }
}
        

        
void Game::Exit()
{
    m_is_running = false;
}

void Game::MoveSquare(std::string user_input)
{
    int x = user_input[1] - '0';
    int y = user_input[2] - '0';

    m_board.Swap(x, y, user_input[3]);
    std::cout << "Board after Swap: " << std::endl;
    m_board.PrintBoard();
}

void Game::GetUserDataInput()
{
    std::string command = "wrong";

    while(!(command[0] == 'm' && command[1] >= '0' && command[1] <= '9' &&
         command[2] >= '0' && command[2] <= '9' &&
         (command[3] == 'l' || command[3] == 'r' || command[3] == 'u' || command[3] == 'd')) &&
        command != "q")
    {
        std::cout << "Please enter command: " << std::endl;
        std::cout << "Enter m to make a swap with the x and y of the location and the direction in one letter" << std::endl;
        std::cout << "Enter q to exit" << std::endl;
        m_board.PrintBoard();
        std::cout << "Please enter your command: ";
        std::cin >> command;
        if((command[0] == 'm' && command[1] == '0' && command[3] == 'l') 
            || (command[0] == 'm' && command[1] == '9' && command[3] == 'r') 
            || (command[0] == 'm' && command[2] == '0' && command[3] == 'u') 
            || (command[0] == 'm' && command[2] == '9' && command[3] == 'd'))
        {
            command = "wrong";
        }
    }

    if(command == "q")
    {
        m_is_running = false;
        return;
    }
    else
    {
        MoveSquare(command);
    }
    m_board.RemoveSameSquares();
}
        
void Game::PreapareForNewRound()
{
    m_board.RemoveSameSquares();

    m_board.PrintBoard();

    while(m_board.IsThereSwapAvailable() != true)
    {
        m_board.ShuffleBoard();
    }
}