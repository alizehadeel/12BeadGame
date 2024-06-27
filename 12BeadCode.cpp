#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;

void setPositions(Vector2f circlePosition[5][5], int a, int b)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            circlePosition[i][j] = Vector2f(a, b);
            a += 222;
        }
        b += 223, a = 502;
    }
    return;
}
void drawCircles(RenderWindow& window, CircleShape Circles[5][5], int Board[5][5], Vector2f circlePosition[5][5], Texture circle1Texture, Texture circle2Texture)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (Board[i][j] == 1)
            {
                Circles[i][j].setRadius(35);
                Circles[i][j].setFillColor(Color::White);
                Circles[i][j].setPosition(circlePosition[i][j]);
                Circles[i][j].setOrigin(Vector2f(35, 35));
                Circles[i][j].setTexture(&circle1Texture);
            }
            else if (Board[i][j] == 2)
            {
                Circles[i][j].setRadius(35);
                Circles[i][j].setFillColor(Color::White);
                Circles[i][j].setPosition(circlePosition[i][j]);
                Circles[i][j].setOrigin(Vector2f(35, 35));
                Circles[i][j].setTexture(&circle2Texture);
            }
            else if (Board[i][j] == 0)
            {
                Circles[i][j].setRadius(25);
                Circles[i][j].setFillColor(Color::Transparent);
                Circles[i][j].setPosition(circlePosition[i][j]);
                Circles[i][j].setOrigin(Vector2f(25, 25));
            }
            window.draw(Circles[i][j]);
        }
    return;
}
void swap(int board[5][5], int Btemp, int Ttemp, int storei[2], int storej[], int& currentplayer, int& otherplayer)
{
    Btemp = board[storei[0]][storej[0]];
    board[storei[0]][storej[0]] = board[storei[1]][storej[1]];
    board[storei[1]][storej[1]] = Btemp;

    Ttemp = currentplayer;
    currentplayer = otherplayer;
    otherplayer = Ttemp;

    return;
}
void click1(RenderWindow& window, CircleShape Circles[5][5], int board[5][5], int Btemp, int Ttemp, int storei[], int storej[], int& currentplayer, int& otherplayer, int& click, int& i, int& j)
{
    Vector2i mousePos = Mouse::getPosition(window);
    Vector2f FmousePos(float(mousePos.x), float(mousePos.y));
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (Circles[i][j].getGlobalBounds().contains(FmousePos))
            {
                if (board[i][j] == currentplayer)
                {
                    click++;
                    storei[0] = i;
                    storej[0] = j;
                    Circles[i][j].setRadius(50);
                    Circles[i][j].setOrigin(50, 50);
                    cout << i << j << endl;
                    break;
                }

            }
        }
    }
}
void click2(RenderWindow& window, CircleShape Circles[5][5], int board[5][5], int Btemp, int Ttemp, int storei[], int storej[], int& currentplayer, int& otherplayer, int& click, int& i2, int& j2, int& i, int& j, RectangleShape choose)
{
    Vector2i mousePos = Mouse::getPosition(window);
    Vector2f FmousePos(float(mousePos.x), float(mousePos.y));
    for (i2 = 0; i2 < 5; i2++)
    {
        for (j2 = 0; j2 < 5; j2++)
        {
            if (Circles[i2][j2].getGlobalBounds().contains(FmousePos))
            {
                if (board[i2][j2] == 0)
                {
                    if (storei[0] == 0)
                    {
                        if (storej[0] == 0)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    if (board[0][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    if (board[1][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 1)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 3)
                                {
                                    if (board[0][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 2)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    if (board[0][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 4)
                                {
                                    if (board[0][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 3)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 1)
                                {
                                    if (board[0][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 4)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    if (board[0][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[0][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][4] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                    }
                    else if (storei[0] == 1)
                    {
                        if (storej[0] == 0)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 0)
                                {
                                    if (board[2][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 1)
                        {
                            cout << i2 << " " << j2 << endl;
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    if (board[2][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    cout << 1;
                                    if (board[2][2] == otherplayer)
                                    {
                                        cout << 2;
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    if (board[1][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 2)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 0)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (storej[0] == 3)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    if (board[1][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    if (board[2][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (storej[0] == 4)
                        {
                            if (i2 == 0)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 4)
                                {
                                    if (board[2][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][4] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else if (storei[0] == 2)
                    {
                        if (storej[0] == 0)
                        {
                            if (i2 == 1)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    if (board[1][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[2][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    if (board[3][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 1)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 1)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 1)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 2)
                        {
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 0)
                            {
                                if (j2 == 0)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    if (board[2][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }

                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    if (board[2][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 3)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 3)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 3)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 4)
                        {
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][4] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 0)
                            {
                                if (j2 == 2)
                                {
                                    if (board[1][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[1][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[2][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    if (board[3][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][4] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                    }
                    else if (storei[0] == 3)
                    {
                        if (storej[0] == 0)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 0)
                                {
                                    if (board[2][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }

                        }
                        else if (storej[0] == 1)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    if (board[2][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    if (board[3][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (storej[0] == 2)
                        {
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 0)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 2)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 3)
                            {
                                if (j2 == 4)
                                {
                                    if (board[1][1] == otherplayer)
                                    {
                                        storei[3] = i2;
                                        storej[3] = j2;
                                        board[1][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (storej[0] == 3)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            else if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            else if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    if (board[3][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 1)
                                {
                                    if (board[2][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 3)
                                {
                                    if (board[2][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                        }
                        else if (storej[0] == 4)
                        {
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }
                            if (i2 == 1)
                            {
                                if (j2 == 4)
                                {
                                    if (board[2][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[2][4] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }
                            }

                        }
                    }
                    else if (storei[0] == 4)
                    {
                        if (storej[0] == 0)
                        {
                            if (i2 == 3)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    if (board[3][0] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][0] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    if (board[4][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 1)
                        {
                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 1)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 3)
                                {
                                    if (board[4][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 2)
                        {
                            if (i2 == 4)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 1)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }
                            }
                            if (i2 == 4)
                            {
                                if (j2 == 0)
                                {
                                    if (board[4][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 0)
                                {
                                    if (board[3][1] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    if (board[4][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }

                        }
                        else if (storej[0] == 3)
                        {
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 3)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 1)
                                {
                                    if (board[4][2] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][2] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                        else if (storej[0] == 4)
                        {
                            if (i2 == 3)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 3)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 3)
                            {
                                if (j2 == 4)
                                {
                                    storei[1] = i2;
                                    storej[1] = j2;
                                    cout << 2;
                                    swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                    cout << i2 << " " << j2 << endl;
                                    click = 0;
                                    break;
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 4)
                                {
                                    if (board[3][4] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][1] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 2)
                            {
                                if (j2 == 2)
                                {
                                    if (board[3][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[3][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                            if (i2 == 4)
                            {
                                if (j2 == 2)
                                {
                                    if (board[4][3] == otherplayer)
                                    {
                                        storei[1] = i2;
                                        storej[1] = j2;
                                        board[4][3] = 0;
                                        swap(board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer);
                                        cout << i2 << " " << j2 << endl;
                                        click = 0;
                                        break;
                                    }
                                }

                            }
                        }
                    }
                }
            }
            else if (choose.getGlobalBounds().contains(FmousePos))
            {
                click = 0;
                click1(window, Circles, board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer, click, i, j);
            }
        }
    }
}
void winners(RenderWindow& window, int board[5][5])
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (board[i][j] == 1)
                count1++;
            else if (board[i][j] == 2)
                count2++;

    if (count1 == 0)
    {
        RectangleShape result(Vector2f(400, 400));
        result.setPosition(Vector2f(1460, 80));
        result.setFillColor(Color::White);
        Texture resultTexture;
        resultTexture.loadFromFile("p2.png");
        result.setTexture(&resultTexture);
        result.setTextureRect(sf::IntRect(0, 0, resultTexture.getSize().x, resultTexture.getSize().y));

        RectangleShape restart((Vector2f(150, 80)));
        restart.setPosition(Vector2f(1500, 370));
        restart.setFillColor(Color::White);
        Texture restartTexture;
        restartTexture.loadFromFile("restart.png");
        restart.setTexture(&restartTexture);

        RectangleShape close((Vector2f(150, 80)));
        close.setPosition(Vector2f(1670, 370));
        close.setFillColor(Color::White);
        Texture closeTexture;
        closeTexture.loadFromFile("close.png");
        close.setTexture(&closeTexture);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            Vector2f FmousePos(float(mousePos.x), float(mousePos.y));
            cout << FmousePos.x << " " << FmousePos.y << endl;
            if (close.getGlobalBounds().contains(FmousePos))
            {
                window.close();
            }
            else if (restart.getGlobalBounds().contains(FmousePos))
            {
                board[0][0] = 1; board[0][1] = 1; board[0][2] = 1; board[0][3] = 1; board[0][4] = 1;
                board[1][0] = 1; board[1][1] = 1; board[1][2] = 1; board[1][3] = 1; board[1][4] = 1;
                board[2][0] = 1; board[2][1] = 1; board[2][2] = 0; board[2][3] = 2; board[2][4] = 2;
                board[3][0] = 2; board[3][1] = 2; board[3][2] = 2; board[3][3] = 2; board[3][4] = 2;
                board[4][0] = 2; board[4][1] = 2; board[4][2] = 2; board[4][3] = 2; board[4][4] = 2;
            }
        }

        window.draw(result);
        window.draw(restart);
        window.draw(close);
    }
    else if (count2 == 0)
    {
        RectangleShape result(Vector2f(400, 400));
        result.setPosition(Vector2f(1460, 80));
        result.setFillColor(Color::White);
        Texture resultTexture;
        resultTexture.loadFromFile("p1.png");
        result.setTexture(&resultTexture);
        result.setTextureRect(sf::IntRect(0, 0, resultTexture.getSize().x, resultTexture.getSize().y));

        RectangleShape restart((Vector2f(150, 80)));
        restart.setPosition(Vector2f(1500, 370));
        restart.setFillColor(Color::White);
        Texture restartTexture;
        restartTexture.loadFromFile("restart.png");
        restart.setTexture(&restartTexture);

        RectangleShape close((Vector2f(150, 80)));
        close.setPosition(Vector2f(1670, 370));
        close.setFillColor(Color::White);
        Texture closeTexture;
        closeTexture.loadFromFile("close.png");
        close.setTexture(&closeTexture);

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            Vector2f FmousePos(float(mousePos.x), float(mousePos.y));
            cout << FmousePos.x << " " << FmousePos.y << endl;
            if (close.getGlobalBounds().contains(FmousePos))
            {
                window.close();
            }
            else if (restart.getGlobalBounds().contains(FmousePos))
            {
                board[0][0] = 1; board[0][1] = 1; board[0][2] = 1; board[0][3] = 1; board[0][4] = 1;
                board[1][0] = 1; board[1][1] = 1; board[1][2] = 1; board[1][3] = 1; board[1][4] = 1;
                board[2][0] = 1; board[2][1] = 1; board[2][2] = 0; board[2][3] = 2; board[2][4] = 2;
                board[3][0] = 2; board[3][1] = 2; board[3][2] = 2; board[3][3] = 2; board[3][4] = 2;
                board[4][0] = 2; board[4][1] = 2; board[4][2] = 2; board[4][3] = 2; board[4][4] = 2;
            }
        }

        window.draw(result);
        window.draw(restart);
        window.draw(close);
    }

}
void saveGame(const int board[5][5])
{
    std::ofstream saveFile("savegame.txt");

    if (saveFile.is_open())
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                saveFile << board[i][j] << " ";
            }
            saveFile << "\n";
        }

        saveFile.close();
        std::cout << "Game saved successfully.\n";
    }
    else
    {
        std::cerr << "Unable to open savegame.txt for saving.\n";
    }
}
void loadGame(int board[5][5])
{
    std::ifstream loadFile("savegame.txt");

    if (loadFile.is_open()) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                loadFile >> board[i][j];
            }
        }

        loadFile.close();
        std::cout << "Game loaded successfully.\n";
    }
    else
    {
        std::cerr << "Unable to open savegame.txt for loading.\n";
    }
}

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "Bead 12", Style::Close);

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Board2.png"))
    {
        cout << "Failed to load background image!" << endl;
        return -1;
    }
    Sprite backgroundImage;
    backgroundImage.setTexture(backgroundTexture);

    CircleShape Circles[5][5];

    float a = 502, b = 84;
    Vector2f circlePosition[5][5];
    setPositions(circlePosition, a, b);

    int board[5][5] = { {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 0, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2} };

    int storei[2] = { 0 }, storej[2] = { 0 }, Btemp = 0, i, j, i2, j2;

    int currentplayer = 1, otherplayer = 2, Ttemp = 0, click = 0;

    RectangleShape choose((Vector2f(150, 80)));
    choose.setPosition(Vector2f(1480, 550));
    choose.setFillColor(Color::White);
    Texture chooseTexture;
    chooseTexture.loadFromFile("choose.png");
    choose.setTexture(&chooseTexture);

    RectangleShape saveProgress((Vector2f(150, 80)));
    saveProgress.setPosition(Vector2f(280, 550));
    saveProgress.setFillColor(Color::White);
    Texture saveTexture;
    saveTexture.loadFromFile("save.png");
    saveProgress.setTexture(&saveTexture);

    RectangleShape loadProgress((Vector2f(150, 80)));
    loadProgress.setPosition(Vector2f(280, 650));
    loadProgress.setFillColor(Color::White);
    Texture loadTexture;
    loadTexture.loadFromFile("load.png");
    loadProgress.setTexture(&loadTexture);

    Texture circle2Texture;
    circle2Texture.loadFromFile("BeadW.png");
    Texture circle1Texture;
    circle1Texture.loadFromFile("BeadP.png");

    RectangleShape turn1((Vector2f(320, 130)));
    turn1.setPosition(Vector2f(150, 310));
    turn1.setFillColor(Color::White);
    Texture turn1Texture;
    turn1Texture.loadFromFile("turn1.png");
    turn1.setTexture(&turn1Texture);

    RectangleShape turn2((Vector2f(320, 130)));
    turn2.setPosition(Vector2f(150, 310));
    turn2.setFillColor(Color::White);
    Texture turn2Texture;
    turn2Texture.loadFromFile("turn2.png");
    turn2.setTexture(&turn2Texture);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            window.clear();
            window.draw(backgroundImage);
            drawCircles(window, Circles, board, circlePosition, circle1Texture, circle2Texture);
            window.draw(choose);
            window.draw(saveProgress);
            window.draw(loadProgress);
            if (currentplayer == 1)
            {
                window.draw(turn1);;
            }
            else if (currentplayer == 2)
            {
                window.draw(turn2);;
            }
            if (Mouse::isButtonPressed(Mouse::Left) && click == 0)
            {
                click1(window, Circles, board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer, click, i, j);
            }
            else if (Mouse::isButtonPressed(Mouse::Left) && click == 1)
            {
                click2(window, Circles, board, Btemp, Ttemp, storei, storej, currentplayer, otherplayer, click, i2, j2, i, j, choose);
            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2i mousePos = Mouse::getPosition(window);
                Vector2f FmousePos(float(mousePos.x), float(mousePos.y));
                cout << FmousePos.x << " " << FmousePos.y << endl;
                if (saveProgress.getGlobalBounds().contains(FmousePos))
                {
                    saveGame(board);
                }
                else if (loadProgress.getGlobalBounds().contains(FmousePos))
                {
                    loadGame(board);
                }
            }
            winners(window, board);
            window.display();
        }

    }

    return 0;
}


