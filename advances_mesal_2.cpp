// Note :
// this program uses c++ 14
// Developer = Amir Hossein Nikravan
// shomare daneshjooye = 39914141054085
#include <iostream>
#include <string>
#include <limits>
#include <cstdint>
#include <iomanip>
#include <cstdlib>
namespace
{
    constexpr unsigned count = 20u; // tedad karmand ha
    static int __karmand__ = 0;
    using ull = unsigned long long;
}
struct Personal
{
    std::string name{};
    std::string family{};
    std::string nam_pedar{};
    std::string kod_meli{};
    bool marital_status{};
    int tedad_farzand{};
};

struct Employee
{
    std::string semat{};
    std::uint_fast64_t id{};
    ull hoghoogh{};
    int sabeghe_kar{};
    Personal shakhsi;
};

void checkfail(char, Employee *person, int); // baraye check kardan failure modev
bool receive_information(Employee *);        // daryaft etelaat
void clearscr();                             // clear screen
void clear_buffer();
bool show_information(Employee *); // namayesh etelaat
void menu();                       // menu
void exit();
bool sort(Employee *);                   // sort bar asas hoghoogh nozooli bubble sort
bool check_farzand_hoghoogh(Employee *); // farzand>2 hoghoogh<4M
bool sabeghe_status(Employee *);         // mojarad sabeghe >5
template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{

    Employee person[count];
    std::cout << std::boolalpha; // baraye vaziat ta'ahol
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
        case 2: // sort bar asas hoghoogh nozooli bubble sort
            vaze_edame = sort(person);
            break;
        case 3: // farzand>2 hoghoogh<4M
            vaze_edame = check_farzand_hoghoogh(person);
            break;
        case 4: // mojarad sabeghe >5
            vaze_edame = sabeghe_status(person);
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
            case 't':
                std::cout << "lotfan tedad farzandan ra dar format dorost vared konid : ";
                std::cin >> person[i].shakhsi.tedad_farzand;
                break;
            case 'v':
                std::cout << "lotfan vaziat tahol ra dar format dorost vared konid : ";
                std::cin >> person[i].shakhsi.marital_status;
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
    std::getline(std::cin >> std::ws, person[__karmand__].shakhsi.name);
    std::cout << "*******************************\n";
    std::cout << "family karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin, person[__karmand__].shakhsi.family);
    std::cout << "*******************************\n";
    std::cout << "kod melli karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin, person[__karmand__].shakhsi.kod_meli);
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
    std::cout << "tedad farzand karmand " << __karmand__ + 1 << " : ";
    std::cin >> person[__karmand__].shakhsi.tedad_farzand;
    checkfail('t', person, __karmand__);
    clear_buffer();
    std::cout << "*******************************\n";
    std::cout << "name pedar karmad " << __karmand__ + 1 << " : ";
    std::getline(std::cin >> std::ws, person[__karmand__].shakhsi.nam_pedar);
    std::cout << "*******************************\n";
    std::cout << "vaziat tahol (true/false) karmand " << __karmand__ + 1 << " : ";
    std::cin >> std::boolalpha >> person[__karmand__].shakhsi.marital_status;
    checkfail('v', person, __karmand__);
    clear_buffer();
    std::cout << "*******************************\n";
    std::cout << "semat karmand " << __karmand__ + 1 << " : ";
    std::getline(std::cin >> std::ws, person[__karmand__].semat);
    std::cout << "*******************************\n";
    __karmand__++;
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);

} // end receiving

