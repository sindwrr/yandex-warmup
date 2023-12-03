// C. Путешествие по Москве

// Мэрия Москвы основательно подготовилась к празднованию тысячелетия 
// города в 2147 году, построив под столицей бесконечную асфальтированную 
// площадку, чтобы заменить все существующие в городе автомобильные дороги. 
// В память о кольцевых и радиальных дорогах разрешили двигаться по 
// площадке только двумя способами:

// 1. В сторону точки начала координат или от неё. При этом из точки начала 
// координат разрешено двигаться в любом направлении.
// 2. Вдоль окружности с центром в начале координат и радиусом, который равен 
// текущему расстоянию до начала координат. Двигаться вдоль такой окружности 
// разрешается в любом направлении (по или против часовой стрелки).

// Вам, как ведущему программисту ответственной инстанции поручено разработать 
// модуль, который будет определять кратчайший путь из точки A, с координатами 
// (xA, yA) в точку B с координатами (xB, yB). Считайте, что менять 
// направление движения можно произвольное количество раз, но оно должно 
// всегда соответствовать одному из двух описанных выше вариантов.

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>

int main() 
{
    double xa, ya, xb, yb;

    std::cin >> xa >> ya >> xb >> yb;

    double D1, D2, ra, rb, ka, kb, angle;

    ra = sqrt(pow(xa, 2) + pow(ya, 2));
    rb = sqrt(pow(xb, 2) + pow(yb, 2));
    ka = atan2(ya, xa);
    kb = atan2(yb, xb);

    if (ka >= kb)
        angle = ka - kb <= M_PI ? ka - kb : 2 * M_PI - (ka - kb);
    else
        angle = kb - ka <= M_PI ? kb - ka : 2 * M_PI - (kb - ka);

    if (ra >= rb)
        D1 = ra - rb + rb * angle;
    else
        D1 = rb - ra + ra * angle;

    D2 = ra + rb;

    double res = D1 < D2 ? D1 : D2;
    std::cout << std::setprecision(12) << res;

    return 0;
}