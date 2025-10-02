/********************************
*Имя:Солдатов Владимир Сергеевич*
*Вариант:12                     *
*********************************/

#include <iostream>
#include <cmath>
using namespace std;

double calculate_tcp(double t, double t0, double t_tv) {
    if (t <= t_tv) {
        return t0 * exp(-0.021 * t);
    } else {
        return 327.0 * exp(-0.015 * (t - t_tv));
    }
}

int main() {
    double t0 = 800.0;  // Исходная температура (t_ж)
    double t_tv = 327.0;  // Температура затвердевания (t_TB)
    double t_tv_time = log(t0 / t_tv) / 0.021;  // Время затвердевания (min)
    
    cout << "Curing time: " << t_tv_time << " min" << endl;

    double time_points[] = {10.0, 20.0, 30.0, 50.0, 100.0};

    for (int i = 0.0; i < 5.0; ++i) {
        double t = time_points[i];
        double t_cp;

        if (t <= t_tv_time) {
            t_cp = t0 * exp(-0.021 * t);
        } else {
            t_cp = t_tv * exp(-0.015 * (t - t_tv_time));
        }

        cout << "t = " << t << " min, t_cp = " << t_cp << " °C" << endl;
    }

    return 0;
}
