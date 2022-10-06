#include <iostream>

#define N 4

int mat[N][N];

void solveLeft()
{
    for(int i = 0; i<N; ++i)
    {
        int a = 0;

        for(int j = 1; j<N; ++j)
            if(mat[i][j] != 0)
            {
                while(mat[i][j-1] == 0 && j>0){
                    std::swap(mat[i][j], mat[i][j-1]);
                    --j;
                }

                if(mat[i][j] == mat[i][j-1] && j>a){
                    mat[i][j-1] += mat[i][j];
                    mat[i][j] = 0;
                    a = j;
                }
            }
    }
}

void solveRight()
{
    for(int i = 0; i<N; ++i)
    {
        int a = N-1;

        for(int j = N-2; j>=0; --j)
            if(mat[i][j] != 0)
            {
                while(mat[i][j+1] == 0 && j<N-1){
                    std::swap(mat[i][j], mat[i][j+1]);
                    ++j;
                }

                if(mat[i][j] == mat[i][j+1] && j<a){
                    mat[i][j+1] += mat[i][j];
                    mat[i][j] = 0;
                    a = j;
                }
            }
    }
}

void solveUp()
{
    for(int j = 0; j<N; ++j)
    {
        int a = 0;

        for(int i = 1; i<N; ++i)
            if(mat[i][j] != 0)
            {
                while(mat[i-1][j] == 0 && i>0){
                    std::swap(mat[i][j], mat[i-1][j]);
                    --i;
                }

                if(mat[i-1][j] == mat[i][j] && i>a){
                    mat[i-1][j] += mat[i][j];
                    mat[i][j] = 0;
                    a = i;
                }
            }
    }
}

void solveDown()
{
    for(int j = 0; j<N; ++j)
    {
        int a = N-1;

        for(int i = N-2; i>=0; --i)
            if(mat[i][j] != 0)
            {
                while(mat[i+1][j] == 0 && i<N-1){
                    std::swap(mat[i][j], mat[i+1][j]);
                    ++i;
                }

                if(mat[i+1][j] == mat[i][j] && i<a){
                    mat[i+1][j] += mat[i][j];
                    mat[i][j] = 0;
                    a = i;
                }
            }
    }
}

int main()
{
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<N; ++j)
            std::cin >> mat[i][j];

    int move; std::cin >> move;

    switch (move)
    {
        case 0: solveLeft();
        break;

        case 1: solveUp();
        break;

        case 2: solveRight();
        break;
        
        case 3: solveDown();
        break;
    }

    for(int i = 0; i<N; ++i)
    {
        for(int j = 0; j<N; ++j)
            std::cout << mat[i][j] << ' ';
        std::cout << '\n';
    }
}