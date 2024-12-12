// Lab 2 TOI.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int AddIter(int x, int y) {
    int s = x;
    for (int i = 0; i < y; i++) {
        s++;
    }
    return s;
}
int AddReq(int x, int y) {
    if (y == 0) {
        return x;
    }
    return AddReq(x + 1, y - 1);
}
int FibReq(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return FibReq(n - 2) + FibReq(n - 1);
}
int FibIter(int n) {
    vector<int> nums { 1,1 };
    while (n > nums.size()) {
        int a = nums[nums.size() - 1];
        int b = nums[nums.size() - 2];
        int nxt = a + b;
        nums.push_back(nxt);
    }
    return nums[n - 1];
}
int mac(int n) {
    if (n > 100) {
        return n - 10;
    }
    return mac(mac(n + 11));
}
int acc(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return acc(m - 1, 1);
    }
    return acc(m - 1, acc(m, n - 1));
}
vector<vector<int>> input_field(int bordercolor, int fieldcolor) {
    int m, n;
    cout << "Введите количество строк\n";
    cin >> m;
    cout << "Введите количество столбцов\n";
    cin >> n;
    cout << "Введите фигуру по строкам, числа - номера цветов, " 
        << bordercolor << " - цвет границы, " 
        << fieldcolor << " - цвет закраски"<<'\n';
    vector<vector<int>> res{};
    for (int i = 0;i < m;i++) {
        res.push_back(vector<int>(n,0));
        for (int j = 0;j < n;j++) {
            cin >> res[i][j];
        }
    }
    return res;
}
tuple<int,int> input_start_point() {
    cout << "введите координаты стартовой точки закраски в формате x y\n";
    int x, y;
    cin >> x;
    cin >> y;
    return tuple<int, int>{ x - 1, y - 1 };
}
void fill_field(int x, int y, vector<vector<int>>& field, int bordercolor, int fieldcolor, int fillcolor) {
    if (x<0 || y<0 || x>=field.size() || y>=field[0].size())
        return;
    if (field[x][y] == fieldcolor) {
        field[x][y] = fillcolor;
        fill_field(x + 1, y, field, bordercolor, fieldcolor, fillcolor);
        fill_field(x - 1, y, field, bordercolor, fieldcolor, fillcolor);
        fill_field(x, y + 1, field, bordercolor, fieldcolor, fillcolor);
        fill_field(x, y - 1, field, bordercolor, fieldcolor, fillcolor);
    }
}
void fill_process() {
    int fillcolor = 1, bordercolor = 2, fieldcolor = 0;
    vector < vector<int >> field = input_field(bordercolor, fieldcolor);
    int x, y;
    tie(x, y) = input_start_point();
    fill_field(x, y, field, bordercolor, fieldcolor, fillcolor);
    for (vector<int> v : field) {
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    setlocale(LC_ALL, "");
    fill_process();
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
