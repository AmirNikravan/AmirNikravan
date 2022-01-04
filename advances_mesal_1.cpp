/*
NOTE == this program uses c++ 14
Developer : AmirHosein Nikravan
Shomare dnaeshjooye : 39914141054085
Class : seshanbe Saate 18:00
*/
#include <iostream>
#include <string>
#include <limits>
namespace
{
    constexpr unsigned count = 40u; // tedad karmand ha
    static int __karmand__ = 0;     // tedad karmand haye ezafe shode
    using ull = unsigned long long; // type alias
}

struct Employee
{
    std::string name{};
    std::string family{};
    std::string kod_meli{};
    ull id{};
    ull hoghoogh{};
    int sabeghe_kar{};
};

void checkfail(char, Employee *person, int); // baraye check kardan failure modev
bool receive_information(Employee *);        // daryaft etelaat
void clearscr();                             // clear screen
void clear_buffer();
bool show_information(Employee *); // namayesh etelaat
void menu();                       // menu
void exit();                       // exit
bool show_salary(Employee *);      // namayesh hoghoogh karmandan
bool sabeghe_kar(Employee *);      // namayesh sabeghe kar kamtar az 10
bool sort(Employee *);             // sort data by name
template <typename T>
auto swap(T *xp, T *yp) // swap elements for each data-type
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
    return; // void
}

int main()
{
    Employee person[count];
    bool vaze_edame{true};
    int menu_input;
    while (1)
    {
        menu();
        std::cin >> menu_input;
        switch (menu_input)
        {
        case 1: // ezafe kardan karmand
            vaze_edame = receive_information(person);
            break;
        case 2: // sort bar asas alefba bubble sort
            vaze_edame = sort(person);
            break;
        case 3: // namayesh hoghoogh
            vaze_edame = show_salary(person);
            break;
        case 4: // namayesh hoghoogh
            vaze_edame = sabeghe_kar(person);
            break;
        case 5: // namayesh kol karmandan
            vaze_edame = show_information(person);
            break;
        case 6: // khorooj
            exit();
            std::exit(0);
        default:
            std::cout << "lotfan gozine monaseb vared konid \n";
            system("pause");
            break;
        }
        if (!vaze_edame)
        {
            exit();
            std::exit(0);
        }
    }
}

void checkfail(char vaz, Employee *person, int i)
{
    while (1)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (vaz)
            {
            case 's':
                std::cout << "lotfan shomare personely ra dar format dorost vared konid : ";
                std::cin >> person[i].id;
                break;
            case 'h':
                std::cout << "lotfan hoghoogh ra dar format dorost vared konid : ";
                std::cin >> person[i].hoghoogh;
                break;
            case 'a':
                std::cout << "lotfan sabeghe kar ra dar format dorost vared konid : ";
                std::cin >> person[i].sabeghe_kar;
                break;
            default:
                break;
            }
        }
        else
            return;
    }
}

bool receive_information(Employee *person)
{ // start receiving
    clearscr();
    std::cout << "*********************************************************\n";
    std::cout << "daryaft etelaat karmand : \n";
    std::cout << "*********************************************************\n\n\n\n\n";
    std::cout << "*******************************\n";
    std::cout << "nam karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin >> std::ws, person[__karmand__].name);
    std::cout << "*******************************\n";
    std::cout << "family karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin, person[__karmand__].family);
    std::cout << "*******************************\n";
    std::cout << "kod melli karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin, person[__karmand__].kod_meli);
    std::cout << "*******************************\n";
    std::cout << "shomare personely karmand " << __karmand__ + 1 << " : ";
    std::cin >> person[__karmand__].id;
    std::cout << "*******************************\n";
    checkfail('s', person, __karmand__);
    clear_buffer();
    std::cout << "hoghoogh karmand " << __karmand__ + 1 << " : ";
    std::cin >> person[__karmand__].hoghoogh;
    std::cout << "*******************************\n";
    checkfail('h', person, __karmand__);
    clear_buffer();
    std::cout << "sabeghe kar karmand " << __karmand__ + 1 << " : ";
    std::cin >> person[__karmand__].sabeghe_kar;
    std::cout << "*******************************\n";
    checkfail('a', person, __karmand__);
    clear_buffer();
    __karmand__++;
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);

} // end receiving

