#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdio.h>
#define N 3

using namespace std;

int A[N][N];

enum Diag{MainDiag,AccDiag};

bool searchCol(int col)
{
    int nonZero = 0;
    for(int i = 0;i < 3;i++)
        if(A[i][col] != 0)
            nonZero += 1;
    if(nonZero == 2)
        return true;
    else
        return false;
}

bool searchRow(int row)
{
    int nonZero = 0;
    for(int i = 0;i < 3;i++)
        if(A[row][i] != 0)
            nonZero += 1;
    if(nonZero == 2)
        return true;
    else
        return false;
}

pair<bool,int> searchDiag(int row,int col)
{
    bool ret = false;
    int nonZero = 0;
    Diag diag;
    if(row == col)//Main diag
    {
        diag = MainDiag;
        for(int i = 0;i < 3;i++)
            if(A[i][i] != 0)
                nonZero += 1;
    }
    else
    {
        diag = AccDiag;
        if(row + col == 2)
        {
            for(int i = 0;i <= 2;i++)
                if(A[i][2-i] != 0)
                    nonZero += 1;
        }
    }
    if(nonZero == 2)
        ret = true;
    return pair<bool,int>(ret,diag);
}

int main()
{
    freopen("inp8.txt","r",stdin);

    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            cin >> A[i][j];

    A[1][1] = 5;

    int time = 3;
    while(time--)
    {
        for(int i = 0;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)
            {
                if(A[i][j] == 0)
                {
                    if(searchRow(i))
                    {
                        int sum = 0;
                        for(int jj = 0;jj < 3;jj++)
                            sum += A[i][jj];
                        A[i][j] = 15 - sum;
                        continue;
                    }
                    if(searchCol(j))
                    {
                        int sum = 0;
                        for(int ii = 0;ii < 3;ii++)
                            sum += A[ii][j];
                        A[i][j] = 15 - sum;
                        continue;
                    }

                    pair<bool,int> ret = searchDiag(i,j);
                    if(ret.first)
                    {
                        int sum = 0;
                        if(ret.second == MainDiag)
                        {
                            for(int ii = 0;ii < 3;ii++)
                                sum += A[ii][ii];
                            A[i][j] = 15 - sum;
                        }
                        else
                        {
                            if(ret.second == AccDiag)
                            {
                                for(int ii = 0;ii < 3;ii++)
                                    sum += A[ii][2-ii];
                                A[i][j] = 15 - sum;
                            }
                        }
                        continue;
                    }
                }
            }
        }
    }



    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(A[i][j] == 0)
            {
                cout << "Too Many" << endl;
                return 0;
            }
        }
    }

    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    fclose(stdin);
    return 0;
}

