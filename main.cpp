#include <iostream>
#include <cmath>

using namespace std;

typedef struct node
{
    int deg;
    double coef;
    struct node* next;
} node;
node *N = NULL;

void menu() {
	std::cout << "1 - Добавить в конец" << std::endl;
	std::cout << "2 - Напечатать многочлен" << std::endl;
	std::cout << "3 - Посчитать значение в точке" << std::endl;
	std::cout << "0 - Выход из программы" << std::endl;
}

void push(node* &now)
{
    double c = 0; int d = 0;
    cout << "Введите степень"<<endl;
    cin >> d;
    cout << "Введите коэффициент"<<endl;
    cin >> c;
    node *now1= new node;
    now1->deg = d;
    now1->coef = c;
    now1->next = now;
    now = now1;
}

void print(node *now)
{
    if(now->coef < 0) cout<<"-";

        while (now != 0)
        {
            if (now->next == NULL && abs(now->coef) == 1)
        {
              if (now->deg > 1)
                cout<<"x^"<<now->deg;

              if (now->deg == 1)
                cout<<"x";

              if (now->deg == 0)
                cout<<abs(now->coef);
        }
            if (now->next == NULL && abs(now->coef) != 1)
        {
              if (now->deg > 1)
                cout<<abs(now->coef)<<"x^"<<now->deg;

              if (now->deg == 1)
                cout<<abs(now->coef)<<"x";

              if (now->deg == 0)
                cout<<abs(now->coef);
        }
            if (now->next != NULL && abs(now->coef) != 1)
        {
              if (now->deg == 0 && now->next->coef > 0)
                cout<<abs(now->coef)<<"+";

              if (now->deg == 0 && now->next->coef < 0)
                cout<<abs(now->coef)<<"-";

              if (now->deg==1&&now->next->coef>0)
                cout<<abs(now->coef)<<"x+";

              if (now->deg == 1 && now->next->coef < 0)
                cout<<abs(now->coef)<<"x-";

              if (now->deg > 1 && now->next->coef > 0)
                cout<<abs(now->coef)<<"x^"<<now->deg<<"+";

              if (now->deg > 1 && now->next->coef < 0)
                cout<<abs(now->coef)<<"x^"<<now->deg<<"-";
        }

          if (now->next != NULL && abs(now->coef) == 1)
        {

              if (now->deg > 1 && now->next->coef > 0)
              cout<< "x^"<<now->deg<<"+";

              if (now->deg > 1 && now->next->coef < 0)
              cout<< "x^"<<now->deg<<"-";

              if (now->deg == 1 && now->next->coef > 0)
              cout<< "x+";

              if (now->deg == 1 && now->next->coef < 0)
              cout<< "x-";

              if (now->deg == 0 && now->next->coef > 0)
                cout<<abs(now->coef)<<"+";

              if (now->deg == 0 && now->next->coef < 0)
              cout<<abs(now->coef)<<"-";

        }
            now = now->next;
        }
        cout<<endl;
        std::cout << "\n" << std::endl;
}

void mean(node *now)
{
    double f = 0;
    double x, x1 = 0;
    cout << "Введите точку"<<endl;
    cin >> x;

    while (now != NULL)
    {
        x1 = x;
        if (now->deg == 0)
                f = f + now->coef;
        else {
        for (int i = 1; i < now->deg; i++)
            x1 = x1*x;
        f = f + (now->coef)*x1;
        }
        now = now->next;
    }
    cout<<"Значение в точке: "<<f<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int action;
   while (true) {
		menu();
		int action;
		std::cin >> action;
		switch (action) {
		case(1):
			push(N);
			break;
		case(2):
			print(N);
			break;
		case(3):
			mean(N);
			break;
		case(0):
			return 0;
		}
	}
}


