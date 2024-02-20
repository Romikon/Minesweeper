#include <iostream>
#include <random>

using namespace std;


void Board(int a[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a[i][j] = 35;
        }
    }
}

void Show_board(int a[10][10])
{

    int numbers1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int numbers2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "\t";

    for (int i = 0; i < 10; i++)
    {
        cout << numbers1[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << numbers2[i] << "\t";
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] != 35)
            {
                cout << a[i][j] << "\t";
            }
            else
            {
                cout << static_cast<char>(a[i][j]) << "\t";
            }
        }
        cout << endl;
    }

}

void Random(int horizont[5], int vertical[5])
{
    for (int i = 0; i < 5; i++)
    {
        horizont[i] = 1 + rand() % 10;
        vertical[i] = 1 + rand() % 10;
    }

    cout << "Mines:" << endl;

    for (int i = 0; i < 5; i++)
    {

        cout << horizont[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << vertical[i] << " ";
    }
    cout << endl;
}


bool User_choise(int a[10][10], int horizont[5], int vertical[5])
{
    int num1;
    int num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    if (num1 < 1 || num2 < 1 || num1 > 10 || num2 > 10)
    {
        cout << "Enter valid number" << endl;
        User_choise(a, horizont, vertical);
    }
    else
    {
        int counter = 0;
        int start_h = num1 - 1;
        int start_v = num2 - 1;


        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (start_h == horizont[j] && start_v == vertical[j])
                {
                    counter++;
                }
            }
            start_v++;
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (start_h == horizont[j] && start_v == vertical[j])
                {
                    counter++;
                }
            }
            start_h++;
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (start_h == horizont[j] && start_v == vertical[j])
                {
                    counter++;
                }
            }
            start_v--;
        }


        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (start_h == horizont[j] && start_v == vertical[j])
                {
                    counter++;
                }
            }
            start_h--;
        }


        a[num1 - 1][num2 - 1] = counter;


        for (int i = 0; i < 5; i++)
        {
            if (num1 == horizont[i] && num2 == vertical[i])
            {
                return false;
            }
        }

        Show_board(a);
    }
}



int main()
{
    srand(time(0));

    bool is_lose = true;
    bool is_lose1 = true;

    int a[10][10];
    int horizont[5];
    int vertical[5];

    Board(a);
    Show_board(a);
    Random(horizont, vertical);

    while (is_lose)
    {
        is_lose = User_choise(a, horizont, vertical);
    }

    cout << "You lose(";

}
