// laba20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,count=0,k=1,i,j=0;
    //задание 1
    cout << "Task 1. ";
    cout << "\nPrint size arrays: ";
    cin >> n;
    if (cin.fail() || n < 1)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int* masA = new int[n];
        cout << "\nArray A: \n";
        for (i = 0; i < n; i++)
        {
            cout << "Print "<<i<<" number: ";
            cin >> masA[i];
        }
        for (i = 0; i < n; i++)
        {
            if (masA[i] != masA[i + 1])  //считаем кол-во серий
                count++;
        }
        int* masB = new int[count]; 
        int* masC = new int[count];
        for (i = 0; i < n; i++)
        {
            if (masA[i] == masA[i + 1])  //считаем длины серий
                k++;
            else
            {
                masB[j] = k;  //записываем длину серии
                masC[j] = masA[i]; //значение серии
                j++;
                k = 1;
            }
        }
        cout << "\nArray B: \n";
        for (i=0;i<count;i++)
            cout << masB[i] << " "; 
        cout << "\nArray C: \n";
        for (i = 0; i < count; i++)
            cout << masC[i] << " ";
    }
    //задание 2
    cout << "\n\nTask 2. ";
    cout << "\nPrint size arrays: ";
    cin >> n; 
    int L;
    cout << "Print L: ";
    cin >> L;
    if (cin.fail() || n < 1 || L<=0)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int* mas2 = new int[n];
        cout << "\nArray: \n";
        for (i = 0; i < n; i++)
        {
            cout << "Print " << i << " number: ";
            cin >> mas2[i];
        }

        for (i = 0; i < n; i++)
        {
            count = 1;
            for (int j = i+1 ; j < n; j++)
            {
                if (mas2[j] == mas2[i])
                    count++;
                else
                    break;
            }
            if (count > L)
            {
                i = i + count-1 ;
                cout << "0 ";
            }
            else  
                cout << mas2[i]<<" ";
        }
    }
    ////задание 3
    cout << "\n\nTask 3. ";
    cout << "\nPrint size arrays: ";
    cin >> n;
    int K;
    cout << "Print K: ";
    cin >> K;
    if (cin.fail() || n < 1 || K <= 0|| K > n)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int* mas3 = new int[n];
        cout << "\nArray: \n";
        for (i = 0; i < n; i++)
        {
            cout << "Print " << i << " number: ";
            cin >> mas3[i];
        }

        int startENDseries=0,lenKseries = 0, endKseries=0;
        k = 1;
        if (K == 1) lenKseries++;//если меняем первую серию
        for (i = 0; (i < n-1) && (k <= K); i++) 
        {
            if (mas3[i] != mas3[i+1]) 
                k++; //кол-во серий
            if (k == K) //если дошли до серии номер К
                lenKseries++;  //длина К серии
            endKseries = i; //индекс конца К серии
        }
        for (i = n-1; i>1; i--)
        {
            if (mas3[i] != mas3[i - 1])
            {
                startENDseries = i;//индекс начала последней серии
                break;
            }
        }
        cout << "\nModified array: ";
        for (i = 0; i < (endKseries - lenKseries+1);i++)
            cout << mas3[i] << " ";  //записываем серии с номерами < K
        for (i = startENDseries; i < n; i++)
           cout << mas3[i] << " ";//вставляем вместо К серии последнюю серию
        for (i = endKseries+1; i < startENDseries; i++)
            cout << mas3[i] << " "; //выводим серии > K и < последней
        for (i = (endKseries - lenKseries+1); i < endKseries+1; i++)
            cout << mas3[i] << " "; //выводим К серию вместо последней
    }

    //задание 4
    cout << "\n\nTask 4. ";
    cout << "\nPrint count point: ";
    cin >> n;
    if (cin.fail() || n < 1 )
    {
        cout << "ERROR!\n";
    }
    else
    {
        int* masX4 = new int[n];
        int* masY4 = new int[n];
        cout << "\nSet of coordinates: \n";
        for (i = 0; i < n; i++)
        {
            cout << i <<". Print X: ";
            cin >> masX4[i]; //ввод х
            cout << i <<". Print Y: ";
            cin >> masY4[i]; //ввод у
        }
        float x=0, y=0, xy=0;
        for (i = 0; i < n; i++)
            if (masX4[i] < 0 && masY4[i]>0) // координаты во второй четверти?
            {
                if (sqrt(masX4[i] * masX4[i] + masY4[i] * masY4[i]) > xy) //сравниваем удаленность от центра
                {
                    x = masX4[i];
                    y = masY4[i];
                    xy = sqrt(masX4[i] * masX4[i] + masY4[i] * masY4[i]);
                }
            }
        cout << "\nSolution: ";
        cout << "X = "<< x<<", Y = "<<y; 
    }
    //задание 5
    cout << "\n\nTask 5. ";
    cout << "\nPrint count point: ";
    cin >> n;
    if (cin.fail() || n < 3)
    {
        cout << "ERROR!\n";
    }
    else
    {
        int* masX5 = new int[n];
        int* masY5 = new int[n];
        cout << "\nSet of coordinates: \n";
        for (i = 0; i < n; i++)
        {
            cout << i << ". Print X: ";
            cin >> masX5[i]; //ввод х
            cout << i << ". Print Y: ";
            cin >> masY5[i]; //ввод у
        }
        double maxPerimeter = 0;  // максимальный периметр
        double tmpPerimeter = 0;  // текущий периметр
        int A, B, C;              // номера точек
        double ab, ac, bc;
        for ( i = 0; i < n - 2; i++) 
        {                       
            for ( j = i + 1; j < n - 1; j++) 
            {               
                for ( k = j + 1; k < n; k++) 
                {             
                    ab = abs(sqrt(pow((masX5[i] - masX5[j]), 2) + pow((masY5[i] - masY5[j]), 2)));//сторона аб
                    ac = abs(sqrt(pow((masX5[i] - masX5[k]), 2) + pow((masY5[i] - masY5[k]), 2)));//сторона ас
                    bc = abs(sqrt(pow((masX5[k] - masX5[j]), 2) + pow((masY5[k] - masY5[j]), 2)));//сторона бс
                    tmpPerimeter = ab+ac+bc; //  периметр
                    if (tmpPerimeter > maxPerimeter) // если периметр больше максимального
                    {        
                        maxPerimeter = tmpPerimeter;   
                        A = i;                               
                        B = j;                         
                        C = k;                                
                    }
                }
            }
        }
        cout << "\nPerimeter = " << maxPerimeter << "\nA(" << masX5[A] << "," << masY5[A] << "), B(" << masX5[B] << "," << masY5[B] << "), C(" << masX5[C] << "," << masY5[C] << ")";
    }
    cout << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
