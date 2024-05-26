#pragma once
#include <vector>
#include<iostream>
#include "Cell.h"
#include<windows.h>
#include<conio.h>
using namespace std;
template <typename T>
class MiniExcel
{
private:
    Cell<T>* root;
    Cell<T>* current;
    int rows = 0;
    int height = 5;
    int width = 5;
    int cols = 0;
public:
    MiniExcel() {
        root = new Cell<T>();
        current = root;
        for (int i = 0; i < 4; i++) {
            InsertRowBelow();
            InsertColumnToRight();
        }
        root = GetCellLeft();
    }
    void SetSelectedCell(int i, int j) {
        Cell<T>* temp = GetCell(i, j);
        if (temp != nullptr) {
            current = temp;
        }
    }
    Cell<T>* GetCell(int i, int j) {
        Cell<T>* temp = GetCellLeft();

        for (int row = 0; row < i; row++) {
            if (temp->down != nullptr)
                temp = temp->down;
            else
                return nullptr;
        }

        for (int col = 0; col < j; col++) {
            if (temp->right != nullptr)
                temp = temp->right;
            else
                return nullptr;
        }

        return temp;
    }

    Cell<T>* GetTopCell()
    {
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }
    Cell<T>* GetDownCell()
    {
        while (current->down != nullptr)
        {
            current = current->down;
        }
        return current;
    }
    Cell<T>* GetUpCell()
    {
        while (current->up != nullptr)
        {
            current = current->up;
        }
        return current;
    }
    Cell<T>* GetCellLeft()
    {
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }


    void InsertColumnToRight() {

        Cell<T>* temp = GetTopCell();
        while (temp)
        {
            Cell<T>* newCell = new Cell<T>();
            temp->right = newCell;
            temp->right->left = temp;
            temp = temp->down;
        }
        temp = GetTopCell();
        while (temp->left->down)
        {
            temp->down = temp->left->down->right;
            temp->down->up = temp;
            temp = temp->down;
        }
        rows++;
    }
    void InsertRowBelow() {
        Cell <T>* temp = GetDownCell();
        while (temp)
        {
            Cell<T>* newCell = new Cell<T>();
            temp->down = newCell;
            temp->down->up = temp;
            temp = temp->right;
        }
        temp = GetDownCell();
        while (temp->up->right)
        {
            temp->right = temp->up->right->down;
            temp->right->left = temp;
            temp = temp->right;
        }
        cols++;
    }
    void InsertRowLeft()
    {
        Cell<T>* temp = GetCellLeft();
        while (temp)
        {
            Cell<T>* newCell = new Cell<T>();
            temp->left = newCell;
            temp->left->right = temp;
            temp = temp->down;
        }
        temp = GetCellLeft();
        while (temp->right->down)
        {
            temp->down = temp->right->down->left;
            temp->down->up = temp;
            temp = temp->down;
        }
        rows++;
    }
    void InsertRowAbove() {
        Cell <T>* temp = GetUpCell();
        while (temp)
        {
            Cell<T>* newCell = new Cell<T>();
            temp->up = newCell;
            temp->up->down = temp;
            temp = temp->right;
        }
        temp = GetUpCell();
        while (temp->down->right)
        {
            temp->right = temp->down->right->up;
            temp->right->left = temp;
            temp = temp->right;
        }
        cols++;
    }
    void printGrid() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int cell_i, cell_j;
                current->GetPosition(cell_i, cell_j);
                if (i == cell_i && j == cell_j) {
                    printSelectedCell(i * (width + 1), j * (width + 1));
                }
                else {
                    printCell(i * (width + 1), j * (width + 1));
                }
            }
        }
    }

    void gotoxy(int x, int y) {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void printCell(int x, int y) {
        gotoxy(x, y);
        for (int w = 0; w < width; w++) {
            cout << "-";
        }
        cout << '-' << endl;
        for (int h = 0; h < height; h++) {
            gotoxy(x, y + h + 1);
            cout << "| ";
            for (int w = 0; w < width - 3; w++) {
                cout << "  ";
            }
            cout << '|' << endl;
        }
        gotoxy(x, y + height + 1);
        for (int w = 0; w < width; w++) {
            cout << "-";
        }
        cout << '-' << endl;
    }
    void printSelectedCell(int x, int y) {
        gotoxy(x, y);

        for (int w = 0; w < width; w++) {
            cout << "\033[1;31m-";
        }
        cout << "-\033[0m" << endl;

        for (int h = 0; h < width; h++) {
            gotoxy(x, y + h + 1);
            cout << "\033[1;31m| \033[0m";
            for (int w = 0; w < width - 3; w++) {
                cout << "  ";
            }
            cout << "\033[1;31m| \033[0m" << endl;
        }
        gotoxy(x, y + width + 1);
        for (int w = 0; w < width; w++) {
            cout << "\033[1;31m-";
        }
        cout << "-\033[0m" << endl;
    }
    void moveSelectedCell(char direction) {
        switch (direction) {
        case 'u':
            if (current->up != nullptr)
                current = current->up;
            else
                InsertRowAbove();
            break;
        case 'd':
            if (current->down != nullptr)
                current = current->down;
            else
                InsertRowBelow();
            break;
        case 'l':
            if (current->left != nullptr)
                current = current->left;
            else
                InsertRowLeft();
            break;
        case 'r':
            if (current->right != nullptr)
                current = current->right;
            else
                InsertColumnToRight();
            break;
        default:
            cout << "Invalid direction. Use 'u' (up), 'd' (down), 'l' (left), 'r' (right)." << endl;
        }

        printGrid(); // Update the grid after moving
    }

};

////////////////////////CellCLass//////////////////////////////
#pragma once
#include<conio.h>
template<typename T>
class Cell
{
public:
    T data;
    Cell* up;
    Cell* down;
    Cell* left;
    Cell* right;
    Cell(T value = T()) : data(value), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
    void GetPosition(int& i, int& j) {
        Cell* temp = this;
        i = 0;
        j = 0;

        while (temp->up != nullptr) {
            temp = temp->up;
            i++;
        }

        temp = this;
        while (temp->left != nullptr) {
            temp = temp->left;
            j++;
        }
        temp = this;
    }
};