bool show_information(Employee *person)
{ // start showing
    clearscr();
    if (person[0].name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        std::cout << "*********************************************************\n";
        std::cout << "namyaesh list karmandan : \n";
        std::cout << "*********************************************************\n\n\n\n\n";
        for (size_t i = 0; i < ::__karmand__; i++)
        {
            std::cout << "**************************************\n";
            std::cout << "nam karbar = " << person[i].name << '\n';
            std::cout << "**************************************\n";
            std::cout << "famili karbar = " << person[i].family << '\n';
            std::cout << "**************************************\n";
            std::cout << "hoghoogh = " << person[i].hoghoogh << '\n';
            std::cout << "**************************************\n";
            std::cout << "shomare personeli = " << person[i].id << '\n';
            std::cout << "**************************************\n";
            std::cout << "kode melli = " << person[i].kod_meli << '\n';
            std::cout << "**************************************\n";
            std::cout << "sabeghe kar = " << person[i].sabeghe_kar << '\n';
            std::cout << "**************************************\n\n\n";
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
} // end showing

void clearscr()
{ // for clear screen
    system("cls");
}

void clear_buffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void menu()
{ // namyesh menu
    clearscr();

    std::cout << "\a****************************************************\n";
    std::cout << "1.ezafe kardan karmand \n";
    std::cout << "****************************************************\n";
    std::cout << "2.namyesh list karmandan bar asas nam khanevadegi\n";
    std::cout << "****************************************************\n";
    std::cout << "3.namayesh list karmandan ba hoghoogh kamtar az 3M\n";
    std::cout << "****************************************************\n";
    std::cout << "4.list karmandan ba sabeghe balaye 10sal\n";
    std::cout << "****************************************************\n";
    std::cout << "5.namayesh kol karmandan\n";
    std::cout << "****************************************************\n";
    std::cout << "6.khorooj\n";
    std::cout << "****************************************************\n";
    std::cout << "tedad karmand haye vared shode = " << __karmand__ << "\n\n\n\n\n";
    std::cout << "lotfan gozine mored nazar khod ra vared konid :";
}

void exit()
{
    clearscr();
    std::cout << "ba moafaghiat kharej shodid!!";
}

bool sabeghe_kar(Employee *person)
{
    clearscr();
    int counter{__karmand__};
    int sabeghe[40] = {0};
    if (person[0].name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        for (int i = 0; i < counter; i++)
            sabeghe[i] = person[i].sabeghe_kar;
        std::cout << "*********************************************************\n";
        std::cout << "list karmandani ke sabeghe kar bishtar az 10 sal darand : \n";
        std::cout << "*********************************************************\n\n\n\n\n";
        for (size_t i = 0; i < counter; i++)
        {
            if (sabeghe[i] > 10)
            {
                std::cout << "**************************************\n";
                std::cout << "nam karmand = " << person[i].name << '\n';
                std::cout << "nam khanevadegi = " << person[i].family << '\n';
                std::cout << "sabaghe kar karmand = " << person[i].sabeghe_kar << '\n';
                std::cout << "**************************************\n";
            }
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}

bool show_salary(Employee *person)
{ // namayesh karmandan ba hoghhogh kamtar az 3M
    clearscr();
    int counter{__karmand__};
    ull salary[40] = {0};
    if (person[0].name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        for (int i = 0; i < counter; i++)
            salary[i] = person[i].hoghoogh;
        std::cout << "*********************************************************\n";
        std::cout << "list karmandani ke hoghoogh kamtar az 3M migiran : \n";
        std::cout << "*********************************************************\n\n\n\n\n";
        for (size_t i = 0; i < counter; i++)
        {
            if (salary[i] < 3000000)
            {
                std::cout << "**************************************\n";
                std::cout << "nam karmand = " << person[i].name << '\n';
                std::cout << "nam khanevadegi = " << person[i].family << '\n';
                std::cout << "hoghoogh karmand = " << person[i].hoghoogh << '\n';
                std::cout << "**************************************\n";
            }
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}

bool sort(Employee *person)
{
    clearscr();
    int counter{__karmand__};
    std::string famili[40] = {""}, name[40] = {""};
    long double hogh[40] = {0};
    long double sab[40] = {};
    ull id[40] = {};
    std::string kod[40];
    if (person[0].name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        for (size_t i = 0; i < counter; i++)
        {
            famili[i] = person[i].family;
            name[i] = person[i].name;
            hogh[i] = person[i].hoghoogh;
            sab[i] = person[i].sabeghe_kar;
            kod[i] = person[i].kod_meli;
            id[i] = person[i].id;
        }
        for (int i = 0; i < counter - 1; i++)
        {
            for (int j = 0; j < counter - i - 1; j++)
                if (famili[j] > famili[j + 1])
                {
                    swap(&famili[j], &famili[j + 1]);
                    swap(&name[j], &name[j + 1]);
                    swap(&hogh[j], &hogh[j + 1]);
                    swap(&sab[j], &sab[j + 1]);
                    swap(&kod[j], &kod[j + 1]);
                    swap(&id[j], &id[j + 1]);
                }
        }
        std::cout << "*********************************************************\n";
        std::cout << "list karmandan bar asas tartib horoof alephba : \n";
        std::cout << "*********************************************************\n\n\n\n\n";
        for (size_t i = 0; i < ::__karmand__; i++)
        {
            std::cout << "**************************************\n";
            std::cout << "nam karbar = " << name[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "famili karbar = " << famili[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "hoghoogh = " << hogh[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "shomare personeli = " << id[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "kode melli = " << kod[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "sabeghe kar = " << sab[i] << '\n';
            std::cout << "**************************************\n\n\n";
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}