bool show_information(Employee *person)
{ // start showing
    clearscr();
    if (person[0].shakhsi.name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        std::cout << "*********************************************************\n";
        std::cout << "namyaesh list karmandan : \n";
        std::cout << "*********************************************************\n\n\n\n\n";
        for (size_t i = 0; i < ::__karmand__; i++)
        {
            std::cout << "**************************************\n";
            std::cout << "nam karbar = " << person[i].shakhsi.name << '\n';
            std::cout << "**************************************\n";
            std::cout << "famili karbar = " << person[i].shakhsi.family << '\n';
            std::cout << "**************************************\n";
            std::cout << "hoghoogh = " << person[i].hoghoogh << '\n';
            std::cout << "**************************************\n";
            std::cout << "shomare personeli = " << person[i].id << '\n';
            std::cout << "**************************************\n";
            std::cout << "kode melli = " << person[i].shakhsi.kod_meli << '\n';
            std::cout << "**************************************\n";
            std::cout << "sabeghe kar = " << person[i].sabeghe_kar << '\n';
            std::cout << "**************************************\n";
            std::cout << "tedad farzand = " << person[i].shakhsi.tedad_farzand << '\n';
            std::cout << "**************************************\n";
            std::cout << "name pedar = " << person[i].shakhsi.nam_pedar << '\n';
            std::cout << "**************************************\n";
            std::cout << "vaziat tahol = " << std::boolalpha << person[i].shakhsi.marital_status << '\n';
            std::cout << "**************************************\n";
            std::cout << "semat = " << person[i].semat << '\n';
            std::cout << "**************************************\n\n\n";
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
} // end showing

bool check_farzand_hoghoogh(Employee *person)
{
    clearscr();
    if (person[0].shakhsi.name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        std::cout << "******************************************************************\n";
        std::cout << "list karmandan ba farzand bishtar az 2 va hoghoogh kam tar az 4M :\n";
        std::cout << "******************************************************************\n\n\n\n\n";
        for (size_t i = 0; i < __karmand__; i++)
        {
            if (person[i].shakhsi.tedad_farzand > 2 && person[i].hoghoogh < 4000000)
            {
                std::cout << "**************************************\n";
                std::cout << "nam karbar = " << person[i].shakhsi.name << '\n';
                std::cout << "**************************************\n";
                std::cout << "famili karbar = " << person[i].shakhsi.family << '\n';
                std::cout << "**************************************\n";
                std::cout << "hoghoogh = " << person[i].hoghoogh << '\n';
                std::cout << "**************************************\n";
                std::cout << "shomare personeli = " << person[i].id << '\n';
                std::cout << "**************************************\n";
                std::cout << "kode melli = " << person[i].shakhsi.kod_meli << '\n';
                std::cout << "**************************************\n";
                std::cout << "sabeghe kar = " << person[i].sabeghe_kar << '\n';
                std::cout << "**************************************\n";
                std::cout << "name pedar = " << person[i].shakhsi.nam_pedar << '\n';
                std::cout << "**************************************\n";
                std::cout << "vaziat tahaol = " << person[i].shakhsi.marital_status << '\n';
                std::cout << "**************************************\n";
                std::cout << "tedad farzand = " << person[i].shakhsi.tedad_farzand << '\n';
                std::cout << "**************************************\n";
                std::cout << "semat = " << person[i].semat << '\n';
                std::cout << "**************************************\n\n\n\n";
            }
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}

bool sabeghe_status(Employee *person)
{
    clearscr();
    if (person[0].shakhsi.name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        std::cout << "***************************************************\n";
        std::cout << "list karmandan ba sabeghe balaye 5 sal va mojarad :\n";
        std::cout << "***************************************************\n\n\n\n\n";
        for (size_t i = 0; i < __karmand__; i++)
        {
            if (!person[i].shakhsi.marital_status && person[i].sabeghe_kar > 5)
            {
                std::cout << "**************************************\n";
                std::cout << "nam karbar = " << person[i].shakhsi.name << '\n';
                std::cout << "**************************************\n";
                std::cout << "famili karbar = " << person[i].shakhsi.family << '\n';
                std::cout << "**************************************\n";
                std::cout << "hoghoogh = " << person[i].hoghoogh << '\n';
                std::cout << "**************************************\n";
                std::cout << "shomare personeli = " << person[i].id << '\n';
                std::cout << "**************************************\n";
                std::cout << "kode melli = " << person[i].shakhsi.kod_meli << '\n';
                std::cout << "**************************************\n";
                std::cout << "sabeghe kar = " << person[i].sabeghe_kar << '\n';
                std::cout << "**************************************\n";
                std::cout << "name pedar = " << person[i].shakhsi.nam_pedar << '\n';
                std::cout << "**************************************\n";
                std::cout << "vaziat tahaol = " << person[i].shakhsi.marital_status << '\n';
                std::cout << "**************************************\n";
                std::cout << "tedad farzand = " << person[i].shakhsi.tedad_farzand << '\n';
                std::cout << "**************************************\n";
                std::cout << "semat = " << person[i].semat << '\n';
                std::cout << "**************************************\n\n\n\n";
            }
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}

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

    std::cout << "\a*****************************************************************************\n";
    std::cout << "1.ezafe kardan karmand \n";
    std::cout << "*****************************************************************************\n";
    std::cout << "2.namyesh list karmandan bar asas hoghoogh(nozooli)\n";
    std::cout << "*****************************************************************************\n";
    std::cout << "3.namayesh list karmandan ba farzand bishtar az 2 va hoghoogh kam tar az 4M\n";
    std::cout << "*****************************************************************************\n";
    std::cout << "4.list karmandan ba sabeghe balaye 5 sal va mojarad\n";
    std::cout << "*****************************************************************************\n";
    std::cout << "5.namayesh kol karmandan\n";
    std::cout << "*****************************************************************************\n";
    std::cout << "6.khorooj\n";
    std::cout << "*****************************************************************************\n";
    std::cout << "tedad karmand haye vared shode = " << __karmand__ << "\n\n\n\n\n";
    std::cout << "lotfan gozine mored nazar khod ra vared konid :";
}

void exit()
{
    clearscr();
    std::cout << "ba moafaghiat kharej shodid!!";
}

bool sort(Employee *person)
{
    int counter{__karmand__}, tedadfarzand[count];
    std::string famili[count] = {""}, name[count] = {""};
    std::string sema[count]{""}, pedar[count]{""}, kod[count]{""};
    ull hogh[count] = {0};
    int sab[count] = {};
    bool status[count];
    ull id[count] = {};

    clearscr();
    if (person[0].shakhsi.name == "")
        std::cout << "shoma hanooz karmandi ra vared nakarde id!!\n";
    else
    {
        for (size_t i = 0; i < counter; i++)
        {
            famili[i] = person[i].shakhsi.family;
            name[i] = person[i].shakhsi.name;
            hogh[i] = person[i].hoghoogh;
            sab[i] = person[i].sabeghe_kar;
            kod[i] = person[i].shakhsi.kod_meli;
            id[i] = person[i].id;
            status[i] = person[i].shakhsi.marital_status;
            tedadfarzand[i] = person[i].shakhsi.tedad_farzand;
            sema[i] = person[i].semat;
            pedar[i] = person[i].shakhsi.nam_pedar;
        }
        for (int i = 0; i < counter - 1; i++)
        {
            for (int j = 0; j < counter - i - 1; j++)
                if (hogh[j] < hogh[j + 1])
                {
                    swap(&famili[j], &famili[j + 1]);
                    swap(&name[j], &name[j + 1]);
                    swap(&hogh[j], &hogh[j + 1]);
                    swap(&sab[j], &sab[j + 1]);
                    swap(&kod[j], &kod[j + 1]);
                    swap(&id[j], &id[j + 1]);
                    swap(&status[j], &status[j + 1]);
                    swap(&sema[j], &sema[j + 1]);
                    swap(&pedar[j], &pedar[j + 1]);
                    swap(&tedadfarzand[j], &tedadfarzand[j + 1]);
                }
        }
        std::cout << "*********************************************************\n";
        std::cout << "list karmandan bar asas hoghoogh nozooli : \n";
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
            std::cout << "**************************************\n";
            std::cout << "name pedar = " << pedar[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "vaziat tahaol = " << status[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "tedad farzand = " << tedadfarzand[i] << '\n';
            std::cout << "**************************************\n";
            std::cout << "semat = " << sema[i] << '\n';
            std::cout << "**************************************\n\n\n\n";
        }
    }
    std::cout << "\n\nnamyesh menu  y/n ?";
    char vaziat;
    std::cin >> vaziat;
    return ((vaziat == 'y') ? 1 : 0);
}
