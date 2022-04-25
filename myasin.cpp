#include <stdio.h>
#include <math.h>


double myasin(double x) // input����ֵx  output��arcsin(x)����ֵ
{
    int f;
    if (x >= -1 && x <= 1) //�ж������Ƿ��ڶ�������
    {
        if (x < 0)
        {
            x = abs(x); //���������Ǻ������� arcsin��-x��=-arcsin��x���õ�
            f = 1;
        }
        else
        {
            f = 0;
        }
        if (x >= 0.9996615) //��x����1ʱ�����ý��ƹ�ʽ���㣬������ѡ��ΧΪ[0.9996615,1]
        {
            double a0 = 1.5707288, a1 = -0.2121144, a2 = 0.0742610, a3 = -0.0187293;
            return	(3.1415926 / 2 - sqrt(1 - x) * (a0 + a1 * x + a2 * pow(x, 2) + a3 * pow(x, 3)));
        }
        else
        {
            double g, t, n = 1;
            g = x;
            t = x;
            while (fabs(t) >= 1e-9) //����̩�ռ���չ�����м���ƽ�����ֵ
            {
                t = t * (2 * n - 1) * (2 * n - 1) * x * x / ((2 * n) * (2 * n + 1));
                n += 1;
                g += t;
            }
            if (f == 1)
            {
                return -g;
            }
            else
            {
                return g;
            }
        }
    }
}
