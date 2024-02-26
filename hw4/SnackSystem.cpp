/**
 * Title: Balanced search trees and hashing
 * Author : Sertac Derya
 * ID: 22003208
 * Section : 3
 * Homework : 4
 * Description : header
 */
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Sertac_Derya_22003208_SnackSystem.h"
using namespace std;

SnackSystem::SnackSystem()
{
}

void SnackSystem::S(string SName)
{
    sHash.insertItem(SName);
    cout << "Snack '" << SName << "' created" << endl;
}

void SnackSystem::C(string firstSName, string secondSName)
{
    Snack *f = sHash.getItem(firstSName);
    Snack *s = sHash.getItem(secondSName);
    if (f != nullptr && s != nullptr && f != s)
    {
        if (!aHash.checkAccompaniment(firstSName, secondSName) || !aHash.checkAccompaniment(secondSName, firstSName))
        {
            Accompaniment *acc = new Accompaniment(firstSName, secondSName);
            acc->setFirst(f);
            acc->setSecond(s);
            f->addSnackComb(s);
            s->addSnackComb(f);

            aHash.insertItem(acc);
        }
    }
    else if (f == nullptr)
    {
        cout << firstSName << " doesn't exist." << endl;
    }
    else if (s == nullptr)
    {
        cout << secondSName << " doesn't exist." << endl;
    }
}

void SnackSystem::D(string firstSName, string secondSName)
{
    Snack *f = sHash.getItem(firstSName);
    Snack *s = sHash.getItem(secondSName);

    if (f != nullptr && s != nullptr && f != s)
    {
        string comb1 = firstSName + secondSName;
        string comb2 = secondSName + firstSName;

        if (aHash.checkAccompaniment(firstSName, secondSName))
        {
            Accompaniment *acc = aHash.getAccomp(comb1);
            f = acc->getFirstSnack();
            s = acc->getSecondSnack();

            f->removeSnackComb(s);
            s->removeSnackComb(f);

            aHash.deleteAccompaniment(firstSName + secondSName);
        }
        else if (aHash.checkAccompaniment(secondSName, firstSName))
        {
            Accompaniment *acc = aHash.getAccomp(comb2);
            Snack *f = acc->getFirstSnack();
            Snack *s = acc->getSecondSnack();

            f->removeSnackComb(s);
            s->removeSnackComb(f);

            aHash.deleteAccompaniment(secondSName + firstSName);
        }
    }
}

void SnackSystem::L(string SName)
{
    Snack *S = sHash.getItem(SName);
    if (S != nullptr)
    {
        for (int i = 0; i < S->accListLength(); i++)
        {
            cout << S->getFromList(i)->getName();
            if (i + 1 != S->accListLength())
            {
                cout << " ";
            }
        }
        if (S->accListLength() > 0)
        {
            cout << endl;
        }
    }
}

bool SnackSystem::Q(string firstSName, string secondSName)
{
    bool comb1 = aHash.checkAccompaniment(firstSName, secondSName);
    bool comb2 = aHash.checkAccompaniment(secondSName, firstSName);
    if (comb1 || comb2)
    {
        cout << "Yes" << endl;
        return true;
    }
    else
    {
        cout << "No" << endl;
        return false;
    }
}

int main(int argc, char *argv[])
{ // take input from command line
    SnackSystem snacksys;
    bool cont = true;
    string input;
    int index = 1;
    while (cont)
    {
        input = argv[index];
        if (input.at(0) == 'S')
        {
            index++;
            string snackName = argv[index];
            snacksys.S(snackName);
            index++;
        }
        else if (input.at(0) == 'C')
        {
            index++;
            string first = argv[index];
            index++;
            string second = argv[index];
            snacksys.C(first, second);
            index++;
        }
        else if (input.at(0) == 'D')
        {
            index++;
            string first = argv[index];
            index++;
            string second = argv[index];
            snacksys.D(first, second);
            index++;
        }
        else if (input.at(0) == 'L')
        {
            index++;
            string snack = argv[index];
            snacksys.L(snack);
            index++;
        }
        else if (input.at(0) == 'Q')
        {
            index++;
            string first = argv[index];
            index++;
            string second = argv[index];
            snacksys.Q(first, second);
            index++;
        }
        else if (input.at(0) == 'X')
        {
            cont = false;
        }
    }

    /* SnackSystem snacksys;
    string file = "test1.txt";
    ifstream inputFile;
    string line;
    inputFile.open(file.c_str(), ios_base::in);
    string c;
    bool cont = true;
    while(cont) {
        getline(inputFile, line);
        stringstream snackline(line);
        string input;
        getline(snackline, input, ' ');
        if(input.at(0) == 'S') {
            string snackName;
            getline(snackline, snackName);
            snacksys.S(snackName);
        } else if(input.at(0) == 'C') {
            string first;
            getline(snackline, first, ' ');
            string second;
            getline(snackline, second, ' ');
            snacksys.C(first, second);
        } else if(input.at(0) == 'D') {
            string first;
            getline(snackline, first, ' ');
            string second;
            getline(snackline, second, ' ');
            snacksys.D(first, second);
        } else if(input.at(0) == 'L') {
            string snack;
            getline(snackline, snack);
            snacksys.L(snack);
        } else if(input.at(0) == 'Q') {
            string first;
            getline(snackline, first, ' ');
            string second;
            getline(snackline, second, ' ');
            snacksys.Q(first, second);
        } else if(input.at(0) == 'X') {
            cont = false;
        }
    } */
}
