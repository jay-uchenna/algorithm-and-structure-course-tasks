#include <iostream>
#include <iomanip>



int combin(int n, int r)
{
    if ((r == 0) || (r == n))
    {
        return 1;
    }
    else
    {
        return combin(n-1, r-1) + combin(n-1, r);
    }
}

int main()
{
    std::cout << combin(5,3) << std::endl;
}



/*
double pw = 1, pem = 1;
double sine(double x, int n)
{      
        double temp;       
        if (n == 1){
            pw = x;
            return x;
        }
        else 
        {
             temp = sine(x,n-2); 
             pw *= x * x * (-1);
             pem *= (n-1) * n;
             return temp + (pw/pem);
        }
}


int main() {

	
    std::cout << std::fixed;
    std::cout << std::setprecision(5);    
    std::cout << sine(360 * 3.14159265/180, 21) << "\n";
    float kf = 2.45f, jf = 2.45;
    char kch = h; 
    std::cout << kf << " " << jf << " " << kch << "\n";
    return 0;
}
*/
