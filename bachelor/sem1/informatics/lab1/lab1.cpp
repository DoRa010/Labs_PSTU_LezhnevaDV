#include <iostream>
#include <cmath>    // Для функции pow()
#include <iomanip>  // Для форматирования вывода

using namespace std;

int main() {
    // Инициализация данных
    float a_f = 1000.0f;
    float b_f = 0.0001f;

    double a_d = 1000.0;
    double b_d = 0.0001;

    // Вычисления для типа float
    // Промежуточные части числителя
    float skobka_v_stepeni_f = pow(a_f + b_f, 4);       // (a + b)^4
    float a_v_chetvertoy_f = pow(a_f, 4);              // a^4
    float chetyre_a3b_f = 4 * pow(a_f, 3) * b_f;        // 4a^3b
    
    // Числитель
    float chislitel_f = skobka_v_stepeni_f - (a_v_chetvertoy_f + chetyre_a3b_f);

    // Промежуточные части знаменателя
    float tri_ab2_f = 3 * a_f * pow(b_f, 2);            // 3ab^2
    float b_v_kub_f = pow(b_f, 3);                      // b^3
    
    // Знаменатель
    float znamenatel_f = tri_ab2_f + b_v_kub_f;

    // Итоговый результат для float
    float rezultat_f = chislitel_f / znamenatel_f;


    // Вычисления для типа double
    // Промежуточные части числителя
    double skobka_v_stepeni_d = pow(a_d + b_d, 4);
    double a_v_chetvertoy_d = pow(a_d, 4);
    double chetyre_a3b_d = 4 * pow(a_d, 3) * b_d;
    
    // Числитель
    double chislitel_d = skobka_v_stepeni_d - (a_v_chetvertoy_d + chetyre_a3b_d);

    // Промежуточные части знаменателя
    double tri_ab2_d = 3 * a_d * pow(b_d, 2);
    double b_v_kub_d = pow(b_d, 3);
    
    // Знаменатель
    double znamenatel_d = tri_ab2_d + b_v_kub_d;

    // Итоговый результат для double
    double rezultat_d = chislitel_d / znamenatel_d;

    // Вывод результатов
    cout << fixed << setprecision(10);
    
    cout << "Входные данные: a = " << a_f << ", b = " << b_f << endl;
    cout << "Результат (тип float):  " << rezultat_f << endl;
    cout << "Результат (тип double): " << rezultat_d << endl;
    cout << " ~2000.1333..." << endl;

    return 0;
}


//Суффиксы _f и _d оставлены, чтобы чётко разделять переменные типов float и double
/* Тип float (32 бита) имеет ограниченную точность (около 7 значащих цифр). В данной задаче происходит
вычитание двух очень больших чисел 
(порядка 10**12 ) для получения относительно небольшого результата.
Из-за этого в типе float происходит потеря младших разрядов (catastrophic cancellation),
и дробная часть результата теряется. Поэтому программа выводит округлённое значение 
2000.0
Тип double (64 бита) обладает высокой точностью (около 15–17 значащих цифр).
Этого достаточно, чтобы сохранить все значащие разряды при вычитании больших чисел.
Поэтому результат для double максимально близок к теоретическому значению 
2000.1333... */

/*Данный эксперимент подтверждает необходимость использования типа double для задач,
где требуется высокая точность вычислений, особенно при операциях вычитания близких по величине больших чисел.» */